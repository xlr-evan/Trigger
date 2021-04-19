
#include "conf.h"
 

void main()
{
	unsigned char datax[6] = {0};
	short Origin[3] = {0};
	float present[3] = {0};
	float ax,ay;
	
	gpio_Init();
    UartInit();
    EA = 1;
	
	while(adxl345_Init())
	{
		I2C_Reset();
		UartSend(0xcc);
		Delay100ms();
	}

    while (1)
    {
		adxl345_OriginXYZ(datax,6);

		Origin[0] = (datax[1] << 8) | datax[0];
		Origin[1] = (datax[3] << 8) | datax[2];
		Origin[2] = (datax[5] << 8) | datax[4];

		present[0] = 0.35*present[0] + 0.65*Origin[0];
		present[1] = 0.35*present[1] + 0.65*Origin[1];
		present[2] = 0.35*present[2] + 0.65*Origin[2];

		ax = atan2(present[1],present[2])*57.3+0.5;
		ay = atan2((-present[0]),sqrt(pow(present[1],2) + pow(present[2],2)))*57.3+0.5;
		
		usart1_report_imu((short)(ax*100),(short)(ay*100));
		
		Delay100ms();
    }
	
}

