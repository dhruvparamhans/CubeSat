/**
*   @file sensors.h
*   @brief Function definitions for Magnetometer
*   @todo   ADD Functions for calibrations.
*/

#ifndef SENS_H
#define SENS_H

/** @brief Getting data from GPS
*/
void get_GPS_reading(struct GPS_reading *gps);

/** @brief Start Getting data from magnetometer
*/
void get_mag_data(struct mag_sensor *mag);

/** @brief Magnetometer data after calibration
*/
void get_mag_vector(struct mag_vector *mag);

/** @brief Getting data from Sun sensors
*/
void get_sun_reading(struct sun_sensor *sun);

/** @brief Calculating sun vector from sun sensor data
    after correcting for albedo
*/
void get_sun_vector(struct sun_vector *sun_vec);

#endif // SENS_H
