#include "test_square_wave_bobines.h"

uint32_t multiplier;

void Delay_Init(void){
	RCC_ClocksTypeDef RCC_Clocks;

	RCC_GetClocksFreq(&RCC_Clocks);

	multiplier = RCC_Clocks.HCLK_Frequency/120;
}

void Delay_Millis(uint32_t millis){
	millis = 1000*millis*multiplier;
	while(millis--);
}

void test4(){
	configLEDS();
	Delay_Init();

	while (1){
		set(GPIOB, pin15);
		//Faire R2 = 0; F2 = 1
		set(GPIOB, pin12);
		//Attendre
		Delay(1710000/1000);
		//Faire R2 = 1; F2 = 1
		reset(GPIOB, pin12);
		set(GPIOB, pin11);
		//Attendre
		Delay(1710000/1000);
		//Faire R2 = 0; F2 = 0
		reset(GPIOB, pin11);
	}
}
