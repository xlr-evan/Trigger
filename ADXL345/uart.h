
#ifndef	_UART_H
#define	_UART_H

#include "conf.h"

#define 	BRT            (65536 - CLK_FOSC / 115200 / 4)


void UartInit(void);
void UartSend(char dat);
//void usart1_report_imu(short aacx,short aacy,short aacz,short gyrox,short gyroy,short gyroz,short roll,short pitch,short yaw);
void usart1_report_imu(short roll,short pitch);




#endif



