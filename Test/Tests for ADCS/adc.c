#include "stm32f4xx_adc.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"

void ADC_Setup(void){

	GPIO_InitTypeDef GPIO_InitStructure1;
	GPIO_InitTypeDef GPIO_InitStructure2;
	ADC_InitTypeDef ADC_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

	GPIO_StructInit(&GPIO_InitStructure1);
	GPIO_InitStructure1.GPIO_Pin = GPIO_Pin_0| GPIO_Pin_1| GPIO_Pin_5;
	GPIO_InitStructure1.GPIO_Mode = GPIO_Mode_AN;
	GPIO_InitStructure1.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOC, &GPIO_InitStructure1);

	GPIO_StructInit(&GPIO_InitStructure2);
	GPIO_InitStructure2.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1;
	GPIO_InitStructure2.GPIO_Mode = GPIO_Mode_AN;
	GPIO_InitStructure2.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOB, &GPIO_InitStructure2);

	ADC_InitStructure.ADC_ScanConvMode = ENABLE;
	ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;
	ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
	ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_InitStructure.ADC_NbrOfConversion = 5;
	ADC_Init(ADC1, &ADC_InitStructure);

	//PIN PC0 corresponds to ADC123_IN10
	ADC_RegularChannelConfig(ADC1, ADC_Channel_10, 1, ADC_SampleTime_15Cycles);
	//PIN PC1 corresponds to ADC123_IN11
	ADC_RegularChannelConfig(ADC1, ADC_Channel_11, 2, ADC_SampleTime_15Cycles);
	//PIN PC5 corresponds to ADC123_IN15
	ADC_RegularChannelConfig(ADC1, ADC_Channel_15, 3, ADC_SampleTime_15Cycles);
	//PIN PB0 corresponds to ADC12_IN8
	ADC_RegularChannelConfig(ADC1, ADC_Channel_8, 4, ADC_SampleTime_15Cycles);
	//PIN PB1 corresponds to ADC12_IN9
	ADC_RegularChannelConfig(ADC1, ADC_Channel_9, 5, ADC_SampleTime_15Cycles);
	ADC_Cmd(ADC1, ENABLE);
}

/*int main(void){
	while(1)
	{
		ADC_Setup();
		ADC_SoftwareStartConv(ADC1);
		while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET){;}
	}
}*/
