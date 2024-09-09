#include "serial.h"
u8 txpacket[4];
u8 rxpacket[4];
u8 flag;
void serial_init(void)
{
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	
		GPIO_InitTypeDef GPIO_InitStructure;
		GPIO_InitStructure.GPIO_Mode  =	GPIO_Mode_AF_PP;
		GPIO_InitStructure.GPIO_Pin   =	GPIO_Pin_9;
		GPIO_InitStructure.GPIO_Speed =	GPIO_Speed_50MHz;
		GPIO_Init(GPIOA,&GPIO_InitStructure);
	

		GPIO_InitStructure.GPIO_Mode  =	GPIO_Mode_IPU;
		GPIO_InitStructure.GPIO_Pin   =	GPIO_Pin_10;
		GPIO_InitStructure.GPIO_Speed =	GPIO_Speed_50MHz;
		GPIO_Init(GPIOA,&GPIO_InitStructure);
	
		USART_InitTypeDef USART_InitStructure;
		USART_InitStructure.USART_BaudRate=9600;
		USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
		USART_InitStructure.USART_Mode=USART_Mode_Tx | USART_Mode_Rx;
		USART_InitStructure.USART_Parity=USART_Parity_No;
		USART_InitStructure.USART_StopBits=USART_StopBits_1;
		USART_InitStructure.USART_WordLength=USART_WordLength_8b;
		USART_Init(USART1,&USART_InitStructure);
	
	
		USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
		
		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
		NVIC_InitTypeDef NVIC_Initstructure;
		NVIC_Initstructure.NVIC_IRQChannel = USART1_IRQn;
		NVIC_Initstructure.NVIC_IRQChannelCmd = ENABLE;
		NVIC_Initstructure.NVIC_IRQChannelPreemptionPriority = 1;
		NVIC_Initstructure.NVIC_IRQChannelSubPriority = 1;
		NVIC_Init ( &NVIC_Initstructure) ;

	
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

void sendpacket(u8* x)
{
	sendbyte(0xff);
	sendarray(x,4);
	sendbyte(0xfe);
}

u8 getflag(void)
{
	if(flag==1)
	{
		flag=0;
		return 1;
	}
	return 0;
}

void USART1_IRQHandler(void)
{
	static u8 rxstate=0;
	static u8 cnt=0;
	if(USART_GetFlagStatus(USART1,USART_IT_RXNE))
	{	
		u8 data=USART_ReceiveData(USART1);
		
		if(rxstate==0)
		{		
			if(data==0xff)
				rxstate=1;
		}
		else if(rxstate==1)
		{
			rxpacket[cnt]=data;
			cnt++;
			if(cnt>3)
				rxstate=2;
		}
		else if(rxstate==2)
		{
			if(data==0xfe)
			{
				rxstate=0;
				flag=1;
				cnt=0;
				sendpacket(rxpacket);
			}
		}
	

		USART_ClearITPendingBit(USART1,USART_IT_RXNE);
	}
}
