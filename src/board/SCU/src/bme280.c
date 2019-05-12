/*
 * bme280.c
 *
 *  Created on: 16 июл. 2018 г.
 *      Author: snork
 */

// inspired by https://github.com/BoschSensortec/BME280_driver


#ifndef __BME280_C__
#define __BME280_C__


#include "bme280.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <errno.h>
#include <assert.h>
#include <stm32f4xx_hal.h>
#include <diag/Trace.h>
#if defined(CONFIG_SENSORS_BME280)


/**\name Macro to combine two 8 bit data's to form a 16 bit data */
#define BME280_CONCAT_BYTES(msb, lsb)     (((uint16_t)msb << 8) | (uint16_t)lsb)

#define BME280_SET_BITS(reg_data, bitname, data) \
                ((reg_data & ~(bitname##_MSK)) | \
                ((data << bitname##_POS) & bitname##_MSK))
#define BME280_SET_BITS_POS_0(reg_data, bitname, data) \
                ((reg_data & ~(bitname##_MSK)) | \
                (data & bitname##_MSK))

#define BME280_GET_BITS(reg_data, bitname)  ((reg_data & (bitname##_MSK)) >> \
                            (bitname##_POS))
#define BME280_GET_BITS_POS_0(reg_data, bitname)  (reg_data & (bitname##_MSK))

/**\name BME280 chip identifier */
#define BME280_CHIP_ID  (0x58)

/**\name Register Address */
#define BME280_CHIP_ID_ADDR                 (0xD0)
#define BME280_RESET_ADDR                   (0xE0)
#define BME280_TEMP_PRESS_CALIB_DATA_ADDR   (0x88)
#define BME280_HUMIDITY_CALIB_DATA_ADDR     (0xE1)
#define BME280_PWR_CTRL_ADDR                (0xF4)
#define BME280_CTRL_HUM_ADDR                (0xF2)
#define BME280_CTRL_MEAS_ADDR               (0xF4)
#define BME280_CONFIG_ADDR                  (0xF5)
#define BME280_DATA_ADDR                    (0xF7)


/**\name Macros related to size */
#define BME280_TEMP_PRESS_CALIB_DATA_LEN    (26)
#define BME280_HUMIDITY_CALIB_DATA_LEN      (7)
#define BME280_P_T_H_DATA_LEN               (8)

/**\name Sensor power modes */
#define BME280_SLEEP_MODE       (0x00)
#define BME280_FORCED_MODE      (0x01)
#define BME280_NORMAL_MODE      (0x03)

/**\name Macros for bit masking */
#define BME280_SENSOR_MODE_MSK  (0x03)
#define BME280_SENSOR_MODE_POS  (0x00)

#define BME280_CTRL_HUM_MSK     (0x07)
#define BME280_CTRL_HUM_POS     (0x00)

#define BME280_CTRL_PRESS_MSK   (0x1C)
#define BME280_CTRL_PRESS_POS   (0x02)

#define BME280_CTRL_TEMP_MSK    (0xE0)
#define BME280_CTRL_TEMP_POS    (0x05)

#define BME280_FILTER_MSK       (0x1C)
#define BME280_FILTER_POS       (0x02)

#define BME280_STANDBY_MSK      (0xE0)
#define BME280_STANDBY_POS      (0x05)


#define TIMEOUT 5000

#define OK 1
#define true 1
#define false 0





#define printf trace_printf

/****************************************************************************
 * private declarations
 ****************************************************************************/
// character device interface



// private functions

// prepare i2c bus to transfer data
//inline static void _bme280_prepare_i2c_config( const struct bme280_dev_s * priv, struct i2c_config_s * config);

// read register values through i2c bus
static int _bme280_do_read_i2c( const struct bme280_dev_s * priv, uint8_t regaddr, uint8_t * data, size_t datasize);

// write register values through i2c bus
// device accepts data in control pairs of bytes.
// First byte of pair contains register address and second byte contains register data to be written
// Its possible to write any amount of registers through single transaction
static int _bme280_do_write_i2c( const struct bme280_dev_s * priv, uint8_t * ctrl_pairs, size_t ctrl_pairs_count);

// reading multiple registers through abstract bus
inline static int bme280_read_regn( const struct bme280_dev_s * priv, uint8_t regaddr, uint8_t * data, size_t size);
// reading single 8 bit register
inline static int bme280_read_reg8( const struct bme280_dev_s * priv, uint8_t regaddr, uint8_t * regvalue);
// write single 8 bit register
inline static int bme280_write_reg8( const struct bme280_dev_s * priv, uint8_t regaddr, uint8_t regvalue);


// check device id
static int bme280_checkid( const struct bme280_dev_s *priv);
// load calibration values from device
int bme280_pull_calvals( struct bme280_dev_s *priv);

// load configuration from device
int bme280_pull_sensor_conf( struct bme280_dev_s * priv);
// write configuration to device
int bme280_push_sensor_conf( const struct bme280_dev_s * priv, int settings_set_composition);

// write measurement mode to device
int bme280_push_sensor_mode( const struct bme280_dev_s * priv, bme280_mode_t mode);

// software reset
int bme280_soft_reset( const struct bme280_dev_s * priv);

// reading raw measurement data from device
int bme280_pull_raw_data( const struct bme280_dev_s * priv, struct bme280_raw_data_s * data);


 int bme280_init(struct bme280_dev_s *bme280)
{
    int rc = OK;
     struct bme280_dev_s * priv  = bme280;


    // lets load device settings? just in case
    // also to check if its alive
    rc = bme280_pull_sensor_conf(priv);
    if (rc < 0)
    {
        /*error*/printf("ERROR: can`t properly open device: %d\n", rc);
        goto end;
    }
    bme280_config_default(bme280);

end:
    return rc;

	return 0;
}


 int bme280_deinit(struct bme280_dev_s *bme280)
{
    int rc = OK;
     struct bme280_dev_s * priv  = bme280;


    if (1)
    {
        /*info*/printf("putting device to sleep, because no one is using it\n");
        // put device to sleep if no one in using it
        rc = bme280_push_sensor_mode(priv, BME280_MODE_SLEEP);
        if (rc < 0)
            /*error*/printf("ERROR: can`t properly close device: %d\n", rc);
    }

    // in any case close is successful
    return OK;
	return 0;
}


 int bme280_ioctl(struct bme280_dev_s *bme280, int cmd, unsigned long arg)
{
    int rc = OK;
     struct bme280_dev_s * priv  = bme280;

    switch (cmd)
    {
    case SNIOC_BME280_READCONF:
        {
            rc = bme280_pull_sensor_conf(priv);
            if (rc < 0)
                break;

            struct bme280_conf_s * user_settings_ptr = (struct bme280_conf_s *)arg;
            if (user_settings_ptr)
                *user_settings_ptr = priv->settings;
        }
        break;

    case SNIOC_BME280_WRITECONF:
        {
            assert(arg != NULL);
            const struct bme280_conf_s * user_settings_ptr = (struct bme280_conf_s *)arg;
            priv->settings = *user_settings_ptr;

            rc = bme280_push_sensor_conf(priv, BME280_APPLY_SEL_ALL);
        }
        break;

    case SNIOC_BME280_READCALIB:
        {
        	assert(arg != NULL);
            struct bme280_calib_data_s * user_calvals_ptr = (struct bme280_calib_data_s *)arg;
            memcpy(user_calvals_ptr, &priv->calib_data, sizeof(priv->calib_data));
        }
        break;

    case SNIOC_PRESSURE:
        {
            uint32_t * const thearg = (uint32_t*)arg;
            assert(thearg != NULL);
            struct bme280_raw_data_s raw_data;
            rc = bme280_pull_raw_data(priv, &raw_data);
            if (rc < 0)
                break;

            bme280_compensate_temperature_int(&raw_data, &priv->calib_data);
            *thearg = bme280_compensate_pressure_int(&raw_data, &priv->calib_data);
        }
        break;

    case SNIOC_TEMPERATURE:
        {
            uint32_t * const thearg = (uint32_t*)arg;
            assert(thearg != NULL);
            struct bme280_raw_data_s raw_data;
            rc = bme280_pull_raw_data(priv, &raw_data);
            if (rc < 0)
                break;

            bme280_compensate_temperature_int(&raw_data, &priv->calib_data);
            *thearg = bme280_compensate_temperature_int(&raw_data, &priv->calib_data);
        }
        break;

    case SNIOC_START:
        rc = bme280_push_sensor_mode(priv, BME280_MODE_NORMAL);
        break;

    case SNIOC_STOP:
        rc = bme280_push_sensor_mode(priv, BME280_MODE_SLEEP);
        break;

    case SNIOC_MEASURE:
        rc = bme280_push_sensor_mode(priv, BME280_MODE_FORCED);
        break;

    case SNIOC_RESET:
        rc = bme280_soft_reset(priv);
        break;

    default:
        /*error*/printf("ERROR: invalid ioctl cmd: %d\n", cmd);
        rc = -ENOSYS;
        break;
    }


    return rc;

	return 0;
}

 ssize_t bme280_read(struct bme280_dev_s *bme280,  char *buffer, size_t buflen)
{
    int rc = OK;
     struct bme280_dev_s * priv  = bme280;


    switch (buflen)
    {
    case sizeof(struct bme280_int_data_s):
    case sizeof(struct bme280_float_data_s):
    break;
    default:
        rc = -EINVAL;
        goto end;
    }

    struct bme280_raw_data_s raw_data;
    rc = bme280_pull_raw_data(priv, &raw_data);
    if (rc < 0)
        goto end;


    if (buflen == sizeof(struct bme280_int_data_s))
    {
        struct bme280_int_data_s * data = (struct bme280_int_data_s *)buffer;

        data->pressure = bme280_compensate_pressure_int(&raw_data, &priv->calib_data);
        data->temperature = bme280_compensate_temperature_int(&raw_data, &priv->calib_data);
        data->humidity = bme280_compensate_humidity_int(&raw_data, &priv->calib_data);
    }
    else if (buflen == sizeof(struct bme280_float_data_s))
    {
        struct bme280_float_data_s * data = (struct bme280_float_data_s *)buffer;

        data->pressure = bme280_compensate_pressure_flt(&raw_data, &priv->calib_data);
        data->temperature = bme280_compensate_temperature_flt(&raw_data, &priv->calib_data);
        data->humidity = bme280_compensate_humidity_flt(&raw_data, &priv->calib_data);
    }
    else
    {
        rc = -EINVAL;
        goto end;
    }

    rc = buflen;

end:

    return rc;
}


 ssize_t bme280_write(struct bme280_dev_s *bme280,  const char *buffer, size_t buflen)
{
    int rc = OK;

    struct bme280_dev_s * priv  = bme280;

    if (buflen != sizeof(struct bme280_conf_s))
    {
        rc = -EINVAL;
        goto end;
    }

    const struct bme280_conf_s * settings = (const struct bme280_conf_s *)buffer;
    priv->settings = *settings;
    rc = bme280_push_sensor_conf(priv, BME280_APPLY_SEL_ALL);
    if (rc < 0)
        goto end;


    rc = buflen;

end:

    return rc;

}

 /****************************************************************************
  * private definitions
  *****************************************************************************/




static int _bme280_do_read_i2c( const struct bme280_dev_s * priv, uint8_t regaddr, uint8_t * data, size_t datasize)
{

    int ret = 0;
    ret = HAL_I2C_Mem_Read(priv->setup_conf.iface.i2c.bus, priv->setup_conf.iface.i2c.devaddr,
    		regaddr, 1, data, datasize, TIMEOUT);
    if (ret)
        /*error*/printf("ERROR: read_regs_i2c: i2c_writeread failed: %d\n", ret);

    return ret;

}

static int _bme280_do_write_i2c( const struct bme280_dev_s * priv, uint8_t * ctrl_pairs, size_t ctrl_pairs_count)
{

    int ret;

    ret = HAL_I2C_Master_Transmit(priv->setup_conf.iface.i2c.bus,priv->setup_conf.iface.i2c.devaddr,
    		ctrl_pairs, ctrl_pairs_count*2,TIMEOUT);
    if(ret)
        /*error*/printf("ERROR: write_regs_i2c: i2c_write failed: %d\n", ret);

    return ret;


	return 0;
}


inline static int bme280_read_regn( const struct bme280_dev_s * priv, uint8_t regaddr, uint8_t * data, size_t size)
{
    return priv->_do_read(priv, regaddr, data, size);
}


inline static int bme280_read_reg8( const struct bme280_dev_s * priv, uint8_t regaddr, uint8_t * regvalue)
{
    return priv->_do_read(priv, regaddr, regvalue, 1);
}


inline static int bme280_write_reg8( const struct bme280_dev_s * priv, uint8_t regaddr, uint8_t regvalue)
{
    uint8_t ctrl_pair[2] = {regaddr, regvalue};
    return priv->_do_write(priv, ctrl_pair, 1);
}




static int bme280_checkid( const struct bme280_dev_s *priv)
{
  uint8_t devid = 0;

  int rc = bme280_read_reg8(priv, BME280_CHIP_ID_ADDR, &devid);
  if (rc < 0)
      return rc;

  /*info*/printf("INFO: bme280 device id: 0x%02x\n", devid);
  if (devid != (uint8_t)BME280_CHIP_ID)
    {
      /* ID is not Correct */
      /*error*/printf("ERROR: Wrong Device ID: 0x%02X!\n", devid);
      return -ENODEV;
    }

  return OK;
}


int bme280_pull_calvals( struct bme280_dev_s *priv)
{
    int rc = 0;

    uint8_t reg_data[BME280_TEMP_PRESS_CALIB_DATA_LEN] = {0};
    rc = bme280_read_regn(priv, BME280_TEMP_PRESS_CALIB_DATA_ADDR, reg_data, BME280_TEMP_PRESS_CALIB_DATA_LEN);
    if (rc < 0)
    {
        /*error*/printf("ERROR: Can`t load temperature and pressure calibration data: %d", rc);
        return rc;
    }

    struct bme280_calib_data_s *calib_data = &priv->calib_data;
    calib_data->dig_T1 = BME280_CONCAT_BYTES(reg_data[1], reg_data[0]);
    calib_data->dig_T2 = (int16_t)BME280_CONCAT_BYTES(reg_data[3], reg_data[2]);
    calib_data->dig_T3 = (int16_t)BME280_CONCAT_BYTES(reg_data[5], reg_data[4]);
    calib_data->dig_P1 = BME280_CONCAT_BYTES(reg_data[7], reg_data[6]);
    calib_data->dig_P2 = (int16_t)BME280_CONCAT_BYTES(reg_data[9], reg_data[8]);
    calib_data->dig_P3 = (int16_t)BME280_CONCAT_BYTES(reg_data[11], reg_data[10]);
    calib_data->dig_P4 = (int16_t)BME280_CONCAT_BYTES(reg_data[13], reg_data[12]);
    calib_data->dig_P5 = (int16_t)BME280_CONCAT_BYTES(reg_data[15], reg_data[14]);
    calib_data->dig_P6 = (int16_t)BME280_CONCAT_BYTES(reg_data[17], reg_data[16]);
    calib_data->dig_P7 = (int16_t)BME280_CONCAT_BYTES(reg_data[19], reg_data[18]);
    calib_data->dig_P8 = (int16_t)BME280_CONCAT_BYTES(reg_data[21], reg_data[20]);
    calib_data->dig_P9 = (int16_t)BME280_CONCAT_BYTES(reg_data[23], reg_data[22]);
    calib_data->dig_H1 = reg_data[25];

    rc = bme280_read_regn(priv, BME280_HUMIDITY_CALIB_DATA_ADDR, reg_data, BME280_HUMIDITY_CALIB_DATA_LEN);
    if (rc < 0)
    {
        /*error*/printf("ERROR: Can`t load humidity calibration data: %d", rc);
        return rc;
    }

    int16_t dig_H4_lsb;
    int16_t dig_H4_msb;
    int16_t dig_H5_lsb;
    int16_t dig_H5_msb;

    calib_data->dig_H2 = (int16_t)BME280_CONCAT_BYTES(reg_data[1], reg_data[0]);
    calib_data->dig_H3 = reg_data[2];

    dig_H4_msb = (int16_t)(int8_t)reg_data[3] * 16;
    dig_H4_lsb = (int16_t)(reg_data[4] & 0x0F);
    calib_data->dig_H4 = dig_H4_msb | dig_H4_lsb;

    dig_H5_msb = (int16_t)(int8_t)reg_data[5] * 16;
    dig_H5_lsb = (int16_t)(reg_data[4] >> 4);
    calib_data->dig_H5 = dig_H5_msb | dig_H5_lsb;
    calib_data->dig_H6 = (int8_t)reg_data[6];

    return rc;
}


int bme280_pull_sensor_conf( struct bme280_dev_s * priv)
{
    int rc = 0;
    uint8_t reg_data[4];
    rc = bme280_read_regn(priv, BME280_CTRL_HUM_ADDR, reg_data, 4);
    if (rc < 0)
    {
        /*error*/printf("ERROR: can`t get device settings: %d\n", rc);
        return rc;
    }

    priv->settings.osr_h = BME280_GET_BITS_POS_0(reg_data[0], BME280_CTRL_HUM);
    priv->settings.osr_p = BME280_GET_BITS(reg_data[2], BME280_CTRL_PRESS);
    priv->settings.osr_t = BME280_GET_BITS(reg_data[2], BME280_CTRL_TEMP);
    priv->settings.filter = BME280_GET_BITS(reg_data[3], BME280_FILTER);
    priv->settings.standby_time = BME280_GET_BITS(reg_data[3], BME280_STANDBY);

    return rc;
}


int bme280_push_sensor_conf( const struct bme280_dev_s * priv, int settings_set_composition)
{
    int rc = OK;

    // putting device to sleep just in case
    if (settings_set_composition & BME280_APPLY_SET_OSR)
    {
        uint8_t ctrl_hum;
        uint8_t ctrl_meas;

        // setup humidity
        ctrl_hum = priv->settings.osr_h & BME280_CTRL_HUM_MSK;
        rc = bme280_write_reg8(priv, BME280_CTRL_HUM_ADDR, ctrl_hum);
        if (rc < 0)
        {
            /*error*/printf("ERROR: can`t set hum osr value: %d\n", rc);
            return rc;

        }

        /* Humidity related changes will be only effective after a
           write operation to ctrl_meas register */

        ctrl_meas = BME280_SET_BITS(0, BME280_CTRL_PRESS, priv->settings.osr_p);
        ctrl_meas = BME280_SET_BITS(ctrl_meas, BME280_CTRL_TEMP, priv->settings.osr_t);
        rc = bme280_write_reg8(priv, BME280_CTRL_MEAS_ADDR, ctrl_meas);
        if (rc < 0)
        {
            /*error*/printf("ERROR: can`t write ctrl_meas reg: %d\n", rc);
            return rc;
        }
    }


    // if its all that is needs to be done, thesn wrap up
    if (!(settings_set_composition & (BME280_APPLY_SET_FILTER | BME280_APPLY_SET_STANDBY)))
        return rc;


    uint8_t cfg_reg;
    rc = bme280_read_reg8(priv, BME280_CONFIG_ADDR, &cfg_reg);
    if (rc < 0)
    {
        /*error*/printf("ERROR: can`t read cfg reg: %d\n", rc);
        return rc;
    }

    if (settings_set_composition & BME280_APPLY_SET_FILTER)
        cfg_reg = BME280_SET_BITS(cfg_reg, BME280_FILTER, priv->settings.filter);

    if (settings_set_composition & BME280_APPLY_SET_STANDBY)
        cfg_reg = BME280_SET_BITS(cfg_reg, BME280_STANDBY, priv->settings.standby_time);


    rc = bme280_write_reg8(priv, BME280_CONFIG_ADDR, cfg_reg);
    if (rc < 0)
    {
        /*error*/printf("ERROR: can`t read cfg reg: %d\n", rc);
        return rc;
    }

    return rc;
}


int bme280_push_sensor_mode(const  struct bme280_dev_s * priv, bme280_mode_t mode)
{
    int rc;
    uint8_t ctrl_meas;
    rc = bme280_read_reg8(priv, BME280_CTRL_MEAS_ADDR, &ctrl_meas);
    if (rc < 0)
    {
        /*error*/printf("ERROR: can`t read ctrl_meas reg :%d\n", rc);
        return rc;
    }

    ctrl_meas = BME280_SET_BITS_POS_0(ctrl_meas, BME280_SENSOR_MODE, (uint8_t)mode);
    rc = bme280_write_reg8(priv, BME280_CTRL_MEAS_ADDR, ctrl_meas);
    if (rc < 0)
    {
        /*error*/printf("ERROR: can`t write ctrl_meas reg :%d\n", rc);
        return rc;
    }

    return rc;

}


int bme280_soft_reset( const struct bme280_dev_s * priv)
{
    int rc;
    uint8_t soft_rst_cmd = 0xB6;

    rc = bme280_write_reg8(priv, BME280_RESET_ADDR, soft_rst_cmd);
    if (rc < 0)
    {
        /*error*/printf("ERROR: can`t soft reset device: %d\n", rc);
        return rc;
    }

    /* As per data sheet, startup time is 2 ms. */
    HAL_Delay(2);

    /*info*/printf("INFO: bme280 soft reseted\n");

    return rc;
}


int bme280_pull_raw_data( const struct bme280_dev_s * priv, struct bme280_raw_data_s * data)
{
    uint8_t reg_data[BME280_P_T_H_DATA_LEN] = {0};

    int rc = bme280_read_regn(priv, BME280_DATA_ADDR, reg_data, sizeof(reg_data));
    if (rc < 0)
    {
        /*error*/printf("ERROR: can`t get sensor data from device: %d\n", rc);
        return rc;
    }

    /* Variables to store the sensor data */
    uint32_t data_xlsb;
    uint32_t data_lsb;
    uint32_t data_msb;

    /* Store the parsed register values for pressure data */
    data_msb = (uint32_t)reg_data[0] << 12;
    data_lsb = (uint32_t)reg_data[1] << 4;
    data_xlsb = (uint32_t)reg_data[2] >> 4;
    data->pressure = data_msb | data_lsb | data_xlsb;

    /* Store the parsed register values for temperature data */
    data_msb = (uint32_t)reg_data[3] << 12;
    data_lsb = (uint32_t)reg_data[4] << 4;
    data_xlsb = (uint32_t)reg_data[5] >> 4;
    data->temperature = data_msb | data_lsb | data_xlsb;

    /* Store the parsed register values for temperature data */
    data_lsb = (uint32_t)reg_data[6] << 8;
    data_msb = (uint32_t)reg_data[7];
    data->humidity = data_msb | data_lsb;

    return rc;
}




int bme280_register_i2c(struct bme280_dev_s *bme280, I2C_HandleTypeDef *i2c_handler, uint16_t devaddr)
{
    int rc;

    struct bme280_dev_s *priv = bme280;

    //priv = ( struct bme280_dev_s *)malloc(sizeof(struct bme280_dev_s));
    if (!priv)
    {
        /*error*/printf("ERROR: Failed to allocate bme280 device instance\n");//TODO change description
        return -ENOMEM;
    }
    priv->setup_conf.iface.i2c.bus = i2c_handler;
    priv->setup_conf.iface.i2c.devaddr = devaddr;
    priv->_do_read = _bme280_do_read_i2c;
    priv->_do_write = _bme280_do_write_i2c;


    /* reset the device */
    rc = bme280_soft_reset(priv);
    if (rc < 0)
    {
        return rc;
    }

    /* Check Device ID */
    rc = bme280_checkid(priv);
    if (rc < 0)
    {
        return rc;
    }

    /* Read the coefficient value */
    rc = bme280_pull_calvals(priv);
    if (rc < 0)
    {
        /*error*/printf("ERROR: Can`t load calibration values from device: %d\n", rc);
        return rc;
    }
    /*info*/printf("INFO: loaded calibration values\n");

    /*info*/printf("INFO: BME280 driver loaded successfully!\n");
    return rc;
}

int bme280_config_default(bme280_dev_s * bme280)
{
	int rc = 0;
	struct bme280_conf_s cs;
	cs.osr_p = BME280_OVERSAMPLING_16X;
	cs.osr_t = BME280_OVERSAMPLING_16X;
	cs.osr_h = BME280_OVERSAMPLING_16X;
	cs.filter = BME280_FILTER_COEFF_OFF;
	cs.standby_time = BME280_STANDBY_TIME_125_MS;
	bme280->settings = cs;
	rc |= bme280_push_sensor_conf(bme280, BME280_APPLY_SEL_ALL);

	rc |= bme280_push_sensor_mode(bme280, BME280_MODE_NORMAL);

	if(rc)
	{
		trace_printf("ERROR: Can't config bme280\n");
	}
	return rc;
}

#endif
#endif //__BME280_C__

