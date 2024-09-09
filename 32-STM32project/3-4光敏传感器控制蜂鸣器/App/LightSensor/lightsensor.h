#ifndef __lightsensor_H
#define __lightsensor_H

#include "stm32f10x.h"   
void lightsensor_init(void);
u8 lightsensor_read(void);

#endif
