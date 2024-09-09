#include "lightsensor.h" 

void lightsensor_init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode  =	GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin   =	GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Speed =	GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);

}

u8 lightsensor_read(void)
{
	return GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13);
}