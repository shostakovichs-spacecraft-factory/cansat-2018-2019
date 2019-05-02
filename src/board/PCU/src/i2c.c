/*
 * i2c.c
 *
 *  Created on: 20 апр. 2019 г.
 *      Author: snork
 */

#include "i2c.h"

#include <stdlib.h>


#define I2C_IT_BUF                      ((uint16_t)0x0400)
#define I2C_IT_EVT                      ((uint16_t)0x0200)
#define I2C_IT_ERR                      ((uint16_t)0x0100)

#define I2C_DIRECTION_TX 0
#define I2C_DIRECTION_RX 1



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
	bus_init.I2C_DutyCycle = I2C_DutyCycle_2;
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


int i2c_read(I2C_TypeDef * bus, uint8_t slave, void * buffer_, size_t buffer_size)
{
	uint32_t temp = 0;
	uint32_t Timeout = 0;
	uint8_t * buffer = (uint8_t*)buffer_;

	/* Enable I2C errors interrupts (used in all modes: Polling, DMA and Interrupts */
	bus->CR2 |= I2C_IT_ERR;

	int Error = -1;

	if (buffer_size == 1)
	{
		Timeout = 0xFFFF;
		/* Send START condition */
		I2C_GenerateSTART(bus, ENABLE);
		/* Wait until SB flag is set: EV5  */
		while ((bus->SR1 & 0x0001) != 0x0001)
		{
			if (Timeout-- == 0)
				return Error;
		}
		/* Send slave address */
		I2C_Send7bitAddress(bus, slave << 1, I2C_Direction_Receiver);

		/* Wait until ADDR is set: EV6_3, then program ACK = 0, clear ADDR
		and program the STOP just after ADDR is cleared. The EV6_3
		software sequence must complete before the current byte end of transfer.*/
		/* Wait until ADDR is set */
		Timeout = 0xFFFF;
		while ((bus->SR1 & 0x0002) != 0x0002)
		{
			if (Timeout-- == 0)
				return Error;
		}
		/* Clear ACK bit */
		I2C_AcknowledgeConfig(bus, DISABLE);
		/* Disable all active IRQs around ADDR clearing and STOP programming because the EV6_3
		software sequence must complete before the current byte end of transfer */
		__disable_irq();
		/* Clear ADDR flag */
		temp = bus->SR2;
		/* Program the STOP */
		I2C_GenerateSTOP(bus, ENABLE);
		/* Re-enable IRQs */
		__enable_irq();
		/* Wait until a data is received in DR register (RXNE = 1) EV7 */
		while ((bus->SR1 & 0x00040) != 0x000040);
		/* Read the data */
		*buffer = bus->DR;
		/* Make sure that the STOP bit is cleared by Hardware before CR1 write access */
		while ((bus->CR1&0x200) == 0x200);
		/* Enable Acknowledgement to be ready for another reception */
		I2C_AcknowledgeConfig(bus, ENABLE);

	}
	else if (buffer_size == 2)
	{
		/* Set POS bit */
		I2C_PECPositionConfig(bus, I2C_PECPosition_Next);
		Timeout = 0xFFFF;
		/* Send START condition */
		I2C_GenerateSTART(bus, ENABLE);
		/* Wait until SB flag is set: EV5 */
		while ((bus->SR1 & 0x0001) != 0x0001)
		{
			if (Timeout-- == 0)
				return Error;
		}
		Timeout = 0xFFFF;
		/* Send slave address */
		I2C_Send7bitAddress(bus, slave << 1, I2C_Direction_Receiver);
		/* Wait until ADDR is set: EV6 */
		while ((bus->SR1 & 0x0002) != 0x0002)
		{
			if (Timeout-- == 0)
				return Error;
		}
		/* EV6_1: The acknowledge disable should be done just after EV6,
		that is after ADDR is cleared, so disable all active IRQs around ADDR clearing and
		ACK clearing */
		__disable_irq();
		/* Clear ADDR by reading SR2 register  */
		temp = bus->SR2;
		/* Clear ACK */
		I2C_AcknowledgeConfig(bus, DISABLE);
		/*Re-enable IRQs */
		__enable_irq();
		/* Wait until BTF is set */
		while ((bus->SR1 & 0x00004) != 0x000004);
		/* Disable IRQs around STOP programming and data reading because of the limitation ?*/
		__disable_irq();
		/* Program the STOP */
		I2C_GenerateSTOP(bus, ENABLE);
		/* Read first data */
		*buffer = bus->DR;
		/* Re-enable IRQs */
		__enable_irq();
		/**/
		buffer++;
		/* Read second data */
		*buffer = bus->DR;
		/* Make sure that the STOP bit is cleared by Hardware before CR1 write access */
		while ((bus->CR1&0x200) == 0x200);
		/* Enable Acknowledgement to be ready for another reception */
		I2C_AcknowledgeConfig(bus, ENABLE);
		/* Clear POS bit */
		I2C_PECPositionConfig(bus, I2C_PECPosition_Current);
	}
	else
	{
		Timeout = 0xFFFF;
		/* Send START condition */
		I2C_GenerateSTART(bus, ENABLE);
		/* Wait until SB flag is set: EV5 */
		while ((bus->SR1 & 0x0001) != 0x0001)
		{
			if (Timeout-- == 0)
				return Error;
		}
		Timeout = 0xFFFF;
		/* Send slave address */
		I2C_Send7bitAddress(bus, slave << 1, I2C_Direction_Receiver);
		/* Wait until ADDR is set: EV6 */
		while ((bus->SR1 & 0x0002) != 0x0002)
		{
			if (Timeout-- == 0)
				return Error;
		}
		/* Clear ADDR by reading SR2 status register */
		temp = bus->SR2;
		/* While there is data to be read */
		while (buffer_size)
		{
			/* Receive bytes from first byte until byte N-3 */
			if (buffer_size != 3)
			{
				/* Poll on BTF to receive data because in polling mode we can not guarantee the
				EV7 software sequence is managed before the current byte transfer completes */
				while ((bus->SR1 & 0x00004) != 0x000004);
				/* Read data */
				*buffer = bus->DR;
				/* */
				buffer++;
				/* Decrement the read bytes counter */
				buffer_size--;
			}

			/* it remains to read three data: data N-2, data N-1, Data N */
			if (buffer_size == 3)
			{

				/* Wait until BTF is set: Data N-2 in DR and data N -1 in shift register */
				while ((bus->SR1 & 0x00004) != 0x000004);
				/* Clear ACK */
				I2C_AcknowledgeConfig(bus, DISABLE);

				/* Disable IRQs around data reading and STOP programming because of the
				limitation ? */
				__disable_irq();
				/* Read Data N-2 */
				*buffer = bus->DR;
				/* Increment */
				buffer++;
				/* Program the STOP */
				I2C_GenerateSTOP(bus, ENABLE);
				/* Read DataN-1 */
				*buffer = bus->DR;
				/* Re-enable IRQs */
				__enable_irq();
				/* Increment */
				buffer++;
				/* Wait until RXNE is set (DR contains the last data) */
				while ((bus->SR1 & 0x00040) != 0x000040);
				/* Read DataN */
				*buffer = bus->DR;
				/* Reset the number of bytes to be read by master */
				buffer_size = 0;
			}
		}
		/* Make sure that the STOP bit is cleared by Hardware before CR1 write access */
		while ((bus->CR1 & 0x200) == 0x200);
		/* Enable Acknowledgement to be ready for another reception */
		I2C_AcknowledgeConfig(bus, ENABLE);
	}

	return 0;
}


