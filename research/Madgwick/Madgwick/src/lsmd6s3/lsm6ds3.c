#include "../lsmd6s3/lsm6d53_defs.h"

#include "../lsmd6s3/lsm6ds3.h"

#include "diag/Trace.h"

// Запись результата операции в функцию error и переход на метку end в случае, если error != 0
#define SET_AND_GOTO_END_IF_ERROR(x) if (0 != (error = (x))) { goto end; }


// ========================================================================================
// ========================================================================================
int lsm6ds3_readRegister(lsm6ds3_t * self, uint8_t addr, uint8_t * value_ptr)
{
	return HAL_I2C_Mem_Read(self->bus, self->address, addr, I2C_MEMADD_SIZE_8BIT, value_ptr, 1, 10000);
}


int lsm6ds3_readRegisterRegion(lsm6ds3_t * self, uint8_t addr, uint8_t * value_ptr, uint8_t count)
{
	return HAL_I2C_Mem_Read(self->bus, self->address, addr, I2C_MEMADD_SIZE_8BIT, value_ptr, count, 10000);
}


int lsm6ds3_writeRegister(lsm6ds3_t * self, uint8_t offset, uint8_t dataToWrite)
{
   return HAL_I2C_Mem_Write(self->bus, self->address, offset, I2C_MEMADD_SIZE_8BIT, &dataToWrite, 1, 10000);
}


