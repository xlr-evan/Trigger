
#include "gpio.h"


void gpio_Init(void)
{
	/* ��������Ϊ��©��� */
	P3M1 |= 0xc;
	P3M0 |= 0xc;
}


