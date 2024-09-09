#ifndef _led_H
#define _led_H

#include "stm32f10x.h" 
#include "Delay.h" 
void LED_Init(void);
void LED_1_3_5_7_ON(void);
void LED_1_3_5_7_OFF(void);
void LED_2_4_6_8_ON(void);
void LED_2_4_6_8_OFF(void);
void LED1357_TURN(void);
void LED2468_TURN(void);
void LED1_TURN(void);
void LED2_TURN(void);
#endif
