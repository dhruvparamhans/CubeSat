/**
*   @file pwm.h
*   @brief Functions for PWM
*/

#ifndef PWM_H
#define PWM_h

#include "common.h"

/** @brief Initialize PWM
*/

void configure_pont(void);

/** @brief Set PWM values as calculated from the control law
*/

void set_pwm(void);

/** @brief Reset PWM to zero
*/

void reset_pwm(void);

#endif // PWM_H

