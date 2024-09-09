#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Delay.h"
#include "encoder.h"
int main()
{		
		int16_t temp=0;
		OLED_Init();
		Encoder_init();
	OLED_ShowString(1,1,"Num:");

			while(1){
				//temp+=Get_count();
				temp=Get_count();
				OLED_ShowSignedNum(1,5,temp,5);
				
		


}
}
