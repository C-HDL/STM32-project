#ifndef __moter_H
#define __moter_H

#include "stm32f10x.h"
#include "pwm.h"
void Moter_init(void);
void Moter_speed(int16_t speed);


#endif
