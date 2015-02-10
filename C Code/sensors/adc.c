/**
*   @file adc.c
*   @brief Function definitions for ADC drivers
*   @todo  Write code for multiple ADC conversion
*/

#include "adc.h"

#define MAX_STRLEN 12
volatile char received_string[MAX_STRLEN+1];
uint8_t channellist[5] = {channel10, channel11, channel15, channel8, channel9};

//ADC Pins: PC0, PC1, PC5, PB0, PB1
void ADC_Setup(void)
{
    //Initialize GPIO Structure
    GPIO_InitTypeDef GPIO_ADC;
    //Initialize ADC Structure
    ADC_InitTypeDef ADC_InitStruct;

    //Enable Peripheral Clock
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

    //Configuring GPIO Parameters
    GPIO_ADC.GPIO_Pin = pin0|pin1|pin5;
    GPIO_ADC.GPIO_Mode = GPIO_Mode_AN;
    GPIO_ADC = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOC, &GPIO_ADC);

    GPIO_ADC.GPIO_Pin = pin0|pin1;
    GPIO_ADC.GPIO_Mode = GPIO_Mode_AN;
    GPIO_ADC.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOB, &GPIO_ADC);

    //Configuring ADC Parameters
    ADC_InitStruct.ADC_Resolution = ADC_Resolution_8b;
    ADC_InitStruct.ADC_ContinuousConvMode = ENABLE;
    ADC_InitStruct.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;
    ADC_InitStruct.ADC_DataAlign = ADC_DataAlign_Right;
    ADC_InitStruct.ADC_NbrOfConversion = 5;
    ADC_Init(ADC1, &ADC_InitStruct);

    //Enable ADC1
    ADC_Cmd(ADC1,ENABLE);
}

uint16_t getValue_adc(uint8_t channel_number){
    uint16_t adc_val;
    ADC_RegularChannelConfig(ADC1, channel_number, 1, ADC_SampleTime_15Cycles);
    ADC_SoftwareStartConv(ADC1);
    while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET) {;}
    adc_val = ADC_GetConversionValue(ADC1);
    return adc_val;
}

void getallValues_ADC(){
    int i;
    for (i=0;i<5; i++){
        sun_reading_raw.sun_raw[i] = getValue_adc(channellist[i]);
    }
}


