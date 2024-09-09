#include "dma.h"   
u16 AD_Value[4];
void Init_DMA(void)
{
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1,ENABLE);
	DMA_InitTypeDef DMA_Initstructure;
	DMA_Initstructure.DMA_PeripheralBaseAddr =(u32)&ADC1->DR;
	DMA_Initstructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
	DMA_Initstructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	DMA_Initstructure.DMA_MemoryBaseAddr =(u32)AD_Value;
	DMA_Initstructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
	DMA_Initstructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
	DMA_Initstructure.DMA_DIR = 	DMA_DIR_PeripheralSRC;
	DMA_Initstructure.DMA_BufferSize = 4;
	DMA_Initstructure.DMA_Mode = DMA_Mode_Circular;
	DMA_Initstructure. DMA_M2M =DMA_M2M_Disable;
	DMA_Initstructure.DMA_Priority = DMA_Priority_Medium;

	DMA_Init (DMA1_Channel1,&DMA_Initstructure);
	
	DMA_Cmd(DMA1_Channel1,ENABLE);

}

