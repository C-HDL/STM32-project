#include "i2c.h"  
void i2c_init(void)
{
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
		GPIO_InitTypeDef GPIO_InitStructure;
		GPIO_InitStructure.GPIO_Mode  =	GPIO_Mode_Out_OD;
		GPIO_InitStructure.GPIO_Pin   =	GPIO_Pin_10 | GPIO_Pin_11;
		GPIO_InitStructure.GPIO_Speed =	GPIO_Speed_50MHz;
		GPIO_Init(GPIOB,&GPIO_InitStructure);
		GPIO_SetBits(GPIOB,GPIO_Pin_10 | GPIO_Pin_11);
}
void i2c_w_SDA(u8 bitvalue)
{
	GPIO_WriteBit(GPIOB,GPIO_Pin_11,(BitAction)bitvalue);
	Delay_us(10);
}
void i2c_w_SCL(u8 bitvalue)
{
	GPIO_WriteBit(GPIOB,GPIO_Pin_10,(BitAction)bitvalue);
	Delay_us(10);
}
u8 i2c_r_SDA(void)
{	
	u8 bitvalue;
	bitvalue=GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11);
	Delay_us(10);
	return bitvalue;
}
void i2c_start(void)
{
	i2c_w_SDA(1);
	i2c_w_SCL(1);	
	i2c_w_SDA(0);
	i2c_w_SCL(0);
}
void i2c_stop(void)
{
	i2c_w_SDA(0);
	i2c_w_SCL(1);
	i2c_w_SDA(1);
}
void i2c_sendbyte(u8 byte)
{
	for(u8 i=0;i<8;i++)
	{
	i2c_w_SDA(byte & (0x80>>i));
	i2c_w_SCL(1);
	i2c_w_SCL(0);
	}
}
u8 i2c_readbyte(void)
{	
	u8 byte=0x00;
	i2c_w_SDA(1);
	for(u8 i=0;i<8;i++)
	{
	i2c_w_SCL(1);
	if(i2c_r_SDA()==1) byte |= (0x80>>i);
	i2c_w_SCL(0);	
	}
	return byte;
}

void send_ack(u8 ackbit)
{
	for(u8 i=0;i<8;i++)
	{
	i2c_w_SDA(ackbit);
	i2c_w_SCL(1);
	i2c_w_SCL(0);
	}
}
u8 get_ack(void)
{	
	u8 ackbit;
	i2c_w_SDA(1);
	i2c_w_SCL(1);
	ackbit=i2c_r_SDA();
	i2c_w_SCL(0);	
	return ackbit;
}
