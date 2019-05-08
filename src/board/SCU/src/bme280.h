/*
 * bme280.h
 *
 *  Created on: 16 июл. 2018 г.
 *      Author: snork
 */

#ifndef __INCLUDE_SENSORS_BME280_H_
#define __INCLUDE_SENSORS_BME280_H_

//#include <stm32f4xx_hal_i2c.h>
#include <stdlib.h>
#include <stdint.h>

#include <stm32f4xx_hal.h>

#define CONFIG_SENSORS_BME280

#if defined(CONFIG_SENSORS_BME280)


/********************************************************************************************
 * Public Function Prototypes
 ********************************************************************************************/

#ifdef __cplusplus
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

 typedef  int ssize_t;

#define SNIOC_BME280_READCONF 3

#define SNIOC_BME280_WRITECONF 1

#define SNIOC_BME280_READCALIB 2

#define SNIOC_PRESSURE 4

#define SNIOC_TEMPERATURE 5

#define SNIOC_START 6

#define SNIOC_STOP 7

#define SNIOC_MEASURE 8

#define SNIOC_RESET 9





// oversampling values for any of measable parameters
typedef enum
{
    BME280_NO_OVERSAMPLING  = 0x00,
    BME280_OVERSAMPLING_1X  = 0x01,
    BME280_OVERSAMPLING_2X  = 0x02,
    BME280_OVERSAMPLING_4X  = 0x03,
    BME280_OVERSAMPLING_8X  = 0x04,
    BME280_OVERSAMPLING_16X = 0x05,
} bme280_oversampling_t;


// standby time or measurement rate
typedef enum
{
    BME280_STANDBY_TIME_0_5_MS  = 0x00,
    BME280_STANDBY_TIME_62_5_MS = 0x01,
    BME280_STANDBY_TIME_125_MS  = 0x02,
    BME280_STANDBY_TIME_250_MS  = 0x03,
    BME280_STANDBY_TIME_500_MS  = 0x04,
    BME280_STANDBY_TIME_1000_MS = 0x05,
    BME280_STANDBY_TIME_10_MS   = 0x06,
    BME280_STANDBY_TIME_20_MS   = 0x07,
} bme280_standbytime_t;


// embedded filter coefficient
typedef enum
{
    BME280_FILTER_COEFF_OFF = 0x00,
    BME280_FILTER_COEFF_2   = 0x01,
    BME280_FILTER_COEFF_4   = 0x02,
    BME280_FILTER_COEFF_8   = 0x03,
    BME280_FILTER_COEFF_16  = 0x04,
} bme280_filtercoeff_t;


// manufacturer recommended config presets for varius device applications
/* they can be loaded with bme280_load_preset_conf function */
typedef enum
{
    // weather monitoring config preset
    /* Sensor mode: forced mode, 1 sample / minute
       Oversampling settings: pressure x1, temperature x1, humidity x1
       IIR filter settings: filter off

       Current consumption: 0.16 μA
       RMS Noise: 3.3 Pa / 30 cm, 0.07 %RH
       Data output rate:1/60 Hz */
    BME280_CONF_PRESET_WEATHER_MONITORING,


    // humidity monitoring config preset
    /* Sensor mode: forced mode, 1 sample / second
       Oversampling settings: pressure ×0, temperature ×1, humidity ×1
       IIR filter settings: filter off
       Current consumption: 2.9 μA
       RMS Noise: 0.07 %RH
       Data output rate: 1 Hz */
    BME280_CONF_PRESET_HUM_MONITORING,


    // indoor navigation config preset
    /* Sensor mode: normal mode, t standby = 0.5 ms
        Oversampling settings: pressure ×16, temperature ×2, humidity ×1
        IIR filter settings: filter coefficient 16
        Current consumption: 633 μA
        RMS Noise: 0.2 Pa / 1.7 cm
        Data output rate: 25Hz
        Filter bandwidth: 0.53 Hz
        Response time (75%): 0.9 s */
    BME280_CONF_PRESET_INDOOR_NAV,


    // gaming input device config preset
    /* Sensor mode: normal mode, t standby = 0.5 ms
       Oversampling settings: pressure ×4, temperature ×1, humidity ×0
       IIR filter settings: filter coefficient 16
       Current consumption: 581 μA
       RMS Noise: 0.3 Pa / 2.5 cm
       Data output rate: 83 Hz
       Filter bandwidth: 1.75 Hz
       Response time (75%): 0.3 s */
    BME280_CONF_PRESET_GAMING,

} bme280_conf_preset_t;

// device measure mode
typedef enum
{
    BME280_MODE_SLEEP   = 0x00,     // don` measure at all
    BME280_MODE_FORCED  = 0x01,     // measure by command
    BME280_MODE_NORMAL  = 0x03,     // measure automatically
} bme280_mode_t;


// allows to apply only a subset of device conf
typedef enum
{
    // apply oversampling conf (for all measurable parameters)
    BME280_APPLY_SET_OSR          = (1 << 0),
    // apply filter conf
    BME280_APPLY_SET_FILTER       = (1 << 1),
    // apply measurement rate conf
    BME280_APPLY_SET_STANDBY      = (1 << 2),

    // apply all conf
    BME280_APPLY_SEL_ALL = BME280_APPLY_SET_OSR | BME280_APPLY_SET_FILTER | BME280_APPLY_SET_STANDBY,
} bme280_apply_set_t;

