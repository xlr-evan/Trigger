
#ifndef	_ADXL345_H
#define _ADXL345_H

#include "conf.h"

/* ADXL345 i2c 访问地址0x537bit)---"0101 0011*/
#define		adxl345_addr			0xA6	//左移一位，W_addr:0xA6,
											//		   R_addr:0xA7

/* ADXL345 寄存器地址映射 */
#define		Device_ID				0x00	//设备ID:0xE5
#define		BW_RATE					0x2C	//数据速率及功率控制
#define		POWER_CTL				0x2D	//电源控制

#define		DATA_FORMAT				0x31	//数据格式控制
#define		OFSX					0x1E    //X轴偏移
#define		OFSY					0x1F	//Y轴偏移
#define		OFSZ					0x20	//Z轴偏移

#define		Original_0				0x32	//X轴数据0
#define		Original_1				0x33	//X轴数据1
#define		Original_2		    	0x34	//Y轴数据0
#define		Original_3				0x35	//Y轴数据1
#define		Original_4				0x36	//Z轴数据0
#define		Original_5				0x37	//Z轴数据1

#define		Thresh_TAP				0x1D	//敲击阈值   
#define		DUR						0x21	//敲击持续时间
#define		Latent					0x22	//敲击延迟
#define		Window					0x23	//敲击窗口
#define		TAP_AXES				0x2A	//单击/双击轴控制
#define		ACT_TAP_STATUS			0x2B	//单击/双击源

#define		THRESH_ACT				0x24	//活动阈值
#define		THRESH_INACT			0x25	//静止阈值
#define		TIME_INACT				0x26	//静止时间
#define		ACT_INACT_CTL			0x27	//轴使能控制活动和静止时间
#define		THRESH_FF				0x28	//自由落体阈值
#define		TIME_FF					0x29	//自由落体时间

#define		INT_ENABLE				0x2E	//中断使能控制
#define		INT_MAP					0x2F	//中断映射控制
#define		INT_SOURCE				0x30	//中断源

#define		FIFO_CTL				0x38	//FIFO控制
#define		FIFO_STATUS				0x39	//FIFO状态



unsigned char adxl345_Init(void);
unsigned char adxl345_OriginXYZ(unsigned char *buf,unsigned char len);
//unsigned char mpu6050_Init(void);
//unsigned char MPU_Get_Accelerometer(unsigned char *buf,unsigned char len);
void Delay100ms(void);


#endif


