/**
*   @file adc.c
*   @brief Function definitions for ADC drivers
*   @todo  Write code for multiple ADC conversion
*/

#include "stm32f4xx_adc.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"

void ADC_Setup(void)
{
    //Initialize GPIO Structure
    GPIO_InitTypeDef GPIO_InitStructure;
    //Initialize ADC Structure
    ADC_InitTypeDef ADC_InitStructure;

    //Enable Peripheral Clock
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

    //Configuring GPIO Parameters
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOC, &GPIO_InitStructure);

    //Configuring ADC Parameters
    ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b; //12bit Resolution
    ADC_InitStructure.ADC_ContinuousConvMode = ENABLE; //Continuous Conversion
    ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
    ADC_Init(ADC1, &ADC_InitStructure);

    //Enable ADC1
    ADC_Cmd(ADC1,ENABLE);
}

uint16_t ADC_GetValue()
{
    uint16_t adc = 0;
    ADC_Setup();
    ADC_RegularChannelConfig(ADC1, ADC_Channel_11,1, ADC_SampleTime_15Cycles);

    while(1)
    {
        ADC_SoftwareStartConv(ADC1);
        while (ADC_GetFlagStatus(ADC1,ADC_FLAG_EOC)== RESET);
        adc = ADC_GetConversionValue(ADC1);
    }

    return adc;
}
