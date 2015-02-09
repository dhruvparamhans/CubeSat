#ifndef TESTOUT_H
#define TESTOUT_H

#include "common.h"
#include <errno.h>
#include <stdio.h>

void initialiserUSART(void);  // Configuring the USART structure

void transmit_USART(volatile char *s); //Transmits a string of characters to the USART

char *USART_InttoASC(uint8_t data, char *p); //Converts an integer into a string of ASCII Characters

void USART_IRQHandler(void); //Interrupt request handler for USART1 interrupts

void config_ADC(void); // Configuring the ADC Structure

uint16_t getValue_adc(uint8_t channel_number); //Getting the value of the ADC after conversion and sending it to the USART

void getallValues_adc(); //Get values from the 5 sun sensors and store them in an array

void test2(void); //Function for testing "Étape2"


#endif
