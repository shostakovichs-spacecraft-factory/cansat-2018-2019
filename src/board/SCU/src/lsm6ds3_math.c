/*
 * lsm6ds3_usr.c
 *
 *  Created on: 23 июл. 2018 г.
 *      Author: snork
 */

#include "lsm6ds3.h"
#include <assert.h>
#include <stdlib.h>


#define LSM6DS3_STANDARD_G_VALUE ((lsm6ds3_float_t)9.80665)

// пересчет из попугаев в м/c**2
void lsm6ds3_scale_xl(const struct lsm6ds3_xl_conf_s * conf, int16_t * in, lsm6ds3_float_t * out, size_t count)
{
    // все довольно просто. цена бита так и считается - берем размах и делим на количество значений
    lsm6ds3_float_t fs_range;

    switch (conf->fs)
    {
    case LSM6DS3_XL_FS_2G:  fs_range =  4 * LSM6DS3_STANDARD_G_VALUE; break;
    case LSM6DS3_XL_FS_4G:  fs_range =  8 * LSM6DS3_STANDARD_G_VALUE; break;
    case LSM6DS3_XL_FS_8G:  fs_range = 16 * LSM6DS3_STANDARD_G_VALUE; break;
    case LSM6DS3_XL_FS_16G: fs_range = 32 * LSM6DS3_STANDARD_G_VALUE; break;
    default:
        assert(0);
        fs_range = 0;
    };

    lsm6ds3_float_t lsb_value = fs_range / (lsm6ds3_float_t)0x10000 ;

    for (size_t i = 0; i < count; i++)
        out[i] = in[i] * lsb_value;
}


void lsm6ds3_scale_g(const struct lsm6ds3_g_conf_s * conf, int16_t * in, lsm6ds3_float_t * out, size_t count)
{
    // все довольно просто. цена бита так и считается - берем размах и делим на количество значений
    lsm6ds3_float_t fs_range;

    switch (conf->fs)
    {
    case LSM6DS3_G_FS_125DPS:  fs_range =  125; break;
    case LSM6DS3_G_FS_250DPS:  fs_range =  250; break;
    case LSM6DS3_G_FS_500DPS:  fs_range =  500; break;
    case LSM6DS3_G_FS_1000DPS: fs_range = 1000; break;
    case LSM6DS3_G_FS_2000DPS: fs_range = 2000; break;
    default:
        assert(0);
        fs_range = 0;
    };

    lsm6ds3_float_t lsb_value = fs_range / (lsm6ds3_float_t)0x10000 * 2 ;

    for (size_t i = 0; i < count; i++)
    {
        out[i] = in[i] * lsb_value;
    }
}

