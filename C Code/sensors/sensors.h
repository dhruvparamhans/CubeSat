/**
*   @file sensors.h
*   @brief Function definitions for Magnetometer
*   @todo   ADD Functions for calibrations.
*/

#ifndef SENS_H
#define SENS_H

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
    float sun_raw[5];
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
