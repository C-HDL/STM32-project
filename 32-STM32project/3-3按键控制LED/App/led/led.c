#include "led.h"

void LED_Init(void)
{
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
		GPIO_InitTypeDef GPIO_InitStructure;
		GPIO_InitStructure.GPIO_Mode  =	GPIO_Mode_Out_PP;
		GPIO_InitStructure.GPIO_Pin   =	GPIO_Pin_13;
		GPIO_InitStructure.GPIO_Speed =	GPIO_Speed_50MHz;
		GPIO_Init(GPIOC,&GPIO_InitStructure);
		//GPIO_SetBits(GPIOC,GPIO_Pin_13);
		//GPIO_ResetBits(GPIOC,GPIO_Pin_13);
	
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
		GPIO_InitStructure.GPIO_Pin   =	GPIO_Pin_All;
		GPIO_Init(GPIOA,&GPIO_InitStructure);
		//GPIO_SetBits(GPIOA,GPIO_Pin_0);
		//GPIO_ResetBits(GPIOA,GPIO_Pin_0);
		GPIO_Write(GPIOA, 0x00ff);

}
void LED_1_3_5_7_ON(void)
{
	u8 i=0;
	for(i=0;i<8;i++)
	{
		if(i%2==0)
		{
			GPIO_Write(GPIOA, ~(0x0001<<i));
		}
		Delay_ms(50);
	}
}

void LED_2_4_6_8_ON(void)
{
	u8 i=0;
	for(i=0;i<8;i++)
	{
		if(i%2==1)
		{
			GPIO_Write(GPIOA, ~(0x0001<<i));
		}
		Delay_ms(50);
	}
}

void LED_1_3_5_7_OFF(void)
{
	GPIO_SetBits(GPIOA,GPIO_Pin_0|GPIO_Pin_2|GPIO_Pin_4|GPIO_Pin_6);
}
void LED_2_4_6_8_OFF(void)
{
	GPIO_SetBits(GPIOA,GPIO_Pin_1|GPIO_Pin_3|GPIO_Pin_5|GPIO_Pin_7);
}
void LED1357_TURN(void)
{	u8 i=0;
	if(GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_0)&GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_2)&GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_4)&GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_6)==1)
	{
		//GPIO_ResetBits(GPIOA,GPIO_Pin_0);
		for(i=0;i<8;i++)
	{
		if(i%2==0)
		{
			GPIO_Write(GPIOA, ~(0x0001<<i));
		}
		Delay_ms(50);
	}
	}
	else GPIO_SetBits(GPIOA,GPIO_Pin_0|GPIO_Pin_2|GPIO_Pin_4|GPIO_Pin_6);
}
void LED2468_TURN(void)
{
	if(GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_1)&GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_3)&GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_5)&GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_7)==1)
	{	u8 i=0;
		//GPIO_ResetBits(GPIOA,GPIO_Pin_1);
		for(i=0;i<8;i++)
	{
		if(i%2==1)
		{
			GPIO_Write(GPIOA, ~(0x0001<<i));
		}
		Delay_ms(50);
	}
	}
	else GPIO_SetBits(GPIOA,GPIO_Pin_1|GPIO_Pin_3|GPIO_Pin_5|GPIO_Pin_7);
}
void LED1_TURN(void)
{
	if((GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_0)==1))
	GPIO_ResetBits(GPIOA,GPIO_Pin_0);	
	else
  GPIO_SetBits(GPIOA,GPIO_Pin_0);		
	
}
void LED2_TURN(void)
{
	if((GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_1)==1))
	GPIO_ResetBits(GPIOA,GPIO_Pin_1);
	else	
	GPIO_SetBits(GPIOA,GPIO_Pin_1);
	
}
