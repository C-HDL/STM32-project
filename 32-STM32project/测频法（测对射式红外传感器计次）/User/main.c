#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Delay.h"
#include "countsensor.h" 
#include "timer.h"
int main()
{		
		u16 temp=0;
		CountSensor_init();
		OLED_Init();
		timer_init();
		
	OLED_ShowString(1,1,"Count:");
while(1)
			{
		
		temp=Get_count();
		OLED_ShowNum(1,7,temp,5);
}
}
