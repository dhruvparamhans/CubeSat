#ifndef COMM_H
#define COMM_H

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


///Structure for storing GPS data
struct gps_reading{
    ///Position data
    float x, y, z;
    ///Velocity data
    float v_x, v_y, v_z;
    ///Latitude Longitude Altitude
    float lat, lon, alt;
};

///Structure for storing raw magnetometer data
struct mag_sensor{
    float mag_raw_x, mag_raw_y, mag_raw_z;
    float temp;
};

///Structure for storing magnetometer data after calibration
struct mag_vector{
    float mag_vec_x;
    float mag_vec_y;
    float mag_vec_z;
};

///Structure for storing sun sensor data
struct sun_sensor{
    ///Raw data from the sun sensors
    uint16_t *sun_raw;
};

///Sun-vector after correcting for albedo
struct sun_vector{
    float sun_vector_x;
    float sun_vector_y;
    float sun_vector_z;
};

struct State{
    struct gps_reading gps;
    struct mag_vector mag;
    struct sun_vector sun;
};

struct sun_sensor sun_reading_raw; 
#endif 
