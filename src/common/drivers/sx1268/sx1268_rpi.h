/*
 * 	Platform-dependent part of the sx1268 driver for stm32
 *
 *  Created on: May 4, 2019
 *      Author: kirs
 */

#ifndef SX1268_STM32_H_
#define SX1268_STM32_H_

#include <pigpio.h>

typedef struct
{
	unsigned bus_handle;
	unsigned cs_pin;
	unsigned busy_pin;
}	sx1268_rpi_t;

inline sx1268_status_t _cmd(sx1268_t * self, uint8_t opcode, uint8_t * buff, uint8_t arglength)
{
	sx1268_rpi_t * self_specific = (sx1268_rpi_t *) self->platform_specific;
	sx1268_status_t status = SX1268_OK;

	gpioWrite(self_specific->cs_pin, 0);

	spiWrite(self_specific->bus_handle, &opcode, 1);
	spiXfer(self_specific->bus_handle, buff, buff, arglength);

	gpioWrite(self_specific->cs_pin, 1);
	return status;
}

inline sx1268_status_t _cmd_WriteBuffer(sx1268_t * self,	uint8_t addr, uint8_t * data, uint8_t length)
{
	sx1268_rpi_t * self_specific = (sx1268_rpi_t *) self->platform_specific;
	sx1268_status_t status = SX1268_OK;

	gpioWrite(self_specific->cs_pin, 0);

	uint8_t opcode = 0x0E;
	spiWrite(self_specific->bus_handle, &opcode, 1);
	spiWrite(self_specific->bus_handle, &addr, 1);
	spiWrite(self_specific->bus_handle, data, length);

	gpioWrite(self_specific->cs_pin, 1);
	return status;
}

inline sx1268_status_t _cmd_ReadBuffer(sx1268_t * self,	uint8_t addr, uint8_t * data, uint8_t length)
{
	sx1268_rpi_t * self_specific = (sx1268_rpi_t *) self->platform_specific;
	sx1268_status_t status = SX1268_OK;

	gpioWrite(self_specific->cs_pin, 0);

	uint8_t opcode = 0x1E;
	spiWrite(self_specific->bus_handle, &opcode, 1);
	spiWrite(self_specific->bus_handle, &addr, 1);
	spiRead(self_specific->bus_handle, data, length);

	gpioWrite(self_specific->cs_pin, 1);
	return status;
}

inline uint8_t _readbusypin(sx1268_t * self)
{
	return gpioRead( ((sx1268_rpi_t *) self->platform_specific)->busy_pin );
}

#endif /* DRIVERS_SX1268_SX1268_STM32_H_ */
