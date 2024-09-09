#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Delay.h"
#include "timer.h"
#include "encoder.h"
int16_t speed;
int main()
{		

		OLED_Init();
		timer_init();
		Encoder_init();
		OLED_ShowString(1,1,"Speed:");

	

			while(1){
				OLED_ShowSignedNum(1,7,speed,5);
				OLED_ShowSignedNum(2,7,TIM_GetCounter(TIM3),5);

}
}
void TIM2_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM2,TIM_IT_Update)==SET)
	{
		speed=Get_encoder();
		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
	}
		
}