/*
 * ina219.h
 *
 *  Created on: 18 марта 2017 г.
 *      Author: developer
 */

#ifndef INA219_H_
#define INA219_H_

#include <stdint.h>
#include <stdbool.h>
#include <stm32f10x.h>


//! Тип с плавающей точкой
#ifdef INA219_FLT_DOUBLE
	typedef double ina219_float_t;
#else
	typedef float ina219_float_t;
#endif


//! Значение LSB для регистра с напряжением на шунте
#define INA219_SHUNTV_LSB_MKV (10)

//! Значение LSB для регистра для напряжения на шине питанмия
#define INA219_BUSV_LSB_MV (4)

//! Набор допустимых I2C адресов для ina219
/*! Адреса выровнены по 0 биту без учета места под RW бит I2C */
// TODO: перегнать значения в хексы, написать комментарии
typedef enum
{
	INA219_I2CADDR_A1_GND_A0_GND = 0b1000000,
	INA219_I2CADDR_A1_GND_A0_VSP = 0b1000001,
	INA219_I2CADDR_A1_GND_A0_SDA = 0b1000010,
	INA219_I2CADDR_A1_GND_A0_SCL = 0b1000011,

	INA219_I2CADDR_A1_VSP_A0_GND = 0b1000100,
	INA219_I2CADDR_A1_VSP_A0_VSP = 0b1000101,
	INA219_I2CADDR_A1_VSP_A0_SDA = 0b1000110,
	INA219_I2CADDR_A1_VSP_A0_SCL = 0b1000111,

	INA219_I2CADDR_A1_SDA_A0_GND = 0b1001000,
	INA219_I2CADDR_A1_SDA_A0_VSP = 0b1001001,
	INA219_I2CADDR_A1_SDA_A0_SDA = 0b1001010,
	INA219_I2CADDR_A1_SDA_A0_SCL = 0b1001011,

	INA219_I2CADDR_A1_SCL_A0_GND = 0b1001100,
	INA219_I2CADDR_A1_SCL_A0_VSP = 0b1001101,
	INA219_I2CADDR_A1_SCL_A0_SDA = 0b1001110,
	INA219_I2CADDR_A1_SCL_A0_SCL = 0b1001111,

} ina219_i2c_addr_t;


//! Диапазон измерения напряжения на шине питания
typedef enum
{
	INA219_BUS_RANGE_16V    = 0x00000,
	INA219_BUS_RANGE_32V    = 0x00001,
} ina219_bus_range_t;


//! Делитель для измерения напражения на шунте
/*! Задает диапазон измерения напряжения на шунте
	На сырые данные влияет слабо, но позволяет бороться с шумами */
typedef enum
{
	INA219_SHUNT_RANGE_40MV    = 0x0000,   //!< делитель == /1, диапазон 40 мВ
	INA219_SHUNT_RANGE_80MV    = 0x0001,   //!< делитель == /2, диапазон 80 мВ
	INA219_SHUNT_RANGE_160MV   = 0x0002,   //!< делитель == /4, диапазон 160 мВ
	INA219_SHUNT_RANGE_320MV   = 0x0003,   //!< делитель == /8, диапазон 320 мВ
} ina219_shunt_range_t;

//! Разрешение АЦП / количество перезамеров значений АЦП
/*! Этой опцией можно достигать различных компромиисов между точностью/скорость измерения
	Для самые малых времен измерения можно регулирать разрешение АЦП
	Для большей "точности" на максимальном разрешении АЦП можно использовать усреднение
	с нескольких замеров */
typedef enum
{
	// для последующих 4ех значений бит 2 (считая с 0) может принимать любое значение
	INA219_ADC_RES_9_BIT_OVS_1 = 0x0000,    //! Разрешение АЦП 9 бит,  нет уср., время замера 84 мкс
	INA219_ADC_RES_10_BIT_OVS_1 = 0x0001,   //! Разрешение АЦП 10 бит, нет уср., время замера 148 мкс
	INA219_ADC_RES_11_BIT_OVS_1 = 0x0002,   //! Разрешение АЦП 11 бит, нет уср., время замера 276 мкс
	INA219_ADC_RES_12_BIT_OVS_1 = 0x0003,   //! Разрешение АЦП 12 бит, нет уср., время замера 532 мкс
	// для INA219_ADC_RES_12_BIT_OVS_1 так же допустимо значение 0x0008
	INA219_ADC_RES_12_BIT_OVS_2 = 0x0009,   //! Разрешение АЦП 12 бит, уср. с 2 замеров, время замера 1.06 мс
	INA219_ADC_RES_12_BIT_OVS_4 = 0x000A,   //! Разрешение АЦП 12 бит, уср. с 4 замеров, время замера 2.13 мс
	INA219_ADC_RES_12_BIT_OVS_8 = 0x000B,   //! Разрешение АЦП 12 бит, уср. с 8 замеров, время замера 4.26 мс
	INA219_ADC_RES_12_BIT_OVS_16 = 0x000C,  //! Разрешение АЦП 12 бит, уср. с 16 замеров, время замера 8.51 мс
	INA219_ADC_RES_12_BIT_OVS_32 = 0x000D,  //! Разрешение АЦП 12 бит, уср. с 32 замеров, время замера 17.02 мс
	INA219_ADC_RES_12_BIT_OVS_64 = 0x000E,  //! Разрешение АЦП 12 бит, уср. с 64 замеров, время замера 34.05 мс
	INA219_ADC_RES_12_BIT_OVS_128 = 0x000F, //! Разрешение АЦП 12 бит, уср. с 128 замеров, время замера 68.10 мс
} ina219_adc_res_t;


