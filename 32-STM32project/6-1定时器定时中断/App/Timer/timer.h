#ifndef __timer_H
#define __timer_H

#include "stm32f10x.h"   
#include "Delay.h"

void timer_init(void);
u16 Get_count(void);

#endif