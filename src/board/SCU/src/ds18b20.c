/**	
 * |----------------------------------------------------------------------
 * | Copyright (c) 2016 Tilen Majerle
 * |  
 * | Permission is hereby granted, free of charge, to any person
 * | obtaining a copy of this software and associated documentation
 * | files (the "Software"), to deal in the Software without restriction,
 * | including without limitation the rights to use, copy, modify, merge,
 * | publish, distribute, sublicense, and/or sell copies of the Software, 
 * | and to permit persons to whom the Software is furnished to do so, 
 * | subject to the following conditions:
 * | 
 * | The above copyright notice and this permission notice shall be
 * | included in all copies or substantial portions of the Software.
 * | 
 * | THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * | EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * | OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
 * | AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * | HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * | WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
 * | FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * | OTHER DEALINGS IN THE SOFTWARE.
 * |----------------------------------------------------------------------
 */
#include "ds18b20.h"

uint8_t ds18b20_Start(ds18b20_config_t * hds) {
	/* Check if device is DS18B20 */
	if (!ds18b20_Is(hds->rom)) {
		return 0;
	}
	
	/* Reset line */
	onewire_Reset(hds->how);
	/* Select ROM number */
	onewire_SelectWithPointer(hds->how, hds->rom);
	/* Start temperature conversion */
	onewire_WriteByte(hds->how, DS18B20_CMD_CONVERTTEMP);
	
	return 1;
}

void ds18b20_StartAll(ds18b20_config_t * hds) {
	/* Reset pulse */
	onewire_Reset(hds->how);
	/* Skip rom */
	onewire_WriteByte(hds->how, ONEWIRE_CMD_SKIPROM);
	/* Start conversion on all connected devices */
	onewire_WriteByte(hds->how, DS18B20_CMD_CONVERTTEMP);
}

uint8_t ds18b20_Read(ds18b20_config_t * hds, float *destination) {
	uint16_t temperature;
	uint8_t resolution;
	int8_t digit, minus = 0;
	float decimal;
	uint8_t i = 0;
	uint8_t data[9];
	uint8_t crc;
	
	/* Check if device is DS18B20 */
	if (!ds18b20_Is(hds->rom)) {
		return 0;
	}
	
	/* Check if line is released, if it is, then conversion is complete */
	if (!onewire_ReadBit(hds->how)) {
		/* Conversion is not finished yet */
		return 0; 
	}

	/* Reset line */
	onewire_Reset(hds->how);
	/* Select ROM number */
	onewire_SelectWithPointer(hds->how, hds->rom);
	/* Read scratchpad command by onewire protocol */
	onewire_WriteByte(hds->how, ONEWIRE_CMD_RSCRATCHPAD);
	
	/* Get data */
	for (i = 0; i < 9; i++) {
		/* Read byte by byte */
		data[i] = onewire_ReadByte(hds->how);
	}
	
	/* Calculate CRC */
	crc = onewire_CRC8(data, 8);
	
	/* Check if CRC is ok */
	if (crc != data[8]) {
		/* CRC invalid */
		return 0;
	}
	
	/* First two bytes of scratchpad are temperature values */
	temperature = data[0] | (data[1] << 8);

	/* Reset line */
	onewire_Reset(hds->how);
	
	/* Check if temperature is negative */
	if (temperature & 0x8000) {
		/* Two's complement, temperature is negative */
		temperature = ~temperature + 1;
		minus = 1;
	}

	
	/* Get sensor resolution */
	resolution = ((data[4] & 0x60) >> 5) + 9;

	
	/* Store temperature integer digits and decimal digits */
	digit = temperature >> 4;
	digit |= ((temperature >> 8) & 0x7) << 4;
	
	/* Store decimal digits */
	switch (resolution) {
		case 9: {
			decimal = (temperature >> 3) & 0x01;
			decimal *= (float)DS18B20_DECIMAL_STEPS_9BIT;
		} break;
		case 10: {
			decimal = (temperature >> 2) & 0x03;
			decimal *= (float)DS18B20_DECIMAL_STEPS_10BIT;
		} break;
		case 11: {
			decimal = (temperature >> 1) & 0x07;
			decimal *= (float)DS18B20_DECIMAL_STEPS_11BIT;
		} break;
		case 12: {
			decimal = temperature & 0x0F;
			decimal *= (float)DS18B20_DECIMAL_STEPS_12BIT;
		} break;
		default: {
			decimal = 0xFF;
			digit = 0;
		}
	}
	
	/* Check for negative part */
	decimal = digit + decimal;
	if (minus) {
		decimal = 0 - decimal;
	}
	
	/* Set to pointer */
	*destination = decimal;
	
	/* Return 1, temperature valid */
	return 1;
}