int lsm6ds3_setup(lsm6ds3_t * self, lsm6ds3_settings_t * settings)
{
   int error = LMS6DS3_ERROR_NONE;

   uint8_t regValue = 0;
   if (settings->accelEnabled)
   {
      switch (settings->accelFilterBandWidth)
      {
      case LSM6DS3_ACCEL_FILTER_BW_50:
         regValue |= LSM6DS3_ACC_GYRO_BW_XL_50Hz;
         break;
      case LSM6DS3_ACCEL_FILTER_BW_100:
         regValue |= LSM6DS3_ACC_GYRO_BW_XL_100Hz;
         break;
      case LSM6DS3_ACCEL_FILTER_BW_200:
         regValue |= LSM6DS3_ACC_GYRO_BW_XL_200Hz;
         break;
      case LSM6DS3_ACCEL_FILTER_BW_400: default:
         regValue |= LSM6DS3_ACC_GYRO_BW_XL_400Hz;
         break;
      }

      switch (settings->accelRange)
      {
      case LSM6DS3_ACCEL_RANGE_2:
         regValue |= LSM6DS3_ACC_GYRO_FS_XL_2g;
         self->acc_k = 0.061;
         break;
      case LSM6DS3_ACCEL_RANGE_4:
         regValue |= LSM6DS3_ACC_GYRO_FS_XL_4g;
         self->acc_k = 0.122;
         break;
      case LSM6DS3_ACCEL_RANGE_8:
         regValue |= LSM6DS3_ACC_GYRO_FS_XL_8g;
         self->acc_k = 0.244;
         break;
      case LSM6DS3_ACCEL_RANGE_16: default:
         regValue |= LSM6DS3_ACC_GYRO_FS_XL_16g;
         self->acc_k = 0.488;
         break;
      }

      switch (settings->accelSampleRate)
      {
      case LSM6DS3_ACCEL_SRATE_12dot5:
         regValue |= LSM6DS3_ACC_GYRO_ODR_XL_13Hz;
         break;
      case LSM6DS3_ACCEL_SRATE_26:
         regValue |= LSM6DS3_ACC_GYRO_ODR_XL_26Hz;
         break;
      case LSM6DS3_ACCEL_SRATE_52:
         regValue |= LSM6DS3_ACC_GYRO_ODR_XL_52Hz;
         break;
      case LSM6DS3_ACCEL_SRATE_104: default:
         regValue |= LSM6DS3_ACC_GYRO_ODR_XL_104Hz;
         break;
      case LSM6DS3_ACCEL_SRATE_208:
         regValue |= LSM6DS3_ACC_GYRO_ODR_XL_208Hz;
         break;
      case LSM6DS3_ACCEL_SRATE_416:
         regValue |= LSM6DS3_ACC_GYRO_ODR_XL_416Hz;
         break;
      case LSM6DS3_ACCEL_SRATE_833:
         regValue |= LSM6DS3_ACC_GYRO_ODR_XL_833Hz;
         break;
      case LSM6DS3_ACCEL_SRATE_1660:
         regValue |= LSM6DS3_ACC_GYRO_ODR_XL_1660Hz;
         break;
      case LSM6DS3_ACCEL_SRATE_3330:
         regValue |= LSM6DS3_ACC_GYRO_ODR_XL_3330Hz;
         break;
      case LSM6DS3_ACCEL_SRATE_6660:
         regValue |= LSM6DS3_ACC_GYRO_ODR_XL_6660Hz;
         break;
      }
   }
   trace_printf("L\n");
   SET_AND_GOTO_END_IF_ERROR(lsm6ds3_writeRegister(self, LSM6DS3_ACC_GYRO_CTRL1_XL, regValue));
   trace_printf("LA\n");
   // бит разрешающий автоматический выбор полосы пропускания для фильтра
   // прочитаем что там уже записано в девайсе
   SET_AND_GOTO_END_IF_ERROR(lsm6ds3_readRegister(self, LSM6DS3_ACC_GYRO_CTRL4_C, &regValue));
   trace_printf("LALA\n");
   // затрем нужный бит
   regValue &= ~((uint8_t)LSM6DS3_ACC_GYRO_BW_SCAL_ODR_ENABLED);
   // и если он нужен - выставим заново
   if (LSM6DS3_ACCEL_FILTER_BW_AUTO == settings->accelFilterBandWidth)
      regValue |= LSM6DS3_ACC_GYRO_BW_SCAL_ODR_ENABLED;

   // запишем обратно
   SET_AND_GOTO_END_IF_ERROR(lsm6ds3_writeRegister(self, LSM6DS3_ACC_GYRO_CTRL4_C, regValue));
   trace_printf("LALALA\n");
   //Setup the gyroscope**********************************************
   regValue = 0; //Start Fresh!
   if (settings->gyroEnabled) {
      //Build config reg
      //First, patch in full scale
      switch (settings->gyroRange) {
      case LSM6DS3_GYRO_RANGE_125:
         regValue |= LSM6DS3_ACC_GYRO_FS_125_ENABLED;
         self->gyro_k = 4.375;
         break;
      case LSM6DS3_GYRO_RANGE_245:
         regValue |= LSM6DS3_ACC_GYRO_FS_G_245dps;
         self->gyro_k = 8.75;
         break;
      case LSM6DS3_GYRO_RANGE_500:
         regValue |= LSM6DS3_ACC_GYRO_FS_G_500dps;
         self->gyro_k = 17.5;
         break;
      case LSM6DS3_GYRO_RANGE_1000:
         regValue |= LSM6DS3_ACC_GYRO_FS_G_1000dps;
         self->gyro_k = 35;
         break;
      case LSM6DS3_GYRO_RANGE_2000: default:
         regValue |= LSM6DS3_ACC_GYRO_FS_G_2000dps;
         self->gyro_k = 70;
         break;
      }
      //Lastly, patch in gyro ODR
      switch (settings->gyroSampleRate) {
      case LSM6DS3_GYRO_SRATE_12dot5:
         regValue |= LSM6DS3_ACC_GYRO_ODR_G_13Hz;
         break;
      case LSM6DS3_GYRO_SRATE_26:
         regValue |= LSM6DS3_ACC_GYRO_ODR_G_26Hz;
         break;
      case LSM6DS3_GYRO_SRATE_52:
         regValue |= LSM6DS3_ACC_GYRO_ODR_G_52Hz;
         break;
      case LSM6DS3_GYRO_SRATE_104: default:
         regValue |= LSM6DS3_ACC_GYRO_ODR_G_104Hz;
         break;
      case LSM6DS3_GYRO_SRATE_208:
         regValue |= LSM6DS3_ACC_GYRO_ODR_G_208Hz;
         break;
      case LSM6DS3_GYRO_SRATE_416:
         regValue |= LSM6DS3_ACC_GYRO_ODR_G_416Hz;
         break;
      case LSM6DS3_GYRO_SRATE_833:
         regValue |= LSM6DS3_ACC_GYRO_ODR_G_833Hz;
         break;
      case LSM6DS3_GYRO_SRATE_1660:
         regValue |= LSM6DS3_ACC_GYRO_ODR_G_1660Hz;
         break;
      }
   }

   //Write the byte
   SET_AND_GOTO_END_IF_ERROR(lsm6ds3_writeRegister(self, LSM6DS3_ACC_GYRO_CTRL2_G, regValue));
   trace_printf("LALALAM\n");
   //Setup the internal temperature sensor
   if (settings->tempEnabled == 1) {
   }

end:
   return error;
}



