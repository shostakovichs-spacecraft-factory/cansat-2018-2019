/*
 * lsm6ds3.h
 *
 *  Created on: 19 июл. 2018 г.
 *      Author: snork
 */

#ifndef __INCLUDE_NUTT_SENSORS_LSM6DS3_H_
#define __INCLUDE_NUTT_SENSORS_LSM6DS3_H_


#include <stdint.h>
#include <stddef.h>
#include <sys/types.h>

#include <stm32f4xx_hal.h>

#ifdef __cplusplus
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif


// ===========================================================================
// Gyroscope settings
// ===========================================================================

// Gyro also have a low pass filter, but it`s not directly controllable
// Take a look at tables in app note to get filter parameters, which are dependent
// at gyro odr and power mode

// gyro power mode
typedef enum
{
    // POWER_DOWN mode is set through ODR settings
    LSM6DS3_G_PM_SLEEP,               // almost the same as power down, but device wakes up faster
    LSM6DS3_G_PM_LOW_POWER_OR_NORMAL, // three slowest odr values results an low power mode, everything else is normal mode
    LSM6DS3_G_PM_HIGH_PERFORMANCE,    // best performance in terms of noise
} lsm6ds3_g_pm_t;


// gyro full scale range
typedef enum
{
    LSM6DS3_G_FS_125DPS  = 0x10,    // gyro measurement range at 125 degrees per second
    LSM6DS3_G_FS_250DPS  = 0x00,    // etc
    LSM6DS3_G_FS_500DPS  = 0x01,
    LSM6DS3_G_FS_1000DPS = 0x02,
    LSM6DS3_G_FS_2000DPS = 0x03,
} lsm6ds3_g_fs_t;


// gyro measure rate
typedef enum
{
    LSM6DS3_G_ODR_POWER_DOWN    = 0x00,  // gyro disabled

    LSM6DS3_G_ODR_12_5_HZ       = 0x01,  // gyro measure rate at 12.5 Hz
    LSM6DS3_G_ODR_26_HZ         = 0x02,  // etc
    LSM6DS3_G_ODR_52_HZ         = 0x03,
    LSM6DS3_G_ODR_104_HZ        = 0x04,
    LSM6DS3_G_ODR_208_HZ        = 0x05,
    LSM6DS3_G_ODR_416_HZ        = 0x06,
    LSM6DS3_G_ODR_833_HZ        = 0x07,
    LSM6DS3_G_ODR_1660_HZ       = 0x08,
} lsm6ds3_g_odr_t;


// the only controllable filter for a lsm6ds3 gyroscope - high pass filter
typedef enum
{
    LSM6DS3_G_HPF_DISABLED          = 0x00,  // don`t use hpf filter for gyro

    LSM6DS3_G_HPF_CUTOFF_0_0081_HZ  = 0x10,  // hpf filter cutoff frequency 0.0081 Hz
    LSM6DS3_G_HPF_CUTOFF_0_0324_HZ  = 0x11,  // etc
    LSM6DS3_G_HPF_CUTOFF_2_07_HZ    = 0x12,
    LSM6DS3_G_HPF_CUTOFF_16_32_HZ   = 0x13,
} lsm6ds3_g_hpf_t;


// gyro conf structure
struct lsm6ds3_g_conf_s
{
    lsm6ds3_g_odr_t odr;          // gyroscope measure rate
    lsm6ds3_g_pm_t pm;            // gyroscope power mode
    lsm6ds3_g_fs_t fs;            // gyroscope full scale range
    lsm6ds3_g_hpf_t hpf;          // gyroscope high pass filter params
};

// ===========================================================================
// accelerometer config
// ===========================================================================

// accelerometer power mode
typedef enum
{
    // POWER_DOWN mode is set through odr settings
    LSM6DS3_XL_PM_LOW_POWER_OR_NORMAL   = 0x01,  // three slowest odr results in power down mode, else normal
    LSM6DS3_XL_PM_HIGH_PERFORMANCE      = 0x00,  // best performance in terms of noise with any ODR setting
} lsm6ds3_xl_pm_t;


// accelerometer full scale range
typedef enum
{
    LSM6DS3_XL_FS_2G    = 0x00,     // accelerometer full scale range at 2G
    LSM6DS3_XL_FS_4G    = 0x02,     // etc
    LSM6DS3_XL_FS_8G    = 0x03,
    LSM6DS3_XL_FS_16G   = 0x01,
} lsm6ds3_xl_fs_t;


