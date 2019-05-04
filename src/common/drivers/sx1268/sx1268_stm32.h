/*
 * 	Platform-dependent part of the sx1268 driver for stm32
 *
 *  Created on: May 4, 2019
 *      Author: kirs
 */

#ifndef SX1268_STM32_H_
#define SX1268_STM32_H_

#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_spi.h"

typedef struct
{
	SPI_HandleTypeDef * bus;
	GPIO_TypeDef * cs_port;
	uint16_t cs_pin;
	GPIO_TypeDef * busy_port;
	uint16_t busy_pin;
}	sx1268_stm32_t;

inline sx1268_status_t _cmd(sx1268_t * self, uint8_t opcode, uint8_t * buff, uint8_t arglength)
{
	sx1268_stm32_t * self_specific = (sx1268_stm32_t *) self->platform_specific;
	sx1268_status_t status = SX1268_OK;

	HAL_GPIO_WritePin(self_specific->cs_port, self_specific->cs_pin, GPIO_PIN_RESET);

	HAL_SPI_Transmit(self_specific->bus, &opcode, 1, TIMEOUT);
	HAL_SPI_TransmitReceive(self_specific->bus, buff, buff, arglength, TIMEOUT);

	HAL_GPIO_WritePin(self_specific->cs_port, self_specific->cs_pin, GPIO_PIN_SET);
	return status;
}

inline sx1268_status_t _cmd_WriteBuffer(sx1268_t * self,	uint8_t addr, uint8_t * data, uint8_t length)
{
	sx1268_stm32_t * self_specific = (sx1268_stm32_t *) self->platform_specific;
	sx1268_status_t status = SX1268_OK;

	HAL_GPIO_WritePin(self_specific->cs_port, self_specific->cs_pin, GPIO_PIN_RESET);

	uint8_t opcode = 0x0E;
	HAL_SPI_Transmit(self_specific->bus, &opcode, 1, TIMEOUT);
	HAL_SPI_Transmit(self_specific->bus, &addr, 1, TIMEOUT);
	HAL_SPI_Transmit(self_specific->bus, data, length, TIMEOUT);

	HAL_GPIO_WritePin(self_specific->cs_port, self_specific->cs_pin, GPIO_PIN_SET);
	return status;
}

inline sx1268_status_t _cmd_ReadBuffer(sx1268_t * self,	uint8_t addr, uint8_t * data, uint8_t length)
{
	sx1268_stm32_t * self_specific = (sx1268_stm32_t *) self->platform_specific;
	sx1268_status_t status = SX1268_OK;

	HAL_GPIO_WritePin(self_specific->cs_port, self_specific->cs_pin, GPIO_PIN_RESET);

	uint8_t opcode = 0x1E;
	HAL_SPI_Transmit(self_specific->bus, &opcode, 1, TIMEOUT);
	HAL_SPI_Transmit(self_specific->bus, &addr, 1, TIMEOUT);
	HAL_SPI_Receive(self_specific->bus, data, length, TIMEOUT);

	HAL_GPIO_WritePin(self_specific->cs_port, self_specific->cs_pin, GPIO_PIN_SET);
	return status;
}

inline uint8_t _readbusypin(sx1268_t * self)
{
	return HAL_GPIO_ReadPin( ( (sx1268_stm32_t *) self->platform_specific )->busy_port, \
				( (sx1268_stm32_t *) self->platform_specific )->busy_pin);
}

#endif /* DRIVERS_SX1268_SX1268_STM32_H_ */
