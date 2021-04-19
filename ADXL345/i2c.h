
/***************************************************************************
 *   @file   i2c.h
 *   @brief  Communication Driver.
 *   @author xlr-spock
****************************************************************************/
#ifndef _I2C_H_
#define _I2C_H_

/***************************************************************************/
/* Include Files                                                           */
/***************************************************************************/
#include "conf.h"


/******************************************************************************/
/* Functions Prototypes                                                       */
/******************************************************************************/


/*! Writes data to a slave device. */
void I2C_Reset(void);

/*! Writes data to a slave device. */
unsigned char I2C_Write( unsigned char slaveAdder,unsigned regAdder,
							 unsigned char* dataBuffer,unsigned char len );
/*! Reads data from a slave device. */
unsigned char I2C_Read(	unsigned char slaveAdder,unsigned regAdder,
                       		unsigned char* dataBuffer,unsigned char len	);




#endif /* _I2C_H_ */



