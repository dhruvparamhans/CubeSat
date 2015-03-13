#include "test_pwm.h"

//PA5  = TIM2_CH1_ETR
//PB10 = TIM2_CH3
//PB11 = TIM2_CH4
//PB12 = TIM2_BKIN
//PB13 = TIM1_CH1N
//PB14 = TIM1_CH2N


void port_Config(){
	//F1 = PB14
	//F2 = PB11
	//F3 = PB10
	GPIO_InitTypeDef GPIO_PWM;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	//RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	GPIO_PWM.GPIO_Pin = pin10 | pin11 | pin14;
	GPIO_PWM.GPIO_OType = GPIO_OType_PP;
	GPIO_PWM.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_PWM.GPIO_Mode = GPIO_Mode_AF;
	GPIO_PWM.GPIO_Speed = GPIO_Speed_100MHz;

	GPIO_Init(GPIOB, &GPIO_PWM);

	GPIO_PinAFConfig(GPIOB, GPIO_PinSource10, GPIO_AF_TIM2);
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource11, GPIO_AF_TIM2);
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource14, GPIO_AF_TIM1);
}

void TIM1_Config(uint32_t PWM_Freq, uint32_t duty_cycle){

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

void TIM2_Config(uint32_t PWM_Freq, uint32_t duty_cycle){
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

	//TIM_OC3Init(TIM2, &TIM2_PWM_OC);
	//TIM_OC3PreloadConfig(TIM2, TIM_OCPreload_Enable);
}

void test4_tim1(uint32_t PWM_Freq, uint32_t duty_cycle){
	SystemInit();
	port_Config();
	TIM1_Config(PWM_Freq, duty_cycle);
}

void test4_tim2(uint32_t PWM_Freq, uint32_t duty_cycle){
	SystemInit();
	port_Config();
	TIM2_Config(PWM_Freq, duty_cycle);
}
