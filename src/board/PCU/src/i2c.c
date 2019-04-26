/*
 * i2c.c
 *
 *  Created on: 20 апр. 2019 г.
 *      Author: snork
 */

#include "i2c.h"

#include <stdlib.h>


typedef struct
{
	uint8_t slave_address;
	uint8_t xfer_direction;
	uint8_t * xfer_buffer;
	size_t xfer_size;
	int error;
} i2c_bus_state_t;

static i2c_bus_state_t _i2c1_state;
static i2c_bus_state_t _i2c2_state;


static i2c_bus_state_t * _get_bus_state(I2C_TypeDef * bus)
{
	if (bus == I2C1)
		return &_i2c1_state;
	else if (bus == I2C2)
		return &_i2c2_state;
	else
	{
		return NULL;
		abort();
	}
}


static void _init_bus_common(I2C_TypeDef * bus)
{
	I2C_SoftwareResetCmd(bus, DISABLE);

	I2C_InitTypeDef bus_init;
	bus_init.I2C_Ack = I2C_Ack_Enable;
	bus_init.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
	bus_init.I2C_ClockSpeed = 400*1000;
	bus_init.I2C_DutyCycle = I2C_DutyCycle_16_9;
	bus_init.I2C_Mode = I2C_Mode_I2C;
	bus_init.I2C_OwnAddress1 = 0x00;

	I2C_Init(bus, &bus_init);
}


void i2c_init_bus1(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

	{
		GPIO_InitTypeDef port;
		port.GPIO_Mode = GPIO_Mode_AF_OD;
		port.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7; // B6 == SCL, B7 == SDA
		port.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOB, &port);
	}

	_init_bus_common(I2C1);

	NVIC_EnableIRQ(I2C1_ER_IRQn);
	NVIC_EnableIRQ(I2C1_EV_IRQn);
}


void i2c_init_bus2(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C2, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

	{
		GPIO_InitTypeDef port;
		port.GPIO_Mode = GPIO_Mode_AF_OD;
		port.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11; // B10 == SCL, B11 == SDA
		port.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOB, &port);
	}

	_init_bus_common(I2C2);

	NVIC_EnableIRQ(I2C2_ER_IRQn);
	NVIC_EnableIRQ(I2C2_EV_IRQn);
}


int i2c_read(I2C_TypeDef * bus, uint8_t slave, void * buffer, size_t buffer_size)
{
	i2c_bus_state_t * const state = _get_bus_state(bus);
	/* Enable EVT IT*/
	bus->CR2 |= I2C_IT_EVT;
	/* Enable BUF IT */
	bus->CR2 |= I2C_IT_BUF;
	/* Set the I2C direction to reception */
	state->xfer_direction = I2C_Direction_Receiver;
	state->slave_address = slave << 1;
	state->xfer_buffer = (uint8_t*)buffer;
	state->xfer_size = buffer_size;
	state->error = 0;

	/* Send START condition */
	I2C_GenerateSTART(bus, ENABLE);
	/* Wait until the START condition is generated on the bus: START bit is cleared by hardware */
	while ((bus->CR1 & 0x100) == 0x100);
	/* Wait until BUSY flag is reset (until a STOP is generated) */
	while ((bus->SR2 & 0x0002) == 0x0002);
	/* Enable Acknowledgement to be ready for another reception */
	I2C_AcknowledgeConfig(bus, ENABLE);
	//bus->CR1 |= CR1_ACK_Set;

	return state->error;
}


int i2c_write(I2C_TypeDef * bus, uint8_t slave, void * buffer, size_t buffer_size)
{
	i2c_bus_state_t * const state = _get_bus_state(bus);
	/* Enable Error IT */
	bus->CR2 |= I2C_IT_ERR;
	/* Enable EVT IT*/
	bus->CR2 |= I2C_IT_EVT;
	/* Enable BUF IT */
	bus->CR2 |= I2C_IT_BUF;
	/* Set the I2C direction to Transmission */
	state->xfer_direction = I2C_Direction_Transmitter;
	state->slave_address = slave << 1;
	state->xfer_buffer = (uint8_t*)buffer;
	state->xfer_size = buffer_size;
	state->error = 0;

	/* Send START condition */
	I2C_GenerateSTART(bus, ENABLE);
	//I2Cx->CR1 |= CR1_START_Set;
	/* Wait until the START condition is generated on the bus: the START bit is cleared by hardware */
	while ((bus->CR1 & 0x100) == 0x100);
	/* Wait until BUSY flag is reset: a STOP has been generated on the bus signaling the end
	of transmission */
	while ((bus->SR2 & 0x0002) == 0x0002);

	return state->error;
}


