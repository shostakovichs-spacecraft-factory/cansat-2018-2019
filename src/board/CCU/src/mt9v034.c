/****************************************************************************
 *
 *   Copyright (C) 2013 PX4 Development Team. All rights reserved.
 *   Author: Laurens Mackay <mackayl@student.ethz.ch>
 *   		 Dominik Honegger <dominik.honegger@inf.ethz.ch>
 *   		 Petri Tanskanen <tpetri@inf.ethz.ch>
 *   		 Samuel Zihlmann <samuezih@ee.ethz.ch>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

#include <stdbool.h>

#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_dcmi.h"
#include "stm32f4xx_hal_dma.h"
#include "stm32f4xx_hal_rcc.h"
#include "stm32f4xx_hal_i2c.h"
#include "mt9v034.h"

extern I2C_HandleTypeDef hi2c2;

inline bool FLOAT_AS_BOOL(float f)
{
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wfloat-equal"
  return (f != 0.0f);
#pragma GCC diagnostic pop
}

/**
  * @brief  Configures the mt9v034 camera with two context (binning 4 and binning 2).
  */
void mt9v034_context_configuration(void)
{
	/* Chip Control
	 *
	 * bits           | 15 | ... | 9 | 8 | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
	 * -------------------------------------------------------------------
	 * current values | 0  | ... | 0 | 1 | 1 | 0 | 0 | 0 | 1 | 0 | 0 | 0 |
	 *
	 * (0:2) Scan Mode (Progressive scan)
	 * (3:4) Sensor Operation Mode (Master mode)
	 * (5) Stereoscopy Mode (Disable)
	 * (6) Stereoscopic Master/Slave mode (not used)
	 * (7) Parallel Output Enable (Enable)
	 * (8) Simultaneous/Sequential Mode (Simultaneous mode)
	 * (9) Reserved
	 *
	 * (15)Context A (0) / Context B (1)
	 *
	 */

	uint16_t new_control;

	// Context b by default (to be true, we don't need both contexts)
	new_control = 0x8188; // Context B

	/* image dimentions */
	uint16_t new_width_context_a  = FULL_IMAGE_ROW_SIZE * 4; // windowing off, row + col bin reduce size
	uint16_t new_height_context_a = FULL_IMAGE_COLUMN_SIZE * 4;
	uint16_t new_width_context_b  = FULL_IMAGE_ROW_SIZE * 4; // windowing off, row + col bin reduce size
	uint16_t new_height_context_b = FULL_IMAGE_COLUMN_SIZE * 4;

	/* blanking settings */
	uint16_t new_hor_blanking_context_a = 425 + MINIMUM_HORIZONTAL_BLANKING;// 709 is minimum value without distortions
	uint16_t new_ver_blanking_context_a = 10; // this value is the first without image errors (dark lines)
	uint16_t new_hor_blanking_context_b = MAX_IMAGE_WIDTH - new_width_context_b + MINIMUM_HORIZONTAL_BLANKING;
	if (new_hor_blanking_context_b < 800) {
		new_hor_blanking_context_b = 800;
	}
	uint16_t new_ver_blanking_context_b = 10;


	/* Read Mode
	 *
	 * bits           | ... | 10 | 9 | 8 | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
	 * -------------------------------------------------------------------
	 * current values | ... |  0 | 1 | 1 | 0 | 0 | 0 | 0 | 1 | 0 | 1 | 0 |
	 *
	 * (1:0) Row Bin
	 * (3:2) Column Bin
	 * (9:8) Reserved
	 *
	 */
	uint16_t new_readmode_context_a = 0x30A ; // row + col bin 4 enable, (9:8) default
	uint16_t new_readmode_context_b = 0x305 ; // row bin 2 col bin 4 enable, (9:8) default

	/*
	 * Settings for both context:
	 *
	 * Exposure time should not affect frame time
	 * so we set max on 64 (lines) = 0x40
	 */
	uint16_t min_exposure = 0x0001; // default
	uint16_t pixel_count = 4096; //64x64 take all pixels to estimate exposure time // VALID RANGE: 1-65535
	uint16_t shutter_width_ctrl = 0x0164; // default from context A
	uint16_t aec_update_freq = 0x02; // default Number of frames to skip between changes in AEC VALID RANGE: 0-15
	uint16_t aec_low_pass = 0x01; // default VALID RANGE: 0-2
	uint16_t agc_update_freq = 0x02; // default Number of frames to skip between changes in AGC VALID RANGE: 0-15
	uint16_t agc_low_pass = 0x02; // default VALID RANGE: 0-2

	uint16_t resolution_ctrl = 0x0303; // 12 bit adc for low light
	uint16_t max_gain = CCU_SPECTRUM_PARAM_GAIN_MAX;
	uint16_t max_exposure = CCU_SPECTRUM_PARAM_EXPOSURE_MAX;
	uint16_t coarse_sw1 = CCU_SPECTRUM_PARAM_SHTR_W_1;
	uint16_t coarse_sw2 = CCU_SPECTRUM_PARAM_SHTR_W_2;
	uint16_t total_shutter_width = CCU_SPECTRUM_PARAM_SHTR_W_TOT;
	uint16_t hdr_enabled = 0x0000;
	bool hdr_enable_flag = CCU_SPECTRUM_PARAM_HDR > 0;
	if (hdr_enable_flag) {
		hdr_enabled = 0x0100;
	}

	bool aec_enable_flag = CCU_SPECTRUM_PARAM_AEC > 0;
	uint16_t aec_agc_enabled = 0x0000;
	if (aec_enable_flag) {
		aec_agc_enabled |= (1 << 0);
	}

	bool agc_enable_flag = CCU_SPECTRUM_PARAM_AGC > 0;
	if (agc_enable_flag) {
		aec_agc_enabled |= (1 << 1);
	}

	uint16_t desired_brightness = CCU_SPECTRUM_PARAM_BRIGHT;

	uint16_t row_noise_correction = 0x0000; // default
	uint16_t test_data = 0x0000; // default

	if(FLOAT_AS_BOOL(CCU_SPECTRUM_PARAM_IMAGE_ROW_NOISE_CORR) && !FLOAT_AS_BOOL(CCU_SPECTRUM_PARAM_IMAGE_TEST_PATTERN))
		row_noise_correction = 0x0101;
	else
		row_noise_correction = 0x0000;

	if (FLOAT_AS_BOOL(CCU_SPECTRUM_PARAM_IMAGE_TEST_PATTERN))
		test_data = 0x3000; //enable vertical gray shade pattern
	else
		test_data = 0x0000;

	uint16_t version = mt9v034_ReadReg16(MTV_CHIP_VERSION_REG);

	if (version == 0x1324)
	{
		mt9v034_WriteReg16(MTV_CHIP_CONTROL_REG, new_control);

		// Initialize frame control reg
		mt9v034_WriteReg(0x72, 0x0000);

		// Write reserved registers per Rev G datasheet table 8 recommendations
		mt9v034_WriteReg16(0x13, 0x2D2E);
		mt9v034_WriteReg16(0x20, 0x03C7);
		mt9v034_WriteReg16(0x24, 0x001B);
		mt9v034_WriteReg16(0x2B, 0x0003);
		mt9v034_WriteReg16(0x2F, 0x0003);

		/* Context A */
		mt9v034_WriteReg16(MTV_WINDOW_WIDTH_REG_A, new_width_context_a);
		mt9v034_WriteReg16(MTV_WINDOW_HEIGHT_REG_A, new_height_context_a);
		mt9v034_WriteReg16(MTV_HOR_BLANKING_REG_A, new_hor_blanking_context_a);
		mt9v034_WriteReg16(MTV_VER_BLANKING_REG_A, new_ver_blanking_context_a);
		mt9v034_WriteReg16(MTV_READ_MODE_REG_A, new_readmode_context_a);
		mt9v034_WriteReg16(MTV_COLUMN_START_REG_A, (MAX_IMAGE_WIDTH - new_width_context_a) / 2 + MINIMUM_COLUMN_START); // Set column/row start point for lower resolutions (center window)
		mt9v034_WriteReg16(MTV_ROW_START_REG_A, (MAX_IMAGE_HEIGHT - new_height_context_a) / 2 + MINIMUM_ROW_START);
		mt9v034_WriteReg16(MTV_COARSE_SW_1_REG_A, coarse_sw1);
		mt9v034_WriteReg16(MTV_COARSE_SW_2_REG_A, coarse_sw2);
		mt9v034_WriteReg16(MTV_COARSE_SW_CTRL_REG_A, shutter_width_ctrl);
		mt9v034_WriteReg16(MTV_COARSE_SW_TOTAL_REG_A, total_shutter_width);


		/* Context B */
		mt9v034_WriteReg16(MTV_WINDOW_WIDTH_REG_B, new_width_context_b);
		mt9v034_WriteReg16(MTV_WINDOW_HEIGHT_REG_B, new_height_context_b);
		mt9v034_WriteReg16(MTV_HOR_BLANKING_REG_B, new_hor_blanking_context_b);
		mt9v034_WriteReg16(MTV_VER_BLANKING_REG_B, new_ver_blanking_context_b);
		mt9v034_WriteReg16(MTV_READ_MODE_REG_B, new_readmode_context_b);
		mt9v034_WriteReg16(MTV_COLUMN_START_REG_B, MINIMUM_COLUMN_START); // default
		mt9v034_WriteReg16(MTV_ROW_START_REG_B, MINIMUM_ROW_START);
		mt9v034_WriteReg16(MTV_COARSE_SW_1_REG_B, coarse_sw1);
		mt9v034_WriteReg16(MTV_COARSE_SW_2_REG_B, coarse_sw2);
		mt9v034_WriteReg16(MTV_COARSE_SW_CTRL_REG_B, shutter_width_ctrl);
		mt9v034_WriteReg16(MTV_COARSE_SW_TOTAL_REG_B, total_shutter_width);

		/* General Settings */
		mt9v034_WriteReg16(MTV_ROW_NOISE_CORR_CTRL_REG, row_noise_correction);
		mt9v034_WriteReg16(MTV_AEC_AGC_ENABLE_REG, aec_agc_enabled); // disable AEC/AGC for both contexts
		mt9v034_WriteReg16(MTV_HDR_ENABLE_REG, hdr_enabled); // disable HDR on both contexts
		mt9v034_WriteReg16(MTV_MIN_EXPOSURE_REG, min_exposure);
		mt9v034_WriteReg16(MTV_MAX_EXPOSURE_REG, max_exposure);
		mt9v034_WriteReg16(MTV_MAX_GAIN_REG, max_gain);
		mt9v034_WriteReg16(MTV_AGC_AEC_PIXEL_COUNT_REG, pixel_count);
		mt9v034_WriteReg16(MTV_AGC_AEC_DESIRED_BIN_REG, desired_brightness);
		mt9v034_WriteReg16(MTV_ADC_RES_CTRL_REG, resolution_ctrl); // here is the way to regulate darkness :)

		mt9v034_WriteReg16(MTV_DIGITAL_TEST_REG, test_data);//enable test pattern

		mt9v034_WriteReg16(MTV_AEC_UPDATE_REG,aec_update_freq);
		mt9v034_WriteReg16(MTV_AEC_LOWPASS_REG,aec_low_pass);
		mt9v034_WriteReg16(MTV_AGC_UPDATE_REG,agc_update_freq);
		mt9v034_WriteReg16(MTV_AGC_LOWPASS_REG,agc_low_pass);

		/* Reset */
		mt9v034_WriteReg16(MTV_SOFT_RESET_REG, 0x01);
	}

}

