#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Delay.h"
#include "key.h"
#include "moter.h"
int main()
{		
		
		int16_t speed=0;
		u8 key=0;
		OLED_Init();
		Moter_init();
		KEY_Init();
		OLED_ShowString(1,1,"Speed:");
		
			while(1){
				key=scan(0);
				if(key==keypress_1)
				{
					speed+=20;
					if(speed>100) speed=-100;
					
					
				}
				Moter_speed(speed);	
				OLED_ShowSignedNum(1,7,speed,3);
}
}