// accelerometer analog low pass filter alpf parameters
typedef enum
{
    LSM6DS3_XL_ALPF_BW_AUTO     = 0x00,     // filter bandwidth dependent on power mode and odr

    LSM6DS3_XL_ALPF_BW_50_HZ    = 0x13,     // filter bandwidth fixed at 50 Hz
    LSM6DS3_XL_ALPF_BW_100_HZ   = 0x12,     // etc
    LSM6DS3_XL_ALPF_BW_200_HZ   = 0x11,
    LSM6DS3_XL_ALPF_BW_400_HZ   = 0x10,
} lsm6ds3_xl_alpf_bw_t;


// accelerometer measure rate
typedef enum
{
    LSM6DS3_XL_ODR_POWER_DOWN   = 0x00,  // accelerometer disabled

    LSM6DS3_XL_ODR_12_5_HZ      = 0x01,  // accelerometer measure rate 12.5 Hz
    LSM6DS3_XL_ODR_26_HZ        = 0x02,  // etc
    LSM6DS3_XL_ODR_52_HZ        = 0x03,
    LSM6DS3_XL_ODR_104_HZ       = 0x04,
    LSM6DS3_XL_ODR_208_HZ       = 0x05,
    LSM6DS3_XL_ODR_416_HZ       = 0x06,
    LSM6DS3_XL_ODR_833_HZ       = 0x07,
    LSM6DS3_XL_ODR_1660_HZ      = 0x08,
    LSM6DS3_XL_ODR_3330_HZ      = 0x09,
    LSM6DS3_XL_ODR_6660_HZ      = 0x0A,
} lsm6ds3_xl_odr_t;


// accelerometer composite filter settings
// if devics is configured in acc only mode, then composite filter should be enabled
typedef enum
{
    // don`t use composite filter at all
    LSM6DS3_XL_CF_DISABLED                = 0x00,

    // use slope filter
    LSM6DS3_XL_CF_SLOPE_CUTOFF_ODR_DIV_4  = 0x30, // use slope filter with cutoff frequency as ODR / 4

    // use high pass filter hpf
    LSM6DS3_XL_CF_HPF_CUTOFF_ODR_DIV_100  = 0x31, // use high pass filter with cutoff frequency = ODR / 100
    LSM6DS3_XL_CF_HPF_CUTOFF_ODR_DIV_9    = 0x32, // use high pass filter with cutoff frequency = ODR / 9
    LSM6DS3_XL_CF_HPF_CUTOFF_ODR_DIV_400  = 0x33, // use high pass filter with cutoff frequency = ODR / 400

    // use low pass filter lpf2
    LSM6DS3_XL_CF_LPF2_CUTOFF_ODR_DIV_50  = 0x20, // use low pass 2 filter with cutoff frequency = ODR / 50
    LSM6DS3_XL_CF_LPF2_CUTOFF_ODR_DIV_100 = 0x21, // use low pass 2 filter with cutoff frequency = ODR / 100
    LSM6DS3_XL_CF_LPF2_CUTOFF_ODR_DIV_9   = 0x22, // use low pass 2 filter with cutoff frequency = ODR / 9
    LSM6DS3_XL_CF_LPF2_CUTOFF_ODR_DIV_400 = 0x23, // use low pass 2 filter with cutoff frequency = ODR / 400
} lsm6ds3_xl_cf_t;


struct lsm6ds3_xl_conf_s
{
    lsm6ds3_xl_odr_t odr;           // accelerometer measure rate
    lsm6ds3_xl_pm_t pm;             // accelerometer power mode
    lsm6ds3_xl_alpf_bw_t alpf_bw;   // accelerometer analog low pass filter params
    lsm6ds3_xl_fs_t fs;             // accelerometer full scale range
    lsm6ds3_xl_cf_t cf;             // accelerometer composite filter
};

// ===========================================================================
// fifo config
// ===========================================================================


// fifo mode (refer to device appnote and datasheet)
typedef enum
{
    LSM6DS3_FIFO_MODE_BYPASS                 = 0x00,
    LSM6DS3_FIFO_MODE_FIFO                   = 0x01,
    LSM6DS3_FIFO_MODE_CONTINIOUS_TO_FIFO     = 0x03,
    LSM6DS3_FIFO_MODE_BYPASS_TO_CONTINOUS    = 0x04,
    LSM6DS3_FIFO_MODE_CONTINOUS              = 0x06,
} lsm6ds3_fifo_mode_t;


// fifo odr rate
typedef enum
{
    LSM6DS3_FIFO_ODR_DISABLED   = 0x00, // fifo disabled

    LSM6DS3_FIFO_ODR_12_5_HZ    = 0x01,
    LSM6DS3_FIFO_ODR_26_HZ      = 0x02,
    LSM6DS3_FIFO_ODR_52_HZ      = 0x03,
    LSM6DS3_FIFO_ODR_104_HZ     = 0x04,
    LSM6DS3_FIFO_ODR_208_HZ     = 0x05,
    LSM6DS3_FIFO_ODR_416_HZ     = 0x06,
    LSM6DS3_FIFO_ODR_833_HZ     = 0x07,
    LSM6DS3_FIFO_ODR_1660_HZ    = 0x08,
    LSM6DS3_FIFO_ODR_3330_HZ    = 0x09,
    LSM6DS3_FIFO_ODR_6660_HZ    = 0x0A,
} lsm6ds3_fifo_odr_t;