// device configuration
struct bme280_conf_s {
    /* pressure oversampling */
    uint8_t osr_p;
    /* temperature oversampling */
    uint8_t osr_t;
    /* humidity oversampling */
    uint8_t osr_h;
    /* filter coefficient */
    uint8_t filter;
    /* standby time */
    uint8_t standby_time;
};

// bme280 calibration data struct
struct bme280_calib_data_s {
    uint16_t dig_T1;
    int16_t dig_T2;
    int16_t dig_T3;
    uint16_t dig_P1;
    int16_t dig_P2;
    int16_t dig_P3;
    int16_t dig_P4;
    int16_t dig_P5;
    int16_t dig_P6;
    int16_t dig_P7;
    int16_t dig_P8;
    int16_t dig_P9;
    uint8_t  dig_H1;
    int16_t dig_H2;
    uint8_t  dig_H3;
    int16_t dig_H4;
    int16_t dig_H5;
    int8_t  dig_H6;
    int32_t t_fine;
};


// raw device data
struct bme280_raw_data_s {
    /* un-compensated pressure */
    uint32_t pressure;
    /* un-compensated temperature */
    uint32_t temperature;
    /* un-compensated humidity */
    uint32_t humidity;
};


// compensated device data in integer values
struct bme280_int_data_s {
    /* Compensated pressure */
    uint32_t pressure;
    /* Compensated temperature */
    int32_t temperature;
    /* Compensated humidity */
    uint32_t humidity;
};


// compensated device data in double
struct bme280_float_data_s {
    /* Compensated pressure */
    double pressure;
    /* Compensated temperature */
    double temperature;
    /* Compensated humidity */
    double humidity;
};



double bme280_compensate_pressure_flt(const struct bme280_raw_data_s *uncomp_data,
        const struct bme280_calib_data_s *calib_data);

double bme280_compensate_temperature_flt(const struct bme280_raw_data_s *uncomp_data,
        struct bme280_calib_data_s *calib_data);

double bme280_compensate_humidity_flt(const struct bme280_raw_data_s *uncomp_data,
        const struct bme280_calib_data_s *calib_data);


uint32_t bme280_compensate_pressure_int(const struct bme280_raw_data_s *uncomp_data,
        const struct bme280_calib_data_s *calib_data);

int32_t bme280_compensate_temperature_int(const struct bme280_raw_data_s *uncomp_data,
        struct bme280_calib_data_s *calib_data);

uint32_t bme280_compensate_humidity_int(const struct bme280_raw_data_s *uncomp_data,
        const struct bme280_calib_data_s *calib_data);


int bme280_load_preset_conf(struct bme280_conf_s * conf, bme280_conf_preset_t conf_preset);



// bme280 i2c addresses
typedef enum
{
    // this adress is chosen when SDO pin is high
    BME280_I2C_ADDR_SDO_HIGH = 0x77 << 1,
    // this adress is chosen when SDO pin is low
    BME280_I2C_ADDR_SDO_LOW  = 0x76 << 1,
} bme280_i2c_addr_t;


struct i2c_master_s;

// startup initialization parameters for device on i2c buss
struct bme280_setup_conf_s {
    union
    {
        struct
        {
            // TODO
        } spi;

        struct
        {
        	I2C_HandleTypeDef * bus;  // i2c bus
            bme280_i2c_addr_t devaddr;      // device i2c address
        } i2c;
    } iface;
};



// device descriptor
typedef struct bme280_dev_s {
    /* setup config */
    struct bme280_setup_conf_s setup_conf;
    /* Chip Id */
    uint8_t chip_id;
    /* Device Id */
    uint8_t dev_id;
    /* SPI/I2C interface */
    /* Read function pointer */
    int (*_do_read)(const struct bme280_dev_s */*priv*/, uint8_t /*regaddr*/, uint8_t */*data*/, size_t /*datasize*/);
    /* Write function pointer */
    int (*_do_write)(const struct bme280_dev_s */*priv*/, uint8_t */*ctrl_pairs*/, size_t /*ctrl_pairs_count*/);
    /* Trim data */
    struct bme280_calib_data_s calib_data;
    /* Sensor settings */
    struct bme280_conf_s settings;
} bme280_dev_s;

int bme280_config_default(bme280_dev_s * bme280);

int bme280_register_i2c(struct bme280_dev_s *bme280, I2C_HandleTypeDef *i2c_handler, uint16_t devaddr);

int bme280_init(struct bme280_dev_s *bme280);

int bme280_deinit(struct bme280_dev_s *bme280);

int bme280_ioctl(struct bme280_dev_s *bme280, int cmd, unsigned long arg);

ssize_t bme280_read(struct bme280_dev_s *bme280,  char *buffer, size_t buflen);

ssize_t bme280_write(struct bme280_dev_s *bme280,  const char *buffer, size_t buflen);

int bme280_pull_calvals( struct bme280_dev_s *priv);

int bme280_pull_sensor_conf( struct bme280_dev_s * priv);

int bme280_push_sensor_conf( const struct bme280_dev_s * priv, int settings_set_composition);

int bme280_push_sensor_mode(const  struct bme280_dev_s * priv, bme280_mode_t mode);

int bme280_soft_reset( const struct bme280_dev_s * priv);

int bme280_pull_raw_data( const struct bme280_dev_s * priv, struct bme280_raw_data_s * data);


#undef EXTERN
#ifdef __cplusplus
}
#endif

#endif // #if defined(CONFIG_SENSORS_BME280)

#endif /*__INCLUDE_SENSORS_BME280_H_ */
