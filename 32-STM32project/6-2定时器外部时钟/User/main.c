#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Delay.h"
#include "timer.h"
int main()
{		
		u16 temp=0;
		OLED_Init();
		timer_init();
		OLED_ShowString(1,1,"Num:");
		OLED_ShowString(2,1,"CNT:");
	

			while(1){
				temp=Get_count();
				OLED_ShowNum(1,5,temp,5);
				OLED_ShowNum(2,5,TIM_GetCounter(TIM2),5);

}
}
