#include "stm32f10x.h"                  // Device header
#include "led.h"
#include "Delay.h"
#include "key.h"
int main()
{	
	KEY_Init();
	LED_Init();
	u8 key=0;
	u8 i=0;
				/*while(1)
				{
					if(!key)
					key=scan(0);
					if(key==keypress_1) 
					{	
						key=0;
						if(GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_0)&GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_2)&GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_4)&GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_6)==1)
						{while(!key)
						{
							//LED1357_TURN();
							
							for(i=0;i<8;i++)
						{
								if(i%2==0)
						{
								GPIO_Write(GPIOA, ~(0x0001<<i));
						}
								Delay_ms(50);
						}
								key=scan(0);
							
						}
					}
					else 
					{
						GPIO_SetBits(GPIOA,GPIO_Pin_0|GPIO_Pin_2|GPIO_Pin_4|GPIO_Pin_6);
					}
					}
					if(key==keypress_11) 
					{	
						key=0;
						if(GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_1)&GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_3)&GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_5)&GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_7)==1)
						{while(!key)
						{
							//LED2468_TURN();
							
							for(i=1;i<8;i++)
						{
								if(i%2==1)
						{
								GPIO_Write(GPIOA, ~(0x0001<<i));
						}
								Delay_ms(50);
						}
								key=scan(0);
							
						}
					}
					else 
					{
						GPIO_SetBits(GPIOA,GPIO_Pin_1|GPIO_Pin_3|GPIO_Pin_5|GPIO_Pin_7);
					}
					}
				}//¿ØÖÆÁ÷Ë®µÆ                   */
while(1)
	{
					key=scan(0);
					if(key==keypress_1) LED1_TURN();
	        if(key==keypress_11) LED2_TURN();
}


}





