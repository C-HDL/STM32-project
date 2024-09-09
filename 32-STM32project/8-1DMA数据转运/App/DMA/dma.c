#include "dma.h"   
u16 mysize;
void Init_DMA(u32 address1,u32 address2,u16 size)
{
	mysize=size;
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1,ENABLE);
	DMA_InitTypeDef DMA_Initstructure;
	DMA_Initstructure.DMA_PeripheralBaseAddr =address1;
	DMA_Initstructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
	DMA_Initstructure.DMA_PeripheralInc = DMA_PeripheralInc_Enable;
	DMA_Initstructure.DMA_MemoryBaseAddr =address2;
	DMA_Initstructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
	DMA_Initstructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
	DMA_Initstructure.DMA_DIR = 	DMA_DIR_PeripheralSRC;
	DMA_Initstructure.DMA_BufferSize = size;
	DMA_Initstructure.DMA_Mode = DMA_Mode_Normal;
	DMA_Initstructure. DMA_M2M =DMA_M2M_Enable;
	DMA_Initstructure.DMA_Priority = DMA_Priority_Medium;

	DMA_Init (DMA1_Channel1,&DMA_Initstructure);
	
	DMA_Cmd(DMA1_Channel1,DISABLE);

}

void DMA_transfer(void)
{
	DMA_Cmd(DMA1_Channel1,DISABLE);
	DMA_SetCurrDataCounter(DMA1_Channel1, mysize); 
	DMA_Cmd(DMA1_Channel1,ENABLE);

	while(!DMA_GetFlagStatus(DMA1_FLAG_TC1))
		DMA_ClearFlag(DMA1_FLAG_TC1);
		
}