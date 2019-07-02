/*
 * bme280_usr.c
 *
 *  Created on: 19 июл. 2018 г.
 *      Author: snork
 */

// inspired by https://github.com/BoschSensortec/BME280_driver

#include "bme280.h"

#include <stdint.h>
#include <errno.h>



#if defined(CONFIG_SENSORS_BME280)


double bme280_compensate_pressure_flt(const struct bme280_raw_data_s *uncomp_data,
                        const struct bme280_calib_data_s *calib_data)
{
    double var1;
    double var2;
    double var3;
    double pressure;
    double pressure_min = 30000.0;
    double pressure_max = 110000.0;

    var1 = ((double)calib_data->t_fine / 2.0) - 64000.0;
    var2 = var1 * var1 * ((double)calib_data->dig_P6) / 32768.0;
    var2 = var2 + var1 * ((double)calib_data->dig_P5) * 2.0;
    var2 = (var2 / 4.0) + (((double)calib_data->dig_P4) * 65536.0);
    var3 = ((double)calib_data->dig_P3) * var1 * var1 / 524288.0;
    var1 = (var3 + ((double)calib_data->dig_P2) * var1) / 524288.0;
    var1 = (1.0 + var1 / 32768.0) * ((double)calib_data->dig_P1);
    /* avoid exception caused by division by zero */
    if (var1) {
        pressure = 1048576.0 - (double) uncomp_data->pressure;
        pressure = (pressure - (var2 / 4096.0)) * 6250.0 / var1;
        var1 = ((double)calib_data->dig_P9) * pressure * pressure / 2147483648.0;
        var2 = pressure * ((double)calib_data->dig_P8) / 32768.0;
        pressure = pressure + (var1 + var2 + ((double)calib_data->dig_P7)) / 16.0;

        if (pressure < pressure_min)
            pressure = pressure_min;
        else if (pressure > pressure_max)
            pressure = pressure_max;
    } else { /* Invalid case */
        pressure = pressure_min;
    }

    return pressure;
}


double bme280_compensate_temperature_flt(const struct bme280_raw_data_s *uncomp_data,
        struct bme280_calib_data_s *calib_data)
{
    double var1;
    double var2;
    double temperature;
    double temperature_min = -40;
    double temperature_max = 85;

    var1 = ((double)uncomp_data->temperature) / 16384.0 - ((double)calib_data->dig_T1) / 1024.0;
    var1 = var1 * ((double)calib_data->dig_T2);
    var2 = (((double)uncomp_data->temperature) / 131072.0 - ((double)calib_data->dig_T1) / 8192.0);
    var2 = (var2 * var2) * ((double)calib_data->dig_T3);
    calib_data->t_fine = (int32_t)(var1 + var2);
    temperature = (var1 + var2) / 5120.0;

    if (temperature < temperature_min)
        temperature = temperature_min;
    else if (temperature > temperature_max)
        temperature = temperature_max;

    return temperature;
}


double bme280_compensate_humidity_flt(const struct bme280_raw_data_s *uncomp_data,
        const struct bme280_calib_data_s *calib_data)
{
    double humidity;
    double humidity_min = 0.0;
    double humidity_max = 100.0;
    double var1;
    double var2;
    double var3;
    double var4;
    double var5;
    double var6;

    var1 = ((double)calib_data->t_fine) - 76800.0;
    var2 = (((double)calib_data->dig_H4) * 64.0 + (((double)calib_data->dig_H5) / 16384.0) * var1);
    var3 = uncomp_data->humidity - var2;
    var4 = ((double)calib_data->dig_H2) / 65536.0;
    var5 = (1.0 + (((double)calib_data->dig_H3) / 67108864.0) * var1);
    var6 = 1.0 + (((double)calib_data->dig_H6) / 67108864.0) * var1 * var5;
    var6 = var3 * var4 * (var5 * var6);
    humidity = var6 * (1.0 - ((double)calib_data->dig_H1) * var6 / 524288.0);

    if (humidity > humidity_max)
        humidity = humidity_max;
    else if (humidity < humidity_min)
        humidity = humidity_min;

    return humidity;
}


#ifdef CONFIG_BME280_HIGH_PREC_COMP
/*!
 * @brief This internal API is used to compensate the raw pressure data and
 * return the compensated pressure data in integer data type with higher
 * accuracy.
 */
