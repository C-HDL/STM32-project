#ifndef _mpu6050_H
#define _mpu6050_H

#include "i2c.h"  
#include "mpu6050_reg.h" 

extern u8 glength;
void mpu6050_init(void);
void mpu6050_W1_reg(u8 RegADDR,u8 data); //дһ������
void mpu6050_W2_reg(u8 RegADDR,u8 *Array,u8 length); //д�������
u8 mpu6050_R1_reg(u8 RegADDR); //��һ������
u8* mpu6050_R2_reg(u8 RegADDR); //���������
void mpu6050_R3_reg(u8 RegADDR,u8 *array,u8 length); //���������
#endif
