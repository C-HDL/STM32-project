#ifndef _key_H
#define _key_H

#include "stm32f10x.h" 
#include "Delay.h" 

#define keypress_1 		1
#define keypress_11		11
#define nopress				0
void KEY_Init(void);
u8 scan(u8 i);
#endif
