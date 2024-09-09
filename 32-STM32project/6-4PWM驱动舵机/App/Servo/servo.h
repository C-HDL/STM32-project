#ifndef __servo_H
#define __servo_H

#include "stm32f10x.h"
#include "pwm.h"
void Servo_init(void);
void Servo_angle(float angle);
#endif
