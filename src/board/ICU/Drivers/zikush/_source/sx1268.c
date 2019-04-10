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

#define RFFREQ_CALC(FREQ)	(FREQ * 32000000 / 2 ^ 25)

static inline sx1268_status_t _cmd_SetRfFrequency(sx1268_t * self, uint32_t RfFreq)
{
	uint8_t buff[4];
	buff[0] = (RfFreq >> 24) & 0xFF;
	buff[1] = (RfFreq >> 16) & 0xFF;
	buff[2] = (RfFreq >> 8) & 0xFF;
	buff[3] = RfFreq & 0xFF;
	return _cmd(self, 0x97, buff, 4);
}

static inline sx1268_status_t _cmd_SetPacketType(sx1268_t * self, bool LoRa)
{
	return _cmd(self, 0x8A, &LoRa, 1);
}

static inline sx1268_status_t _cmd_GetPacketType(sx1268_t * self, bool * LoRa)
{
	uint8_t buff[2];
	return _cmd(self, 0x11, buff, 2);
	LoRa = buff[1];
}

#define RAMPTIME_10U 	0x00
#define RAMPTIME_20U 	0x01
#define RAMPTIME_40U 	0x02
#define RAMPTIME_80U 	0x03
#define RAMPTIME_200U 	0x04
#define RAMPTIME_800U 	0x05
#define RAMPTIME_1700U 	0x06
#define RAMPTIME_3400U 	0x07

#define POWER_LOW_LOWEST	0xEF
#define POWER_LOW_HIGHEST	0x0E
#define POWER_HIGH_LOWEST	0xF7
#define POWER_HIGH_HIGHEST	0x16

static inline sx1268_status_t _cmd_SetTxParams(sx1268_t * self, uint8_t power, uint8_t RampTime)
{
	uint8_t buff[2];
	buff[0] = power;
	buff[1] = RampTime;
	return _cmd(self, 0x8E, buff, 2);
}

// Mod_Params - array of 8 uint8_t representing modulation params (see 13.4.5 section of datasheet)
static inline sx1268_status_t _cmd_SetModulationParams(sx1268_t * self, uint8_t * Mod_Params)
{

	return _cmd(self, 0x8B, Mod_Params, 8);
}

// Mod_Params - array of 8 uint8_t representing packet handling params (see 13.4.6 section of datasheet)
static inline sx1268_status_t _cmd_SetPacketParams(sx1268_t * self, uint8_t * Packet_Params)
{

	return _cmd(self, 0x8C, Packet_Params, 9);
}

static inline sx1268_status_t _cmd_SetBufferBaseAddress(sx1268_t * self, uint8_t rxbuff, uint8_t txbuff)
{
	uint8_t buff[2] = {rxbuff, txbuff};
	return _cmd(self, 0x8F, buff, 2);
}

#define STATUS_CHIPMODE(STATUS)	(STATUS>>4)&0x07
#define STATUS_COMMAND(STATUS)	(STATUS>>1)&0x07

#define STATUS_CHIPMODE_STBY_RC		0x02
#define STATUS_CHIPMODE_STBY_XOSC	0x03
#define STATUS_CHIPMODE_FS			0x04
#define STATUS_CHIPMODE_RX			0x05
#define STATUS_CHIPMODE_TX			0x06

#define STATUS_COMMAND_AVAIL		0x02
#define STATUS_COMMAND_TIMEOUT		0x03
#define STATUS_COMMAND_ERROR		0x04
#define STATUS_COMMAND_FAIL			0x05
#define STATUS_COMMAND_DONE			0x06

static inline sx1268_status_t _cmd_GetStatus(sx1268_t * self, uint8_t * status)
{
	return _cmd(self, 0xC0, status, 1);
}

void sx1268_struct_init(sx1268_t * self, uint8_t * rxbuff, int rxbufflen, uint8_t * txbuff, int txbufflen){
	self->fifo_rx.mem = rxbuff;
	self->fifo_rx.length = rxbufflen;
	self->fifo_rx.head = 0;
	self->fifo_rx.tail = 0;

	self->fifo_tx.mem = txbuff;
	self->fifo_tx.length = txbufflen;
	self->fifo_tx.head = 0;
	self->fifo_tx.tail = 0;
}

sx1268_status_t sx1268_init(sx1268_t * self)
{
	uint8_t status;
	_cmd_GetStatus(self, &status);

	if(STATUS_CHIPMODE(status) != STATUS_CHIPMODE_STBY_RC)
		_cmd_SetStandby(self, false);

	_cmd_SetPacketType(self, true);
	_cmd_SetRfFrequency(self, RFFREQ_CALC(432000000));
	_cmd_SetTxParams(self, POWER_LOW_HIGHEST, RAMPTIME_200U);
	_cmd_SetBufferBaseAddress(self, 0, 0);
	//_cmd_SetModulationParams(self, ///) TODO

	/*configure irq, maybe through calling msp function, which should be defined by user*/
}

sx1268_status_t sx1268_send(sx1268_t * self, uint8_t * data, int len)
{
	//TODO
}

sx1268_status_t sx1268_receive(sx1268_t * self, uint8_t * data, int len)
{
	//TODO
}

sx1268_status_t sx1268_event(sx1268_t * self)
{
	//TODO
}