/**
  * @brief  Changes sensor context based on settings
  */
void mt9v034_set_context(mt9v034_context_t context)
{
	uint16_t new_control;
	if (context == MT9V034_CONTEXT_B)
		new_control = 0x8188; // Context B
	else
		new_control = 0x0188; // Context A

	mt9v034_WriteReg16(MTV_CHIP_CONTROL_REG, new_control);
}

/**
  * @brief  Writes a byte at a specific Camera register
  * @param  Addr: mt9v034 register address.
  * @param  Data: Data to be written to the specific register
  * @retval 0x00 if write operation is OK.
  *       0xFF if timeout condition occured (device not connected or bus error).
  */
uint8_t mt9v034_WriteReg(uint16_t Addr, uint8_t Data)
{
	// FIXME check adress and add proper error handling
	return HAL_I2C_Mem_Write(&hi2c2, mt9v034_DEVICE_WRITE_ADDRESS, Addr, I2C_MEMADD_SIZE_8BIT, &Data, 1, TIMEOUT_MAX);
}

/**
  * @brief  Writes to a specific Camera register
  */
uint8_t mt9v034_WriteReg16(uint16_t address, uint16_t Data)
{
	Data = ( (Data&0xFF) << 8) | ( (Data >> 8) & 0xFF);
	// FIXME check endianness, address and add proper error handling
	return HAL_I2C_Mem_Write(&hi2c2, mt9v034_DEVICE_WRITE_ADDRESS, address, I2C_MEMADD_SIZE_8BIT, &Data, 2, TIMEOUT_MAX);
}

/**
  * @brief  Reads a byte from a specific Camera register
  * @param  Addr: mt9v034 register address.
  * @retval data read from the specific register or 0xFF if an error occured.
  */
uint8_t mt9v034_ReadReg(uint16_t Addr)
{
	uint8_t data = 0;
	HAL_StatusTypeDef status;

	status = HAL_I2C_Mem_Read(&hi2c2, mt9v034_DEVICE_READ_ADDRESS, Addr, I2C_MEMADD_SIZE_8BIT, &data, 1, TIMEOUT_MAX);
	if(status != HAL_OK)
		return 0xFF;

	return data;
}

/**
  * @brief  Reads from a specific Camera register
  */
uint16_t mt9v034_ReadReg16(uint8_t address)
{
	uint16_t data = 0;
	HAL_StatusTypeDef status;

	status = HAL_I2C_Mem_Read(&hi2c2, mt9v034_DEVICE_READ_ADDRESS, address, I2C_MEMADD_SIZE_8BIT, &data, 2, TIMEOUT_MAX);
	if(status != HAL_OK)
		return 0xFFFF;

	data = ( (data&0xFF) << 8) | ( (data >> 8) & 0xFF);

	return data;
}
