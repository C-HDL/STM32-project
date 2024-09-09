#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Delay.h"
#include "pwm.h"

int main()
{		
		
		uint16_t i=0;
		uint16_t j=0;
		uint16_t k=0;
		uint16_t dir1=0;
		uint16_t dir2=0;
		uint16_t dir3=0;
	
		OLED_Init();
		PWM_Init();
	
		OLED_ShowString(1,3,"HelloWorld!");

			while(1){
					if(dir1==0)
					{
						i++;
						if(i==100)dir1=1;
					}
					else if(dir1==1)
					{
						i--;
						if(i==0)dir1=0;
					}
					PWM_SetCompare1(i);
					Delay_ms(10);

}
}
