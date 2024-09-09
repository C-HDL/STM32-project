#include "ad.h"            
#include "dma.h"  
void AD_Init(void)
{
	  RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
		

		RCC_ADCCLKConfig(RCC_PCLK2_Div6);
	
		GPIO_InitTypeDef GPIO_InitStructure;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 |GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3;
		GPIO_Init(GPIOA, &GPIO_InitStructure);
	
		ADC_RegularChannelConfig(ADC1,ADC_Channel_0,1,ADC_SampleTime_55Cycles5);
		ADC_RegularChannelConfig(ADC1,ADC_Channel_1,2,ADC_SampleTime_55Cycles5);
		ADC_RegularChannelConfig(ADC1,ADC_Channel_2,3,ADC_SampleTime_55Cycles5);
		ADC_RegularChannelConfig(ADC1,ADC_Channel_3,4,ADC_SampleTime_55Cycles5);
		
		ADC_InitTypeDef ADC_InitStructure;
		ADC_InitStructure.ADC_Mode=ADC_Mode_Independent;
		ADC_InitStructure.ADC_DataAlign=ADC_DataAlign_Right;
		ADC_InitStructure.ADC_ExternalTrigConv=ADC_ExternalTrigConv_None;
		ADC_InitStructure.ADC_ContinuousConvMode=ENABLE;
		ADC_InitStructure.ADC_ScanConvMode=ENABLE;
		ADC_InitStructure.ADC_NbrOfChannel=4;
		ADC_Init(ADC1,&ADC_InitStructure);
		
Init_DMA();
		ADC_DMACmd(ADC1,ENABLE);
		ADC_Cmd(ADC1,ENABLE);
		ADC_ResetCalibration(ADC1);
		while(ADC_GetResetCalibrationStatus(ADC1));
		ADC_StartCalibration(ADC1);
		while(ADC_GetCalibrationStatus(ADC1));
		ADC_SoftwareStartConvCmd(ADC1,ENABLE);
}

