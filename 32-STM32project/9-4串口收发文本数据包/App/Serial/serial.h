#ifndef __serial_H
#define __serial_H

#include "stm32f10x.h"
extern u8 txpacket[];
extern char rxpacket[];
void serial_init(void);
void sendbyte(u8 byte);
void sendarray(u8 *array,u16 length);
void sendstring(char* string);
void sendnumber(u16 number,u16 length);


u8 getflag(void);
#endif