int i2c_write(I2C_TypeDef * bus, uint8_t slave, void * buffer_, size_t buffer_size)
{
	uint32_t temp = 0;
	uint32_t Timeout = 0;
	int Error = -1;
	uint8_t * buffer = (uint8_t*)buffer_;

	/* Enable Error IT (used in all modes: DMA, Polling and Interrupts */
	bus->CR2 |= I2C_IT_ERR;

	Timeout = 0xFFFF;
	/* Send START condition */
	I2C_GenerateSTART(bus, ENABLE);
	/* Wait until SB flag is set: EV5 */
	while ((bus->SR1 & 0x0001) != 0x0001)
	{
		if (Timeout-- == 0)
			return Error;
	}

	/* Send slave address */
	/* Reset the address bit0 for write*/
	I2C_Send7bitAddress(bus, slave << 1, I2C_Direction_Transmitter);
	Timeout = 0xFFFF;
	/* Wait until ADDR is set: EV6 */
	while ((bus->SR1 & 0x0002) != 0x0002)
	{
		if (Timeout-- == 0)
			return Error;
	}

	/* Clear ADDR flag by reading SR2 register */
	temp = bus->SR2;
	/* Write the first data in DR register (EV8_1) */
	bus->DR = *buffer;
	/* Increment */
	buffer++;
	/* Decrement the number of bytes to be written */
	buffer_size--;
	/* While there is data to be written */
	while (buffer_size--)
	{
		/* Poll on BTF to receive data because in polling mode we can not guarantee the
		  EV8 software sequence is managed before the current byte transfer completes */
		while ((bus->SR1 & 0x00004) != 0x000004);
		/* Send the current byte */
		bus->DR = *buffer;
		/* Point to the next byte to be written */
		buffer++;
	}
	/* EV8_2: Wait until BTF is set before programming the STOP */
	while ((bus->SR1 & 0x00004) != 0x000004);
	/* Send STOP condition */
	I2C_GenerateSTOP(bus, ENABLE);
	/* Make sure that the STOP bit is cleared by Hardware */
	while ((bus->CR1 & 0x200) == 0x200);

	return 0;
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
