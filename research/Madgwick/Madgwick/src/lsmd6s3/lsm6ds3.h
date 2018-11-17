#ifndef LSM6DS3_H_
#define LSM6DS3_H_

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#include "stm32f4xx_hal.h"

#include "stm32f4xx_hal_def.h"
#include "stm32f4xx_hal_i2c.h"

// Модуль для работы с датчиком STMicro LSM6DS3
/*
 * Модуль обеспечивает программный интерфейс управления дачтиком LSM6DS3 используя дескрипторы определенные
 * структурой lsm6d53_t
 * Такой подход обеспечивает возможность использования нескольких независимых устройств в одной программе
 * и позволяет использовать абстрактную среду передачи данных между МК и датчиком (SPI или I2C)
 */

// ==============================================================================
// Вспомогательные сущности модуля
// ==============================================================================
// Ошибки модуля (пока не определены)
typedef enum
{
   LMS6DS3_ERROR_NONE = 0,
} lms6ds3_error_t;


// Диапазон измерений гироскопа (градусы/с)
typedef enum
{
   LSM6DS3_GYRO_RANGE_125,
   LSM6DS3_GYRO_RANGE_245,
   LSM6DS3_GYRO_RANGE_500,
   LSM6DS3_GYRO_RANGE_1000,
   LSM6DS3_GYRO_RANGE_2000
} lsm6ds3_gyro_range_t;

// частота опроса гироскопа (Герц)
typedef enum
{
   LSM6DS3_GYRO_SRATE_12dot5,
   LSM6DS3_GYRO_SRATE_26,
   LSM6DS3_GYRO_SRATE_52,
   LSM6DS3_GYRO_SRATE_104,
   LSM6DS3_GYRO_SRATE_208,
   LSM6DS3_GYRO_SRATE_416,
   LSM6DS3_GYRO_SRATE_833,
   LSM6DS3_GYRO_SRATE_1660,
} lsm6ds3_gyro_srate_t;

// диапазон измерений акселерометра (g)
typedef enum
{
   LSM6DS3_ACCEL_RANGE_2,
   LSM6DS3_ACCEL_RANGE_4,
   LSM6DS3_ACCEL_RANGE_8,
   LSM6DS3_ACCEL_RANGE_16,
} lsm6ds3_accel_range_t;

// Частота опроса акселерометра (Герц)
typedef enum
{
   LSM6DS3_ACCEL_SRATE_12dot5,
   LSM6DS3_ACCEL_SRATE_26,
   LSM6DS3_ACCEL_SRATE_52,
   LSM6DS3_ACCEL_SRATE_104,
   LSM6DS3_ACCEL_SRATE_208,
   LSM6DS3_ACCEL_SRATE_416,
   LSM6DS3_ACCEL_SRATE_833,
   LSM6DS3_ACCEL_SRATE_1660,
   LSM6DS3_ACCEL_SRATE_3330,
   LSM6DS3_ACCEL_SRATE_6660,
} lsm6ds3_accel_srate_t;

// Полоса пропускания сглаживающего фильтра акселерометра (Герц)
typedef enum
{
   LSM6DS3_ACCEL_FILTER_BW_AUTO,     // Автоматически по частоте опроса
   LSM6DS3_ACCEL_FILTER_BW_400,
   LSM6DS3_ACCEL_FILTER_BW_200,
   LSM6DS3_ACCEL_FILTER_BW_100,
   LSM6DS3_ACCEL_FILTER_BW_50
} lsm6ds3_accel_filter_bw_t;

// Структура настроек
typedef struct lsm6d53_settings_t {
   //Temperature settings
   bool tempEnabled;

   //Gyro settings
   bool gyroEnabled;
   lsm6ds3_gyro_range_t gyroRange;
   lsm6ds3_gyro_srate_t gyroSampleRate;

   //Accelerometer settings
   bool accelEnabled;
   lsm6ds3_accel_range_t accelRange;
   lsm6ds3_accel_srate_t accelSampleRate;
   lsm6ds3_accel_filter_bw_t accelFilterBandWidth;

   //Non-basic mode settings
   uint8_t commMode;
} lsm6ds3_settings_t;

// дескриптор устройства. Позволяет обращаться к конрктетному устройству, в случае использования нескольких
// и обеспечивает абстракцию транспортного уровня (i2c/spi) от их аппаратной реализации в конкретном МК
// перед использованием все поля должны быть определены
typedef struct
{
   I2C_HandleTypeDef * bus;

   enum {
	   LSM6DS3_ADDRESS_LOW = 0xD4,
	   LSM6DS3_ADDRESS_HIGH = 0xD6
   } address;

   float acc_k, gyro_k;

   int gyro_precalibration_cycles;
   float gyro_calibration_coeffs[3];
} lsm6ds3_t;


// ==============================================================================
// Уровень доступа к регистрам
// ==============================================================================
// чтение одного регистра
// Параметры:
// - self -дескриптор устройста,
// - addr - адрес регистра
// - value_ptr - указатель на буфер данных регистра
// Возвращаемое значение - код ошибки функций чтения/записи/.. из дескриптора
int lsm6ds3_readRegister(lsm6ds3_t * self, uint8_t addr, uint8_t* value_ptr);

