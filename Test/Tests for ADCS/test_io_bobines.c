#include "test_io_bobines.h"

GPIO_InitTypeDef GPIO_Led;

void Delay(uint32_t nCount)
{
	for (; nCount !=0; nCount--);
}

void set(GPIO_TypeDef* GPIO_x, uint16_t pin_number){
	GPIO_SetBits(GPIO_x, pin_number);
}

void reset(GPIO_TypeDef* GPIO_x, uint16_t pin_number){
	GPIO_ResetBits(GPIO_x, pin_number);
}

void configLEDS(void){

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

	//Configuring the Pins PB10, PB11, PB12, PB13, PB14
	GPIO_Led.GPIO_Pin = pin10|pin11|pin12|pin13|pin14|pin15;
	GPIO_Led.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Led.GPIO_OType = GPIO_OType_PP;
	GPIO_Led.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_Led.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOB, &GPIO_Led);

	//Configuring the pin PA5
	GPIO_Led.GPIO_Pin = pin5;
	GPIO_Led.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Led.GPIO_OType = GPIO_OType_PP;
	GPIO_Led.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_Led.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOA, &GPIO_Led);
}

void blink(void){

	while (1)
	{
		//Activer commande des bobines
		set(GPIOB, pin15);

		//Faire R1 = 0; F1 = 1
		set(GPIOB, pin13);
		//Attendre
		Delay(1194303);
		//Faire R1 = 1; F1 = 1
		reset(GPIOB, pin13);
		set(GPIOB, pin14);
		//Attendre
		Delay(1194303);
		//Faire R1 = 0; F1 = 0
		reset(GPIOB, pin14);



		//Faire R2 = 0; F2 = 1
		set(GPIOB, pin12);
		//Attendre
		Delay(1194303);
		//Faire R2 = 1; F2 = 1
		reset(GPIOB, pin12);
		set(GPIOB, pin11);
		//Attendre
		Delay(1194303);
		//Faire R2 = 0; F2 = 0
		reset(GPIOB, pin11);

		//Faire R3 = 0; F3 = 1
		set(GPIOB, pin10);
		//Attendre
		Delay(1194303);
		//Faire R3 = 1; F3 = 1
		reset(GPIOB, pin10);
		set(GPIOA, pin5);
		//Attendre
		Delay(1194303);
		//Faire R3 = 0; F3 = 0
		reset(GPIOA, pin5);

		reset(GPIOB, pin15);
	}
}

void test1(void){
	SystemInit();
	configLEDS();
	blink();
}
