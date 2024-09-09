#ifndef __ad_H
#define __ad_H

#include "stm32f10x.h"            

void AD_Init(void);
u16 AD_Get(u8 ADC_Channel);

#endif