static void _i2c_ev_it_handler(I2C_TypeDef * bus)
{
	i2c_bus_state_t * const state = _get_bus_state(bus);
	volatile uint32_t SR1Register = 0;
	volatile uint32_t SR2Register = 0;

	/* Read the bus SR1 and SR2 status registers */
	SR1Register = bus->SR1;
	SR2Register = bus->SR2;

	/* If SB = 1, I2C1 master sent a START on the bus: EV5) */
	if ((SR1Register & 0x0001) == 0x0001)
	{
		/* Send the slave address for transmssion or for reception (according to the configured value
			in the write master write routine */
		I2C_Send7bitAddress(bus, state->slave_address, state->xfer_direction);
		//I2C2->DR = state->slave_address;
		SR1Register = 0;
		SR2Register = 0;
	}

	/* If I2C2 is Master (MSL flag = 1) */
	if ((SR2Register &0x0001) == 0x0001)
	{
		/* If ADDR = 1, EV6 */
		if ((SR1Register &0x0002) == 0x0002)
		{
			/* Write the first data in case the Master is Transmitter */
			if (state->xfer_direction == I2C_Direction_Transmitter)
			{
				/* Write the first data in the data register */
				bus->DR = *(state->xfer_buffer++);
				/* Decrement the number of bytes to be written */
				state->xfer_size--;
				/* If no further data to be sent, disable the I2C BUF IT
				in order to not have a TxE  interrupt */
				if (state->xfer_size == 0)
				{
					bus->CR2 &= (uint16_t)~I2C_IT_BUF;
				}

			}
			/* Master Receiver */
			else
			{
				/* At this stage, ADDR is cleared because both SR1 and SR2 were read.*/
				/* EV6_1: used for single byte reception. The ACK disable and the STOP
				Programming should be done just after ADDR is cleared. */
				if (state->xfer_size == 1)
				{
					/* Clear ACK */
					I2C_AcknowledgeConfig(bus, DISABLE);
					//I2C2->CR1 &= CR1_ACK_Reset;
					/* Program the STOP */
					I2C_GenerateSTOP(bus, ENABLE);
					//I2C2->CR1 |= CR1_STOP_Set;
				}
			}
			SR1Register = 0;
			SR2Register = 0;

		}
		/* Master transmits the remaing data: from data2 until the last one.  */
		/* If TXE is set */
		if ((SR1Register &0x0084) == 0x0080)
		{
			/* If there is still data to write */
			if (state->xfer_size != 0)
			{
				/* Write the data in DR register */
				bus->DR = *(state->xfer_buffer++);
				/* Decrment the number of data to be written */
				state->xfer_size--;
				/* If  no data remains to write, disable the BUF IT in order
				to not have again a TxE interrupt. */
				if (state->xfer_size == 0)
				{
					/* Disable the BUF IT */
					bus->CR2 &= (uint16_t)~I2C_IT_BUF;
				}
			}
			SR1Register = 0;
			SR2Register = 0;
		}

		/* If BTF and TXE are set (EV8_2), program the STOP */
		if ((SR1Register &0x0084) == 0x0084)
		{

			/* Program the STOP */
			I2C_GenerateSTOP(bus, ENABLE);
			//I2C2->CR1 |= CR1_STOP_Set;
			/* Disable EVT IT In order to not have again a BTF IT */
			I2C2->CR2 &= (uint16_t)~I2C_IT_EVT;
			SR1Register = 0;
			SR2Register = 0;
		}

		/* If RXNE is set */
		if ((SR1Register &0x0040) == 0x0040)
		{
			/* Read the data register */
			*(state->xfer_buffer++) = (uint8_t)bus->DR;
			/* Decrement the number of bytes to be read */
			state->xfer_size--;

			/* If it remains only one byte to read, disable ACK and program the STOP (EV7_1) */
			if (state->xfer_size == 1)
			{
				/* Clear ACK */
				I2C_AcknowledgeConfig(bus, DISABLE);
				//I2C2->CR1 &= CR1_ACK_Reset;
				/* Program the STOP */
				I2C_GenerateSTOP(bus, ENABLE);
				//I2C2->CR1 |= CR1_STOP_Set;
			}
			SR1Register = 0;
			SR2Register = 0;
		}
	}
}


void I2C1_EV_IRQHandler(void)
{
	_i2c_ev_it_handler(I2C1);
}


void I2C2_EV_IRQHandler(void)
{
	_i2c_ev_it_handler(I2C2);
}



static void _i2c_er_it_handler(I2C_TypeDef * bus)
{
	i2c_bus_state_t * const state = _get_bus_state(bus);
	volatile  uint32_t SR1Register = 0;

	/* Read the bus status register */
	SR1Register = bus->SR1;
	/* If AF = 1 */
	if ((SR1Register & 0x0400) == 0x0400)
	{
		bus->SR1 &= 0xFBFF;
		SR1Register = 0;
		state->error = 0x0400;
		I2C_GenerateSTOP(bus, ENABLE);
	}

	/* If ARLO = 1 */
	if ((SR1Register & 0x0200) == 0x0200)
	{
		bus->SR1 &= 0xFDFF;
		SR1Register = 0;
		state->error = 0x0200;
		I2C_GenerateSTOP(bus, ENABLE);
	}

	/* If BERR = 1 */
	if ((SR1Register & 0x0100) == 0x0100)
	{
		bus->SR1 &= 0xFEFF;
		SR1Register = 0;
		state->error = 0x0100;
		I2C_GenerateSTOP(bus, ENABLE);
	}

	/* If OVR = 1 */
	if ((SR1Register & 0x0800) == 0x0800)
	{
		bus->SR1 &= 0xF7FF;
		SR1Register = 0;
		state->error = 0x0800;
		I2C_GenerateSTOP(bus, ENABLE);
	}
}


void I2C1_ER_IRQHandler(void)
{
	_i2c_er_it_handler(I2C1);
}


void I2C2_ER_IRQHandler(void)
{
	_i2c_er_it_handler(I2C2);
}
