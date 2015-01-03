#include "test_out_adc.h"
#include <stdio.h>

//ADC Pins = PC0, PC1, PC5, PB0, PB1

void initialiserUSART(){

	GPIO_InitTypeDef GPIO_USART;

	GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1);

	//Configuring TX
	GPIO_USART.GPIO_Pin = pin9;
	GPIO_USART.GPIO_Mode = GPIO_Mode_AF;
	GPIO_USART.GPIO_OType = GPIO_OType_PP;
	GPIO_USART.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_USART.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOA, &GPIO_USART);

	//Configuring RX
	GPIO_USART.GPIO_Pin = pin10;
	GPIO_USART.GPIO_Mode = GPIO_Mode_AF;
	GPIO_Init(GPIOA, &GPIO_USART);

	USART_InitTypeDef USART_InitStruct;

	USART_InitStruct.USART_BaudRate = 9600;
	USART_InitStruct.USART_WordLength = USART_WordLength_8b;
	USART_InitStruct.USART_StopBits = USART_StopBits_1;
	USART_InitStruct.USART_Parity = USART_Parity_No;
	USART_InitStruct.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_Init(USART1, &USART_InitStruct);

	USART_Cmd(USART1, ENABLE);
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
}

void envoyerDataDecimalUSART(uint8_t data){
	char buf[3];
	sprintf(buf, "%u", data);
	int i;
	for (i=0; i<3; i++)
		 envoyerDataDecimalUSART(buf[i]);
}

void USART_Putstr(char *str){

	while (*str)
	{
		if (*str == '\n')
		{
			while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET){;}
			USART_SendData(USART1, '\r');
		}

		while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET){;}
		USART_SendData(USART1, *str++);
	}
}

char *USART_InttoASC(int16_t data, char *p){
	int16_t t1, t2;
	char h[10];

	t1 = t2 = 0;

	if (data < 0 ){
		p[t2] = '-';
		t2++;
		data = -data;
	}

	if (data<1000)
		p[t2++] = '0';
	if (data<100)
		p[t2++] = '0';
	if (data<10)
		p[t2++] = '0';

	do
	{
		h[t1] = data %10 +48;
		t1++;
		data = data/10;
	} while(data>0);

	while (t1>0)
		p[t2++] = h[--t1];
	p[t2] = '\0';

	return (p);
}
void config_ADC(){

	GPIO_InitTypeDef GPIO_ADC;
	ADC_InitTypeDef ADC_InitStruct;

	GPIO_ADC.GPIO_Pin = pin0|pin1|pin5;
	GPIO_ADC.GPIO_Mode = GPIO_Mode_AN;
	GPIO_ADC.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOC, &GPIO_ADC);

	GPIO_ADC.GPIO_Pin = pin0|pin1;
	GPIO_ADC.GPIO_Mode = GPIO_Mode_AN;
	GPIO_ADC.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOB, &GPIO_ADC);

	ADC_InitStruct.ADC_Resolution = ADC_Resolution_12b;
	ADC_InitStruct.ADC_ContinuousConvMode = ENABLE;
	ADC_InitStruct.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;
	ADC_InitStruct.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_InitStruct.ADC_NbrOfConversion = 5;
	ADC_Init(ADC1, &ADC_InitStruct);

	ADC_Cmd(ADC1, ENABLE);

	//while (ADC_GetFlagStatus(ADC1, ADC_FLAG_STRT) == RESET);
}

void getValue_adc(uint8_t channel_number){
	uint16_t adc_val;
	char str[10];
	ADC_RegularChannelConfig(ADC1, channel_number, 1, ADC_SampleTime_15Cycles);
	ADC_SoftwareStartConv(ADC1);
	while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET) {;}
	adc_val = ADC_GetConversionValue(ADC1);

	USART_InttoASC((int16_t)adc_val, str);
	USART_Putstr(str);
	USART_Putstr("\r");
}
void test2(){

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	SystemInit();
	initialiserUSART();
	USART_Putstr("Test for ADC Conversion \n");

	config_ADC();

	while (1){

		//GS1 Value

		USART_Putstr("GS1 VALUE: ");
		getValue_adc(channel10);

		//GS2 Value

		USART_Putstr("GS2 VALUE: ");
		getValue_adc(channel11);

		//GS3 Value
		USART_Putstr("GS3 VALUE: ");
		getValue_adc(channel15);

		//GS4 Value
		USART_Putstr("GS4 VALUE: ");
		getValue_adc(channel8);

		//GS5 Value
		USART_Putstr("GS5 VALUE: ");
		getValue_adc(channel9);
	}
}
