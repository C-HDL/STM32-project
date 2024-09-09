#ifndef __dma_H
#define __dma_H

#include "stm32f10x.h"   

void Init_DMA(u32 address1,u32 address2,u16 size);
void DMA_transfer(void);
#endif