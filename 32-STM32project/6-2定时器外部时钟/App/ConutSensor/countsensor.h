#ifndef __countsensor_H
#define __countsensor_H

#include "Delay.h"
#include "stm32f10x.h" 

void CountSensor_init(void);
u16 Get_count(void);

#endif