static uint32_t bme280_compensate_pressure_int(const struct bme280_raw_data_s *uncomp_data,
        const struct bme280_calib_data_s *calib_data)
{
    int64_t var1;
    int64_t var2;
    int64_t var3;
    int64_t var4;
    uint32_t pressure;
    uint32_t pressure_min = 3000000;
    uint32_t pressure_max = 11000000;

    var1 = ((int64_t)calib_data->t_fine) - 128000;
    var2 = var1 * var1 * (int64_t)calib_data->dig_P6;
    var2 = var2 + ((var1 * (int64_t)calib_data->dig_P5) * 131072);
    var2 = var2 + (((int64_t)calib_data->dig_P4) * 34359738368);
    var1 = ((var1 * var1 * (int64_t)calib_data->dig_P3) / 256) + ((var1 * ((int64_t)calib_data->dig_P2) * 4096));
    var3 = ((int64_t)1) * 140737488355328;
    var1 = (var3 + var1) * ((int64_t)calib_data->dig_P1) / 8589934592;

    /* To avoid divide by zero exception */
    if (var1 != 0) {
        var4 = 1048576 - uncomp_data->pressure;
        var4 = (((var4 * 2147483648) - var2) * 3125) / var1;
        var1 = (((int64_t)calib_data->dig_P9) * (var4 / 8192) * (var4 / 8192)) / 33554432;
        var2 = (((int64_t)calib_data->dig_P8) * var4) / 524288;
        var4 = ((var4 + var1 + var2) / 256) + (((int64_t)calib_data->dig_P7) * 16);
        pressure = (uint32_t)(((var4 / 2) * 100) / 128);

        if (pressure < pressure_min)
            pressure = pressure_min;
        else if (pressure > pressure_max)
            pressure = pressure_max;
    } else {
        pressure = pressure_min;
    }

    return pressure;
}
#else

/*!
 * @brief This internal API is used to compensate the raw pressure data and
 * return the compensated pressure data in integer data type.
 */
uint32_t bme280_compensate_pressure_int(const struct bme280_raw_data_s *uncomp_data,
        const struct bme280_calib_data_s *calib_data)
{
    int32_t var1;
    int32_t var2;
    int32_t var3;
    int32_t var4;
    uint32_t var5;
    uint32_t pressure;
    uint32_t pressure_min = 30000;
    uint32_t pressure_max = 110000;

    var1 = (((int32_t)calib_data->t_fine) / 2) - (int32_t)64000;
    var2 = (((var1 / 4) * (var1 / 4)) / 2048) * ((int32_t)calib_data->dig_P6);
    var2 = var2 + ((var1 * ((int32_t)calib_data->dig_P5)) * 2);
    var2 = (var2 / 4) + (((int32_t)calib_data->dig_P4) * 65536);
    var3 = (calib_data->dig_P3 * (((var1 / 4) * (var1 / 4)) / 8192)) / 8;
    var4 = (((int32_t)calib_data->dig_P2) * var1) / 2;
    var1 = (var3 + var4) / 262144;
    var1 = (((32768 + var1)) * ((int32_t)calib_data->dig_P1)) / 32768;
     /* avoid exception caused by division by zero */
    if (var1) {
        var5 = (uint32_t)((uint32_t)1048576) - uncomp_data->pressure;
        pressure = ((uint32_t)(var5 - (uint32_t)(var2 / 4096))) * 3125;
        if (pressure < 0x80000000)
            pressure = (pressure << 1) / ((uint32_t)var1);
        else
            pressure = (pressure / (uint32_t)var1) * 2;

        var1 = (((int32_t)calib_data->dig_P9) * ((int32_t)(((pressure / 8) * (pressure / 8)) / 8192))) / 4096;
        var2 = (((int32_t)(pressure / 4)) * ((int32_t)calib_data->dig_P8)) / 8192;
        pressure = (uint32_t)((int32_t)pressure + ((var1 + var2 + calib_data->dig_P7) / 16));

        if (pressure < pressure_min)
            pressure = pressure_min;
        else if (pressure > pressure_max)
            pressure = pressure_max;
    } else {
        pressure = pressure_min;
    }

    return pressure;
}
#endif


