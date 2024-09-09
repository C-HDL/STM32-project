#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Delay.h"
#include "pwm.h"
#include "ic.h"
int main()
{		
		

	
		OLED_Init();
		PWM_Init();
		IC_Init();
		PWM_SetPrescaler(7200-1);
		PWM_SetCompare1(80);
		OLED_ShowString(1,1,"Freq:00000Hz");
		OLED_ShowString(2,1,"Duty:00%");
			while(1){
					OLED_ShowNum(1,6,IC_Get(),5);
					OLED_ShowNum(2,6,IC_duty_Get(),2);
}
}
