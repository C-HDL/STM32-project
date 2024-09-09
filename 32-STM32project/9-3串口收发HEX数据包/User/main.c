#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Delay.h"
#include "serial.h"
#include "key.h"
u8 array[4]={0x98,0xfe,0x88,0x03};
u8 rxdata;
int main()
{		
		u8 key=0;
		KEY_Init();
		OLED_Init();
	serial_init();
	OLED_ShowString(1,1,"txpacket:");
	OLED_ShowString(3,1,"rxpacket:");
	txpacket[0]=0x01;
	txpacket[1]=0x02;
	txpacket[2]=0x03;
	txpacket[3]=0x04;
	
			while(1){
				key=scan(0);
		if(getflag())
		{
			OLED_ShowHexNum(4,1,rxpacket[0],2);
			OLED_ShowHexNum(4,4,rxpacket[1],2);
			OLED_ShowHexNum(4,7,rxpacket[2],2);
			OLED_ShowHexNum(4,10,rxpacket[3],2);
		}
		if(key==keypress_1)
		{
			
			sendpacket(txpacket);
			OLED_ShowHexNum(2,1,txpacket[0],2);
			OLED_ShowHexNum(2,4,txpacket[1],2);
			OLED_ShowHexNum(2,7,txpacket[2],2);
			OLED_ShowHexNum(2,10,txpacket[3],2);
			txpacket[0]++;
			txpacket[1]++;
			txpacket[2]++;
			txpacket[3]++;
		}

}
}
