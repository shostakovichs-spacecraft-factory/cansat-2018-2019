/*
 * 	Driver for sx1268 transceiver circuit
 *
 *  Created on: Mar 30, 2019
 *      Author: Kirs67
 */

#include <stdbool.h>

#include "sx1268.h"

#ifndef NULL
#define NULL ((uint8_t *)0x00)
#endif

#define TIMEOUT 10000
#define TRY_UNTIL_TIMEOUT_HEADER for(cycles = 0; cycles < TIMEOUT; cycles++)
#define TRY_UNTIL_TIMEOUT_FOOTER if(cycles == TIMEOUT - 1) {status == SX1268_TIMEOUT; goto end;}


static sx1268_status_t _cmd(sx1268_t * self, uint8_t opcode, uint8_t * buff, uint8_t arglength)
{
	sx1268_status_t status = SX1268_OK;
	int cycles = 0;

	HAL_GPIO_WritePin(self->cs_port, self->cs_pin, GPIO_PIN_RESET);

	HAL_SPI_Transmit(self->bus, &opcode, 1, TIMEOUT);
	HAL_SPI_TransmitReceive(self->bus, buff, buff, arglength, TIMEOUT);

end:
	HAL_GPIO_WritePin(self->cs_port, self->cs_pin, GPIO_PIN_SET);
	return status;
}

static inline sx1268_status_t _cmd_SetSleep(sx1268_t * self, uint8_t sleepConfig)
{
	return _cmd(self, 0x84, &sleepConfig, 1);
}

static inline sx1268_status_t _cmd_SetStandby(sx1268_t * self, uint8_t standbyConfig)
{
	return _cmd(self, 0x80, &standbyConfig, 1);
}

static inline sx1268_status_t _cmd_SetFS(sx1268_t * self)
{
	return _cmd(self, 0xC1, NULL, 0);
}

static inline sx1268_status_t _cmd_SetTX(sx1268_t * self, uint32_t timeout)
{
	uint8_t buff[3];
	buff[0] = (timeout >> 16) & 0xFF;
	buff[1] = (timeout >> 8) & 0xFF;
	buff[2] = (timeout >> 0) & 0xFF;
	return _cmd(self, 0x83, buff, 3);
}

static inline sx1268_status_t _cmd_SetRX(sx1268_t * self, uint32_t timeout)
{
	uint8_t buff[3];
	buff[0] = (timeout >> 16) & 0xFF;
	buff[1] = (timeout >> 8) & 0xFF;
	buff[2] = (timeout >> 0) & 0xFF;
	return _cmd(self, 0x82, buff, 3);
}

static inline sx1268_status_t _cmd_StopTimerOnPreamble(sx1268_t * self, bool enable)
{
	return _cmd(self, 0x9F, (uint8_t *)&enable, 1); //FIXME pay attention to endianness
}

static inline sx1268_status_t _cmd_SetRxDutyCycle(sx1268_t * self, uint32_t rxPeriod, uint32_t sleepPeriod)
{
	uint8_t buff[6];
	buff[0] = (rxPeriod >> 16) & 0xFF;
	buff[1] = (rxPeriod >> 8) & 0xFF;
	buff[2] = (rxPeriod >> 0) & 0xFF;
	buff[3] = (sleepPeriod >> 16) & 0xFF;
	buff[4] = (sleepPeriod >> 8) & 0xFF;
	buff[5] = (sleepPeriod >> 0) & 0xFF;
	return _cmd(self, 0x9F, buff, 6);
}

static inline sx1268_status_t _cmd_SetCad(sx1268_t * self)
{
	return _cmd(self, 0xC5, NULL, 0);
}

static inline sx1268_status_t _cmd_SetTxContinuousWave(sx1268_t * self)
{
	return _cmd(self, 0xD1, NULL, 0);
}

static inline sx1268_status_t _cmd_SetTxInfinitePreamble(sx1268_t * self)
{
	return _cmd(self, 0xD2, NULL, 0);
}

static inline sx1268_status_t _cmd_SetRegulatorMode(sx1268_t * self, bool useDCDC)
{
	return _cmd(self, 0x96, &useDCDC, 1);
}

static inline sx1268_status_t _cmd_Calibrate(sx1268_t * self, uint8_t calibParam)
{
	return _cmd(self, 0x89, &calibParam, 1);
}

static inline sx1268_status_t _cmd_CalibrateImage(sx1268_t * self, uint8_t freg1, uint8_t freg2)
{
	uint8_t buff[2];
	buff[0] = freg1;
	buff[1] = freg2;
	return _cmd(self, 0x98, buff, 1);
}

