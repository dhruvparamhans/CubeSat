#ifndef COMMON_H
#define COMMON_H

#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_adc.h"
#include "stm32f4xx_usart.h"
#include "stm32f4xx_tim.h"
#include "misc.h"


#define pin0	GPIO_Pin_0
#define pin1	GPIO_Pin_1
#define pin2	GPIO_Pin_2
#define pin3	GPIO_Pin_3
#define	pin4	GPIO_Pin_4
#define pin5	GPIO_Pin_5
#define pin6	GPIO_Pin_6
#define pin7	GPIO_Pin_7
#define pin8	GPIO_Pin_8
#define pin9	GPIO_Pin_9
#define pin10	GPIO_Pin_10
#define pin11	GPIO_Pin_11
#define pin12	GPIO_Pin_12
#define pin13	GPIO_Pin_13
#define pin14	GPIO_Pin_14
#define pin15	GPIO_Pin_15

#define channel10 ADC_Channel_10 //Channel corresponding to Pin PC0
#define channel11 ADC_Channel_11 //Channel corresponding to Pin PC1
#define channel15 ADC_Channel_15 //Channel corresponding to Pin PC5
#define channel8  ADC_Channel_8  //Channel corresponding to Pin PB0
#define channel9  ADC_Channel_9  //Channel corresponding to Pin PB1

//The Struct for the raw sun sensor data
struct ssraw{
	uint16_t *raw;
};

//Struct for the calculated sun vector
struct ssvect{
	uint16_t *vect;
};

//struct for the calculated mag vector
struct magvect{
	uint16_t raw_Bx;
	uint16_t raw_By;
	uint16_t raw_Bz;
};

//struct for the PWM
struct pwm_r{
	uint16_t PWM_x; //F1
	uint16_t PWM_y; //F2
	uint16_t PWM_z; //F3

	uint8_t x_dir;
	uint8_t y_dir;
	uint8_t z_dir;
};

struct state{
	struct pwm_r PWM;
	struct magvect mag_field;
	struct ssvect sun_vector;
	struct ssraw sun_raw;
};

struct state Current_state;

#endif
