#include "mpu6050.h"  
#include "stdlib.h"  
#define MPU6050_ADDR 0xd0

u8 glength;
void mpu6050_init(void)
{
		i2c_init();
	mpu6050_W1_reg(MPU6050_PWR_MGMT_1,0x01);
	mpu6050_W1_reg(MPU6050_PWR_MGMT_2,0x00);
	mpu6050_W1_reg(MPU6050_SMPLRT_DIV,0x09);
	mpu6050_W1_reg(MPU6050_CONFIG,0x06);
	mpu6050_W1_reg(MPU605O_GYRO_CONFIG,0x18);
	mpu6050_W1_reg(MPU6050_ACCEL_CONFIG,0x18);
}
void mpu6050_W1_reg(u8 RegADDR,u8 data) //写一个数据
{
		i2c_start();
		i2c_sendbyte(MPU6050_ADDR);
		get_ack();
		i2c_sendbyte(RegADDR);
		get_ack();
	
			i2c_sendbyte(data);
			get_ack();
		
		i2c_stop();
}
void mpu6050_W2_reg(u8 RegADDR,u8 *Array,u8 length) //写多个数据
{		glength=length;
		i2c_start();
		i2c_sendbyte(MPU6050_ADDR);
		get_ack();
		i2c_sendbyte(RegADDR);
		get_ack();
		for(u8 i=0;i<length;i++)
		{
			i2c_sendbyte(Array[i]);
			get_ack();
		}
		i2c_stop();
}
u8 mpu6050_R1_reg(u8 RegADDR) //读一个数据
{	
		u8 data;
		i2c_start();
		i2c_sendbyte(MPU6050_ADDR);
		get_ack();
		i2c_sendbyte(RegADDR);
		get_ack();
	
		i2c_start();
		i2c_sendbyte(MPU6050_ADDR | 0x01);
		get_ack();
	
			data=i2c_readbyte();
			send_ack(1);

		i2c_stop();
		return data;
}

u8* mpu6050_R2_reg(u8 RegADDR) //读多个数据
{	
		u8* array=(u8*)malloc(10);
		i2c_start();
		i2c_sendbyte(MPU6050_ADDR);
		get_ack();
		i2c_sendbyte(RegADDR);
		get_ack();
	
		i2c_start();
		i2c_sendbyte(MPU6050_ADDR | 0x01);
		get_ack();
		for(u8 i=0;i<glength;i++)
		{
			array[i]=i2c_readbyte();
			if(i!=2)
			send_ack(0);
			else
			send_ack(1);
		}
		i2c_stop();
		return array;
}
void mpu6050_R3_reg(u8 RegADDR,u8 *array,u8 length) //读多个数据
{	
		
		i2c_start();
		i2c_sendbyte(MPU6050_ADDR);
		get_ack();
		i2c_sendbyte(RegADDR);
		get_ack();
	
		i2c_start();
		i2c_sendbyte(MPU6050_ADDR | 0x01);
		get_ack();
		for(u8 i=0;i<length;i++)
		{
			array[i]=i2c_readbyte();
			if(i!=2)
			send_ack(0);
			else
			send_ack(1);
		}
		i2c_stop();
}

//void mpu_getdata()
