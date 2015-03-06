#ifndef TESTPWM_H
#define TESTPWM_H
#include "common.h"

void TIM_Config(uint32_t PWM_Freq, uint32_t duty_cycle);

void TIM_Config_Aux(void);

void PWM_Config_Aux(void);

void LED_Config(void);

void test4_Aux(void);

void test4(uint32_t PWM_Freq, uint32_t duty_cycle);

#endif