// decimation of fifo data sources
typedef enum
{
    LSM6DS3_FIFO_DECIMATION_IGNORE_DATA     = 0x00,
    LSM6DS3_FIFO_DECIMATION_1X              = 0x01,
    LSM6DS3_FIFO_DECIMATION_2X              = 0x02,
    LSM6DS3_FIFO_DECIMATION_3X              = 0x03,
    LSM6DS3_FIFO_DECIMATION_4X              = 0x04,
    LSM6DS3_FIFO_DECIMATION_8X              = 0x05,
    LSM6DS3_FIFO_DECIMATION_16X             = 0x06,
    LSM6DS3_FIFO_DECIMATION_32X             = 0x07,
} lsm6ds3_fifo_decimation_t;


// device embedded fifo status flags
typedef enum
{
    LSM6DS3_FIFO_STATUS_WATERMARK   = (1 << 7),    // fifo samples count is above treshhold
    LSM6DS3_FIFO_STATUS_OVERRUN     = (1 << 6),    // has overrun bit
    LSM6DS3_FIFO_STATUS_FULL        = (1 << 5),    // fifo is full
    LSM6DS3_FIFO_STATUS_EMPTY       = (1 << 4),    // fifo is empty
} lsm6ds3_fifo_status_flags_t;


// device embedded fifo configuration
struct lsm6ds3_fifo_conf_s
{
    lsm6ds3_fifo_mode_t mode;               // fifo mode
    lsm6ds3_fifo_odr_t odr;                 // fifo accumulation rate
    uint16_t treshold;                      // fifo treshhold to some interrupt signals (not used currently)
    lsm6ds3_fifo_decimation_t dec_g_set;    // fifo decimation for gyro data
    lsm6ds3_fifo_decimation_t dec_xl_set;   // fifo decimation for xl data
    lsm6ds3_fifo_decimation_t dec_3rd_set;  // fifo decimation for xl data
    lsm6ds3_fifo_decimation_t dec_4rth_set; // fifo decimation for xl data
};

// ===========================================================================
// full device config
// ===========================================================================


// sensor configuration values
struct lsm6ds3_conf_s
{
    // accelerometer conf
    struct lsm6ds3_xl_conf_s xl;
    // gyro conf
    struct lsm6ds3_g_conf_s g;
    // fifo conf
    struct lsm6ds3_fifo_conf_s fifo;
};


// ===========================================================================
// Structures for data reading (through read syscall)
// ===========================================================================

// data type for floating point results
typedef float lsm6ds3_float_t;


// device data reading mode
// actual value is bit composition of raw/scaled and fifo/nofifo values
// this enum is used through appropriate ioctl call
// default read mode is LSM6DS3_READMODE_SCALED
typedef enum
{
    // read single measurement from device and provide it as raw data
    // `read` function argument should be pointer to struct lsm6ds3_raw_data_s
    // with appropriate size
    LSM6DS3_READMODE_RAW            = 0x0100,

    // read single measurement from device, scale it to m/s**2 and grad/s
    // and provide to user buffer
    // `read` function argument should be pointer to struct lsm6ds3_scaled_data_s
    // with appropriate size
    LSM6DS3_READMODE_SCALED         = 0x0200,

    // read data from embedded device fifo
    // its just raw stream, so user can read any amount of bytes
    // its advisable to check data amount in fifo first by using `SNIOC_LSM6DS3_GETFIFOS` ioctl command
    // also you can set lower byte of this word to multiplier. An amount of data readed from fifo (in 16bit words)
    // is guaranteed to be interger divisible to this number
    LSM6DS3_READMODE_FIFO_RAW       = 0x1000,
} lsm6ds3_readmode_t;


// structure for reading device embedded fifo status
// usable with appropriate ioctl call
struct lsm6ds3_fifo_status_s
{
    uint16_t samples_count16;   // amount of samples available in fifo in terms of 16bit words
    uint16_t pattern_value;     // current pattern value. Refer for datasheet for details
    uint8_t flags;              // bit combination of lsm6ds3_fifo_status_flags_t
};


// sensor raw data, as it stored in device registers
struct lsm6ds3_raw_data_s
{
    int16_t g[3];   // gyro x,y,z measurements in raw sensor representation
    int16_t xl[3];  // accelerometer x,y,z measurements in raw sensor representation
};


