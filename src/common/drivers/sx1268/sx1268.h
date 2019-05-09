/*
 * 	Driver for sx1268 transceiver circuit
 *
 *  Created on: Mar 30, 2019
 *      Author: kirs
 */

#ifndef SX1268_H_
#define SX1268_H_

#include <stdint.h>
#include <stdbool.h>

#define TIMEOUT 10000 //Timeout for SPI operations, ms

#define RXLEN(SELF)	((SELF.fifo_rx.head - SELF.fifo_rx.tail) % (SELF.fifo_rx.length))

typedef struct
{
	uint8_t * mem;
	int length, head, tail;
	bool empty;
} sx1268_fifo_t;

typedef struct
{
	sx1268_fifo_t fifo_rx, fifo_tx;
	void * platform_specific;
} sx1268_t;

typedef enum
{
	SX1268_OK,
	SX1268_TIMEOUT,
	SX1268_BUSY,
	SX1268_ERR_BUFSIZE,
} sx1268_status_t;

#ifdef SX1268_STM32
#include "sx1268_stm32.h"
#elif defined SX1268_RPI
#include "sx1268_rpi.h"
#endif

//Inits all descriptor fields as they should be by default
void sx1268_struct_init(sx1268_t * self, void * platform_specific, uint8_t * rxbuff, int rxbufflen, uint8_t * txbuff, int txbufflen);

//Do basic initialization
sx1268_status_t sx1268_init(sx1268_t * self);

//Send data through radio channel
sx1268_status_t sx1268_send(sx1268_t * self, uint8_t * data, int len);

//Receive data from channel
sx1268_status_t sx1268_receive(sx1268_t * self, uint8_t * data, int len);

//Process an event (should be called every time the IRq occurs)
void sx1268_event(sx1268_t * self);

#endif /* SX1268_H_ */
