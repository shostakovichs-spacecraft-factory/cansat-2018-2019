/*
 * 	Driver for sx1268 transceiver circuit
 *
 *  Created on: Mar 30, 2019
 *      Author: kirs
 */

#ifndef SX1268_H_
#define SX1268_H_

#include <stdint.h>

#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_spi.h"

typedef struct
{
	uint8_t * mem;
	int length, head, tail;
	bool empty;
} sx1268_fifo_t;

typedef struct
{
	SPI_HandleTypeDef * bus;
	GPIO_TypeDef * cs_port;
	uint16_t cs_pin;
	GPIO_TypeDef * busy_port;
	uint16_t busy_pin;
	sx1268_fifo_t fifo_rx, fifo_tx;
} sx1268_t;

typedef enum
{
	SX1268_OK,
	SX1268_TIMEOUT,
	SX1268_BUSY,
	SX1268_ERR_BUFSIZE,
} sx1268_status_t;


#endif /* SX1268_H_ */
