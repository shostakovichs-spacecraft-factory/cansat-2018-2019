/*
 * lsm6ds3.c
 *
 *  Created on: 19 июл. 2018 г.
 *      Author: snork
 */

#include "lsm6ds3.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <errno.h>
#include <assert.h>
#include <diag/Trace.h>

#include <stm32f4xx_hal.h>
// ===========================================
// SPI BUS settings
// ===========================================

#define warning trace_printf
#define snerr trace_printf
#define sninfo trace_printf

#define LSM6DS3_SPI_MODE 1
#define LSM6DS3_SPI_BITS (8)


#define OK 0
// ===========================================
// Common macro
// ===========================================
#define LSM6DS3_SET_BITS(reg_data, bitname, data) \
                ((reg_data & ~(bitname##_MSK)) | \
                (((uint8_t)data << bitname##_POS) & bitname##_MSK))

#define LSM6DS3_GET_BITS(reg_data, bitname)  ((reg_data & (bitname##_MSK)) >> \
                            (bitname##_POS))

#define LSM6DS3_MIN(a,b)    ((a < b) ? a : b)


// ===========================================
// Particular registers macro
// ===========================================


// FIFO CTRL1
// ===========================================
#define LSM6DS3_FIFOCTRL1_REGADDR           (0x06)

#define LSM6DS3_FIFOCTRL1_FTH0_POS          (0)
#define LSM6DS3_FIFOCTRL1_FTH0_MSK          (0xff)

#define LSM6DS3_FIFOCTRL1_RESERVED_MSK      (0x00)


// FIFO CTRL2
// ===========================================
#define LSM6DS3_FIFOCTRL2_REGADDR                   (0x07)

#define LSM6DS3_FIFOCTRL2_TIMER_PEDO_FIFO_EN_POS    (7)
#define LSM6DS3_FIFOCTRL2_TIMER_PEDO_FIFO_EN_MSK    (0x01 << 7)

#define LSM6DS3_FIFOCTRL2_TIMER_PEDO_FIFO_DRDY_POS  (6)
#define LSM6DS3_FIFOCTRL2_TIMER_PEDO_FIFO_DRDY_MSK  (0x01 << 6)

#define LSM6DS3_FIFOCTRL2_FTH8_POS                  (0)
#define LSM6DS3_FIFOCTRL2_FTH8_MSK                  (0x0f << 0)


#define LSM6DS3_FIFOCTRL2_RESERVED_MSK              (0x03 << 4)


// FIFO CTRL3
// ===========================================
#define LSM6DS3_FIFOCTRL3_REGADDR               (0x08)

#define LSM6DS3_FIFOCTRL3_DEC_FIFO_GYRO_POS     (3)
#define LSM6DS3_FIFOCTRL3_DEC_FIFO_GYRO_MSK     (0x07 << 3)

#define LSM6DS3_FIFOCTRL3_DEC_FIFO_XL_POS       (0)
#define LSM6DS3_FIFOCTRL3_DEC_FIFO_XL_MSK       (0x07 << 0)


#define LSM6DS3_FIFOCTRL3_RESERVED_MSK          (0x03 << 6)


// FIFO CTRL4
// ===========================================
#define LSM6DS3_FIFOCTRL4_REGADDR               (0x09)

#define LSM6DS3_FIFOCTRL4_ONLY_HIGH_DATA_POS    (6)
#define LSM6DS3_FIFOCTRL4_ONLY_HIGH_DATA_MSK    (0x01 << 6)

#define LSM6DS3_FIFOCTRL4_DEC_DS4_FIFO_POS      (3)
#define LSM6DS3_FIFOCTRL4_DEC_DS4_FIFO_MSK      (0x07 << 3)

#define LSM6DS3_FIFOCTRL4_DEC_DS3_FIFO_POS      (0)
#define LSM6DS3_FIFOCTRL4_DEC_DS3_FIFO_MSK      (0x07 << 0)


#define LSM6DS3_FIFOCTRL4_RESERVED_MSK          (0x01 << 7)


// FIFO CTRL5
// ===========================================
#define LSM6DS3_FIFOCTRL5_REGADDR           (0x0a)

#define LSM6DS3_FIFOCTRL5_FIFO_MODE_POS     (0)
#define LSM6DS3_FIFOCTRL5_FIFO_MODE_MSK     (0x7 << 0)

#define LSM6DS3_FIFOCTRL5_FIFO_ODR_POS      (3)
#define LSM6DS3_FIFOCTRL5_FIFO_ODR_MSK      (0x0f << 3)


#define LSM6DS3_FIFOCTRL5_RESERVED_MSK      (0x01 << 7)


// INT1_CTRL
// ===========================================
#define LSM6DS3_INT1CTRL_REGADDR            (0x0d)

#define LSM6DS3_INT1CTRL_INT1_FTH_POS       (3)
#define LSM6DS3_INT1CTRL_INT1_FTH_MSK       (0x01 << 3)


#define LSM6DS3_INT1CTRL_RESERVED_MSK       (0x00)


// WHO_AM_I
// ===========================================
#define LSM6DS3_WHOAMI_REGADDR              (0x0f)

#define LSM6DS3_WHOAMI_REGVAL               (0x69)


// CTRL1_XL
// ===========================================
#define LSM6DS3_CTRL1XL_REGADDR             (0x10)

#define LSM6DS3_CTRL1XL_ODR_XL_POS          (4)
#define LSM6DS3_CTRL1XL_ODR_XL_MSK          (0x0f << 4)

#define LSM6DS3_CTRL1XL_FS_XL_POS           (2)
#define LSM6DS3_CTRL1XL_FS_XL_MSK           (0x03 << 2)

#define LSM6DS3_CTRL1XL_BW_XL_POS           (0)
#define LSM6DS3_CTRL1XL_BW_XL_MSK           (0x03 << 0)


#define LSM6DS3_CTRL1XL_RESEVED_MSK         (0x00)


// CTRL2_G
// ===========================================
#define LSM6DS3_CTRL2G_REGADDR              (0x11)

#define LSM6DS3_CTRL2G_ODR_G_POS            (4)
#define LSM6DS3_CTRL2G_ODR_G_MSK            (0x0f << 4)

#define LSM6DS3_CTRL2G_FS_G_POS             (2)
#define LSM6DS3_CTRL2G_FS_G_MSK             (0x03 << 2)

#define LSM6DS3_CTRL2G_FS125_G_POS          (1)
#define LSM6DS3_CTRL2G_FS125_G_MSK          (0x01 << 1)


#define LSM6DS3_CTRL2G_RESEVED_MSK          (0x01)


// CTRL3_C
// ===========================================
#define LSM6DS3_CTRL3C_REGADDR              (0x12)

#define LSM6DS3_CTRL3C_BOOT_POS             (7)
#define LSM6DS3_CTRL3C_BOOT_MSK             (0x01 << 7)

#define LSM6DS3_CTRL3C_H_LACTIVE_POS        (5)
#define LSM6DS3_CTRL3C_H_LACTIVE_MSK        (0x01 << 5)

#define LSM6DS3_CTRL3C_BLE_POS              (1)
#define LSM6DS3_CTRL3C_BLE_MSK              (0x01 << 1)
#define LSM6DS3_CTRL3C_BLE_BIG_ENDIAN       (0x01)
#define LSM6DS3_CTRL3C_BLE_LITTLE_ENDIAN    (0x00)

#define LSM6DS3_CTRL3C_SW_RESET_POS         (0)
#define LSM6DS3_CTRL3C_SW_RESET_MSK         (0x01 << 0)


#define LSM6DS3_CTRL3C_RESEVED_MSK          (0x00)


// CTRL4_C
// ===========================================
#define LSM6DS3_CTRL4C_REGADDR              (0x13)

#define LSM6DS3_CTRL4C_XL_BW_SCAL_ODR_POS   (7)
#define LSM6DS3_CTRL4C_XL_BW_SCAL_ODR_MSK   (0x01 << 7)

#define LSM6DS3_CTRL4C_SLEEP_G_POS          (6)
#define LSM6DS3_CTRL4C_SLEEP_G_MSK          (0x01 << 6)

#define LSM6DS3_CTRL4C_I2C_DISABLE_POS      (2)
#define LSM6DS3_CTRL4C_I2C_DISABLE_MSK      (0x01 << 2)


#define LSM6DS3_CTRL4C_RESEVED_MSK          (0x01 << 1)


// CTRL6_C
// ===========================================
#define LSM6DS3_CTRL6C_REGADDR              (0x15)

#define LSM6DS3_CTRL6C_XL_HM_MODE_POS       (4)
#define LSM6DS3_CTRL6C_XL_HM_MODE_MSK       (0x01 << 4)


#define LSM6DS3_CTRL6C_RESEVED_MSK          (0x0f << 0)


// CTRL7_G
// ===========================================
#define LSM6DS3_CTRL7G_REGADDR              (0x16)

#define LSM6DS3_CTRL7G_G_HM_MODE_POS        (7)
#define LSM6DS3_CTRL7G_G_HM_MODE_MSK        (0x01 << 7)

#define LSM6DS3_CTRL7G_HP_G_EN_POS          (6)
#define LSM6DS3_CTRL7G_HP_G_EN_MSK          (0x01 << 6)

#define LSM6DS3_CTRL7G_HPCF_G_POS           (4)
#define LSM6DS3_CTRL7G_HPCF_G_MSK           (0x03 << 4)

#define LSM6DS3_CTRL7G_HP_G_RST_POS         (3)
#define LSM6DS3_CTRL7G_HP_G_RST_MSK         (0x01 << 3)


#define LSM6DS3_CTRL7G_RESEVED_MSK          (0x03 << 0)


// CTRL8_XL
// ===========================================
#define LSM6DS3_CTRL8XL_REGADDR             (0x17)

#define LSM6DS3_CTRL8XL_LPF2_XL_EN_POS      (7)
#define LSM6DS3_CTRL8XL_LPF2_XL_EN_MSK      (0x01 << 7)

#define LSM6DS3_CTRL8XL_HPCF_XL_POS         (5)
#define LSM6DS3_CTRL8XL_HPCF_XL_MSK         (0x03 << 5)

#define LSM6DS3_CTRL8XL_HP_SLOPE_XL_EN_POS  (2)
#define LSM6DS3_CTRL8XL_HP_SLOPE_XL_EN_MSK  (0x01 << 3)


#define LSM6DS3_CTRL8XL_RESEVED_MSK         ((1 << 1) | (1 << 3) | (1 << 4))


// CTRL9_XL
// ===========================================
#define LSM6DS3_CTRL9XL_REGADDR             (0x18)

#define LSM6DS3_CTRL9XL_ZEN_XL_POS          (5)
#define LSM6DS3_CTRL9XL_ZEN_XL_MSK          (0x01 << 5)

#define LSM6DS3_CTRL9XL_YEN_XL_POS          (4)
#define LSM6DS3_CTRL9XL_YEN_XL_MSK          (0x01 << 4)

#define LSM6DS3_CTRL9XL_XEN_XL_POS          (3)
#define LSM6DS3_CTRL9XL_XEN_XL_MSK          (0x01 << 3)


#define LSM6DS3_CTRL9XL_RESERVED_MSK        (0xc3)


// CTRL10_C
// ===========================================
#define LSM6DS3_CTRL10C_REGADDR            (0x19)

#define LSM6DS3_CTRL10C_ZEN_G_POS          (5)
#define LSM6DS3_CTRL10C_ZEN_G_MSK          (0x01 << 5)

#define LSM6DS3_CTRL10C_YEN_G_POS          (4)
#define LSM6DS3_CTRL10C_YEN_G_MSK          (0x01 << 4)

#define LSM6DS3_CTRL10C_XEN_G_POS          (3)
#define LSM6DS3_CTRL10C_XEN_G_MSK          (0x01 << 3)

#define LSM6DS3_CTRL10C_FUNC_EN_POS        (2)
#define LSM6DS3_CTRL10C_FUNC_EN_MSK        (0x01 << 2)


#define LSM6DS3_CTRL10XL_RESERVED_MSK      (0xc0)


// MASTERCONFIG
// ===========================================
#define LSM6DS3_MASTERCONFIG_REGADDR                    (0x1a)

#define LSM6DS3_MASTERCONFIG_DATA_VALID_SEL_FIFO_POS    (6)
#define LSM6DS3_MASTERCONFIG_DATA_VALID_SEL_FIFO_MSK    (0x01 << 6)


#define LSM6DS3_MASTERCONFIG_RESERVED_MSK               (0x00)


// FIFO_STATUS1
// ===========================================
#define LSM6DS3_FIFOSTATUS1_REGADDR         (0x3a)

#define LSM6DS3_FIFOSTATUS1_DIFF_FIFO0_POS  (0)
#define LSM6DS3_FIFOSTATUS1_DIFF_FIFO0_MSK  (0xff)


#define LSM6DS3_FIFOSTATUS1_RESERVED_MSK    (0x00)


// FIFO_STATUS2
// ===========================================
#define LSM6DS3_FIFOSTATUS2_REGADDR             (0x3b)

#define LSM6DS3_FIFOSTATUS2_FTH_POS             (7)
#define LSM6DS3_FIFOSTATUS2_FTH_MSK             (0x01 << 7)

#define LSM6DS3_FIFOSTATUS2_FIFO_OVER_RUN_POS   (6)
#define LSM6DS3_FIFOSTATUS2_FIFO_OVER_RUN_MSK   (0x01 << 6)

#define LSM6DS3_FIFOSTATUS2_FIFO_FULL_POS       (5)
#define LSM6DS3_FIFOSTATUS2_FIFO_FULL_MSK       (0x01 << 5)

#define LSM6DS3_FIFOSTATUS2_FIFO_EMPTY_POS      (4)
#define LSM6DS3_FIFOSTATUS2_FIFO_EMPTY_MSK      (0x01 << 4)

// mask to select only flag values
#define LSM6DS3_FIFOSTATUS2_FLAGS_MSK           (0xf0)

#define LSM6DS3_FIFOSTATUS2_DIFF_FIFO8_POS      (0)
#define LSM6DS3_FIFOSTATUS2_DIFF_FIFO8_MSK      (0x0f << 0)


#define LSM6DS3_FIFOSTATUS2_RESERVED_MSK        (0x00)


// FIFO_STATUS3
// ===========================================
#define LSM6DS3_FIFOSTATUS3_REGADDR             (0x3c)

#define LSM6DS3_FIFOSTATUS3_FIFOPATTERN0_POS    (0)
#define LSM6DS3_FIFOSTATUS3_FIFOPATTERN0_MSK    (0xff)


#define LSM6DS3_FIFOSTATUS3_RESERVED_MSK        (0x00)


// FIFO_STATUS4
// ===========================================
#define LSM6DS3_FIFOSTATUS4_REGADDR             (0x3d)

#define LSM6DS3_FIFOSTATUS4_FIFOPATTERN8_POS    (0)
#define LSM6DS3_FIFOSTATUS4_FIFOPATTERN8_MSK    (0x03)


#define LSM6DS3_FIFOSTATUS4_RESERVED_MSK        (0xfc)



// data out regs
// ===========================================

#define LSM6DS3_OUTXLG_REGADDR              (0x22)
#define LSM6DS3_OUTXHG_REGADDR              (0x23)
#define LSM6DS3_OUTYLG_REGADDR              (0x24)
#define LSM6DS3_OUTYHG_REGADDR              (0x25)
#define LSM6DS3_OUTZLG_REGADDR              (0x26)
#define LSM6DS3_OUTZHG_REGADDR              (0x27)
#define LSM6DS3_OUTXLXL_REGADDR             (0x28)
#define LSM6DS3_OUTXHXL_REGADDR             (0x29)
#define LSM6DS3_OUTYLXL_REGADDR             (0x2a)
#define LSM6DS3_OUTYHXL_REGADDR             (0x2b)
#define LSM6DS3_OUTZLXL_REGADDR             (0x2c)
#define LSM6DS3_OUTZHXL_REGADDR             (0x2d)

#define LSM6DS3_FIFO_DATA_OUT_L_REGADDR     (0x3e)
#define LSM6DS3_FIFO_DATA_OUT_H_REGADDR     (0x3f)

#define LSM6DS3_TIMEOUT 100 //ms

/****************************************************************************
 * private functions definements
 ****************************************************************************/

//static const struct file_operations lsm6ds3_fops =
//{
//        lsm6ds3_chdev_open,                  /* open */
//        lsm6ds3_chdev_close,                 /* close */
//        lsm6ds3_chdev_read,                  /* read */
//        lsm6ds3_chdev_write,                 /* write */
//        0,                                   /* seek */
//        lsm6ds3_chdev_ioctl,                 /* ioctl */
//    #ifndef CONFIG_DISABLE_POLL
//        0,                                   /* poll */
//    #endif
//        0                                    /* unlink */
//};


/****************************************************************************
 * private driver functions definitions
 ****************************************************************************/
#define true 1
#define false 0



static int lsm6ds3_do_read_regn_spi(const  struct lsm6ds3_dev_s * priv, uint8_t regaddr,
        uint8_t * data, size_t datasize)
{
    SPI_HandleTypeDef * const bus = priv->setup_conf.iface.spi.bus;

    if (0 == datasize)
        return 0;

    regaddr |= 0x80; // for read by SPI, regaddr should be modified with most significant bit setted to 1

    // passing register value
   // SPI_SEND(bus, regaddr);
    int rc = 0;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    if(rc = HAL_SPI_Transmit(bus, &regaddr, 1, LSM6DS3_TIMEOUT))
    	trace_printf("ERROR: %d\n", rc);

    //MY_HAL_SPI_TransmitReceive(bus, &regaddr, data, 1, datasize, LSM6DS3_TIMEOUT);
    // passing data

    // we have two type of read transfers
    // first - is to read simple reg data
    // and second - to read relatively large blocs of sensor data and even fifo buffers
    // its possible to use DMA for block transfers
    // and there is no need to use it for single byte transfer
    /*
    if (datasize <= 1)
    {
        //data[0] = SPI_SEND(bus, 0xFF);

    }
    else
    {
        SPI_RECVBLOCK(bus, data, datasize);
    }*/
    if(rc = HAL_SPI_Receive(bus, data, datasize, LSM6DS3_TIMEOUT))
    	trace_printf("ERROR: %d\n", rc);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);




    return datasize;
}


static int lsm6ds3_do_write_regn_spi( struct lsm6ds3_dev_s * priv, uint8_t regaddr,
        uint8_t * data, size_t datasize)
{
    SPI_HandleTypeDef * bus = priv->setup_conf.iface.spi.bus;

    if (0 == datasize)
        return 0;
    uint8_t t[datasize + 1];
    t[0] = regaddr;
    for(int i = 1; i < datasize + 1; i++)
    	t[i] = data[i - 1];
    //lsm6ds3_prepare_spi_bus(priv);
    int rc = 0;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(bus, t, datasize + 1, LSM6DS3_TIMEOUT);
//    if(rc = HAL_SPI_Transmit(bus, &regaddr, 1, LSM6DS3_TIMEOUT))
//    	trace_printf("ERROR: %d\n", rc);
//    if(rc = HAL_SPI_Transmit(bus, data, datasize, LSM6DS3_TIMEOUT))
//    	trace_printf("ERROR: %d\n", rc);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);

    //SPI_SEND(bus, regaddr);
    //SPI_SNDBLOCK(bus, (uint8_t*)data, datasize); // const should be removed here, since
                                                 // it`s not conforms the spi bus interface


    return datasize;
}


inline int lsm6ds3_read_regn( const struct lsm6ds3_dev_s * priv, uint8_t regaddr,
        uint8_t * data, size_t datasize)
{
    return priv->_do_read_regn(priv, regaddr, data, datasize);
}


inline int lsm6ds3_write_regn( const struct lsm6ds3_dev_s *priv, uint8_t regaddr,
        const uint8_t * data, size_t datasize)
{
    return priv->_do_write_regn(priv, regaddr, data, datasize);
}





int lsm6ds3_sw_reset( const struct lsm6ds3_dev_s *priv)
{
    int rc = OK;

    // we wont read all bits to keep them, device will be reseted now
    uint8_t reg_ctrl3 = 0x00;
    reg_ctrl3 = LSM6DS3_SET_BITS(reg_ctrl3, LSM6DS3_CTRL3C_SW_RESET, 1);

    rc = lsm6ds3_write_regn(priv, LSM6DS3_CTRL3C_REGADDR, &reg_ctrl3, 1);
    if (rc < 0)
        return rc;

    // device will be ready after 20 ms according to datasheet
    HAL_Delay(25);

    // thats is
    return rc;
}


int lsm6ds3_reset_g_hpf( const struct lsm6ds3_dev_s *priv)
{
    int rc = OK;
    uint8_t ctrl7_reg;

    rc = lsm6ds3_read_regn(priv, LSM6DS3_CTRL7G_REGADDR, &ctrl7_reg, 1);
    if (rc < 0)
        return rc;

    ctrl7_reg = LSM6DS3_SET_BITS(ctrl7_reg, LSM6DS3_CTRL7G_HP_G_RST, 1);
    ctrl7_reg &= ~LSM6DS3_CTRL7G_RESEVED_MSK;

    rc = lsm6ds3_write_regn(priv, LSM6DS3_CTRL7G_REGADDR, &ctrl7_reg, 1);
    if (rc < 0)
        return rc;

    return rc;
}


void lsm6ds3_conf_default(struct lsm6ds3_dev_s *hlsm )
{
	struct lsm6ds3_conf_s * conf = &hlsm->conf;
//	 // xl default conf
//	conf->xl.pm = LSM6DS3_XL_PM_LOW_POWER_OR_NORMAL;
//	conf->xl.odr = LSM6DS3_XL_ODR_POWER_DOWN;
//	conf->xl.fs = LSM6DS3_XL_FS_2G;
//	conf->xl.cf = LSM6DS3_XL_CF_DISABLED;
//	conf->xl.alpf_bw = LSM6DS3_XL_ALPF_BW_AUTO;
//
//	// g default conf
//	conf->g.pm = LSM6DS3_G_PM_LOW_POWER_OR_NORMAL;
//	conf->g.odr = LSM6DS3_G_ODR_POWER_DOWN;
//	conf->g.fs = LSM6DS3_G_FS_250DPS;
//	conf->g.hpf = LSM6DS3_G_HPF_DISABLED;
//
//	// fifo default conf
//	conf->fifo.mode = LSM6DS3_FIFO_MODE_BYPASS;
//	conf->fifo.odr = LSM6DS3_FIFO_ODR_DISABLED;
//	conf->fifo.dec_g_set = LSM6DS3_FIFO_DECIMATION_IGNORE_DATA;
//	conf->fifo.dec_xl_set = LSM6DS3_FIFO_DECIMATION_IGNORE_DATA;
//	conf->fifo.dec_3rd_set = LSM6DS3_FIFO_DECIMATION_IGNORE_DATA;
//	conf->fifo.dec_4rth_set = LSM6DS3_FIFO_DECIMATION_IGNORE_DATA;
    // xl default conf
    conf->xl.pm = LSM6DS3_XL_PM_HIGH_PERFORMANCE;
    conf->xl.odr = LSM6DS3_XL_ODR_104_HZ;
    conf->xl.fs = LSM6DS3_XL_FS_8G;
    conf->xl.cf = LSM6DS3_XL_CF_DISABLED;
    conf->xl.alpf_bw = LSM6DS3_XL_ALPF_BW_AUTO;

    // g default conf
    conf->g.pm = LSM6DS3_G_PM_HIGH_PERFORMANCE;
    conf->g.odr = LSM6DS3_G_ODR_104_HZ;
    conf->g.fs = LSM6DS3_G_FS_1000DPS;
    conf->g.hpf = LSM6DS3_G_HPF_CUTOFF_0_0081_HZ;

    // fifo default conf
    conf->fifo.mode = LSM6DS3_FIFO_MODE_BYPASS;
    conf->fifo.odr = LSM6DS3_FIFO_ODR_DISABLED;
    conf->fifo.dec_g_set = LSM6DS3_FIFO_DECIMATION_IGNORE_DATA;
    conf->fifo.dec_xl_set = LSM6DS3_FIFO_DECIMATION_IGNORE_DATA;
    conf->fifo.dec_3rd_set = LSM6DS3_FIFO_DECIMATION_IGNORE_DATA;
    conf->fifo.dec_4rth_set = LSM6DS3_FIFO_DECIMATION_IGNORE_DATA;
}

/*
static int lsm6ds3_halt( struct lsm6ds3_dev_s *priv)
{
    int rc = OK;
    uint8_t reg_ctrl2;
    uint8_t reg_ctrl1;
    uint8_t reg_fifo_ctrl5 = 0x00;

    // first of all read all configuration registers to keep any unchanged bits
    rc = lsm6ds3_read_regn(priv, LSM6DS3_CTRL2G_REGADDR, &reg_ctrl2, 1);
    if (rc < 0)
        return rc;

    rc = lsm6ds3_read_regn(priv, LSM6DS3_CTRL1XL_REGADDR, &reg_ctrl1, 1);
    if (rc < 0)
        return rc;

    // we wont read fifo ctrl5 since there is no bits to spare

    reg_ctrl2 = LSM6DS3_SET_BITS(reg_ctrl2, LSM6DS3_CTRL2G_ODR_G, LSM6DS3_G_ODR_POWER_DOWN);
    reg_ctrl2 &= ~LSM6DS3_CTRL2G_RESEVED_MSK;

    reg_ctrl1 = LSM6DS3_SET_BITS(reg_ctrl1, LSM6DS3_CTRL1XL_ODR_XL, LSM6DS3_XL_ODR_POWER_DOWN);
    reg_ctrl1 &= ~LSM6DS3_CTRL1XL_RESEVED_MSK;

    reg_fifo_ctrl5 = LSM6DS3_SET_BITS(reg_fifo_ctrl5, LSM6DS3_FIFOCTRL5_FIFO_ODR,
            LSM6DS3_FIFO_ODR_DISABLED);
    reg_fifo_ctrl5 = LSM6DS3_SET_BITS(reg_fifo_ctrl5, LSM6DS3_FIFOCTRL5_FIFO_MODE,
            LSM6DS3_FIFO_MODE_BYPASS);
    reg_fifo_ctrl5 &= ~LSM6DS3_FIFOCTRL5_RESERVED_MSK;

    rc = lsm6ds3_write_regn(priv, LSM6DS3_FIFOCTRL5_REGADDR, &reg_fifo_ctrl5, 1);
    if (rc < 0)
        return rc;

    priv->conf.fifo.mode = LSM6DS3_FIFO_MODE_BYPASS;
    priv->conf.fifo.odr = LSM6DS3_FIFO_ODR_DISABLED;

    rc = lsm6ds3_write_regn(priv, LSM6DS3_CTRL2G_REGADDR, &reg_ctrl2, 1);
    if (rc < 0)
        return rc;

    priv->conf.g.odr = LSM6DS3_G_ODR_POWER_DOWN;

    rc = lsm6ds3_write_regn(priv, LSM6DS3_CTRL1XL_REGADDR, &reg_ctrl1, 1);
    if (rc < 0)
        return rc;

    priv->conf.xl.odr = LSM6DS3_G_ODR_POWER_DOWN;

    return rc;
}
*/


int lsm6ds3_g_push_conf( const struct lsm6ds3_dev_s *priv,
         const struct lsm6ds3_g_conf_s * g_conf)
{
    int rc = OK;

    // first of all read all configuration registers to keep any unchanged bits
    uint8_t reg_ctrl7;
    uint8_t reg_ctrl4;
    uint8_t reg_ctrl2;

    rc = lsm6ds3_read_regn(priv, LSM6DS3_CTRL7G_REGADDR, &reg_ctrl7, 1);
    if (rc < 0)
        return rc;

    rc = lsm6ds3_read_regn(priv, LSM6DS3_CTRL4C_REGADDR, &reg_ctrl4, 1);
        if (rc < 0)
            return rc;

    rc = lsm6ds3_read_regn(priv, LSM6DS3_CTRL2G_REGADDR, &reg_ctrl2, 1);
    if (rc < 0)
        return rc;

    // odr
    reg_ctrl2 = LSM6DS3_SET_BITS(reg_ctrl2, LSM6DS3_CTRL2G_ODR_G, g_conf->odr);

    // fs
    const uint8_t fs_125dps = (g_conf->fs & 0x10) >> 4;
    const uint8_t fs_common = g_conf->fs & 0x0f;
    reg_ctrl2 = LSM6DS3_SET_BITS(reg_ctrl2, LSM6DS3_CTRL2G_FS125_G, fs_125dps);
    reg_ctrl2 = LSM6DS3_SET_BITS(reg_ctrl2, LSM6DS3_CTRL2G_FS_G, fs_common);

    // hpf
    const uint8_t hpf_enabled = (g_conf->hpf & 0x01) >> 4;
    const uint8_t hpf_common = (g_conf->hpf & 0x0f);
    reg_ctrl7 = LSM6DS3_SET_BITS(reg_ctrl7, LSM6DS3_CTRL7G_HP_G_EN, hpf_enabled);
    reg_ctrl7 = LSM6DS3_SET_BITS(reg_ctrl7, LSM6DS3_CTRL7G_HPCF_G, hpf_common);

    // pm
    uint8_t high_perf_disable;
    uint8_t sleep;
    if (g_conf->pm == LSM6DS3_G_PM_SLEEP)
    {
        high_perf_disable = 1;
        sleep = 1;
    }
    else if (g_conf->pm == LSM6DS3_G_PM_HIGH_PERFORMANCE)
    {
        high_perf_disable = 0;
        sleep = 0;
    }
    else
    {
        high_perf_disable = 1;
        sleep = 0;
    }

    reg_ctrl4 = LSM6DS3_SET_BITS(reg_ctrl4, LSM6DS3_CTRL4C_SLEEP_G, sleep);
    reg_ctrl7 = LSM6DS3_SET_BITS(reg_ctrl7, LSM6DS3_CTRL7G_G_HM_MODE, high_perf_disable);

    reg_ctrl7 &= ~LSM6DS3_CTRL7G_RESEVED_MSK;
    reg_ctrl4 &= ~LSM6DS3_CTRL4C_RESEVED_MSK;
    reg_ctrl2 &= ~LSM6DS3_CTRL2G_RESEVED_MSK;

    // odr settings must be writed last
    rc = lsm6ds3_write_regn(priv, LSM6DS3_CTRL7G_REGADDR, &reg_ctrl7, 1);
    if (rc < 0)
        return rc;

    rc = lsm6ds3_write_regn(priv, LSM6DS3_CTRL4C_REGADDR, &reg_ctrl4, 1);
    if (rc < 0)
        return rc;

    rc = lsm6ds3_write_regn(priv, LSM6DS3_CTRL2G_REGADDR, &reg_ctrl2, 1);
    if (rc < 0)
        return rc;


    return rc;
}


int lsm6ds3_xl_push_conf( const struct lsm6ds3_dev_s *priv,
         const struct lsm6ds3_xl_conf_s * xl_conf)
{
    int rc = OK;

    uint8_t ctrl1_reg;
    uint8_t ctrl4_reg;
    uint8_t ctrl6_reg;
    uint8_t ctrl8_reg;
    uint8_t ctrl10_reg;

    // first of all read all configuration registers to keep any unchanged bits
    rc = lsm6ds3_read_regn(priv, LSM6DS3_CTRL10C_REGADDR, &ctrl10_reg, 1);
    if (rc < 0)
        return rc;

    rc = lsm6ds3_read_regn(priv, LSM6DS3_CTRL8XL_REGADDR, &ctrl8_reg, 1);
    if (rc < 0)
        return rc;

    rc = lsm6ds3_read_regn(priv, LSM6DS3_CTRL6C_REGADDR, &ctrl6_reg, 1);
    if (rc < 0)
        return rc;

    rc = lsm6ds3_read_regn(priv, LSM6DS3_CTRL4C_REGADDR, &ctrl4_reg, 1);
    if (rc < 0)
        return rc;

    rc = lsm6ds3_read_regn(priv, LSM6DS3_CTRL1XL_REGADDR, &ctrl1_reg, 1);
    if (rc < 0)
        return rc;

    // now we can configure values
    ctrl1_reg = LSM6DS3_SET_BITS(ctrl1_reg, LSM6DS3_CTRL1XL_ODR_XL, xl_conf->odr);
    ctrl1_reg = LSM6DS3_SET_BITS(ctrl1_reg, LSM6DS3_CTRL1XL_FS_XL, xl_conf->fs);
    ctrl1_reg = LSM6DS3_SET_BITS(ctrl1_reg, LSM6DS3_CTRL1XL_BW_XL, (xl_conf->alpf_bw & 0x0f));

    ctrl4_reg = LSM6DS3_SET_BITS(ctrl4_reg, LSM6DS3_CTRL4C_XL_BW_SCAL_ODR, ((xl_conf->alpf_bw & 0x10) >> 4));

    ctrl6_reg = LSM6DS3_SET_BITS(ctrl6_reg, LSM6DS3_CTRL6C_XL_HM_MODE, xl_conf->pm);

    // most significant "quartet" indicates which filter are used
    // and whether filter used at all
    // less significant "quartet" indicates selected filter parameters

    const uint8_t cf_filter_enabled = ((xl_conf->cf & 0x20) >> 5);
    const uint8_t hp_slope_enabled = ((xl_conf->cf & 0x10) >> 4);
    const uint8_t filter_params = (xl_conf->cf & 0x03);

    if (cf_filter_enabled)
    {
        ctrl8_reg = LSM6DS3_SET_BITS(ctrl8_reg, LSM6DS3_CTRL8XL_HP_SLOPE_XL_EN, hp_slope_enabled);
        ctrl8_reg = LSM6DS3_SET_BITS(ctrl8_reg, LSM6DS3_CTRL8XL_HPCF_XL, filter_params);
    }

    ctrl10_reg = LSM6DS3_SET_BITS(ctrl10_reg, LSM6DS3_CTRL10C_FUNC_EN, cf_filter_enabled);

    if (!cf_filter_enabled && priv->conf.g.odr == LSM6DS3_G_ODR_POWER_DOWN)
        warning("accelerometer cf filter should be enabled when device configured as acc only\n");

    ctrl1_reg  &= ~LSM6DS3_CTRL1XL_RESEVED_MSK;
    ctrl4_reg  &= ~LSM6DS3_CTRL4C_RESEVED_MSK;
    ctrl6_reg  &= ~LSM6DS3_CTRL6C_RESEVED_MSK;
    ctrl8_reg  &= ~LSM6DS3_CTRL8XL_RESEVED_MSK;
    ctrl10_reg &= ~LSM6DS3_CTRL10XL_RESERVED_MSK;

    // now write everything back to device, but odr settings must be passed last
    rc = lsm6ds3_write_regn(priv, LSM6DS3_CTRL10C_REGADDR, &ctrl10_reg, 1);
    if (rc < 0)
        return rc;

    rc = lsm6ds3_write_regn(priv, LSM6DS3_CTRL8XL_REGADDR, &ctrl8_reg, 1);
    if (rc < 0)
        return rc;

    rc = lsm6ds3_write_regn(priv, LSM6DS3_CTRL6C_REGADDR, &ctrl6_reg, 1);
    if (rc < 0)
        return rc;

    rc = lsm6ds3_write_regn(priv, LSM6DS3_CTRL4C_REGADDR, &ctrl4_reg, 1);
    if (rc < 0)
        return rc;

    rc = lsm6ds3_write_regn(priv, LSM6DS3_CTRL1XL_REGADDR, &ctrl1_reg, 1);
    if (rc < 0)
        return rc;

    return rc;
}


int lsm6ds3_gxl_pull( const struct lsm6ds3_dev_s *priv,
         struct lsm6ds3_raw_data_s * raw)
{
    int rc = 0;
    rc = lsm6ds3_read_regn(priv, LSM6DS3_OUTXLG_REGADDR, (uint8_t*)raw, sizeof(*raw));
    return rc;
}


int lsm6ds3_fifo_push_conf( const struct lsm6ds3_dev_s *priv,
         const struct lsm6ds3_fifo_conf_s * fifo_conf)
{
    int rc = OK;

    uint8_t reg_fifo_ctrl[5] = { 0x00 };

    // we won`t read almost anything from sensor,
    // because we want to override every bit in chosen registers

    // if fifo is disabled, then just disable it
    if (fifo_conf->odr == LSM6DS3_FIFO_ODR_DISABLED)
    {
        // its assumed that fifo is halted prior to this call, sooo
        return OK;
    }

    // so fifo is not disabled, we need to configure EVERYTHING

    // treshold
    const uint8_t treshold_lo = fifo_conf->treshold & 0xFF;
    const uint8_t treshold_hi = fifo_conf->treshold >> 8;

    reg_fifo_ctrl[0] = LSM6DS3_SET_BITS(reg_fifo_ctrl[0], LSM6DS3_FIFOCTRL1_FTH0, treshold_lo);
    reg_fifo_ctrl[1] = LSM6DS3_SET_BITS(reg_fifo_ctrl[1], LSM6DS3_FIFOCTRL2_FTH8, treshold_hi);

    // decimation of everything
    reg_fifo_ctrl[2] = LSM6DS3_SET_BITS(reg_fifo_ctrl[2], LSM6DS3_FIFOCTRL3_DEC_FIFO_GYRO,
            fifo_conf->dec_g_set);
    reg_fifo_ctrl[2]= LSM6DS3_SET_BITS(reg_fifo_ctrl[2], LSM6DS3_FIFOCTRL3_DEC_FIFO_XL,
            fifo_conf->dec_g_set);

    reg_fifo_ctrl[3] = LSM6DS3_SET_BITS(reg_fifo_ctrl[3], LSM6DS3_FIFOCTRL4_DEC_DS3_FIFO,
            fifo_conf->dec_3rd_set);
    reg_fifo_ctrl[3] = LSM6DS3_SET_BITS(reg_fifo_ctrl[3], LSM6DS3_FIFOCTRL4_DEC_DS4_FIFO,
            fifo_conf->dec_4rth_set);

    // mode and odr
    reg_fifo_ctrl[4] = LSM6DS3_SET_BITS(reg_fifo_ctrl[4], LSM6DS3_FIFOCTRL5_FIFO_MODE,
            fifo_conf->mode);
    reg_fifo_ctrl[4] = LSM6DS3_SET_BITS(reg_fifo_ctrl[4], LSM6DS3_FIFOCTRL5_FIFO_ODR,
            fifo_conf->odr);


    reg_fifo_ctrl[0] &= ~LSM6DS3_FIFOCTRL1_RESERVED_MSK;
    reg_fifo_ctrl[1] &= ~LSM6DS3_FIFOCTRL2_RESERVED_MSK;
    reg_fifo_ctrl[2] &= ~LSM6DS3_FIFOCTRL3_RESERVED_MSK;
    reg_fifo_ctrl[3] &= ~LSM6DS3_FIFOCTRL4_RESERVED_MSK;
    reg_fifo_ctrl[4] &= ~LSM6DS3_FIFOCTRL5_RESERVED_MSK;


    // write all of them in batch
    rc = lsm6ds3_write_regn(priv, LSM6DS3_FIFOCTRL1_REGADDR, reg_fifo_ctrl, sizeof(reg_fifo_ctrl));

    return rc;
}


int lsm6ds3_fifo_pull_status( const struct lsm6ds3_dev_s *priv,
         struct lsm6ds3_fifo_status_s * status)
{
    int rc = OK;

    uint8_t reg_fifostatus[4];

    // read all of status regs in batch
    rc = lsm6ds3_read_regn(priv, LSM6DS3_FIFOSTATUS1_REGADDR, reg_fifostatus, sizeof(reg_fifostatus));
    if (rc < 0)
        return rc;

    const uint8_t samples_count_lo = LSM6DS3_GET_BITS(reg_fifostatus[0], LSM6DS3_FIFOSTATUS1_DIFF_FIFO0);
    const uint8_t samples_count_hi = LSM6DS3_GET_BITS(reg_fifostatus[1], LSM6DS3_FIFOSTATUS2_DIFF_FIFO8);

    const uint8_t pattern_lo = LSM6DS3_GET_BITS(reg_fifostatus[2], LSM6DS3_FIFOSTATUS3_FIFOPATTERN0);
    const uint8_t pattern_hi = LSM6DS3_GET_BITS(reg_fifostatus[3], LSM6DS3_FIFOSTATUS4_FIFOPATTERN8);

    status->samples_count16 = ((uint16_t)samples_count_hi << 8) | samples_count_lo;
    status->pattern_value = ((uint16_t)pattern_hi << 8) | pattern_lo;
    status->flags = reg_fifostatus[1] & LSM6DS3_FIFOSTATUS2_FLAGS_MSK;

    return rc;
}


ssize_t lsm6ds3_fifo_pull_data( const struct lsm6ds3_dev_s * priv,
         uint16_t * buffer, size_t buffersize16, size_t size_factor16)
{
    int rc = OK;
    //DEBUGASSERT(buffer != NULL);

    if (buffersize16 == 0)
        return 0;

    // how much data is available on device?
    uint16_t samples_count16;
    struct lsm6ds3_fifo_status_s fifo_status;
    rc = lsm6ds3_fifo_pull_status(priv, &fifo_status);
    if (rc < 0)
        return rc;

    samples_count16 = fifo_status.samples_count16;

    // how much data will we read
    uint16_t readout_count16 = LSM6DS3_MIN(buffersize16, samples_count16);

    // round down readout to size factor
    readout_count16 = (readout_count16 / size_factor16) * size_factor16;
    //sninfo("bs16: %d, sc16: %d, rd16: %d\n", buffersize16, samples_count16, readout_count16);
    if (0 == readout_count16)
        return -EAGAIN;

    // read it!
    rc = lsm6ds3_read_regn(priv, LSM6DS3_FIFO_DATA_OUT_L_REGADDR, (uint8_t*)buffer,
            readout_count16 * sizeof(uint16_t));
    if (rc < 0)
        return rc;

    return rc;
}

int lsm6ds3_register_spi(struct lsm6ds3_dev_s * config, SPI_HandleTypeDef* bus)
{

	struct lsm6ds3_dev_s *priv = config;
    int rc;

    /* Sanity check */
    assert(priv != 0);
    assert(bus != 0);

    priv->setup_conf.iface.spi.bus = bus;
    priv->_do_read_regn = lsm6ds3_do_read_regn_spi;
    priv->_do_write_regn = lsm6ds3_do_write_regn_spi;
    priv->readmode = LSM6DS3_READMODE_SCALED;

    // reset the sensor
    rc = lsm6ds3_sw_reset(priv);
    if (rc < 0)
    {
        snerr("can`t reset device: %d\n", rc);
        return rc;
    }


    // checking whoami register
    uint8_t reg_whoami;
    rc = lsm6ds3_read_regn(priv, LSM6DS3_WHOAMI_REGADDR, &reg_whoami, 1);
    if (rc < 0)
    {
        snerr("can`t get whoami reg value: %d\n");
        return rc;
    }

    if (reg_whoami != LSM6DS3_WHOAMI_REGVAL)
    {
        snerr("who_am_i value is wrong: 0x%02X, while 0x%02X expected\n", reg_whoami, LSM6DS3_WHOAMI_REGVAL);
        return -ENODEV;
    }

    sninfo("INFO: LMD6DS3 driver loaded sucessfully\n");

    return OK;
}

int lsm6ds3_push_conf(struct lsm6ds3_dev_s *handler)
{
	int rc = 0;
	rc |= lsm6ds3_fifo_push_conf(handler, &handler->conf.fifo);
	rc |= lsm6ds3_g_push_conf(handler, &handler->conf.g);
	rc |= lsm6ds3_xl_push_conf(handler, &handler->conf.xl);
	return rc;
}

