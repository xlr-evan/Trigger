
/***************************************************************************
 *   @file   i2c.h
 *   @brief  Communication Driver.
 *   @author xlr-spock
****************************************************************************/

/***************************************************************************/
/* Include Files                                                           */
/***************************************************************************/
#include "i2c.h"


/****************************************************************************
 * @brief Initializes the I2C communication peripheral.
 *
 * @param clockFreq - I2C clock frequency (Hz).
 *                    Example: 100000 - I2C clock frequency is 100 kHz.
 * @return status - Result of the initialization procedure.
 *                  Example: 1 - if initialization was successful;
 *                           0 - if initialization was unsuccessful.
*****************************************************************************/
static void I2C_Delay3us(void) //@11.0592MHz
{
	unsigned char i;

	i = 9;
	while(--i);

}

/****************************************************************************
 * @brief Initializes the I2C communication peripheral.
 *
 * @param clockFreq - I2C clock frequency (Hz).
 *                    Example: 100000 - I2C clock frequency is 100 kHz.
 * @return status - Result of the initialization procedure.
 *                  Example: 1 - if initialization was successful;
 *                           0 - if initialization was unsuccessful.
*****************************************************************************/
static void I2C_Start(void)
{
	I2C_SCL = 1;
	I2C_SDA = 1;
	I2C_Delay3us();
	I2C_SDA = 0;
	I2C_Delay3us();
	I2C_SCL = 0;
}

/****************************************************************************
 * @brief Initializes the I2C communication peripheral.
 *
 * @param clockFreq - I2C clock frequency (Hz).
 *                    Example: 100000 - I2C clock frequency is 100 kHz.
 * @return status - Result of the initialization procedure.
 *                  Example: 1 - if initialization was successful;
 *                           0 - if initialization was unsuccessful.
*****************************************************************************/
static void I2C_Stop(void)
{
	I2C_SDA = 0;
	I2C_SCL = 1;
	I2C_Delay3us();
	I2C_SDA = 1;
	I2C_Delay3us();
}

/****************************************************************************
 * @brief Initializes the I2C communication peripheral.
 *
 * @param clockFreq - I2C clock frequency (Hz).
 *                    Example: 100000 - I2C clock frequency is 100 kHz.
 * @return status - Result of the initialization procedure.
 *                  Example: 1 - if initialization was successful;
 *                           0 - if initialization was unsuccessful.
*****************************************************************************/
static void I2C_SendAck(void)
{
	I2C_SDA = 0;
	I2C_SCL = 1;
	I2C_Delay3us();
	I2C_SCL = 0;
	I2C_Delay3us();
}

/****************************************************************************
 * @brief Initializes the I2C communication peripheral.
 *
 * @param clockFreq - I2C clock frequency (Hz).
 *                    Example: 100000 - I2C clock frequency is 100 kHz.
 * @return status - Result of the initialization procedure.
 *                  Example: 1 - if initialization was successful;
 *                           0 - if initialization was unsuccessful.
*****************************************************************************/
static void I2C_SendNAck(void)
{
	I2C_SDA = 1;
	I2C_SCL = 1;
	I2C_Delay3us();
	I2C_SCL = 0;
	I2C_Delay3us();
}

/****************************************************************************
 * @brief Initializes the I2C communication peripheral.
 *
 * @param clockFreq - I2C clock frequency (Hz).
 *                    Example: 100000 - I2C clock frequency is 100 kHz.
 * @return status - Result of the initialization procedure.
 *                  Example: 1 - if initialization was successful;
 *                           0 - if initialization was unsuccessful.
*****************************************************************************/
void I2C_Reset(void)
{
	while(!I2C_SDA)
	{
		I2C_SCL = 0;
		I2C_Delay3us();
		I2C_Delay3us();
		I2C_SCL = 1;
		I2C_Delay3us();
		I2C_Delay3us();
	}
	I2C_Stop();
}

/****************************************************************************
 * @brief Initializes the I2C communication peripheral.
 *
 * @param clockFreq - I2C clock frequency (Hz).
 *                    Example: 100000 - I2C clock frequency is 100 kHz.
 * @return status - Result of the initialization procedure.
 *                  Example: 1 - if initialization was successful;
 *                           0 - if initialization was unsuccessful.
*****************************************************************************/
static unsigned char I2C_RecvACK(void)
{
	unsigned char i = 100;
	
	I2C_SCL = 1;
	I2C_Delay3us();
	while(I2C_SDA)
	{
		I2C_Delay3us();
		i--;
		if(i == 0)
		{
			I2C_SCL = 0;
			return 1;
		}
	}
	I2C_SCL = 0;
	
	return 0;
}