uint8_t ds18b20_GetResolution(ds18b20_config_t * hds) {
	uint8_t conf;
	
	if (!ds18b20_Is(hds->rom)) {
		return 0;
	}
	
	/* Reset line */
	onewire_Reset(hds->how);
	/* Select ROM number */
	onewire_SelectWithPointer(hds->how, hds->rom);
	/* Read scratchpad command by onewire protocol */
	onewire_WriteByte(hds->how, ONEWIRE_CMD_RSCRATCHPAD);
	
	/* Ignore first 4 bytes */
	onewire_ReadByte(hds->how);
	onewire_ReadByte(hds->how);
	onewire_ReadByte(hds->how);
	onewire_ReadByte(hds->how);
	
	/* 5th byte of scratchpad is configuration register */
	conf = onewire_ReadByte(hds->how);
	
	/* Return 9 - 12 value according to number of bits */
	return ((conf & 0x60) >> 5) + 9;
}

uint8_t ds18b20_SetResolution(ds18b20_config_t * hds, ds18b20_Resolution_t resolution) {
	uint8_t th, tl, conf;
	if (!ds18b20_Is(hds->rom)) {
		return 0;
	}
	
	/* Reset line */
	onewire_Reset(hds->how);
	/* Select ROM number */
	onewire_SelectWithPointer(hds->how, hds->rom);
	/* Read scratchpad command by onewire protocol */
	onewire_WriteByte(hds->how, ONEWIRE_CMD_RSCRATCHPAD);
	
	/* Ignore first 2 bytes */
	onewire_ReadByte(hds->how);
	onewire_ReadByte(hds->how);
	
	th = onewire_ReadByte(hds->how);
	tl = onewire_ReadByte(hds->how);
	conf = onewire_ReadByte(hds->how);
	
	if (resolution == ds18b20_Resolution_9bits) {
		conf &= ~(1 << DS18B20_RESOLUTION_R1);
		conf &= ~(1 << DS18B20_RESOLUTION_R0);
	} else if (resolution == ds18b20_Resolution_10bits) {
		conf &= ~(1 << DS18B20_RESOLUTION_R1);
		conf |= 1 << DS18B20_RESOLUTION_R0;
	} else if (resolution == ds18b20_Resolution_11bits) {
		conf |= 1 << DS18B20_RESOLUTION_R1;
		conf &= ~(1 << DS18B20_RESOLUTION_R0);
	} else if (resolution == ds18b20_Resolution_12bits) {
		conf |= 1 << DS18B20_RESOLUTION_R1;
		conf |= 1 << DS18B20_RESOLUTION_R0;
	}
	
	/* Reset line */
	onewire_Reset(hds->how);
	/* Select ROM number */
	onewire_SelectWithPointer(hds->how, hds->rom);
	/* Write scratchpad command by onewire protocol, only th, tl and conf register can be written */
	onewire_WriteByte(hds->how, ONEWIRE_CMD_WSCRATCHPAD);
	
	/* Write bytes */
	onewire_WriteByte(hds->how, th);
	onewire_WriteByte(hds->how, tl);
	onewire_WriteByte(hds->how, conf);
	
	/* Reset line */
	onewire_Reset(hds->how);
	/* Select ROM number */
	onewire_SelectWithPointer(hds->how, hds->rom);
	/* Copy scratchpad to EEPROM of DS18B20 */
	onewire_WriteByte(hds->how, ONEWIRE_CMD_CPYSCRATCHPAD);
	
	return 1;
}

uint8_t ds18b20_Is(uint64_t ROM) {
	/* Checks if first byte is equal to DS18B20's family code */
	if (*(uint8_t*)&ROM == DS18B20_FAMILY_CODE) {
		return 1;
	}
	return 0;
}

uint8_t ds18b20_SetAlarmLowTemperature(ds18b20_config_t * hds, int8_t temp) {
	uint8_t tl, th, conf;
	if (!ds18b20_Is(hds->rom)) {
		return 0;
	}
	if (temp > 125) {
		temp = 125;
	} 
	if (temp < -55) {
		temp = -55;
	}
	/* Reset line */
	onewire_Reset(hds->how);
	/* Select ROM number */
	onewire_SelectWithPointer(hds->how, hds->rom);
	/* Read scratchpad command by onewire protocol */
	onewire_WriteByte(hds->how, ONEWIRE_CMD_RSCRATCHPAD);
	
	/* Ignore first 2 bytes */
	onewire_ReadByte(hds->how);
	onewire_ReadByte(hds->how);
	
	th = onewire_ReadByte(hds->how);
	tl = onewire_ReadByte(hds->how);
	conf = onewire_ReadByte(hds->how);
	
	tl = (uint8_t)temp; 

	/* Reset line */
	onewire_Reset(hds->how);
	/* Select ROM number */
	onewire_SelectWithPointer(hds->how, hds->rom);
	/* Write scratchpad command by onewire protocol, only th, tl and conf register can be written */
	onewire_WriteByte(hds->how, ONEWIRE_CMD_WSCRATCHPAD);
	
	/* Write bytes */
	onewire_WriteByte(hds->how, th);
	onewire_WriteByte(hds->how, tl);
	onewire_WriteByte(hds->how, conf);
	
	/* Reset line */
	onewire_Reset(hds->how);
	/* Select ROM number */
	onewire_SelectWithPointer(hds->how, hds->rom);
	/* Copy scratchpad to EEPROM of DS18B20 */
	onewire_WriteByte(hds->how, ONEWIRE_CMD_CPYSCRATCHPAD);
	
	return 1;
}

