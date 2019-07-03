/*
 * lsm303c.h
 *
 *  Created on: 6 июн. 2019 г.
 *      Author: sereshotes
 *
 *  Use just magnetometer
 */

#ifndef LSM303C_H_
#define LSM303C_H_

#include "main.h"

typedef enum
{
    LSM303C_M_PM_SLEEP,
    LSM303C_M_PM_LOW_POWER,
    LSM303C_M_PM_NORMAL_POWER,
    LSM303C_M_PM_HIGH_PERFORMANCE,
    LSM303C_M_PM_ULTRA_HIGH_PERFORMANCE,
} lsm303c_m_pm_t;


// mag full scale range
typedef enum
{
    LSM303C_M_FS_16_GAUSS  = 0x3,
} lsm303c_m_fs_t;


// mag measure rate
typedef enum
{

    LSM303C_M_ODR_0_625_HZ      = 0x00,
    LSM303C_M_ODR_1_25_HZ 		= 0x01,
    LSM303C_M_ODR_2_5_HZ		= 0x02,
    LSM303C_M_ODR_5_HZ			= 0x03,
    LSM303C_M_ODR_10_HZ			= 0x04,
    LSM303C_M_ODR_20_HZ			= 0x05,
    LSM303C_M_ODR_40_HZ			= 0x06,
    LSM303C_M_ODR_80_HZ			= 0x07,
} lsm303c_m_odr_t;

//mag operating mode
typedef enum
{
	LSM303C_M_MD_CONT_CONV = 0x00,
	LSM303C_M_MD_SINGLE_CONV = 0x01,
	LSM303C_M_MD_POWER_DOWN = 0x02,
} lsm303c_m_md_t;



// mag conf structure
struct lsm303c_m_conf_s
{
    lsm303c_m_odr_t odr;          // mag measure rate
    lsm303c_m_pm_t pm;            // mag power mode
    lsm303c_m_fs_t fs;            // mag full scale range
    lsm303c_m_md_t md;			  // mag mode
};

// fifo mode (refer to device appnote and datasheet)
typedef enum
{
    LSM303C_FIFO_MODE_BYPASS                 = 0x00,
    LSM303C_FIFO_MODE_FIFO                   = 0x01,
    LSM303C_FIFO_MODE_CONTINIOUS_TO_FIFO     = 0x03,
    LSM303C_FIFO_MODE_BYPASS_TO_CONTINOUS    = 0x04,
    LSM303C_FIFO_MODE_CONTINOUS              = 0x06,
} lsm303c_fifo_mode_t;


// fifo odr rate
typedef enum
{
    LSM303C_FIFO_ODR_DISABLED   = 0x00, // fifo disabled

    LSM303C_FIFO_ODR_12_5_HZ    = 0x01,
    LSM303C_FIFO_ODR_26_HZ      = 0x02,
    LSM303C_FIFO_ODR_52_HZ      = 0x03,
    LSM303C_FIFO_ODR_104_HZ     = 0x04,
    LSM303C_FIFO_ODR_208_HZ     = 0x05,
    LSM303C_FIFO_ODR_416_HZ     = 0x06,
    LSM303C_FIFO_ODR_833_HZ     = 0x07,
    LSM303C_FIFO_ODR_1660_HZ    = 0x08,
    LSM303C_FIFO_ODR_3330_HZ    = 0x09,
    LSM303C_FIFO_ODR_6660_HZ    = 0x0A,
} lsm303c_fifo_odr_t;


// decimation of fifo data sources
typedef enum
{
    LSM303C_FIFO_DECIMATION_IGNORE_DATA     = 0x00,
    LSM303C_FIFO_DECIMATION_1X              = 0x01,
    LSM303C_FIFO_DECIMATION_2X              = 0x02,
    LSM303C_FIFO_DECIMATION_3X              = 0x03,
    LSM303C_FIFO_DECIMATION_4X              = 0x04,
    LSM303C_FIFO_DECIMATION_8X              = 0x05,
    LSM303C_FIFO_DECIMATION_16X             = 0x06,
    LSM303C_FIFO_DECIMATION_32X             = 0x07,
} lsm303c_fifo_decimation_t;


// device embedded fifo status flags
typedef enum
{
    LSM303C_FIFO_STATUS_WATERMARK   = (1 << 7),    // fifo samples count is above treshhold
    LSM303C_FIFO_STATUS_OVERRUN     = (1 << 6),    // has overrun bit
    LSM303C_FIFO_STATUS_FULL        = (1 << 5),    // fifo is full
    LSM303C_FIFO_STATUS_EMPTY       = (1 << 4),    // fifo is empty
} lsm303c_fifo_status_flags_t;


