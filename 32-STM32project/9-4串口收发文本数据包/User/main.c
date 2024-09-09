#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Delay.h"
#include "serial.h"
#include "led.h"
#include <string.h>


u8 array[4]={0x98,0xfe,0x88,0x03};
u8 rxdata;
int main()
{		
	LED_Init();
	OLED_Init();
	serial_init();
	OLED_ShowString(1,1,"txpacket:");
	OLED_ShowString(3,1,"rxpacket:");
	
			while(1){
	
		if(getflag())
		{
				OLED_ShowString(4,1,rxpacket);
			
				if(strcmp(rxpacket,"LED_ON")==0)
				{
					GPIO_ResetBits(GPIOA,GPIO_Pin_0);
					sendstring("LED_ON_OK\r\n");
					OLED_ShowString(2,1,"LED_ON_OK");					
				}
				else if(strcmp(rxpacket,"LED_OFF")==0)
				{
					GPIO_SetBits(GPIOA,GPIO_Pin_0);
					sendstring("LED_OFF_OK\r\n");
					OLED_ShowString(2,1,"LED_OFF_OK");					
				}
				else
				{
					sendstring("ERROR\r\n");
					OLED_ShowString(2,1,"ERROR     ");	
				}
				
		}


}
}
