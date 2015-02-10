/**
*   @file pwm.c
*   @brief Configure the PWM values and calculate
*   current for the bobines
*/

#include "pwm.h"
void configure_pont()
{
}

void set_pwm()
{
}

void reset_pwm()
{
    pwm_val.i_x = 0;
    pwm_val.i_y = 0;
    pwm_val.i_z = 0;
    pwm_val.i_dir_x = 0;
    pwm_val.i_dir_y = 0;
    pwm_val.i_dir_z = 0;
}

