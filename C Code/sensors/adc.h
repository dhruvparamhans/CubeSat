/**
*   @file adc.h
*   @brief Function definitions for ADC drivers
*   @todo  Write code for multiple ADC conversion
*/

#ifndef ADC_H
#define ADC_H

#include "common.h"

void config_ADC(void);
uint16_t getValue_adc(uint8_t channel_number);
void getallValues_adc();


#endif //ADC_H
