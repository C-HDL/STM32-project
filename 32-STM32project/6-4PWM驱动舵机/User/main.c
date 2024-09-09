#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Delay.h"
#include "key.h"
#include "servo.h"
int main()
{		
		
		float angle=0;
		u8 key=0;
		OLED_Init();
		Servo_init();
		KEY_Init();
	OLED_ShowString(1,1,"Angle:");

			while(1){
				key=scan(0);
				if(key==keypress_1)
				{
					angle+=30;
						if(angle>180) angle=0;
					Servo_angle(angle);
					OLED_ShowNum(1,7,angle,3);
				}
					

}
}
