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
#include "onewire.h"

/**
 * @brief  Sets pin(s) low
 * @note   Defined as macro to get maximum speed using register access
 * @param  GPIOx: GPIOx PORT where you want to set pin low
 * @param  GPIO_Pin: Select GPIO pin(s). You can select more pins with | (OR) operator to set them low
 * @retval None
 */
#define TM_GPIO_SetPinLow(GPIOx, GPIO_Pin)			((GPIOx)->BSRR = (uint32_t)(((uint32_t)GPIO_Pin) << 16))

/**
 * @brief  Sets pin(s) high
 * @note   Defined as macro to get maximum speed using register access
 * @param  GPIOx: GPIOx PORT where you want to set pin high
 * @param  GPIO_Pin: Select GPIO pin(s). You can select more pins with | (OR) operator to set them high
 * @retval None
 */
#define TM_GPIO_SetPinHigh(GPIOx, GPIO_Pin)			((GPIOx)->BSRR = (uint32_t)(GPIO_Pin))

/**
 * @brief  Sets pin(s) value
 * @note   Defined as macro to get maximum speed using register access
 * @param  GPIOx: GPIOx PORT where you want to set pin value
 * @param  GPIO_Pin: Select GPIO pin(s). You can select more pins with | (OR) operator to set them value
 * @param  val: If parameter is 0 then pin will be low, otherwise high
 * @retval None
 */
#define TM_GPIO_SetPinValue(GPIOx, GPIO_Pin, val)	((val) ? TM_GPIO_SetPinHigh(GPIOx, GPIO_Pin) : TM_GPIO_SetPinLow(GPIOx, GPIO_Pin))

/**
 * @brief  Toggles pin(s)
 * @note   Defined as macro to get maximum speed using register access
 * @param  GPIOx: GPIOx PORT where you want to toggle pin value
 * @param  GPIO_Pin: Select GPIO pin(s). You can select more pins with | (OR) operator to toggle them all at a time
 * @retval None
 */
#define TM_GPIO_TogglePinValue(GPIOx, GPIO_Pin)		((GPIOx)->ODR ^= (GPIO_Pin))

/**
 * @brief  Sets value to entire GPIO PORT
 * @note   Defined as macro to get maximum speed using register access
 * @param  GPIOx: GPIOx PORT where you want to set value
 * @param  value: Value for GPIO OUTPUT data
 * @retval None
 */
#define TM_GPIO_SetPortValue(GPIOx, value)			((GPIOx)->ODR = (value))

/**
 * @brief  Gets input data bit
 * @note   Defined as macro to get maximum speed using register access
 * @param  GPIOx: GPIOx PORT where you want to read input bit value
 * @param  GPIO_Pin: GPIO pin where you want to read value
 * @retval 1 in case pin is high, or 0 if low
 */

#define TM_GPIO_GetInputPinValue(GPIOx, GPIO_Pin)	(((GPIOx)->IDR & (GPIO_Pin)) == 0 ? 0 : 1)

/**
 * @brief  Gets output data bit
 * @note   Defined as macro to get maximum speed using register access
 * @param  GPIOx: GPIOx PORT where you want to read output bit value
 * @param  GPIO_Pin: GPIO pin where you want to read value
 * @retval 1 in case pin is high, or 0 if low
 */
#define TM_GPIO_GetOutputPinValue(GPIOx, GPIO_Pin)	(((GPIOx)->ODR & (GPIO_Pin)) == 0 ? 0 : 1)

/**
 * @brief  Gets input value from entire GPIO PORT
 * @note   Defined as macro to get maximum speed using register access
 * @param  GPIOx: GPIOx PORT where you want to read input data value
 * @retval Entire PORT INPUT register
 */
#define TM_GPIO_GetPortInputValue(GPIOx)			((GPIOx)->IDR)

/**
 * @brief  Gets output value from entire GPIO PORT
 * @note   Defined as macro to get maximum speed using register access
 * @param  GPIOx: GPIOx PORT where you want to read output data value
 * @retval Entire PORT OUTPUT register
 */
#define TM_GPIO_GetPortOutputValue(GPIOx)			((GPIOx)->ODR)


void TM_GPIO_SetPinAsInput(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) {
    uint8_t i;
    /* Go through all pins */
    for (i = 0x00; i < 0x10; i++) {
        /* Pin is set */
        if (GPIO_Pin & (1 << i)) {
            /* Set 00 bits combination for input */
            if (i < 7) {
                GPIOx->CRL &= ~((uint32_t)(0x03 << 4*i));
            }
            else {
                const uint8_t j = i - 8;
                GPIOx->CRH &= ~((uint32_t)(0x03 << 4*j));
            }
        }
    }
}

