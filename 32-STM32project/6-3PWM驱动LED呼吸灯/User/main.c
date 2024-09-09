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
					if(dir2==0)
					{
						j++;
						if(j==70)dir2=1;
					}
					else if(dir2==1)
					{
						j--;
						if(j==0)dir2=0;
					}
					PWM_SetCompare2(j);
					if(dir3==0)
					{
						k++;
						if(k==50)dir3=1;
					}
					else if(dir3==1)
					{
						k--;
						if(k==0)dir3=0;
					}
					PWM_SetCompare3(k);
					Delay_ms(10);

}
}
