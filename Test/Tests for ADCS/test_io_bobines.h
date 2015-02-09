#ifndef TEST_H
#define TEST_H

#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx.h"
#include "common.h"

void Delay(uint32_t nCount); //Function for delay

void set(GPIO_TypeDef* GPIO_x, uint16_t pin_number); //Setting up a given port  PORT = 1

void reset(GPIO_TypeDef* GPIO_x, uint16_t pin_number); //Resetting a port	PORT = 0

void configLEDS(void); //Configuring pins

void blink(void); //Blinking the leds for the test

void test1(void); //Function for testing the blinking

#endif
