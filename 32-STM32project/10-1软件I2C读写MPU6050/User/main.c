#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Delay.h"
#include "i2c.h"  
#include "mpu6050.h"  
u8 a[4]={0x56,0xaa,0x06,0x09};
u8 b[];

int main()
{		
		OLED_Init();
		mpu6050_init();
		mpu6050_W1_reg(0x6b,0x00);
		mpu6050_W2_reg(0x1d,a,4);
//	  u8 *id;
		u8 id[glength];
	
		for(u8 i=0;i<4;i++)
		 	{
				id[i]= *(mpu6050_R2_reg(0x1d)+i);
			}
//			id=mpu6050_R2_reg(0x1d);
			OLED_ShowHexNum(1,1,id[0],2);
			OLED_ShowHexNum(2,1,id[1],2);
			OLED_ShowHexNum(3,1,id[2],2);
			OLED_ShowNum(4,1,glength,2);
	
	
//	mpu6050_R3_reg(0x1e,b,4);
//	OLED_ShowHexNum(1,1,b[0],2);
//	OLED_ShowHexNum(2,1,b[1],2);	
//	OLED_ShowHexNum(3,1,b[2],2);	
//	OLED_ShowHexNum(4,1,b[3],2);



	while(1){

}
}