// recalculated in m/s**2 and grad/s sensor parameters
struct lsm6ds3_scaled_data_s
{
    lsm6ds3_float_t g[3];   // gyro x,y,z measurements in grad/s
    lsm6ds3_float_t xl[3];  // accelerometer x,y,z, measurements in m/s**2
};


// recalculation of accelerometer measure results from register values to m/s**2
void lsm6ds3_scale_xl(const struct lsm6ds3_xl_conf_s * conf, int16_t * in, lsm6ds3_float_t * out, size_t count);
// recalculation of gyroscope measure results from register values to grad/s
void lsm6ds3_scale_g(const struct lsm6ds3_g_conf_s * conf, int16_t * in, lsm6ds3_float_t * out, size_t count);


// ===========================================================================
// Device driver registration
// ===========================================================================s

// device interrupt selector
typedef enum {
    LSM6DS3_IRQPIN_INT1,
    LSM6DS3_IRQPIN_INT2,
} lsm6ds3_irqpin_t;


// device options for SPI mode configuration
struct lsm6ds3_setup_conf_s
{
    // device interface info
    // this device can use both i2c and spi buses
    union
    {
        // spi bus params
        struct
        {
        	SPI_HandleTypeDef * bus; // spi bus
            uint32_t bus_freq;          // spi bus frequency
            int dev_id;                 // spi device id for cs callbacks
        } spi;

        // i2c bus params
        struct
        {
            // TODO;
        } i2c;
    } iface;

};

struct lsm6ds3_dev_s
{
    /* device startup and hw configuration */
    struct lsm6ds3_setup_conf_s setup_conf;

    /* Registers read function pointer */
    ssize_t (*_do_read_regn)(const struct lsm6ds3_dev_s * priv, uint8_t regaddr,
            uint8_t * data, size_t datasize);

    /* Registers write function pointer */
    ssize_t (*_do_write_regn)( const struct lsm6ds3_dev_s * priv, uint8_t regaddr,
            const uint8_t * data, size_t datasize);

    /* current device configuration */
    struct lsm6ds3_conf_s conf;

    // mode of reading data
    lsm6ds3_readmode_t readmode;
    // additional parameter to read mode
    uint8_t readmode_arg;

};

// registration of device on spi bus
int lsm6ds3_register_spi(struct lsm6ds3_dev_s * config, SPI_HandleTypeDef* bus);
// configure spi bus to work with this particular device
void lsm6ds3_prepare_spi_bus(const struct lsm6ds3_dev_s * priv);



// reading n registers data abstract from transfer bus
ssize_t lsm6ds3_read_regn(const struct lsm6ds3_dev_s * priv, uint8_t regaddr,
        uint8_t * data, size_t datasize);

// writing n registers data abstract from transfer bus
ssize_t lsm6ds3_write_regn(const struct lsm6ds3_dev_s *priv, uint8_t regaddr,
        const uint8_t * data, size_t datasize);


// halt device measurements to allow applying new settings (or to put it to sleep)
//int lsm6ds3_halt(struct lsm6ds3_dev_s *priv);
// software device reset and wait until it completes
int lsm6ds3_sw_reset(const struct lsm6ds3_dev_s *priv);
// reset gyro hpf filter
int lsm6ds3_reset_g_hpf(const struct lsm6ds3_dev_s *priv);
// load default configuration to as it as after reset
void lsm6ds3_conf_default(struct lsm6ds3_dev_s * conf);


// send gyroscope settings to device
int lsm6ds3_g_push_conf(const struct lsm6ds3_dev_s *priv,
        const struct lsm6ds3_g_conf_s * g_conf);

// send accelerometer settings to device
int lsm6ds3_xl_push_conf(const struct lsm6ds3_dev_s *priv,
        const struct lsm6ds3_xl_conf_s * xl_conf);

// read raw gyro and acc values
int lsm6ds3_gxl_pull(const struct lsm6ds3_dev_s *priv,
        struct lsm6ds3_raw_data_s * raw);


// push fifo config to device
// its assumed that device (or at least fifo) is halted
int lsm6ds3_fifo_push_conf(const struct lsm6ds3_dev_s *priv,
        const struct lsm6ds3_fifo_conf_s * fifo_conf);

// get full status of fifo
int lsm6ds3_fifo_pull_status(const struct lsm6ds3_dev_s *priv,
        struct lsm6ds3_fifo_status_s * status);

// read data from device to local buffer
// reading in terms of struct lsm6ds3_raw_data elems
ssize_t lsm6ds3_fifo_pull_data(const struct lsm6ds3_dev_s * priv,
        uint16_t * buffer, size_t buffersize16, size_t size_factor);

int lsm6ds3_push_conf(struct lsm6ds3_dev_s *handler);

#undef EXTERN
#ifdef __cplusplus
}
#endif


#endif /* #ifdef CONFIG_SENSORS_LSM6DS3 */

