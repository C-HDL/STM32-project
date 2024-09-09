#include "servo.h"

void Servo_init(void)
{
	PWM_Init();
}

void Servo_angle(float angle)
{
		PWM_SetCompare2(angle/180*2000+500);

}