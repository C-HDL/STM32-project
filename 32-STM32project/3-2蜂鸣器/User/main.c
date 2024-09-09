#include "stm32f10x.h"                  // Device header
#include "beep.h"
#include "Delay.h"
int main()
{		
		int i=5;
			while(i--)
			{Beep_();			
			GPIO_ResetBits(GPIOB,GPIO_Pin_12);
			Delay_ms(100);
			GPIO_SetBits(GPIOB,GPIO_Pin_12);
			Delay_ms(100);
			GPIO_ResetBits(GPIOB,GPIO_Pin_12);
			Delay_ms(100);
			GPIO_SetBits(GPIOB,GPIO_Pin_12);
			Delay_ms(700);}


}

