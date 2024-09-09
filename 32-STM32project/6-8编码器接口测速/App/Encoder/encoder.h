#ifndef __encoder_H
#define __encoder_H

#include "stm32f10x.h"

void Encoder_init(void);
int16_t Get_encoder(void);

#endif
