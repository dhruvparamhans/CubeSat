#include "test_timer.h"
void initializeTIMER(){

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM12, ENABLE);

	TIM_TimeBaseInitTypeDef timerLed;

	timerLed.TIM_Prescaler = 40000;
	timerLed.TIM_CounterMode = TIM_CounterMode_Up;
	timerLed.TIM_Period = 500;
	timerLed.TIM_ClockDivision = TIM_CKD_DIV1;
	timerLed.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM12, &timerLed);
	TIM_Cmd(TIM12, ENABLE);
	TIM_ITConfig(TIM12, TIM_IT_Update, ENABLE);
}

void initializeLED(){

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

	GPIO_InitTypeDef GPIO_Led_Timer;

	//GPIO_PinAFConfig(GPIOB, GPIO_PinSource12, GPIO_AF_TIM4);
	//GPIO_PinAFConfig(GPIOB, GPIO_PinSource15, GPIO_AF_TIM4);


	GPIO_Led_Timer.GPIO_Pin = pin15|pin12|pin11;
	GPIO_Led_Timer.GPIO_OType = GPIO_OType_PP;
	GPIO_Led_Timer.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_Led_Timer.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOB, &GPIO_Led_Timer);

	GPIO_WriteBit(GPIOB, pin15, Bit_SET);
}

void EnableTimerInterrupt(){
	NVIC_InitTypeDef nvicStructure;
	nvicStructure.NVIC_IRQChannel = TIM2_IRQn;
	nvicStructure.NVIC_IRQChannelPreemptionPriority = 0;
	nvicStructure.NVIC_IRQChannelSubPriority = 1;
	nvicStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&nvicStructure);
}

void TIM2_IRQHandler(){

	if (TIM_GetITStatus(TIM12, TIM_IT_Update) != RESET){
		TIM_ClearITPendingBit(TIM12, TIM_IT_Update);
		set(GPIOB, pin12);
	}

}

void test3(){

	SystemInit();
	initializeTIMER();
	initializeLED();
	EnableTimerInterrupt();

	while (1){
		set(GPIOB, pin11);
	}

}