void TM_GPIO_SetPinAsOutput(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) {
    uint8_t i;
    /* Go through all pins */
    for (i = 0x00; i < 0x10; i++) {
        /* Pin is set */
        if (GPIO_Pin & (1 << i)) {
            /* Set 00 bits combination for input */
            if (i < 7) {
                GPIOx->CRL = (GPIOx->CRL & ~((uint32_t)(0x03 << 4*i))) | ((uint32_t)0x01 << 4*i);
            }
            else {
                const uint8_t j = i - 8;
                GPIOx->CRH = (GPIOx->CRH & ~((uint32_t)(0x03 << 4*j))) | ((uint32_t)0x01 << 4*j);
            }
        }
    }
}
void onewire_Init(onewire_t* OneWireStruct, GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) {
	/* Initialize delay if it was not already */
    delay_us_init();

	/* Init GPIO pin */
	//TM_GPIO_Init(GPIOx, GPIO_Pin, TM_GPIO_Mode_OUT, TM_GPIO_OType_PP, TM_GPIO_PuPd_UP, TM_GPIO_Speed_Medium);
	HAL_GPIO_WritePin(GPIOx, GPIO_Pin, SET);

    GPIO_InitTypeDef gp;
	gp.Mode = GPIO_MODE_OUTPUT_OD;
	gp.Pin = GPIO_Pin;
	gp.Pull = GPIO_NOPULL;
	gp.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOx, &gp);
	
	/* Save settings */
	OneWireStruct->GPIOx = GPIOx;
	OneWireStruct->GPIO_Pin = GPIO_Pin;
}

uint8_t onewire_Reset(onewire_t* OneWireStruct) {
	uint8_t i;
	
	/* Line low, and wait 480us */
	ONEWIRE_LOW(OneWireStruct);
	ONEWIRE_OUTPUT(OneWireStruct);
	ONEWIRE_DELAY(480);
	
	/* Release line and wait for 70us */
	ONEWIRE_INPUT(OneWireStruct);
	ONEWIRE_DELAY(70);
	
	/* Check bit value */
	i = TM_GPIO_GetInputPinValue(OneWireStruct->GPIOx, OneWireStruct->GPIO_Pin);
	
	/* Delay for 410 us */
	ONEWIRE_DELAY(410);
	
	/* Return value of presence pulse, 0 = OK, 1 = ERROR */
	return i;
}

void onewire_WriteBit(onewire_t* OneWireStruct, uint8_t bit) {
	if (bit) {
		/* Set line low */
		ONEWIRE_LOW(OneWireStruct);
		ONEWIRE_OUTPUT(OneWireStruct);
		ONEWIRE_DELAY(10);
		
		/* Bit high */
		ONEWIRE_INPUT(OneWireStruct);
		
		/* Wait for 55 us and release the line */
		ONEWIRE_DELAY(55);
		ONEWIRE_INPUT(OneWireStruct);
	} else {
		/* Set line low */
		ONEWIRE_LOW(OneWireStruct);
		ONEWIRE_OUTPUT(OneWireStruct);
		ONEWIRE_DELAY(65);
		
		/* Bit high */
		ONEWIRE_INPUT(OneWireStruct);
		
		/* Wait for 5 us and release the line */
		ONEWIRE_DELAY(5);
		ONEWIRE_INPUT(OneWireStruct);
	}
}

uint8_t onewire_ReadBit(onewire_t* OneWireStruct) {
	uint8_t bit = 0;
	
	/* Line low */
	ONEWIRE_LOW(OneWireStruct);
	ONEWIRE_OUTPUT(OneWireStruct);
	ONEWIRE_DELAY(3);
	
	/* Release line */
	ONEWIRE_INPUT(OneWireStruct);
	ONEWIRE_DELAY(10);
	
	/* Read line value */
	if (TM_GPIO_GetInputPinValue(OneWireStruct->GPIOx, OneWireStruct->GPIO_Pin)) {
		/* Bit is HIGH */
		bit = 1;
	}
	
	/* Wait 50us to complete 60us period */
	ONEWIRE_DELAY(50);
	
	/* Return bit value */
	return bit;
}