uint8_t ds18b20_SetAlarmHighTemperature(ds18b20_config_t * hds, int8_t temp) {
	uint8_t tl, th, conf;
	if (!ds18b20_Is(hds->rom)) {
		return 0;
	}
	if (temp > 125) {
		temp = 125;
	} 
	if (temp < -55) {
		temp = -55;
	}
	/* Reset line */
	onewire_Reset(hds->how);
	/* Select ROM number */
	onewire_SelectWithPointer(hds->how, hds->rom);
	/* Read scratchpad command by onewire protocol */
	onewire_WriteByte(hds->how, ONEWIRE_CMD_RSCRATCHPAD);
	
	/* Ignore first 2 bytes */
	onewire_ReadByte(hds->how);
	onewire_ReadByte(hds->how);
	
	th = onewire_ReadByte(hds->how);
	tl = onewire_ReadByte(hds->how);
	conf = onewire_ReadByte(hds->how);
	
	th = (uint8_t)temp; 

	/* Reset line */
	onewire_Reset(hds->how);
	/* Select ROM number */
	onewire_SelectWithPointer(hds->how, hds->rom);
	/* Write scratchpad command by onewire protocol, only th, tl and conf register can be written */
	onewire_WriteByte(hds->how, ONEWIRE_CMD_WSCRATCHPAD);
	
	/* Write bytes */
	onewire_WriteByte(hds->how, th);
	onewire_WriteByte(hds->how, tl);
	onewire_WriteByte(hds->how, conf);
	
	/* Reset line */
	onewire_Reset(hds->how);
	/* Select ROM number */
	onewire_SelectWithPointer(hds->how, hds->rom);
	/* Copy scratchpad to EEPROM of DS18B20 */
	onewire_WriteByte(hds->how, ONEWIRE_CMD_CPYSCRATCHPAD);
	
	return 1;
}

uint8_t ds18b20_DisableAlarmTemperature(ds18b20_config_t * hds) {
	uint8_t tl, th, conf;
	if (!ds18b20_Is(hds->rom)) {
		return 0;
	}
	/* Reset line */
	onewire_Reset(hds->how);
	/* Select ROM number */
	onewire_SelectWithPointer(hds->how, hds->rom);
	/* Read scratchpad command by onewire protocol */
	onewire_WriteByte(hds->how, ONEWIRE_CMD_RSCRATCHPAD);
	
	/* Ignore first 2 bytes */
	onewire_ReadByte(hds->how);
	onewire_ReadByte(hds->how);
	
	th = onewire_ReadByte(hds->how);
	tl = onewire_ReadByte(hds->how);
	conf = onewire_ReadByte(hds->how);
	
	th = 125;
	tl = (uint8_t)-55;

	/* Reset line */
	onewire_Reset(hds->how);
	/* Select ROM number */
	onewire_SelectWithPointer(hds->how, hds->rom);
	/* Write scratchpad command by onewire protocol, only th, tl and conf register can be written */
	onewire_WriteByte(hds->how, ONEWIRE_CMD_WSCRATCHPAD);
	
	/* Write bytes */
	onewire_WriteByte(hds->how, th);
	onewire_WriteByte(hds->how, tl);
	onewire_WriteByte(hds->how, conf);
	
	/* Reset line */
	onewire_Reset(hds->how);
	/* Select ROM number */
	onewire_SelectWithPointer(hds->how, hds->rom);
	/* Copy scratchpad to EEPROM of DS18B20 */
	onewire_WriteByte(hds->how, ONEWIRE_CMD_CPYSCRATCHPAD);
	
	return 1;
}

uint8_t ds18b20_AlarmSearch(ds18b20_config_t * hds) {
	/* Start alarm search */
	return onewire_Search(hds->how, DS18B20_CMD_ALARMSEARCH);
}

uint8_t ds18b20_AllDone(ds18b20_config_t * hds) {
	/* If read bit is low, then device is not finished yet with calculation temperature */
	return onewire_ReadBit(hds->how);
}


