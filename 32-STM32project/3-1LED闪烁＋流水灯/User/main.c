#include "stm32f10x.h"                  // Device header
#include "led.h"
#include "Delay.h"
int main()
{		
		while(1)
		{	
			
			for(int i=0;i<8;i++)
			{
				LED_Init();
				GPIO_Write(GPIOA,~(0x0001<<i));
				Delay_ms(250);			
			}
			for(int i=6;i>0;i--)
			{
				LED_Init();
				GPIO_Write(GPIOA,~(0x0001<<i));
				Delay_ms(250);			
			}
			

		}
}