//! Режим работы устройства
typedef enum
{
	INA219_MODE_POWER_DOWN = 0x0000,            //!< Устройство выключено
	INA219_MODE_SHUNT_TRIG = 0x0001,            //!< Замер напряжения шунта по запросу
	INA219_MODE_BUS_TRIG = 0x0002,              //!< Замер напряжения на шине питания по запросу
	INA219_MODE_SHUNT_AND_BUS_TRIG = 0x0003,    //!< Замер напряжения на шунте и шине питания по запросу
	INA219_MODE_ADC_OFF = 0x0004,               //!< Ацп выключено (более "мягкий" power down)
	INA219_MODE_SHUNT_CONT = 0x0005,            //!< Замер напряжения на шунте постоянно
	INA219_MODE_BUS_CONT = 0x0006,              //!< Замер напряжения на шине питания постоянно
	INA219_MODE_SHUNT_AND_BUS_CONT = 0x0007,    //!< Замер напряжения на шунте и на шине питания постоянно
} ina219_mode_t;


//! Конфигурация устройства
typedef struct
{
	ina219_bus_range_t bus_range;       //!< Диапазон измерения напряжения шине питания
	ina219_adc_res_t bus_res;           //!< Настройки АЦП при измерении напряжения на шине питания

	ina219_shunt_range_t shunt_range;   //!< Диапазон измерения напряжения на шунте
	ina219_adc_res_t shunt_res;         //!< Настройки АЦП при измерении напряжения на шине

	ina219_mode_t mode;                 //!< Режим работы датчика

	/*  Далее идут значения, необходимые для расчета калидробовчного регистра
		Калибровочный регистр необходим для расчета значений тока и мощности
		Без установки этого регистра эти значения не рассчитываются

		current_lsb - "вес" значения самого младшего бита регистра current
		power_lsb - "вес" значения самого младешго бита регистра power, автоматически
		принимает значение = 20*current_lsb
		shunt_r - сопротивление шунта (Ом)

		Наилучшее разрешение достигается, если выбирать значение current_lsb по формуле
		current_lsb = максимальный ожидаемый ток (А)/2**15

		Если shunt_r == 0.0 или current_lsb == 0.0 => калибровочный регистр программируется в 0x0000,
		что отключает расчеты тока и мощности */
	ina219_float_t shunt_r;
	ina219_float_t current_lsb;
} ina219_cfg_t;


//! Дескриптор устройства
/*! Поля дескриптора не предназначены для прямого доступа */
typedef struct
{
	I2C_TypeDef * bus;
	uint8_t address;
	ina219_cfg_t cfg;
} ina219_t;


//! Первичные данные с устройства в сыром виде
typedef struct
{
	//! Содержит напряжение на шунте c величиной LSB в 10мкВ (INA219_SHUNTV_LSB_MKV)
	int16_t shuntv;
	//! Содержит напряжение на шине питания с LSB в 4мВ (INA219_BUSV_LSB_MV)
	/*! Занимает не больше 13 бит */
	uint16_t busv;
	//! Флаг завершения преобразования.
	/*! Используется при замерах по заросу. Означает что все замеры и расчеты завершены */
	bool cnvr;
	//! Флаг арифтемтического переполнения при расчетах.
	/*! При значени в 1 показывает, что значения тока и мощности могут быть не верны */
	bool ovf;
} ina219_primary_data_t;


//! Рассчитанные устройством данные в сыром виде
typedef struct
{
	//! Ток через шунт устройства. Величина LSB задается при калибровке (ina219_set_cal)
	int16_t current;
	//! Мощность нагрузки на шине питания. Величина LSB задается при калибровке (ina219_set_cal)
	uint16_t power;
} ina219_secondary_data_t;


//! Загрузка в структуру конфига значений по-умолчанию
void ina219_load_default_cfg(ina219_cfg_t * cfg);


//! инициализация дескриптора устройства
void ina219_init(ina219_t * device, I2C_TypeDef * bus, uint8_t i2c_addr);

//! деинициализация дескриптора устройства
void ina219_deinit(ina219_t * device);


//! Программный reset устройства
/*! После резета следует подождать FIXME сколько времени) */
int ina219_sw_reset(ina219_t * device);

//! Запись калибровочного регистра
int ina219_set_cal(ina219_t * device, float current_lsb, float shunt_r);

//! Установка параметров конфигурации устойства
/*! И сохранение параметров в дескрипторе */
int ina219_set_cfg(ina219_t * device, const ina219_cfg_t * cfg);

//! Получение конфигурации из дескриптора (которая теоретически совпадает с фактической)
const ina219_cfg_t * ina219_get_cfg(ina219_t * device);

//! Устанавливает режим работы датчика
/*! Конфигурация при этом перезаписывается конфигурацеий из дескриптора.
	В целом этот вызов аналогичен ina219_set_cfg, но не пишет калибрационный регистр */
int ina219_set_mode(ina219_t * device, const ina219_mode_t mode);


//! чтение первичных данных с устройства в сыром виде
int ina219_read_primary(ina219_t * device, ina219_primary_data_t * data);

//! чтение рассчитанных данных с устройства в сыром виде
int ina219_read_secondary(ina219_t * device, ina219_secondary_data_t * data);

//! Чтение всех данных с устройства в сыром виде
int ina219_read_all(ina219_t * device, ina219_primary_data_t * prim_data,
		ina219_secondary_data_t * secondary_data);

int ina219_read_reg(ina219_t * device, uint8_t regaddr, uint16_t * regdata);


#endif /* INA219_H_ */
