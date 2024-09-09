#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Delay.h"
#include "serial.h"

u8 array[4]={0x98,0xfe,0x88,0x03};
u8 rxdata;
int main()
{		
		OLED_Init();
	serial_init();
//	OLED_ShowChar(1,1,'A');
//	OLED_ShowString(1,3,"HelloWorld!");
//	OLED_ShowNum(2,1,12345,5);
//	OLED_ShowSignedNum(2,7,-98,2);	
//	OLED_ShowHexNum(3,1,0xfd53,4);
//	OLED_ShowBinNum(4,1,0xfd53,16);
	sendbyte(0x42);
	sendarray(array,4);
	sendstring("whyppfat\r\n");
	sendnumber(603,3);
			while(1){
		
//	if(USART_GetFlagStatus(USART1,USART_FLAG_RXNE))
//	{
//		rxdata=USART_ReceiveData(USART1);
//		OLED_ShowHexNum(1,1,rxdata,2);
//	}
			if(getflag())	
			{
			sendbyte(receive);	
			OLED_ShowHexNum(1,1,receive,2);
			}
}
}
