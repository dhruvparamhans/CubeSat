/**
*   @file pwm.h
*   @brief Functions for PWM
*/

#ifndef PWM_H
#define PWM_h

///Structure for saving PWM Values (to be used to control the bobines)
struct PWM_data{
    int i_x;
    int i_y;
    int i_z;

    int i_dir_x;
    int i_dir_y;
    int i_dir_z;
};

/** @brief Initialize PWM
*/

void configure_pont(void);

/** @brief Set PWM values as calculated from the control law
*/

void set_pwm(void);

/** @brief Reset PWM to zero
*/

void reset_pwm(void);

extern volatile struct PWM_data pwm_val;

#endif // PWM_H