// device embedded fifo configuration
struct lsm303c_fifo_conf_s
{
    lsm303c_fifo_mode_t mode;               // fifo mode
    lsm303c_fifo_odr_t odr;                 // fifo accumulation rate
    uint16_t treshold;                      // fifo treshhold to some interrupt signals (not used currently)
    lsm303c_fifo_decimation_t dec_g_set;    // fifo decimation for gyro data
    lsm303c_fifo_decimation_t dec_xl_set;   // fifo decimation for xl data
    lsm303c_fifo_decimation_t dec_3rd_set;  // fifo decimation for xl data
    lsm303c_fifo_decimation_t dec_4rth_set; // fifo decimation for xl data
};

// ===========================================================================
// full device config
// ===========================================================================


// sensor configuration values
struct lsm303c_conf_s
{
    struct lsm303c_m_conf_s m;
};


// ===========================================================================
// Device driver registration
// ===========================================================================s


// device options for SPI mode configuration
struct lsm303c_setup_conf_s
{
    // device interface info
    // this device can use both i2c and spi buses
    union
    {

        // i2c bus params
        struct
        {
        	I2C_HandleTypeDef *hi2c;
        	uint8_t addr_a;
        	uint8_t addr_m;
        } i2c;
    } iface;

};

struct lsm303c_handler_s
{
    /* device startup and hw configuration */
    struct lsm303c_setup_conf_s setup_conf;

    /* Registers read function pointer */
    ssize_t (*read_regn)(const struct lsm303c_handler_s * handler, uint8_t regaddr,
            uint8_t * data, size_t datasize);

    /* Registers write function pointer */
    ssize_t (*write_regn)( const struct lsm303c_handler_s * handler, uint8_t regaddr,
            const uint8_t * data, size_t datasize);

    /* current device configuration */
    struct lsm303c_conf_s conf;

    // mode of reading data
    //lsm303c_readmode_t readmode;
    // additional parameter to read mode
   // uint8_t readmode_arg;

};



struct lsm303c_fifo_status_s
{
    uint16_t samples_count16;   // amount of samples available in fifo in terms of 16bit words
    uint16_t pattern_value;     // current pattern value. Refer for datasheet for details
    uint8_t flags;              // bit combination of lsm6ds3_fifo_status_flags_t
};

struct lsm303c_raw_data_m_s
{
	int16_t m[3];
};



void lsm303c_scale_m(const struct lsm303c_handler_s *handler, int16_t *in, float *out, int count);

// registration of device on spi bus
int lsm303c_register_i2c(struct lsm303c_handler_s * config, I2C_HandleTypeDef* bus);
// configure spi bus to work with this particular device
void lsm303c_prepare_spi_bus(const struct lsm303c_handler_s * priv);



// reading n registers data abstract from transfer bus
ssize_t lsm303c_read_regn(const struct lsm303c_handler_s * priv, uint8_t regaddr,
        uint8_t * data, size_t datasize);

// writing n registers data abstract from transfer bus
ssize_t lsm303c_write_regn(const struct lsm303c_handler_s *priv, uint8_t regaddr,
        const uint8_t * data, size_t datasize);


// halt device measurements to allow applying new settings (or to put it to sleep)
//int lsm303c_halt(struct lsm303c_dev_s *priv);
// software device reset and wait until it completes
int lsm303c_sw_reset(const struct lsm303c_handler_s *priv);
// reset gyro hpf filter
int lsm303c_reset_g_hpf(const struct lsm303c_handler_s *priv);
// load default configuration to as it as after reset
void lsm303c_conf_default(struct lsm303c_handler_s * conf);

// load default configuration to as it as after reset
void lsm303c_m_conf_default(struct lsm303c_handler_s * handler);


// send mag settings to device
int lsm303c_m_push_conf(const struct lsm303c_handler_s *handler,
        const struct lsm303c_m_conf_s * m_conf);



int lsm303c_m_pull(const struct lsm303c_handler_s *handler,
        struct lsm303c_raw_data_m_s * m_raw);
// push fifo config to device
// its assumed that device (or at least fifo) is halted
int lsm303c_fifo_push_conf(const struct lsm303c_handler_s *priv,
        const struct lsm303c_fifo_conf_s * fifo_conf);

// get full status of fifo
int lsm303c_fifo_pull_status(const struct lsm303c_handler_s *priv,
        struct lsm303c_fifo_status_s * status);

// read data from device to local buffer
// reading in terms of struct lsm303c_raw_data elems
ssize_t lsm303c_fifo_pull_data(const struct lsm303c_handler_s * priv,
        uint16_t * buffer, size_t buffersize16, size_t size_factor);

int lsm303c_push_conf(struct lsm303c_handler_s *handler);

#endif /* LSM303C_H_ */