// чтение нескольких регистров
// Параметры:
// - self - дескриптор устройства
// - addr - адрес первого читаемого регистра
// - value_ptr - указатель на буфер для читаемых данных
// - count - количество читаемых регистров
// Возвращаемое значение - код ошибки функций чтения/записи/.. из дескриптора
int lsm6ds3_readRegisterRegion(lsm6ds3_t * self, uint8_t addr, uint8_t * value_ptr, uint8_t count);

// чтение пары регистров как шестнадцатибитного числа
// Параметры:
// - self - дескриптор устройства
// - addr - адрес первого регистра из пары
// - value_ptr - указатель на буфер для читаемых данных
// Возвращаемое значение - код ошибки функций чтения/записи/.. из дескриптора
inline static int lsm6ds3_readRegisterInt16(lsm6ds3_t * self, uint8_t addr, int16_t* value_ptr) {
   return lsm6ds3_readRegisterRegion(self, addr, (uint8_t*)value_ptr, 2);
}

// Запись регистра
// Параметры:
// - self - дескриптор устройства
// - addr - адрес регистра
// - value - записываемое значение
// Возвращаемое значение - код ошибки функций чтения/записи/.. из дескриптора
int lsm6ds3_writeRegister(lsm6ds3_t * self, uint8_t addr, uint8_t value);

// ==============================================================================
// Уровень управления базовыми функциями устройства
// ==============================================================================
// Настройка устройства
// Параметры
// - self - дескриптор устройства
// - settings - указатель на структуру с параметрами
// Возвращаемое значение - код ошибки функций чтения/записи/.. из дескриптора
int lsm6ds3_setup(lsm6ds3_t * self, lsm6ds3_settings_t * settings);

// Чтение сырых данных акселерометра по оси X
// Параметры:
// - self - дескриптор устройства
// - value_ptr - указатель на буффер для читаемых данных (должен вместить 1 int16_t)
// Возвращаемое значение - код ошибки функций чтения/записи/.. из дескриптора
int lsm6ds3_acc_read_raw_X(lsm6ds3_t * self, int16_t * value_ptr);
// Чтение сырых данных акселерометра по оси Y (аналогична lsm6ds3_acc_read_raw_X)
int lsm6ds3_acc_read_raw_Y(lsm6ds3_t * self, int16_t * value_ptr);
// Чтение сырых данных акселерометра по оси Z (аналогична lsm6ds3_acc_read_raw_X)
int lsm6ds3_acc_read_raw_Z(lsm6ds3_t * self, int16_t * value_ptr);

// чтение сырых данных акселерометра по всем трем осям
// Параметры
// - self - дескриптор устройства
// - values_ptr - указатель на буффер для читаемых данных. Должен вместить 3 int16_t. Данные по осям в буфере расположены в порядке XYZ
// Возвращаемое значение - код ошибки функций чтения/записи/.. из дескриптора
int lsm6ds3_acc_read_raw_XYZ(lsm6ds3_t * self, int16_t * values_ptr);

// Чтение сырых данных гироскопа по оси X (аналогична lsm6ds3_acc_read_raw_X)
int lsm6ds3_gyro_read_raw_X(lsm6ds3_t * self, int16_t * value_ptr);
// Чтение сырых данных гироскопа по оси Y (аналогична lsm6ds3_acc_read_raw_X)
int lsm6ds3_gyro_read_raw_Y(lsm6ds3_t * self, int16_t * value_ptr);
// Чтение сырых данных гироскопа по оси Z (аналогична lsm6ds3_acc_read_raw_X)
int lsm6ds3_gyro_read_raw_Z(lsm6ds3_t * self, int16_t * value_ptr);
// чтение сырых данных гироскопа по всем трем осям (аналогична lsm6ds3_acc_read_raw_XYZ
int lsm6ds3_gyro_read_raw_XYZ(lsm6ds3_t * self, int16_t * values_ptr);

// чтение сырых данных акселерометра и гироскопа за один проход
// Параметры
// - self - дескриптор устройства
// - values_ptr - указатель на буффер для читаемых данных.
//                буффер должен вмещать 6 int16_t. Данные по осям располагаются в буффере по порядку:
//                GYRO_X,GYRO_Y,GYRO_Z,ACC_X,ACC_Y,ACC_Z;
// Возвращаемое значение - код ошибки функций чтения/записи/.. из дескриптора
int lsm6ds3_acc_gyro_read_raw_all(lsm6ds3_t * self, int16_t * values_ptr);

// перевод из попугаев в mg
void lsm6ds3_acc_recalc(lsm6ds3_t * self, int16_t * parrots, float * not_parrots);

//перевод из попугаев в mdps
void lsm6ds3_gyro_recalc(lsm6ds3_t * self, int16_t * parrots, float * not_parrots);

//
void lsm6ds3_gyro_remove_static_error(lsm6ds3_t * self, float * data);

#endif /* LSM6DS3_H_ */



