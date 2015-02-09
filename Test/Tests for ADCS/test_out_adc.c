#include "test_out_adc.h"
#include "test_io_bobines.h"
#include "common.h"

#define MAX_STRLEN 12 
volatile char received_string[MAX_STRLEN+1];
uint8_t channellist[5] = {channel10, channel11, channel15, channel8, channel9};

//ADC Pins = PC0, PC1, PC5, PB0, PB1


void initialiserUSART(){

	/* Steps to take for using USART
	 * 1. Enable the USART peripheral clock
	 * 2. Enable the corresponding GPIO clock
	 * 3. Enable the Alternate function for the GPIO
	 * 4. Configure the GPIO for USART use
	 * 5. Initialize the GPIO structure using GPIO_Init()
	 * 6. Configure Baud rate etc for USART.
	 * 7. Configure the interrupt controller for USART
	 * Output est vers port TX Debug
	 */
	GPIO_InitTypeDef GPIO_USART;  //For the GPIO Pins
	USART_InitTypeDef USART_InitStruct; //For the USART 
	NVIC_InitTypeDef NVIC_InitStruct; // For Interrupt handling 

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	
	//GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1);

	//Configuring TX
	GPIO_USART.GPIO_Pin = GPIO_Pin_6;
	GPIO_USART.GPIO_Mode = GPIO_Mode_AF;
	GPIO_USART.GPIO_OType = GPIO_OType_PP;
	GPIO_USART.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_USART.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOB, &GPIO_USART);
	
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_USART1);

	//Configuring RX
	//GPIO_USART.GPIO_Pin = pin10;
	//GPIO_USART.GPIO_Mode = GPIO_Mode_AF;
	//GPIO_Init(GPIOA, &GPIO_USART);

	USART_InitStruct.USART_BaudRate = 9600;
	USART_InitStruct.USART_WordLength = USART_WordLength_8b;
	USART_InitStruct.USART_StopBits = USART_StopBits_1;
	USART_InitStruct.USART_Parity = USART_Parity_No;
	USART_InitStruct.USART_Mode = USART_Mode_Tx;
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_Init(USART1, &USART_InitStruct);

	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE); //enable the USART1 Receive Interrupt 
	
	//Here the interrupt controller for the USART is configured 
	
	NVIC_InitStruct.NVIC_IRQChannel = USART1_IRQn; //configures USART1 Interrupts
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE; 
	
	USART_Cmd(USART1, ENABLE);
	
}

void transmit_USART(volatile char *s){
	while (*s){
		//Wait until the data register is empty
		while (!(USART1->SR & 0x00000040));
		USART_SendData(USART1, *s);
		*s++;
	}
}

//Converts a given integer into a character array 
char *USART_InttoASC(uint8_t data, char *p){
	uint8_t t1, t2;
	char h[10];

	t1 = t2 = 0;

	if (data < 0 ){
		p[t2] = '-';
		t2++;
		data = -data;
	}

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


//Interrupt request handler (IRQ) for USART1 Interrupts

void USART_IRQHandler(void){


	if ( USART_GetITStatus(USART1, USART_IT_RXNE)){
		static uint8_t cnt = 0;
		char t = USART1->DR; // Character from the USART1 Data register is stored here

		if ((t != '\n') && (cnt < MAX_STRLEN)){
			received_string[cnt] = t;
			cnt++;
		}
		else {
			cnt = 0;
			transmit_USART(received_string);
		}
	}
}

//For configuring the ADC 
void config_ADC(){

	/* Steps to take for using ADC
	 * 1. Enable RCC_APB2 Clock
	 * 2. Enable the clock for ADC GPIOs. For our case, we will enable the GPIOB and GPIOC Clocks
	 * 3. Configure the pins to be used in Analog mode
	 * 4. Initialize the GPIO structure using GPIO_Init()
	 */

	GPIO_InitTypeDef GPIO_ADC;
	ADC_InitTypeDef ADC_InitStruct;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

	GPIO_ADC.GPIO_Pin = pin0|pin1|pin5;
	GPIO_ADC.GPIO_Mode = GPIO_Mode_AN;
	GPIO_ADC.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOC, &GPIO_ADC);

	GPIO_ADC.GPIO_Pin = pin0|pin1;
	GPIO_ADC.GPIO_Mode = GPIO_Mode_AN;
	GPIO_ADC.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOB, &GPIO_ADC);

	ADC_InitStruct.ADC_Resolution = ADC_Resolution_8b;
	ADC_InitStruct.ADC_ContinuousConvMode = ENABLE;
	ADC_InitStruct.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;
	ADC_InitStruct.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_InitStruct.ADC_NbrOfConversion = 5;
	ADC_Init(ADC1, &ADC_InitStruct);

	ADC_Cmd(ADC1, ENABLE);

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
		SS_test.raw[i] = getValue_adc(channellist[i]);
	}
}

void test2(){

	initialiserUSART();
	config_ADC();

	while(1){
		//uint16_t *data;
		char p[10];
		getallValues_ADC();
		transmit_USART("ADC Values: \r");
		int i;
		for (i=0; i<5; i++){
			uint16_t temp = 0;
			temp = SS_test.raw[i];
			USART_InttoASC(temp, p);
			transmit_USART(p);
			Delay(1194303);
			transmit_USART("\r");
		}
	}
}
