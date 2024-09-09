#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Delay.h"
int main()
{		
		OLED_Init();
	OLED_ShowChar(1,1,'A');
	OLED_ShowString(1,3,"HelloWorld!");
	OLED_ShowNum(2,1,12345,5);
	OLED_ShowSignedNum(2,7,-98,2);	
	OLED_ShowHexNum(3,1,0xfd53,4);
	OLED_ShowBinNum(4,1,0xfd53,16);
			while(1){
		


}
}
