
#include "gpio.h"


void gpio_Init(void)
{
	/* 配置引脚为开漏输出 */
	P3M1 |= 0xc;
	P3M0 |= 0xc;
}


