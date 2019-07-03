/**************************************************************************/
/*!
    @file     ADS1x1x.c
    @author   CPV (Elektor)
    @license  BSD (see license.txt)

    Driver for the ADS101x/ADS111x Sigma-Delta Analog/Digital Converters.

    This started out as a port of the Adafruit library, but ended
    up largely rewritten.

    v1.0 - First release
*/
/**************************************************************************/


#include "ads1x1x.h"
#include <stdlib.h>

void swap_endian(uint8_t* a, int size)
{
	uint8_t *b = a + size - 1;
	while(a < b)
	{
		uint8_t t = *a;
		*a = *b;
		*b = t;
		a++;
		b--;
	}
}
/**************************************************************************/
/*!
    @brief  Writes 16 bits to the specified destination register.
*/
/**************************************************************************/
void ADS1x1x_write_register(I2C_HandleTypeDef *hi2c, uint8_t i2c_address, uint8_t reg, uint16_t value)
{
	swap_endian((uint8_t*)&value, 2);
	volatile int rc = HAL_I2C_Mem_Write(hi2c, (uint16_t)i2c_address, (uint16_t)reg, I2C_MEMADD_SIZE_8BIT, (uint8_t*)&value, 2, 100);
	if(rc)
		return;
}

/**************************************************************************/
/*!
    @brief  Read 16 bits from the specified destination register.
*/
/**************************************************************************/
uint16_t ADS1x1x_read_register(I2C_HandleTypeDef *hi2c, uint8_t i2c_address, uint8_t reg)
{

	uint16_t result = 0;
	int rc = HAL_I2C_Mem_Read(hi2c, i2c_address, (uint16_t)reg, I2C_MEMADD_SIZE_16BIT, (uint8_t*)&result, 2, 100);
	swap_endian((uint8_t*)&result, 2);
	return result;
}



int ADS1x1x_register_i2c(ADS1x1x_config_t *p_config, I2C_HandleTypeDef* hi2c, uint16_t devadd)
{
	p_config->hi2c = hi2c;
	p_config->i2c_address = devadd;

	return 0;
}

int ADS1x1x_config_default(ADS1x1x_config_t *p_config)
{
	p_config->chip = ADS1115;
    ADS1x1x_set_os(p_config,OS_SINGLE);
	ADS1x1x_set_multiplexer(p_config, MUX_DIFF_0_1);
	ADS1x1x_set_pga(p_config, PGA_256);
	ADS1x1x_set_mode(p_config, MODE_SINGLE_SHOT);
	ADS1x1x_set_data_rate(p_config, DATA_RATE_ADS111x_8);
	ADS1x1x_set_threshold_lo(p_config, 0);
	ADS1x1x_set_threshold_hi(p_config, 1);
	ADS1x1x_set_comparator_polarity(p_config, COMPARATOR_POLARITY_ACTIVE_HI);
	ADS1x1x_set_comparator_queue(p_config, COMPARATOR_QUEUE_1);

	return 0;
}



int ADS1x1x_init(ADS1x1x_config_t *p_config)
{
	return 0;
}

int ADS1x1x_deinit(ADS1x1x_config_t *p_config)
{
	return 0;
}


/**************************************************************************/
/*!
    @brief  Start an ADC conversion cycle.
            The user must provide a valid pointer to a
            correctly filled ADS1x1x_config_t structure.
*/
/**************************************************************************/
void ADS1x1x_start_conversion(ADS1x1x_config_t *p_config)
{
  // Write configuration to the ADC.
  ADS1x1x_write_register(p_config->hi2c, p_config->i2c_address,ADS1x1x_REG_POINTER_CONFIG,p_config->config);
}


/**************************************************************************/
/*!
    @brief  Read the ADC conversion result.
            The user must provide a valid pointer to a
            correctly filled ADS1x1x_config_t structure.
*/
/**************************************************************************/
int16_t ADS1x1x_read(ADS1x1x_config_t *p_config)
{
  // Read the conversion result.
  int16_t result = (int16_t)ADS1x1x_read_register(p_config->hi2c, p_config->i2c_address,ADS1x1x_REG_POINTER_CONVERSION);
  // Adjust for ADC resolution if needed.
  if (p_config->chip==ADS1013 || p_config->chip==ADS1014 || p_config->chip==ADS1015)
  {
    result >>= 4;
  }
  return result;
}