static inline sx1268_status_t _cmd_SetPaConfig(sx1268_t * self, uint8_t paDutyCycle, uint8_t hpMax)
{
	uint8_t buff[4];
	buff[0] = paDutyCycle;
	buff[1] = hpMax;
	buff[2] = 0x00;
	buff[3] = 0x01;
	return _cmd(self, 0x95, buff, 4);
}

static inline sx1268_status_t _cmd_SetRxTxFallbackMode(sx1268_t * self, uint8_t fallbackMode)
{
	return _cmd(self, 0x93, &fallbackMode, 1);
}

static inline sx1268_status_t _cmd_WriteRegister_single(sx1268_t * self, uint16_t addr, uint8_t data)
{
	uint8_t buff[3];
	buff[0] = (addr >> 8) & 0xFF;
	buff[1] = addr & 0xFF;
	buff[2] = data;
	return _cmd(self, 0x0D, buff, 3);
}

static inline sx1268_status_t _cmd_ReadRegister_single(sx1268_t * self, uint16_t addr, uint8_t * data)
{
	uint8_t buff[3];
	buff[0] = (addr >> 8) & 0xFF;
	buff[1] = addr & 0xFF;
	buff[2] = 0;
	return _cmd(self, 0x1D, buff, 3);
}

//NOTE: address should be already in the first elements of data (16 bit, MSB first)
static inline sx1268_status_t _cmd_WriteRegister_burst(sx1268_t * self,	uint8_t * data, uint8_t length)
{
	return _cmd(self, 0x0D, data, length);
}

//NOTE: address should be already in the first elements of data (16 bit, MSB first)
static inline sx1268_status_t _cmd_ReadRegister_burst(sx1268_t * self,	uint8_t * data, uint8_t length)
{
	return _cmd(self, 0x1D, data, length);
}

//NOTE: address should be already in the first elements of data (16 bit, MSB first)
static inline sx1268_status_t _cmd_WriteBuffer(sx1268_t * self,	uint8_t * data, uint8_t length)
{
	return _cmd(self, 0x0E, data, length);
}

//NOTE: address should be already in the first elements of data (16 bit, MSB first)
static inline sx1268_status_t _cmd_ReadBuffer(sx1268_t * self,	uint8_t * data, uint8_t length)
{
	return _cmd(self, 0x1E, data, length);
}

static inline sx1268_status_t _cmd_SetDioIrqParams(sx1268_t * self, uint16_t irqmask, \
												uint16_t dio1mask, uint16_t dio2mask, uint16_t dio3mask)
{
	uint8_t buff[8];
	buff[0] = (irqmask >> 8) & 0xFF;
	buff[1] = irqmask & 0xFF;
	buff[2] = (dio1mask >> 8) & 0xFF;
	buff[3] = dio1mask & 0xFF;
	buff[4] = (dio2mask >> 8) & 0xFF;
	buff[5] = dio2mask & 0xFF;
	buff[6] = (dio3mask >> 8) & 0xFF;
	buff[7] = dio3mask & 0xFF;

	return _cmd(self, 0x08, buff, 8);
}

static inline sx1268_status_t _cmd_GetIrqStatus(sx1268_t * self, uint8_t * Status, uint16_t *IrqStatus)
{
	uint8_t buff[3];
	return _cmd(self, 0x12, buff, 3);

	*Status = buff[0];
	*IrqStatus = buff[2] | (buff[1] << 8);
}

static inline sx1268_status_t _cmd_ClearIrqStatus(sx1268_t * self, uint16_t ClearIrqParam)
{
	uint8_t buff[2];
	buff[0] = (ClearIrqParam >> 8) & 0xFF;
	buff[1] = ClearIrqParam & 0xFF;
	return _cmd(self, 0x02, buff, 2);
}

static inline sx1268_status_t _cmd_SetDIO2AsRfSwitchCtrl(sx1268_t * self, bool enable)
{
	return _cmd(self, 0x9D, &enable, 1);
}

static inline sx1268_status_t _cmd_SetDIO3AsTCXOCtrl(sx1268_t * self, uint8_t txcoVoltage, uint32_t timeout)
{
	uint8_t buff[4];
	buff[0] = txcoVoltage;
	buff[1] = (timeout >> 16) & 0xFF;
	buff[2] = (timeout >> 8) & 0xFF;
	buff[3] = timeout & 0xFF;
	return _cmd(self, 0x97, buff, 4);
}

static inline sx1268_status_t _cmd_SetRfFrequency(sx1268_t * self, uint32_t RfFreq)
{
	uint8_t buff[4];
	buff[0] = (timeout >> 16) & 0xFF;
	buff[1] = (timeout >> 16) & 0xFF;
	buff[2] = (timeout >> 8) & 0xFF;
	buff[3] = timeout & 0xFF;
	return _cmd(self, 0x97, buff, 4);
}
