
#ifndef	_ADXL345_H
#define _ADXL345_H

#include "conf.h"

/* ADXL345 i2c ���ʵ�ַ0x537bit)---"0101 0011*/
#define		adxl345_addr			0xA6	//����һλ��W_addr:0xA6,
											//		   R_addr:0xA7

/* ADXL345 �Ĵ�����ַӳ�� */
#define		Device_ID				0x00	//�豸ID:0xE5
#define		BW_RATE					0x2C	//�������ʼ����ʿ���
#define		POWER_CTL				0x2D	//��Դ����

#define		DATA_FORMAT				0x31	//���ݸ�ʽ����
#define		OFSX					0x1E    //X��ƫ��
#define		OFSY					0x1F	//Y��ƫ��
#define		OFSZ					0x20	//Z��ƫ��

#define		Original_0				0x32	//X������0
#define		Original_1				0x33	//X������1
#define		Original_2		    	0x34	//Y������0
#define		Original_3				0x35	//Y������1
#define		Original_4				0x36	//Z������0
#define		Original_5				0x37	//Z������1

#define		Thresh_TAP				0x1D	//�û���ֵ   
#define		DUR						0x21	//�û�����ʱ��
#define		Latent					0x22	//�û��ӳ�
#define		Window					0x23	//�û�����
#define		TAP_AXES				0x2A	//����/˫�������
#define		ACT_TAP_STATUS			0x2B	//����/˫��Դ

#define		THRESH_ACT				0x24	//���ֵ
#define		THRESH_INACT			0x25	//��ֹ��ֵ
#define		TIME_INACT				0x26	//��ֹʱ��
#define		ACT_INACT_CTL			0x27	//��ʹ�ܿ��ƻ�;�ֹʱ��
#define		THRESH_FF				0x28	//����������ֵ
#define		TIME_FF					0x29	//��������ʱ��

#define		INT_ENABLE				0x2E	//�ж�ʹ�ܿ���
#define		INT_MAP					0x2F	//�ж�ӳ�����
#define		INT_SOURCE				0x30	//�ж�Դ

#define		FIFO_CTL				0x38	//FIFO����
#define		FIFO_STATUS				0x39	//FIFO״̬



unsigned char adxl345_Init(void);
unsigned char adxl345_OriginXYZ(unsigned char *buf,unsigned char len);
//unsigned char mpu6050_Init(void);
//unsigned char MPU_Get_Accelerometer(unsigned char *buf,unsigned char len);
void Delay100ms(void);


#endif