void onewire_WriteByte(onewire_t* OneWireStruct, uint8_t byte) {
	uint8_t i = 8;
	/* Write 8 bits */
	while (i--) {
		/* LSB bit is first */
		onewire_WriteBit(OneWireStruct, byte & 0x01);
		byte >>= 1;
	}
}



uint8_t onewire_ReadByte(onewire_t* OneWireStruct) {
	uint8_t i = 8, byte = 0;
	while (i--) {
		byte >>= 1;
		byte |= (onewire_ReadBit(OneWireStruct) << 7);
	}
	
	return byte;
}



uint8_t onewire_First(onewire_t* OneWireStruct) {
	/* Reset search values */
	onewire_ResetSearch(OneWireStruct);

	/* Start with searching */
	return onewire_Search(OneWireStruct, ONEWIRE_CMD_SEARCHROM);
}

uint8_t onewire_Next(onewire_t* OneWireStruct) {
   /* Leave the search state alone */
   return onewire_Search(OneWireStruct, ONEWIRE_CMD_SEARCHROM);
}

void onewire_ResetSearch(onewire_t* OneWireStruct) {
	/* Reset the search state */
	OneWireStruct->LastDiscrepancy = 0;
	OneWireStruct->LastDeviceFlag = 0;
	OneWireStruct->LastFamilyDiscrepancy = 0;
}

uint8_t onewire_Search(onewire_t* OneWireStruct, uint8_t command) {
	uint8_t id_bit_number;
	uint8_t last_zero, rom_byte_number, search_result;
	uint8_t id_bit, cmp_id_bit;
	uint8_t rom_byte_mask, search_direction;

	/* Initialize for search */
	id_bit_number = 1;
	last_zero = 0;
	rom_byte_number = 0;
	rom_byte_mask = 1;
	search_result = 0;

	/* Check if any devices */
	if (!OneWireStruct->LastDeviceFlag) {
		/* 1-Wire reset */
		if (onewire_Reset(OneWireStruct)) {
			/* Reset the search */
			OneWireStruct->LastDiscrepancy = 0;
			OneWireStruct->LastDeviceFlag = 0;
			OneWireStruct->LastFamilyDiscrepancy = 0;
			return 0;
		}

		/* Issue the search command */
		onewire_WriteByte(OneWireStruct, command);

		/* Loop to do the search */
		do {
			/* Read a bit and its complement */
			id_bit = onewire_ReadBit(OneWireStruct);
			cmp_id_bit = onewire_ReadBit(OneWireStruct);

			/* Check for no devices on 1-wire */
			if ((id_bit == 1) && (cmp_id_bit == 1)) {
				break;
			} else {
				/* All devices coupled have 0 or 1 */
				if (id_bit != cmp_id_bit) {
					/* Bit write value for search */
					search_direction = id_bit;
				} else {
					/* If this discrepancy is before the Last Discrepancy on a previous next then pick the same as last time */
					if (id_bit_number < OneWireStruct->LastDiscrepancy) {
						search_direction = ((((uint8_t*)&OneWireStruct->ROM_NO)[rom_byte_number] & rom_byte_mask) > 0);
					} else {
						/* If equal to last pick 1, if not then pick 0 */
						search_direction = (id_bit_number == OneWireStruct->LastDiscrepancy);
					}
					
					/* If 0 was picked then record its position in LastZero */
					if (search_direction == 0) {
						last_zero = id_bit_number;

						/* Check for Last discrepancy in family */
						if (last_zero < 9) {
							OneWireStruct->LastFamilyDiscrepancy = last_zero;
						}
					}
				}

				/* Set or clear the bit in the ROM byte rom_byte_number with mask rom_byte_mask */
				if (search_direction == 1) {
					((uint8_t*)&OneWireStruct->ROM_NO)[rom_byte_number] |= rom_byte_mask;
				} else {
					((uint8_t*)&OneWireStruct->ROM_NO)[rom_byte_number] &= ~rom_byte_mask;
				}
				
				/* Serial number search direction write bit */
				onewire_WriteBit(OneWireStruct, search_direction);

				/* Increment the byte counter id_bit_number and shift the mask rom_byte_mask */
				id_bit_number++;
				rom_byte_mask <<= 1;

				/* If the mask is 0 then go to new SerialNum byte rom_byte_number and reset mask */
				if (rom_byte_mask == 0) {
					rom_byte_number++;
					rom_byte_mask = 1;
				}
			}
		/* Loop until through all ROM bytes 0-7 */
		} while (rom_byte_number < 8);

		/* If the search was successful then */
		if (!(id_bit_number < 65)) {
			/* Search successful so set LastDiscrepancy, LastDeviceFlag, search_result */
			OneWireStruct->LastDiscrepancy = last_zero;

			/* Check for last device */
			if (OneWireStruct->LastDiscrepancy == 0) {
				OneWireStruct->LastDeviceFlag = 1;
			}

			search_result = 1;
		}
	}

	/* If no device found then reset counters so next 'search' will be like a first */
	if (!search_result || !((uint8_t*)&OneWireStruct->ROM_NO)[0]) {
		OneWireStruct->LastDiscrepancy = 0;
		OneWireStruct->LastDeviceFlag = 0;
		OneWireStruct->LastFamilyDiscrepancy = 0;
		search_result = 0;
	}

	return search_result;
}

