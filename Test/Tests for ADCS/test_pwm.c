#include "test_pwm.h"

//PA5  = TIM2_CH1_ETR
//PB10 = TIM2_CH3
//PB11 = TIM2_CH4
//PB12 = TIM2_BKIN
//PB13 = TIM1_CH1N
//PB14 = TIM1_CH2N

void TIM_Config_Aux(){
	TIM_TimeBaseInitTypeDef TIM2_PWM;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);

	TIM2_PWM.TIM_Prescaler = 0; //Reduce Tim2 Frequency to 84KHz
	TIM2_PWM.TIM_CounterMode = TIM_CounterMode_Up;

	TIM2_PWM.TIM_Period = 84000000/10000 - 1; //time period
	TIM2_PWM.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM2_PWM.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2, &TIM2_PWM);
	TIM_Cmd(TIM2, ENABLE);
}

void TIM_Config(uint32_t PWM_Freq, uint32_t duty_cycle){
	//Input PWM_Freq in KHz
	//TIM_2 connected to the APB1 Bus which works at frequency of 84MHz
	TIM_TimeBaseInitTypeDef TIM2_PWM;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);

	//To reduce TIM2 Frequency, we use the prescaler.
	//New TIM2 Frequency = 84MhZ/(TIM_Prescaler Value+1)
	TIM2_PWM.TIM_Prescaler = 0; //Reduce Tim2 Frequency to 84KHz
	TIM2_PWM.TIM_CounterMode = TIM_CounterMode_Up;

	TIM2_PWM.TIM_Period = 84000000/(PWM_Freq*1000) - 1; //time period
	uint32_t period = TIM2_PWM.TIM_Period;
	TIM2_PWM.TIM_ClockDivision = TIM_CKD_DIV1;

	TIM2_PWM.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2, &TIM2_PWM);
	TIM_Cmd(TIM2, ENABLE);

	//PWM Settings

	TIM_OCInitTypeDef TIM2_PWM_OC;

	TIM2_PWM_OC.TIM_OCMode = TIM_OCMode_PWM2;
	TIM2_PWM_OC.TIM_OutputState = TIM_OutputState_Enable;
	TIM2_PWM_OC.TIM_OCPolarity = TIM_OCPolarity_Low;
	TIM2_PWM_OC.TIM_Pulse = ((period+1)*duty_cycle)/100 -1;
	TIM_OC4Init(TIM2, &TIM2_PWM_OC);
	TIM_OC4PreloadConfig(TIM2, TIM_OCPreload_Enable);

	TIM_OC3Init(TIM2, &TIM2_PWM_OC);
	TIM_OC3PreloadConfig(TIM2, TIM_OCPreload_Enable);
}

void PWM_Config_Aux(){
	TIM_OCInitTypeDef TIM2_PWM_OC;

	TIM2_PWM_OC.TIM_OCMode = TIM_OCMode_PWM2;
	TIM2_PWM_OC.TIM_OutputState = TIM_OutputState_Enable;
	TIM2_PWM_OC.TIM_OCPolarity = TIM_OCPolarity_Low;
	TIM2_PWM_OC.TIM_Pulse = 83; //50% Duty Cycle

	TIM_OC3Init(TIM2, &TIM2_PWM_OC);
	//TIM_OCStructInit(TIM2_PWM_OC);
	TIM_OC3PreloadConfig(TIM2, TIM_OCPreload_Enable);
}

void LED_Config(){
	GPIO_InitTypeDef GPIO_PWM;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

	GPIO_PinAFConfig(GPIOB, GPIO_PinSource11, GPIO_AF_TIM2);
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource10, GPIO_AF_TIM2);
	GPIO_PWM.GPIO_Pin = GPIO_Pin_11 | GPIO_Pin_10;
	GPIO_PWM.GPIO_OType = GPIO_OType_PP;
	GPIO_PWM.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_PWM.GPIO_Mode = GPIO_Mode_AF;
	GPIO_PWM.GPIO_Speed = GPIO_Speed_100MHz;

	GPIO_Init(GPIOB, &GPIO_PWM);
}

