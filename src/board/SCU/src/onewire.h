/**
 * @author  Tilen Majerle
 * @email   tilen@majerle.eu
 * @website http://stm32f4-discovery.net
 * @link    http://stm32f4-discovery.net/2015/07/hal-library-05-onewire-for-stm32fxxx/
 * @version v1.0
 * @ide     Keil uVision
 * @license MIT
 * @brief   Onewire library for STM32Fxxx devices
 *	
\verbatim
   ----------------------------------------------------------------------
    Copyright (c) 2016 Tilen Majerle

    Permission is hereby granted, free of charge, to any person
    obtaining a copy of this software and associated documentation
    files (the "Software"), to deal in the Software without restriction,
    including without limitation the rights to use, copy, modify, merge,
    publish, distribute, sublicense, and/or sell copies of the Software, 
    and to permit persons to whom the Software is furnished to do so, 
    subject to the following conditions:

    The above copyright notice and this permission notice shall be
    included in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
    OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
    AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
    HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
    WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
    OTHER DEALINGS IN THE SOFTWARE.
   ----------------------------------------------------------------------
\endverbatim
 */
#ifndef onewire_H
#define onewire_H 100

/* C++ detection */
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup TM_STM32Fxxx_HAL_Libraries
 * @{
 */

/**
 * @defgroup onewire
 * @brief    Onewire library for STM32Fxxx devices - http://stm32f4-discovery.net/2015/07/hal-library-05-onewire-for-stm32fxxx/
 * @{
 *
 * \par Changelog
 *
\verbatim
 Version 1.0
  - First release
\endverbatim
 *
 * \par Dependencies
 *
\verbatim
 - STM32Fxxx HAL
 - defines.h
 - TM DELAY
 - TM GPIO
\endverbatim
 */
#include <stm32f4xx_hal.h>
#include "Time.h"
/**
 * @defgroup onewire_Macros
 * @brief    Library defines
 * @{
 */

/* OneWire delay */
#define ONEWIRE_DELAY(x)				delay_us(x)

/* Pin settings */
#define ONEWIRE_LOW(structure)			TM_GPIO_SetPinLow((structure)->GPIOx, (structure)->GPIO_Pin)
#define ONEWIRE_HIGH(structure)			TM_GPIO_SetPinHigh((structure)->GPIOx, (structure)->GPIO_Pin)
#define ONEWIRE_INPUT(structure)		TM_GPIO_SetPinAsInput(structure->GPIOx, (structure)->GPIO_Pin)
#define ONEWIRE_OUTPUT(structure)		TM_GPIO_SetPinAsOutput(structure->GPIOx, (structure)->GPIO_Pin)

/* OneWire commands */
#define ONEWIRE_CMD_RSCRATCHPAD			0xBE
#define ONEWIRE_CMD_WSCRATCHPAD			0x4E
#define ONEWIRE_CMD_CPYSCRATCHPAD		0x48
#define ONEWIRE_CMD_RECEEPROM			0xB8
#define ONEWIRE_CMD_RPWRSUPPLY			0xB4
#define ONEWIRE_CMD_SEARCHROM			0xF0
#define ONEWIRE_CMD_READROM				0x33
#define ONEWIRE_CMD_MATCHROM			0x55
#define ONEWIRE_CMD_SKIPROM				0xCC

/**
 * @}
 */
 
/**
 * @defgroup onewire_Typedefs
 * @brief    Library Typedefs
 * @{
 */

/**
 * @brief  OneWire working struct
 * @note   Except ROM_NO member, everything is fully private and should not be touched by user
 */
typedef struct {
	GPIO_TypeDef* GPIOx;           /*!< GPIOx port to be used for I/O functions */
	uint16_t GPIO_Pin;             /*!< GPIO Pin to be used for I/O functions */
	uint8_t LastDiscrepancy;       /*!< Search private */
	uint8_t LastFamilyDiscrepancy; /*!< Search private */
	uint8_t LastDeviceFlag;        /*!< Search private */
	uint64_t ROM_NO;             /*!< 8-bytes address of last search device */
} onewire_t;

/**
 * @}
 */

/**
 * @defgroup onewire_Functions
 * @brief    Library Functions
 * @{
 */

/**
 * @brief  Initializes OneWire bus
 * @param  *OneWireStruct: Pointer to @ref onewire_t empty working onewire structure
 * @param  *Pointer to GPIO port used for onewire channel
 * @param  GPIO_Pin: GPIO Pin on specific GPIOx to be used for onewire channel
 * @retval None
 */
void onewire_Init(onewire_t* OneWireStruct, GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

/**
 * @brief  Resets OneWire bus
 * 
 * @note   Sends reset command for OneWire
 * @param  *OneWireStruct: Pointer to @ref onewire_t working onewire structure
 * @retval None
 */
uint8_t onewire_Reset(onewire_t* OneWireStruct);

/**
 * @brief  Reads byte from one wire bus
 * @param  *OneWireStruct: Pointer to @ref onewire_t working onewire structure
 * @retval Byte from read operation
 */
uint8_t onewire_ReadByte(onewire_t* OneWireStruct);

/**
 * @brief  Writes byte to bus
 * @param  *OneWireStruct: Pointer to @ref onewire_t working onewire structure
 * @param  byte: 8-bit value to write over OneWire protocol
 * @retval None
 */
void onewire_WriteByte(onewire_t* OneWireStruct, uint8_t byte);

/**
 * @brief  Writes single bit to onewire bus
 * @param  *OneWireStruct: Pointer to @ref onewire_t working onewire structure
 * @param  bit: Bit value to send, 1 or 0
 * @retval None
 */
void onewire_WriteBit(onewire_t* OneWireStruct, uint8_t bit);

/**
 * @brief  Reads single bit from one wire bus
 * @param  *OneWireStruct: Pointer to @ref onewire_t working onewire structure
 * @retval Bit value:
 *            - 0: Bit is low (zero)
 *            - > 0: Bit is high (one)
 */
uint8_t onewire_ReadBit(onewire_t* OneWireStruct);

/**
 * @brief  Searches for OneWire devices on specific Onewire port
 * @note   Not meant for public use. Use @ref onewire_First and @ref onewire_Next for this.
 * @param  *OneWireStruct: Pointer to @ref onewire_t working onewire structure where to search
 * @param  Device status:
 *            - 0: No devices detected
 *            - > 0: Device detected
 */
uint8_t onewire_Search(onewire_t* OneWireStruct, uint8_t command);

/**
 * @brief  Resets search states
 * @param  *OneWireStruct: Pointer to @ref onewire_t working onewire where to reset search values
 * @retval None
 */
void onewire_ResetSearch(onewire_t* OneWireStruct);

/**
 * @brief  Starts search, reset states first
 * @note   When you want to search for ALL devices on one onewire port, you should first use this function.
\code
//...Initialization before
status = onewire_First(&OneWireStruct);
while (status) {
	//Save ROM number from device
	onewire_GetFullROM(ROM_Array_Pointer);
	//Check for new device
	status = onewire_Next(&OneWireStruct);
}
\endcode
 * @param  *OneWireStruct: Pointer to @ref onewire_t working onewire where to reset search values
 * @param  Device status:
 *            - 0: No devices detected
 *            - > 0: Device detected
 */
uint8_t onewire_First(onewire_t* OneWireStruct);

/**
 * @brief  Reads next device
 * @note   Use @ref onewire_First to start searching
 * @param  *OneWireStruct: Pointer to @ref onewire_t working onewire
 * @param  Device status:
 *            - 0: No devices detected any more
 *            - > 0: New device detected
 */
uint8_t onewire_Next(onewire_t* OneWireStruct);

/**
 * @brief  Gets ROM number from device from search
 * @param  *OneWireStruct: Pointer to @ref onewire_t working onewire
 * @param  index: Because each device has 8-bytes long ROm address, you have to call this 8 times, to get ROM bytes from 0 to 7
 * @reetval ROM byte for index (0 to 7) at current found device
 */
uint8_t onewire_GetROM(onewire_t* OneWireStruct, uint8_t index);

/**
 * @brief  Gets all 8 bytes ROM value from device from search
 * @param  *OneWireStruct: Pointer to @ref onewire_t working onewire
 * @param  *firstIndex: Pointer to first location for first byte, other bytes are automatically incremented
 * @retval None
 */
void onewire_GetFullROM(onewire_t* OneWireStruct, uint64_t *firstIndex);

/**
 * @brief  Selects specific slave on bus
 * @param  *OneWireStruct: Pointer to @ref onewire_t working onewire
 * @param  *addr: Pointer to first location of 8-bytes long ROM address
 * @retval None
 */
void onewire_Select(onewire_t* OneWireStruct, uint64_t addr);

/**
 * @brief  Selects specific slave on bus with pointer address
 * @param  *OneWireStruct: Pointer to @ref onewire_t working onewire
 * @param  *ROM: Pointer to first byte of ROM address
 * @retval None
 */
void onewire_SelectWithPointer(onewire_t* OneWireStruct, uint64_t ROM);

/**
 * @brief  Calculates 8-bit CRC for 1-wire devices
 * @param  *addr: Pointer to 8-bit array of data to calculate CRC
 * @param  len: Number of bytes to check
 *
 * @retval Calculated CRC from input data
 */
uint8_t onewire_CRC8(uint8_t* addr, uint8_t len);

void onewire_ReadRom(onewire_t* how, uint64_t *rom);

/**
 * @}
 */
 
/**
 * @}
 */
 
/**
 * @}
 */
 
/* C++ detection */
#ifdef __cplusplus
}
#endif

#endif

