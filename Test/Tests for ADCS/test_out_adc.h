#ifndef TESTOUT_H
#define TESTOUT_H

#include "common.h"

void initialiserUSART(void);  // Configuring the USART structure

void envoyerDataDecimalUSART(uint8_t data); // Sending decimal data to USART

void USART_Putstr(char *str); // Sending a string of characters to USART

char *USART_InttoASC(int8_t data, char *p); //Converts an integer into a string of ASCII Characters

void config_ADC(void); // Configuring the ADC Structure

void getValue_adc(uint8_t channel_number); //Getting the value of the ADC after conversion and sending it to the USART

void test2(void); //Function for testing "Étape2"

#endif