int onewire_Verify(onewire_t* OneWireStruct) {
	uint64_t rom_backup;
	int rslt,ld_backup,ldf_backup,lfd_backup;

	/* Keep a backup copy of the current state */
	rom_backup = OneWireStruct->ROM_NO;
	ld_backup = OneWireStruct->LastDiscrepancy;
	ldf_backup = OneWireStruct->LastDeviceFlag;
	lfd_backup = OneWireStruct->LastFamilyDiscrepancy;

	/* Set search to find the same device */
	OneWireStruct->LastDiscrepancy = 64;
	OneWireStruct->LastDeviceFlag = 0;

	if (onewire_Search(OneWireStruct, ONEWIRE_CMD_SEARCHROM)) {
		/* Check if same device found */
		rslt = 1;
		if (rom_backup != OneWireStruct->ROM_NO)
			rslt = 1;

	} else {
		rslt = 0;
	}

	/* Restore the search state */
	OneWireStruct->ROM_NO = rom_backup;

	OneWireStruct->LastDiscrepancy = ld_backup;
	OneWireStruct->LastDeviceFlag = ldf_backup;
	OneWireStruct->LastFamilyDiscrepancy = lfd_backup;

	/* Return the result of the verify */
	return rslt;
}


void onewire_FamilySkipSetup(onewire_t* OneWireStruct) {
	/* Set the Last discrepancy to last family discrepancy */
	OneWireStruct->LastDiscrepancy = OneWireStruct->LastFamilyDiscrepancy;
	OneWireStruct->LastFamilyDiscrepancy = 0;

	/* Check for end of list */
	if (OneWireStruct->LastDiscrepancy == 0) {
		OneWireStruct->LastDeviceFlag = 1;
	}
}

uint8_t onewire_GetROM(onewire_t* OneWireStruct, uint8_t index) {
	return ((uint8_t*)&OneWireStruct->ROM_NO)[index];
}

void onewire_Select(onewire_t* OneWireStruct, uint64_t addr) {
	uint8_t i;
	onewire_WriteByte(OneWireStruct, ONEWIRE_CMD_MATCHROM);
	
	for (i = 0; i < 8; i++) {
		onewire_WriteByte(OneWireStruct, *((uint8_t*)&addr + i));
	}
}
/////////////////////////
void onewire_ReadRom(onewire_t* how, uint64_t *rom) {
	onewire_Reset(how);
	uint8_t i;
	onewire_WriteByte(how, ONEWIRE_CMD_READROM);

	for (i = 0; i < 8; i++) {
		((uint8_t*)rom)[i] = onewire_ReadByte(how);
	}
}

//////////////////////////
void onewire_SelectWithPointer(onewire_t* OneWireStruct, uint64_t ROM) {
	uint8_t i;
	onewire_WriteByte(OneWireStruct, ONEWIRE_CMD_MATCHROM);
	
	for (i = 0; i < 8; i++) {
		onewire_WriteByte(OneWireStruct, *((uint8_t*)&ROM + i));
	}	
}

void onewire_GetFullROM(onewire_t* OneWireStruct, uint64_t *firstIndex) {
	*firstIndex = OneWireStruct->ROM_NO;
}

uint8_t onewire_CRC8(uint8_t *addr, uint8_t len) {
	uint8_t crc = 0, inbyte, i, mix;
	
	while (len--) {
		inbyte = *addr++;
		for (i = 8; i; i--) {
			mix = (crc ^ inbyte) & 0x01;
			crc >>= 1;
			if (mix) {
				crc ^= 0x8C;
			}
			inbyte >>= 1;
		}
	}
	
	/* Return calculated CRC */
	return crc;
}
