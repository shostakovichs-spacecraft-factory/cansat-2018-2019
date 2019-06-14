/*
 * pcu_inahelpers.h
 *
 *  Created on: Jun 10, 2019
 *      Author: kirs
 */

#include <diag/Trace.h>

#include "ina219.h"

#include "delay.h"

#define INA_CURRENT_LSB	((ina219_float_t)(6.f/0x8000)) // считаем из расчета на 3 ампер максимум
#define INA_POWER_LSB	((ina219_float_t)(20*INA_CURRENT_LSB))

static int _ina_init(ina219_t * self, ina219_i2c_addr_t addr) {
	int error = 0;

	ina219_init(self, I2C1, addr);

	error = ina219_sw_reset(self);
	// подождем после резета
	delay(10);


	uint16_t cfgreg;
	error = ina219_read_reg(self, 0x00, &cfgreg);
	trace_printf("initial cfgreg: 0x%04"PRIX16", error: %d\n", cfgreg, error);

	ina219_cfg_t ina_cfg;
	ina_cfg.bus_range = INA219_BUS_RANGE_16V;
	ina_cfg.bus_res = INA219_ADC_RES_12_BIT_OVS_1;
	ina_cfg.shunt_range = INA219_SHUNT_RANGE_320MV;
	ina_cfg.shunt_res = INA219_ADC_RES_12_BIT_OVS_1;
	ina_cfg.mode = INA219_MODE_SHUNT_AND_BUS_CONT;

	ina_cfg.shunt_r = 0.1f; // 100 миллиом
	ina_cfg.current_lsb = INA_CURRENT_LSB;
	error = ina219_set_cfg(self, &ina_cfg);
	trace_printf("set_cfg error: %d\n", error);

	error = ina219_read_reg(self, 0x00, &cfgreg);
	trace_printf("setted cfgreg: 0x%04"PRIX16" , error: %d\n", cfgreg, error);

	return error;
}

// Current is given in amperes, power is in watts
static int _ina_read(ina219_t * self, float * current, float * power)
{
	ina219_secondary_data_t data;
	int error;

	error = ina219_read_secondary(self, &data);
	trace_printf("INA 219 read error %d\n", error);

	*current = data.current * INA_CURRENT_LSB;
	*power = data.power * INA_POWER_LSB;

	return error;
}
