#include "key.h"
#define keypress_1 		1
#define keypress_11		11
#define nopress				0
void KEY_Init(void)
{
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
		GPIO_InitTypeDef GPIO_InitStructure;
		GPIO_InitStructure.GPIO_Mode  =	GPIO_Mode_IPU;
		GPIO_InitStructure.GPIO_Pin   =	GPIO_Pin_1|GPIO_Pin_11;
		GPIO_InitStructure.GPIO_Speed =	GPIO_Speed_50MHz;
		GPIO_Init(GPIOB,&GPIO_InitStructure);
}

u8 scan(u8 i)
{	
	static u8 key=1;
	if(i==1) key=1;
	
	if(key && (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)==0))
	{
		Delay_ms(20);
		key=0;
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)==0)
		Delay_ms(20);
		return keypress_1;		
	}
	else if(key && (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11)==0))
	{
		Delay_ms(20);
		key=0;
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11)==0)
		Delay_ms(20);
		return keypress_11;		
	}
	else if((key==0) && ((GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)==1) &&(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11)==1)))
		key=1;
		return nopress;
}
