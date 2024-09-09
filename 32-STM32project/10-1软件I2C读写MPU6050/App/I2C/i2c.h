#ifndef _i2c_H
#define _i2c_H

#include "stm32f10x.h"            
#include "Delay.h"
void i2c_init(void);
void i2c_w_SDA(u8 bitvalue);
void i2c_w_SCL(u8 bitvalue);
u8 i2c_r_SDA(void);	
void i2c_start(void);
void i2c_stop(void);
void i2c_sendbyte(u8 byte);
u8 i2c_readbyte(void);
void send_ack(u8 ackbit);
u8 get_ack(void);
#endif
