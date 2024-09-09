#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Delay.h"
#include "dma.h"   

u8 A[]={0x01,0x02,0x03,0x04};
u8 B[]={0,0,0,0};
int main()
{		
		OLED_Init();
		
	OLED_ShowString(1,1,"DataA");
	OLED_ShowString(3,1,"DataB");
	OLED_ShowHexNum(1,8,(u32)A,8);
	OLED_ShowHexNum(3,8,(u32)B,8);
	
	OLED_ShowHexNum(2,1,A[0],2);
	OLED_ShowHexNum(2,4,A[1],2);
	OLED_ShowHexNum(2,7,A[2],2);
	OLED_ShowHexNum(2,10,A[3],2);
	OLED_ShowHexNum(4,1,B[0],2);
	OLED_ShowHexNum(4,4,B[1],2);
	OLED_ShowHexNum(4,7,B[2],2);
	OLED_ShowHexNum(4,10,B[3],2);

		Init_DMA((u32)A,(u32)B,4);
Delay_ms(1000);
			while(1){
				A[0]++;
				A[1]++;
				A[2]++;
		    A[3]++;

	OLED_ShowHexNum(2,1,A[0],2);
	OLED_ShowHexNum(2,4,A[1],2);
	OLED_ShowHexNum(2,7,A[2],2);
	OLED_ShowHexNum(2,10,A[3],2);
	OLED_ShowHexNum(4,1,B[0],2);
	OLED_ShowHexNum(4,4,B[1],2);
	OLED_ShowHexNum(4,7,B[2],2);
	OLED_ShowHexNum(4,10,B[3],2);
				
				Delay_ms(1000);
				
				DMA_transfer();
				
					OLED_ShowHexNum(2,1,A[0],2);
	OLED_ShowHexNum(2,4,A[1],2);
	OLED_ShowHexNum(2,7,A[2],2);
	OLED_ShowHexNum(2,10,A[3],2);
	OLED_ShowHexNum(4,1,B[0],2);
	OLED_ShowHexNum(4,4,B[1],2);
	OLED_ShowHexNum(4,7,B[2],2);
	OLED_ShowHexNum(4,10,B[3],2);
	
				Delay_ms(1000);
}
}
