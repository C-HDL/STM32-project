#include "serial.h"

void serial_init(void)
{
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	
		GPIO_InitTypeDef GPIO_InitStructure;
		GPIO_InitStructure.GPIO_Mode  =	GPIO_Mode_AF_PP;
		GPIO_InitStructure.GPIO_Pin   =	GPIO_Pin_9;
		GPIO_InitStructure.GPIO_Speed =	GPIO_Speed_50MHz;
		GPIO_Init(GPIOA,&GPIO_InitStructure);
	
		USART_InitTypeDef USART_InitStructure;
		USART_InitStructure.USART_BaudRate=9600;
		USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
		USART_InitStructure.USART_Mode=USART_Mode_Tx;
		USART_InitStructure.USART_Parity=USART_Parity_No;
		USART_InitStructure.USART_StopBits=USART_StopBits_1;
		USART_InitStructure.USART_WordLength=USART_WordLength_8b;
		USART_Init(USART1,&USART_InitStructure);
	
		USART_Cmd(USART1,ENABLE);

}

void sendbyte(u8 byte)
{
	USART_SendData(USART1, byte);
	while(!USART_GetFlagStatus(USART1,USART_FLAG_TXE));
}

void sendarray(u8 *array,u16 length)
{
	for(u16 i=0;i<length;i++)
		sendbyte(array[i]);
}
void sendstring(char* string)
{
	for(u16 i=0;string[i]!='\0';i++)
		sendbyte(string[i]);
}

u16 square(u16 x,u16 y)
{
	u16 result =1;
	while(y--)
	{
		result*=x;
	}
	return result;
}

void sendnumber(u16 number,u16 length)
{
	for(u16 i=0;i<length;i++)
		sendbyte(number/square(10,length-i-1)%10+0x30);
}
