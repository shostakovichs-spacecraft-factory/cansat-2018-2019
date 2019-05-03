/*
 * 	Platform-dependent code for sx1268 transceiver driver
 *
 *  Created on: May 3, 2019
 *      Author: kirs
 */

#include "sx1268.h"



sx1268_status_t _cmd(sx1268_t * self, uint8_t opcode, uint8_t * buff, uint8_t arglength)
{
	sx1268_status_t status = SX1268_OK;

	HAL_GPIO_WritePin(self->platform_specific.cs_port, self->platform_specific.cs_pin, GPIO_PIN_RESET);

	HAL_SPI_Transmit(self->platform_specific.bus, &opcode, 1, TIMEOUT);
	HAL_SPI_TransmitReceive(self->platform_specific.bus, buff, buff, arglength, TIMEOUT);

	HAL_GPIO_WritePin(self->platform_specific.cs_port, self->platform_specific.cs_pin, GPIO_PIN_SET);
	return status;
}

sx1268_status_t _cmd_WriteBuffer(sx1268_t * self,	uint8_t addr, uint8_t * data, uint8_t length)
{
	sx1268_status_t status = SX1268_OK;

	HAL_GPIO_WritePin(self->platform_specific.cs_port, self->platform_specific.cs_pin, GPIO_PIN_RESET);

	uint8_t opcode = 0x0E;
	HAL_SPI_Transmit(self->platform_specific.bus, &opcode, 1, TIMEOUT);
	HAL_SPI_Transmit(self->platform_specific.bus, &addr, 1, TIMEOUT);
	HAL_SPI_Transmit(self->platform_specific.bus, data, length, TIMEOUT);

	HAL_GPIO_WritePin(self->platform_specific.cs_port, self->platform_specific.cs_pin, GPIO_PIN_SET);
	return status;
}

sx1268_status_t _cmd_ReadBuffer(sx1268_t * self,	uint8_t addr, uint8_t * data, uint8_t length)
{
	sx1268_status_t status = SX1268_OK;

	HAL_GPIO_WritePin(self->platform_specific.cs_port, self->platform_specific.cs_pin, GPIO_PIN_RESET);

	uint8_t opcode = 0x1E;
	HAL_SPI_Transmit(self->platform_specific.bus, &opcode, 1, TIMEOUT);
	HAL_SPI_Transmit(self->platform_specific.bus, &addr, 1, TIMEOUT);
	HAL_SPI_Receive(self->platform_specific.bus, data, length, TIMEOUT);

	HAL_GPIO_WritePin(self->platform_specific.cs_port, self->platform_specific.cs_pin, GPIO_PIN_SET);
	return status;
}

uint8_t _readbusypin(sx1268_t * self)
{
	return HAL_GPIO_ReadPin(self->platform_specific.busy_port, self->platform_specific.busy_pin);
}
