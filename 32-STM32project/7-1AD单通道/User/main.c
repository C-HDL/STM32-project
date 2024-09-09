#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Delay.h"
#include "ad.h"  
u16 temp;
float V;
int main()
{		
		OLED_Init();
		AD_Init();
	
		OLED_ShowString(1,1,"ADValue");
	OLED_ShowString(2,1,"Voltage:0.00V");
			while(1){
				temp=AD_Get();
				V=(float)temp/4095*3.3;
				OLED_ShowNum(1,9,temp,4);
				OLED_ShowNum(2,9,V,1);
				OLED_ShowNum(2,11,(u16)(V*100)%100,2);

				Delay_ms(100);
}
}
