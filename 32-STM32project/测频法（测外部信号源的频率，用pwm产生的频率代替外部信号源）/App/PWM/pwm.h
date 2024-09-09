#ifndef __pwm_H
#define __pwm_H

#include "stm32f10x.h"

void PWM_Init(void);
void PWM_SetCompare1(uint16_t compare);
#endif