void ADS1x1x_set_threshold_lo(ADS1x1x_config_t *p_config, uint16_t value)
{
  if (p_config->chip==ADS1013 || p_config->chip==ADS1014 || p_config->chip==ADS1015)
  {
    value <<= 4;
  }
  ADS1x1x_write_register(p_config->hi2c, p_config->i2c_address,ADS1x1x_REG_POINTER_LO_THRESH,value);
}


void ADS1x1x_set_threshold_hi(ADS1x1x_config_t *p_config, uint16_t value)
{
  if (p_config->chip==ADS1013 || p_config->chip==ADS1014 || p_config->chip==ADS1015)
  {
    value <<= 4;
  }
  ADS1x1x_write_register(p_config->hi2c, p_config->i2c_address,ADS1x1x_REG_POINTER_HI_THRESH,value);
}


void ADS1x1x_set_config_bitfield(ADS1x1x_config_t *p_config, uint16_t value, uint16_t mask)
{
  p_config->config &= ~mask;
  p_config->config |= (value & mask);
}


void ADS1x1x_set_os(ADS1x1x_config_t *p_config, ADS1x1x_os_t value)
{
  ADS1x1x_set_config_bitfield(p_config,(uint16_t)value,ADS1x1x_REG_CONFIG_OS_MASK);
}


void ADS1x1x_set_multiplexer(ADS1x1x_config_t *p_config, ADS1x1x_mux_t value)
{
  ADS1x1x_set_config_bitfield(p_config,(uint16_t)value,ADS1x1x_REG_CONFIG_MULTIPLEXER_MASK);
}


void ADS1x1x_set_pga(ADS1x1x_config_t *p_config, ADS1x1x_pga_t value)
{
  ADS1x1x_set_config_bitfield(p_config,(uint16_t)value,ADS1x1x_REG_CONFIG_PGA_MASK);
}


void ADS1x1x_set_mode(ADS1x1x_config_t *p_config, ADS1x1x_mode_t value)
{
  ADS1x1x_set_config_bitfield(p_config,(uint16_t)value,ADS1x1x_REG_CONFIG_MODE_MASK);
}


void ADS1x1x_set_data_rate(ADS1x1x_config_t *p_config, ADS1x1x_data_rate_t value)
{
  ADS1x1x_set_config_bitfield(p_config,(uint16_t)value,ADS1x1x_REG_CONFIG_DATA_RATE_MASK);
}


void ADS1x1x_set_comparator_mode(ADS1x1x_config_t *p_config, ADS1x1x_comparator_mode_t value)
{
  ADS1x1x_set_config_bitfield(p_config,(uint16_t)value,ADS1x1x_REG_CONFIG_COMPARATOR_MODE_MASK);
}


void ADS1x1x_set_comparator_polarity(ADS1x1x_config_t *p_config, ADS1x1x_comparator_polarity_t value)
{
  ADS1x1x_set_config_bitfield(p_config,(uint16_t)value,ADS1x1x_REG_CONFIG_COMPARATOR_POLARITY_MASK);
}


void ADS1x1x_set_comparator_latching(ADS1x1x_config_t *p_config, ADS1x1x_comparator_latching_t value)
{
  ADS1x1x_set_config_bitfield(p_config,(uint16_t)value,ADS1x1x_REG_CONFIG_COMPARATOR_LATCHING_MASK);
}


void ADS1x1x_set_comparator_queue(ADS1x1x_config_t *p_config, ADS1x1x_comparator_queue_t value)
{
  ADS1x1x_set_config_bitfield(p_config,(uint16_t)value,ADS1x1x_REG_CONFIG_COMPARATOR_QUEUE_MASK);
}