int32_t bme280_compensate_temperature_int(const struct bme280_raw_data_s *uncomp_data,
        struct bme280_calib_data_s *calib_data)
{
    int32_t var1;
    int32_t var2;
    int32_t temperature;
    int32_t temperature_min = -4000;
    int32_t temperature_max = 8500;

    var1 = (int32_t)((uncomp_data->temperature / 8) - ((int32_t)calib_data->dig_T1 * 2));
    var1 = (var1 * ((int32_t)calib_data->dig_T2)) / 2048;
    var2 = (int32_t)((uncomp_data->temperature / 16) - ((int32_t)calib_data->dig_T1));
    var2 = (((var2 * var2) / 4096) * ((int32_t)calib_data->dig_T3)) / 16384;
    calib_data->t_fine = var1 + var2;
    temperature = (calib_data->t_fine * 5 + 128) / 256;

    if (temperature < temperature_min)
        temperature = temperature_min;
    else if (temperature > temperature_max)
        temperature = temperature_max;

    return temperature;
}


uint32_t bme280_compensate_humidity_int(const struct bme280_raw_data_s *uncomp_data,
        const struct bme280_calib_data_s *calib_data)
{
    int32_t var1;
    int32_t var2;
    int32_t var3;
    int32_t var4;
    int32_t var5;
    uint32_t humidity;
    uint32_t humidity_max = 102400;

    var1 = calib_data->t_fine - ((int32_t)76800);
    var2 = (int32_t)(uncomp_data->humidity * 16384);
    var3 = (int32_t)(((int32_t)calib_data->dig_H4) * 1048576);
    var4 = ((int32_t)calib_data->dig_H5) * var1;
    var5 = (((var2 - var3) - var4) + (int32_t)16384) / 32768;
    var2 = (var1 * ((int32_t)calib_data->dig_H6)) / 1024;
    var3 = (var1 * ((int32_t)calib_data->dig_H3)) / 2048;
    var4 = ((var2 * (var3 + (int32_t)32768)) / 1024) + (int32_t)2097152;
    var2 = ((var4 * ((int32_t)calib_data->dig_H2)) + 8192) / 16384;
    var3 = var5 * var2;
    var4 = ((var3 / 32768) * (var3 / 32768)) / 128;
    var5 = var3 - ((var4 * ((int32_t)calib_data->dig_H1)) / 16);
    var5 = (var5 < 0 ? 0 : var5);
    var5 = (var5 > 419430400 ? 419430400 : var5);
    humidity = (uint32_t)(var5 / 4096);

    if (humidity > humidity_max)
        humidity = humidity_max;

    return humidity;
}


int bme280_load_preset_conf(struct bme280_conf_s * conf, bme280_conf_preset_t conf_preset)
{
    int rc = 0;
    switch (conf_preset)
    {
    case BME280_CONF_PRESET_WEATHER_MONITORING:
        conf->osr_p = BME280_OVERSAMPLING_1X;
        conf->osr_t = BME280_OVERSAMPLING_1X;
        conf->osr_h = BME280_OVERSAMPLING_1X;
        conf->filter = BME280_FILTER_COEFF_OFF;
        break;

    case BME280_CONF_PRESET_HUM_MONITORING:
        conf->osr_p = BME280_NO_OVERSAMPLING;
        conf->osr_t = BME280_OVERSAMPLING_1X;
        conf->osr_h = BME280_OVERSAMPLING_1X;
        conf->filter = BME280_FILTER_COEFF_OFF;
        break;

    case BME280_CONF_PRESET_INDOOR_NAV:
        conf->osr_p = BME280_OVERSAMPLING_16X;
        conf->osr_t = BME280_OVERSAMPLING_2X;
        conf->osr_h = BME280_OVERSAMPLING_1X;
        conf->filter = BME280_FILTER_COEFF_16;
        conf->standby_time = BME280_STANDBY_TIME_0_5_MS;
        break;

    case BME280_CONF_PRESET_GAMING:
        conf->osr_p = BME280_OVERSAMPLING_4X;
        conf->osr_t = BME280_OVERSAMPLING_1X;
        conf->osr_h = BME280_NO_OVERSAMPLING;
        conf->filter = BME280_FILTER_COEFF_16;
        conf->standby_time = BME280_STANDBY_TIME_0_5_MS;
        break;
    default:
        rc = -EINVAL;
    }

    return rc;

}

#endif