void test4_Aux(){
	SystemInit();
	LED_Config();
	TIM_Config_Aux();
	PWM_Config_Aux();
}

void test4(uint32_t PWM_Freq, uint32_t duty_cycle){
	SystemInit();
	LED_Config();
	TIM_Config(PWM_Freq, duty_cycle);
}

void TIM1_Config(uint32_t PWM_Freq, uint32_t duty_cycle){

	GPIO_InitTypeDef GPIO_PWM;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

	GPIO_PWM.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_14;
	GPIO_PWM.GPIO_OType = GPIO_OType_PP;
	GPIO_PWM.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_PWM.GPIO_Mode = GPIO_Mode_AF;
	GPIO_PWM.GPIO_Speed = GPIO_Speed_100MHz;

	GPIO_Init(GPIOB, &GPIO_PWM);

	GPIO_PinAFConfig(GPIOB, GPIO_PinSource13, GPIO_AF_TIM1);
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource14, GPIO_AF_TIM1);


	TIM_TimeBaseInitTypeDef TIM1_PWM;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1,ENABLE);


	TIM1_PWM.TIM_Prescaler = 1; //Reduce TIM1 Frequency to 84MHz
	TIM1_PWM.TIM_CounterMode = TIM_CounterMode_Up;
	TIM1_PWM.TIM_Period = 84000000/(PWM_Freq*1000) - 1; //time period
	uint32_t period = TIM1_PWM.TIM_Period;
	TIM1_PWM.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM1_PWM.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM1, &TIM1_PWM);
	//PWM Settings

	TIM_OCInitTypeDef TIM1_PWM_OC;
	TIM1_PWM_OC.TIM_OCMode = TIM_OCMode_PWM2;
	TIM1_PWM_OC.TIM_OutputNState = TIM_OutputNState_Enable;
	TIM1_PWM_OC.TIM_OCPolarity = TIM_OCPolarity_Low;
	TIM1_PWM_OC.TIM_OCNPolarity = TIM_OCNPolarity_Low;
	TIM1_PWM_OC.TIM_OCIdleState = TIM_OCIdleState_Set;
	TIM1_PWM_OC.TIM_OCNIdleState = TIM_OCIdleState_Reset;
	TIM1_PWM_OC.TIM_Pulse = ((period+1)*duty_cycle)/100 -1;
	TIM_OC1Init(TIM1, &TIM1_PWM_OC);
	TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);

	TIM_OC2Init(TIM1, &TIM1_PWM_OC);
	TIM_OC2PreloadConfig(TIM1,TIM_OCPreload_Enable);

	TIM_BDTRInitTypeDef TIM_BDTRInitStructure;

	TIM_BDTRInitStructure.TIM_OSSRState = TIM_OSSRState_Enable;
	TIM_BDTRInitStructure.TIM_OSSIState = TIM_OSSIState_Enable;
	TIM_BDTRInitStructure.TIM_LOCKLevel = TIM_LOCKLevel_1;
	TIM_BDTRInitStructure.TIM_DeadTime = 11;
	TIM_BDTRInitStructure.TIM_Break = TIM_Break_Enable;
	TIM_BDTRInitStructure.TIM_BreakPolarity = TIM_BreakPolarity_High;
	TIM_BDTRInitStructure.TIM_AutomaticOutput = TIM_AutomaticOutput_Enable;

	TIM_BDTRConfig(TIM1, &TIM_BDTRInitStructure);

	TIM_Cmd(TIM1, ENABLE);

	TIM_CtrlPWMOutputs(TIM1, ENABLE);
}

void test4_tim1(uint32_t PWM_Freq, uint32_t duty_cycle){
	SystemInit();
	TIM1_Config(PWM_Freq, duty_cycle);
}
