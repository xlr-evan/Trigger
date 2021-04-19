
#include "adxl345.h"

void Delay100ms(void)		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	i = 6;
	j = 157;
	k = 59;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}


unsigned char adxl345_Init(void)
{
	unsigned char buf = 0;
	unsigned char configBuff[] = {0x08,0x09,0x00};

	/* 设置adxl345 的数据格式，测量范围-->右对齐，±4g*/
	if(I2C_Write(adxl345_addr,DATA_FORMAT,&configBuff[0],1)) return 1;
	/* 设置adxl345 的数据输出50Hz,正常功耗 */
	if(I2C_Write(adxl345_addr,BW_RATE,&configBuff[1],1)) return 1;
	/* 禁止中断 */
	if(I2C_Write(adxl345_addr,INT_ENABLE,&configBuff[2],1)) return 1;
	/* FIFO旁路模式 */
	if(I2C_Write(adxl345_addr,FIFO_CTL,&configBuff[2],1)) return 1;
	/* 测量模式，禁止休眠 */
	if(I2C_Write(adxl345_addr,POWER_CTL,&configBuff[0],1)) return 1;
	/* 读取adxl345的寄存器0x00，得到设备ID */
	if(I2C_Read(adxl345_addr,Device_ID,&buf,1) == 1) return 1;

	/* 比较设备ID是否正确: 0xe5-->adxl345,0xe6-->adxl346 */
	if(buf != 0xe5 && buf != 0xe6) return 1;

	return 0;
}

unsigned char adxl345_OriginXYZ(unsigned char *buf,unsigned char len)
{
	/* 读取adxl345的寄存器0x32，得到x轴原始数据 */
	if(I2C_Read(adxl345_addr,Original_0,buf,len) == 1) return 1;

	return 0;
}
#if 0
unsigned char mpu6050_Init(void)
{
	unsigned char buf = 0;
	unsigned char configBuff[] = {0x80,0x00,0x01};
	
	if(I2C_Write(0xD0,0x6B,&configBuff[0],1)) return 1;
	Delay100ms();
	if(I2C_Write(0xD0,0x6B,&configBuff[1],1)) return 1;
	
	if(I2C_Read(0xD0,0x75,&buf,1) == 1) return 1;

	if(buf != 0x68) return 1;
	if(I2C_Write(0xD0,0x6B,&configBuff[2],1)) return 1;
	if(I2C_Write(0xD0,0x6C,&configBuff[1],1)) return 1;

	return 0;
}

unsigned char MPU_Get_Accelerometer(unsigned char *buf,unsigned char len)
{
	if(I2C_Read(0x68,0x3b,buf,len) == 1) return 1;

    return 0;
}
#endif
