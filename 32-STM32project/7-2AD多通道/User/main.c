#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Delay.h"
#include "ad.h"  
u16 ad0,ad1,ad2,ad3;
float V;
int main()
{		
		OLED_Init();
		AD_Init();
	
		OLED_ShowString(1,1,"ad0");
		OLED_ShowString(2,1,"ad1");
		OLED_ShowString(3,1,"ad2");
		OLED_ShowString(4,1,"ad3");
			while(1){
				ad0=AD_Get(ADC_Channel_0);
				ad1=AD_Get(ADC_Channel_1);
				ad2=AD_Get(ADC_Channel_2);
				ad3=AD_Get(ADC_Channel_3);
				
				OLED_ShowNum(1,5,ad0,4);
				OLED_ShowNum(2,5,ad1,4);
				OLED_ShowNum(3,5,ad2,4);
				OLED_ShowNum(4,5,ad3,4);
				
				Delay_ms(100);
}
}