int lsm6ds3_acc_read_raw_X(lsm6ds3_t * self, int16_t * value_ptr)
{
   return lsm6ds3_readRegisterInt16(self, LSM6DS3_ACC_GYRO_OUTX_L_XL, value_ptr);
}

int lsm6ds3_acc_read_raw_Y(lsm6ds3_t * self, int16_t * value_ptr)
{
   return lsm6ds3_readRegisterInt16(self, LSM6DS3_ACC_GYRO_OUTY_L_XL, value_ptr);
}

int lsm6ds3_acc_read_raw_Z(lsm6ds3_t * self, int16_t * value_ptr)
{
   return lsm6ds3_readRegisterInt16(self, LSM6DS3_ACC_GYRO_OUTZ_L_XL, value_ptr);
}

int lsm6ds3_acc_read_raw_XYZ(lsm6ds3_t * self, int16_t * values_ptr)
{
   return lsm6ds3_readRegisterRegion(self, LSM6DS3_ACC_GYRO_OUTX_L_XL, (uint8_t*)values_ptr, 3*sizeof(int16_t));
}



int lsm6ds3_gyro_read_raw_X(lsm6ds3_t * self, int16_t * value_ptr)
{
   return lsm6ds3_readRegisterInt16(self, LSM6DS3_ACC_GYRO_OUTX_L_G, value_ptr);
}

int lsm6ds3_gyro_read_raw_Y(lsm6ds3_t * self, int16_t * value_ptr)
{
   return lsm6ds3_readRegisterInt16(self, LSM6DS3_ACC_GYRO_OUTY_L_G, value_ptr);
}

int lsm6ds3_gyro_read_raw_Z(lsm6ds3_t * self, int16_t * value_ptr)
{
   return lsm6ds3_readRegisterInt16(self, LSM6DS3_ACC_GYRO_OUTZ_L_G, value_ptr);
}

int lsm6ds3_gyro_read_raw_XYZ(lsm6ds3_t * self, int16_t * values_ptr)
{
   return lsm6ds3_readRegisterRegion(self, LSM6DS3_ACC_GYRO_OUTX_L_G, (uint8_t*)values_ptr, 3*sizeof(int16_t));
}


int lsm6ds3_acc_gyro_read_raw_all(lsm6ds3_t * self, int16_t * values_ptr)
{
   return lsm6ds3_readRegisterRegion(self, LSM6DS3_ACC_GYRO_OUTX_L_G, (uint8_t*)values_ptr, 6*sizeof(int16_t));
}

void lsm6ds3_acc_recalc(lsm6ds3_t * self, int16_t * parrots, float * not_parrots) {
	not_parrots[0] = parrots[0] * self->acc_k;
	not_parrots[1] = parrots[1] * self->acc_k;
	not_parrots[2] = parrots[2] * self->acc_k;

}

void lsm6ds3_gyro_recalc(lsm6ds3_t * self, int16_t * parrots, float * not_parrots) {
	not_parrots[0] = parrots[0] * self->gyro_k;
	not_parrots[1] = parrots[1] * self->gyro_k;
	not_parrots[2] = parrots[2] * self->gyro_k;

}

void lsm6ds3_gyro_remove_static_error(lsm6ds3_t * self, float * data) {
	if(self->gyro_precalibration_cycles > 10) {
		data[0] -= self->gyro_calibration_coeffs[0];
		data[1] -= self->gyro_calibration_coeffs[1];
		data[2] -= self->gyro_calibration_coeffs[2];
	}

	else if(self->gyro_precalibration_cycles < 10) {
		self->gyro_calibration_coeffs[0] += data[0];
		self->gyro_calibration_coeffs[1] += data[1];
		self->gyro_calibration_coeffs[2] += data[2];
		self->gyro_precalibration_cycles++;
	}
	else if (self->gyro_precalibration_cycles == 10) {
		self->gyro_calibration_coeffs[0] /= 10;
		self->gyro_calibration_coeffs[1] /= 10;
		self->gyro_calibration_coeffs[2] /= 10;
		self->gyro_precalibration_cycles++;
	 }
}