/****************************************************************************
 * @brief Initializes the I2C communication peripheral.
 *
 * @param clockFreq - I2C clock frequency (Hz).
 *                    Example: 100000 - I2C clock frequency is 100 kHz.
 * @return status - Result of the initialization procedure.
 *                  Example: 1 - if initialization was successful;
 *                           0 - if initialization was unsuccessful.
*****************************************************************************/
static void I2C_SendByte(unsigned char dat)
{
	unsigned char i = 8;
	
	for(;i > 0;i--)
	{
		I2C_SCL = 0;
		if(dat & 0x80)
		{
			I2C_SDA= 1;
		}else I2C_SDA= 0;
		dat <<= 1;
		I2C_Delay3us();
		I2C_SCL = 1;
		I2C_Delay3us();
	}
	I2C_SCL = 0;
	I2C_Delay3us();
}

/****************************************************************************
 * @brief Initializes the I2C communication peripheral.
 *
 * @param clockFreq - I2C clock frequency (Hz).
 *                    Example: 100000 - I2C clock frequency is 100 kHz.
 * @return status - Result of the initialization procedure.
 *                  Example: 1 - if initialization was successful;
 *                           0 - if initialization was unsuccessful.
*****************************************************************************/
static unsigned char I2C_RecByte(void)
{
	unsigned char i = 8,dat = 0;

	I2C_SDA = 1;
	for(;i > 0;i--)
	{
		dat <<= 1;
		I2C_SCL = 1;
		I2C_Delay3us();
		dat |= I2C_SDA;
		I2C_SCL = 0;
		I2C_Delay3us();
	}
	return dat;
}

/****************************************************************************
 * @brief Writes data to a slave device.
 *
 * @param slaveAddress - Address of the slave device.
 * @param dataBuffer - Pointer to a buffer storing the transmission data.
 * @param bytesNumber - Number of bytes to write.
 * @param stopBit - Stop condition control.
 *                  Example: 0 - A stop condition will not be sent;
 *                           1 - A stop condition will be sent.
 *
 * @return status - Number of written bytes.

*****************************************************************************/
unsigned char I2C_Write( unsigned char slaveAdder,unsigned regAdder,
							 unsigned char* dataBuffer,unsigned char len )
{
	unsigned char i;

	i = len;
	
    I2C_Start();
	I2C_SendByte(slaveAdder);
	if(I2C_RecvACK()) return 1;
	I2C_SendByte(regAdder);
	if(I2C_RecvACK()) return 1;

	for(;len > 0;len--)
	{
		I2C_SendByte(dataBuffer[i-len]);
		if(I2C_RecvACK()) return 1;
	}
	I2C_Stop();
	
	return 0;
}

/****************************************************************************
 * @brief Reads data from a slave device.
 *
 * @param slaveAddress - Address of the slave device.
 * @param dataBuffer - Pointer to a buffer that will store the received data.
 * @param bytesNumber - Number of bytes to read.
 * @param stopBit - Stop condition control.
 *                  Example: 0 - A stop condition will not be sent;
 *                           1 - A stop condition will be sent.
 *
 * @return status - Number of read bytes.

*****************************************************************************/
unsigned char I2C_Read(	unsigned char slaveAdder,unsigned regAdder,
                       		unsigned char* dataBuffer,unsigned char len	)
{
	unsigned char i;

	i = len;
	
    I2C_Start();
	I2C_SendByte(slaveAdder);
	if(I2C_RecvACK()) return 1;
	I2C_SendByte(regAdder);
	if(I2C_RecvACK()) return 1;

	I2C_Start();
	I2C_SendByte(slaveAdder + 1);
	if(I2C_RecvACK()) return 1;

	for(;len > 0;len--)
	{
		dataBuffer[i-len] = I2C_RecByte();
		if(len == 1)
		{
			I2C_SendNAck();
		}else
		{
			I2C_SendAck();
		}
	}
	I2C_Stop();

	return 0;
}


