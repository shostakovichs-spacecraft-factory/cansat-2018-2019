/*
 * ina219.c
 *
 *  Created on: 18 марта 2017 г.
 *      Author: developer
 */
#include <stdlib.h>
#include <stdbool.h>

#include <stdio.h>

#include <stm32f10x.h>

#include "ina219.h"
#include "i2c.h"


#ifdef INA219_FLT_DOUBLE
#define INA219_FLOAT(x) x
#else
#define INA219_FLOAT(x) x##f
#endif


#define INA219_SET_BITS(reg_data, bitname, data) \
                ((reg_data & ~(bitname##_MSK)) | \
                ((data << bitname##_POS) & bitname##_MSK))

#define INA219_GET_BITS(reg_data, bitname)  ((reg_data & (bitname##_MSK)) >> \
                            (bitname##_POS))

#define INA219_CFGREG_ADDR         (0x00)

#define INA219_CFGREG__RESET_POS   (15)
#define INA219_CFGREG__RESET_MSK    (0x0001 << 15)

#define INA219_CFGREG__BRNG_POS    (13)
#define INA219_CFGREG__BRNG_MSK    (0x0001 << 13)

#define INA219_CFGREG__PG_POS      (11)
#define INA219_CFGREG__PG_MSK      (0x0003 << 11)

#define INA219_CFGREG__BADC_POS    (7)
#define INA219_CFGREG__BADC_MSK    (0x000f << 7)

#define INA219_CFGREG__SADC_POS    (3)
#define INA219_CFGREG__SADC_MSK    (0x000f << 3)

#define INA219_CFGREG__MODE_POS    (0)
#define INA219_CFGREG__MODE_MSK    (0x0007 << 0)


#define INA219_SHUNTVREG_ADDR      (0x01)


#define INA219_BUSVREG_ADDR        (0x02)

#define INA219_BUSVREG__BUSV_POS   (3)
#define INA219_BUSVREG__BUSV_MSK   (0x1fff << 3)

#define INA219_BUSVREG__CNVR_POS   (1)
#define INA219_BUSVREG__CNVR_MSK   (0x0001 << 1)

#define INA219_BUSVREG__OVF_POS    (0)
#define INA219_BUSVREG__OVF_MSK    (0x0001 << 0)


#define INA219_POWERREG_ADDR       (0x03)


#define INA219_CURRENTREG_ADDR     (0x04)


#define INA219_CALREG_ADDR         (0x05)
// формально тут следует написать, что CALREG имеет поле CAL, которые начинается с 1ого бита
// а не с нулевого, но это настолько частный случай, что не будем этим заниматься -
// опишем в коде как << 1



//! Запись одного регистра ины в I2C шину
static int _write_reg(ina219_t * device, uint8_t reg_addr, uint16_t reg_value)
{
    int error;
    // помним, что ина работает в big_endian, а мы в little
    uint8_t package[] = {reg_addr, reg_value >> 8, reg_value & 0xFF };

    error = i2c_write(device->bus, device->address, package, sizeof(package));
    return error;
}


//! Чтение регистра ины из I2C шины
/*! К сожалению ина не умеет читать несколько регистров за раз */
static int _read_reg(ina219_t * device, uint8_t reg_addr, uint16_t * reg_value)
{
    int error;
    error = i2c_write(device->bus, device->address, &reg_addr, sizeof(reg_addr));
    if (error)
        return error;

    uint16_t raw_reg_value;
    error = i2c_read(device->bus, device->address, &raw_reg_value, sizeof(raw_reg_value));

    // помним, что ина работает в big_endian, а мы в little
    *reg_value = (raw_reg_value >> 8) | (raw_reg_value << 8);
    *reg_value = raw_reg_value;
    return error;
}


//! Построение значения калибровочного регистра из его базовых значений
static uint16_t _make_cal_reg(ina219_float_t current_lsb, ina219_float_t shunt_r)
{
    // Если что-то задано по нулям, то калибровки не будет
    if (current_lsb == INA219_FLOAT(0.0) || shunt_r == INA219_FLOAT(0.0))
        return 0x00;

    // волшебные цифры из даташита
    const ina219_float_t calib = INA219_FLOAT(0.04096)/(current_lsb * shunt_r);
    return ((uint16_t)calib) << 1;
    // << 1 так как нулевой бит регистра резервирован, а фактическое значение идет с бита 1
}


//! Построение значения cfg регистра из структуры конфигурации
static uint16_t _make_cfg_reg(const ina219_cfg_t * cfg)
{
    uint16_t retval = 0;

    retval = INA219_SET_BITS(retval, INA219_CFGREG__BRNG, cfg->bus_range);
    retval = INA219_SET_BITS(retval, INA219_CFGREG__PG, cfg->shunt_range);
    retval = INA219_SET_BITS(retval, INA219_CFGREG__BADC, cfg->bus_res);
    retval = INA219_SET_BITS(retval, INA219_CFGREG__SADC, cfg->shunt_res);
    retval = INA219_SET_BITS(retval, INA219_CFGREG__MODE, cfg->mode);

    return retval;
}


//! нарезка значения "первичных" регистров на "исходные" данные
inline static void _slice_prim_data(const uint16_t * primregs, ina219_primary_data_t * primdata)
{
    // тут нужно хитро. нужно скопировать бфайты из uint16_t так, чтобы они воспринимались
    // как int16_t
    uint16_t * const uintptr = (uint16_t *)&primdata->shuntv;
    *uintptr = primregs[0];

    const uint16_t busvreg = primregs[1];
    primdata->busv = INA219_GET_BITS(busvreg , INA219_BUSVREG__BUSV);
    primdata->cnvr = INA219_GET_BITS(busvreg , INA219_BUSVREG__CNVR);
    primdata->ovf = INA219_GET_BITS(busvreg, INA219_BUSVREG__OVF);

}


//! нарезка значений "расчетных" регистров на "расчетные" данные
inline static void _slice_sec_data(const uint16_t * secregs, ina219_secondary_data_t * secdata)
{
    // все очень просто
    secdata->power = secregs[0];

    // тут нужно хитро. нужно скопировать бфайты из uint16_t так, чтобы они воспринимались
    // как int16_t
    uint16_t * const uintptr = (uint16_t *)&secdata->current;
    *uintptr = secregs[1];
}



void ina219_load_default_cfg(ina219_cfg_t * cfg)
{
    cfg->bus_range = INA219_BUS_RANGE_32V;
    cfg->bus_res = INA219_ADC_RES_12_BIT_OVS_1;

    cfg->shunt_range = INA219_SHUNT_RANGE_320MV;
    cfg->shunt_res = INA219_ADC_RES_12_BIT_OVS_1;

    cfg->mode = INA219_MODE_SHUNT_AND_BUS_CONT;

    cfg->shunt_r = 0.0f;
    cfg->current_lsb = 0.0f;
}


void ina219_init(ina219_t * device, I2C_TypeDef * bus, uint8_t i2c_addr)
{
    device->bus = bus;
    device->address = i2c_addr;
    ina219_load_default_cfg(&device->cfg);
}


void ina219_deinit(ina219_t * device)
{
    (void)device;
    // нечего делать..,
}


int ina219_sw_reset(ina219_t * device)
{
    uint16_t cfgreg = 0;
    cfgreg = INA219_SET_BITS(cfgreg, INA219_CFGREG__RESET, 1);
    return _write_reg(device, INA219_CFGREG_ADDR, cfgreg);
}


int ina219_set_cfg(ina219_t * device, const ina219_cfg_t * cfg)
{
    uint16_t cfgreg = _make_cfg_reg(cfg);
    int error = _write_reg(device, INA219_CFGREG_ADDR, cfgreg);
    if (error)
        return error;

    device->cfg = *cfg;
    // FIXME: не все копировать

    uint16_t calreg = _make_cal_reg(cfg->current_lsb, cfg->shunt_r);
    error = _write_reg(device, INA219_CALREG_ADDR, calreg);
    if (error)
        return error;


    device->cfg.current_lsb = cfg->current_lsb;
    device->cfg.shunt_r = cfg->shunt_r;

    return 0;
}


const ina219_cfg_t * ina219_get_cfg(ina219_t * device)
{
    return &device->cfg;
}


int ina219_set_mode(ina219_t * device, const ina219_mode_t mode)
{
    // запоминаем старый режим, на случай если что-то пойдет не так
    const ina219_mode_t old_mode = device->cfg.mode;
    // пробуем обновить режим в дескрипторе
    device->cfg.mode = mode;

    // пробуем зашить новый конфиг регистр
    uint16_t cfgreg = _make_cfg_reg(&device->cfg);
    int error = _write_reg(device, INA219_CFGREG_ADDR, cfgreg);

    // Если что-то пошло не так - восстанавливаем старый режим
    // он наиболее соответствует действительности
    if (error)
        device->cfg.mode = old_mode;

    return error;
}


int ina219_read_primary(ina219_t * device, ina219_primary_data_t * data)
{
    uint16_t raw_reg_data[2];
    int error = _read_reg(device, INA219_SHUNTVREG_ADDR, &raw_reg_data[0]);
    if (error)
        return error;

    error = _read_reg(device, INA219_BUSVREG_ADDR, &raw_reg_data[1]);
    if (error)
        return error;


    _slice_prim_data(raw_reg_data, data);
    return 0;
}


int ina219_read_secondary(ina219_t * device, ina219_secondary_data_t * data)
{
    uint16_t raw_reg_data[2];
    int error = _read_reg(device, INA219_POWERREG_ADDR, &raw_reg_data[0]);
    if (error)
        return error;

    error = _read_reg(device, INA219_CURRENTREG_ADDR, &raw_reg_data[1]);
        if (error)
            return error;


    _slice_sec_data(raw_reg_data, data);
    return 0;
}


int ina219_read_all(ina219_t * device, ina219_primary_data_t * prim_data,
        ina219_secondary_data_t * secondary_data)
{
    int error = ina219_read_primary(device, prim_data);
    if (error)
        return error;

    error = ina219_read_secondary(device, secondary_data);
    return error;
}

int ina219_read_reg(ina219_t * device, uint8_t regaddr, uint16_t * regdata)
{
    return _read_reg(device, regaddr, regdata);
}

