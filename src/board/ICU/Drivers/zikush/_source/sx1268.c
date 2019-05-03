/*
 * 	Driver for sx1268 transceiver circuit
 *
 *  Created on: Mar 30, 2019
 *      Author: Kirs67
 */

#include <stdbool.h>
#include <string.h>

#include "sx1268.h"



/* Defines for internal usage */
#ifndef NULL
#define NULL ((uint8_t *)0x00)
#endif

#ifndef MIN
#define MIN(A, B) (A < B? A:B)
#endif

#define UINT24_T_FORM(SOURCE, BYTE0, BYTE1, BYTE2)		BYTE0 = SOURCE & 0xFF; BYTE1 = (SOURCE >> 8) & 0xFF; BYTE2 = (SOURCE >> 16) & 0xFF;
#define UINT24_T_DECODE(SOURCE, BYTE0, BYTE1, BYTE2)	SOURCE = BYTE0 | (BYTE1 << 8) | (BYTE2 << 16);

#define IRQFLAG_TXDONE	(1 << 0)
#define IRQFLAG_RXDONE	(1 << 1)
#define IRQFLAG_PREAMBLEDETECTED	(1 << 2)
#define IRQFLAG_SYNCWORDWALID	(1 << 3)
#define IRQFLAG_HEADERvALID	(1 << 4)
#define IRQFLAG_HEADERERR	(1 << 5)
#define IRQFLAG_CRCERR	(1 << 6)
#define IRQFLAG_CADDONE	(1 << 7)
#define IRQFLAG_CADDETECTED	(1 << 8)
#define IRQFLAG_TIMEOUT	(1 << 9)

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

#define XTAL_FREQ					(float) 32000000
#define FREQ_STEP					(float) 33554432 //2 ** 25
#define RFFREQ_CALC(FREQUENCY)		((uint32_t)(FREQUENCY / XTAL_FREQ * FREQ_STEP))
#define FREQ_ERR					0.47683715820312

#define STATUS_CHIPMODE(STATUS)	((STATUS>>4)&0x07)
#define STATUS_COMMAND(STATUS)	((STATUS>>1)&0x07)

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

typedef struct
{
	uint8_t br2, br1, br0, //defines baudrate (br = 32 * Fxtal / bit rate)
	PulseShape, //datasheet, table 13-44
	Bandwidth, //datasheet, table 13-45
	Fdev2, Fdev1, Fdev0; //Fdev = (Frequency Deviation * 2^25) / Fxtal
} sx1268_modparams_gfsk_t;

typedef struct //you'd better see a datasheet... (13.4.5.2)
{
	uint8_t sf, bw, cr, LowDataRateOptimize;
	uint32_t margin;
} sx1268_modparams_LoRa_t;

typedef struct
{
	uint8_t PreambleLength1, PreambleLength0, //Length of preamble, in bits
	PreambleDetectorLength, //Preamble detector length. 0 - off, 4-7 - represents 1-4 bytes
	SyncWordLength, //Sync word len in bits. Sync word should be written to 0x06C0 - 0x06C7 registers
	AddrComp, //Address filtering. 0 - disabled, 1 - node (reg 0x06CD) only, 2 - node and broadcast (0x06CE)
	PacketType, //0 - fixed size, 1 - dynamic size
	PayloadLength, //Size to transmit or maximum receiveable
	CRCType, //1 - off, 0 - 1b, 2 - 2b, 4 - 1b_inv, 6 - 2b_inv
	Whitening; //0 - off, 1 - on
} sx1268_packparams_gfsk_t;

typedef struct
{
	uint8_t PreambleLength1, PreambleLength0, //Length of premblamble, in bits
	HeaderType, //0 - variable size, 1 - fixed size
	PayloadLength, //Size to transmit or maximum receiveable
	CRCType, //0 - off, 1 - on
	InvertIQ, //1 - inverted IQ
	margin1, margin2, margin3; //structure should be 9 bytes long
} sx1268_packparams_LoRa_t;



/* Platform-specific functions declaration */
sx1268_status_t _cmd(sx1268_t * self, uint8_t opcode, uint8_t * buff, uint8_t arglength);
sx1268_status_t _cmd_WriteBuffer(sx1268_t * self,	uint8_t addr, uint8_t * data, uint8_t length);
sx1268_status_t _cmd_ReadBuffer(sx1268_t * self,	uint8_t addr, uint8_t * data, uint8_t length);
uint8_t _readbusypin(sx1268_t * self);


/* Functions, representing vaious commands */
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
	return _cmd(self, 0x96, (uint8_t *)&useDCDC, 1);
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
	sx1268_status_t retval = _cmd(self, 0x12, buff, 3);

	*Status = buff[0];
	*IrqStatus = buff[2] | (buff[1] << 8);
	return retval;
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
	return _cmd(self, 0x9D, (uint8_t *)&enable, 1);
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
	buff[0] = (RfFreq >> 24) & 0xFF;
	buff[1] = (RfFreq >> 16) & 0xFF;
	buff[2] = (RfFreq >> 8) & 0xFF;
	buff[3] = RfFreq & 0xFF;
	return _cmd(self, 0x86, buff, 4);
}


static inline sx1268_status_t _cmd_SetPacketType(sx1268_t * self, bool LoRa)
{
	return _cmd(self, 0x8A, (uint8_t *)&LoRa, 1);
}


static inline sx1268_status_t _cmd_GetPacketType(sx1268_t * self, bool * LoRa)
{
	uint8_t buff[2];
	sx1268_status_t retval = _cmd(self, 0x11, buff, 2);
	*LoRa = buff[1];

	return retval;
}


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


static inline sx1268_status_t _cmd_GetStatus(sx1268_t * self, uint8_t * status)
{
	return _cmd(self, 0xC0, status, 1);
}


static inline sx1268_status_t _cmd_GetRxBufferStatus(sx1268_t * self, uint8_t * Status, uint8_t * PayloadLengthRx, uint8_t * RxStartBufferPointer)
{
	uint8_t buff[3];
	return _cmd(self, 0x13, buff, 3);

	*Status = buff[0];
	*PayloadLengthRx = buff[1];
	*RxStartBufferPointer = buff[2];
}


#define FIFO_FREESPACE(FIFO) ((FIFO->tail - FIFO->head) % FIFO->length)
#define FIFO_USEDSPACE(FIFO) ((FIFO->head - FIFO->tail) % (FIFO->length))

static sx1268_status_t _fifo_write(sx1268_fifo_t * fifo, uint8_t * data, int len)
{
	if(FIFO_FREESPACE(fifo) < len & !fifo->empty)
		return SX1268_ERR_BUFSIZE;

	int copylen = MIN(fifo->length - fifo->head, len);
	memcpy(fifo->mem + fifo->head, data, copylen);
	fifo->head = (fifo->head + copylen) % fifo->length;

	memcpy(fifo->mem + fifo->head, data + copylen, len - copylen);
	fifo->head += (len - copylen) % fifo->length;

	fifo->empty = false;
	return SX1268_OK;
}

static sx1268_status_t _fifo_read(sx1268_fifo_t * fifo, uint8_t * data, int len)
{
	if(!fifo->empty)
	{
		if(fifo->length < len)
			return SX1268_ERR_BUFSIZE;
	}
	else if(FIFO_USEDSPACE(fifo) < len)
		return SX1268_ERR_BUFSIZE;

	int copylen = MIN(fifo->length - fifo->head, len);
	memcpy(fifo->mem + fifo->head, data, copylen);
	fifo->head = (fifo->head + copylen) % fifo->length;

	memcpy(fifo->mem + fifo->head, data + copylen, len - copylen);
	fifo->head += (len - copylen) % fifo->length;

	fifo->empty = false;
	return SX1268_OK;
}



/* Internal helper functions */
static void _sendpackparams(sx1268_t * self, uint8_t PayloadLength) //yeees, it's a very dumb way. But it's forced to be used by dumb transceiver
{
	sx1268_packparams_gfsk_t packparams;
	packparams.PreambleLength0 = 80;
	packparams.PreambleLength1 = 0;
	packparams.PreambleDetectorLength = 64; //FIXME maybe should be less
	packparams.SyncWordLength = 64;
	packparams.AddrComp = 0;
	packparams.PacketType = 1;
	packparams.PayloadLength = PayloadLength; // FIXME ?CoRrEcT?
	packparams.CRCType = 0;
	packparams.Whitening = 1;
	_cmd_SetPacketParams(self, (uint8_t *) &packparams);
}

static void _dotx(sx1268_t * self, uint8_t * buff, int len)
{
	volatile uint8_t status;
	_cmd_SetTxParams(self, POWER_LOW_HIGHEST, RAMPTIME_200U);
	_cmd_GetStatus(self, &status);
	_cmd_SetBufferBaseAddress(self, 0, 0);
	_cmd_GetStatus(self, &status);
	_cmd_WriteBuffer(self, 0, buff, len);
	_cmd_GetStatus(self, &status);
	_sendpackparams(self, len);
	_cmd_GetStatus(self, &status);
	_cmd_SetTX(self, 64000); //1 second timeout
	_cmd_GetStatus(self, &status);
}



/* Main functions */
void sx1268_struct_init(sx1268_t * self, uint8_t * rxbuff, int rxbufflen, uint8_t * txbuff, int txbufflen)
{
	self->fifo_rx.mem = rxbuff;
	self->fifo_rx.length = rxbufflen;
	self->fifo_rx.head = 0;
	self->fifo_rx.tail = 0;
	self->fifo_rx.empty = true;

	self->fifo_tx.mem = txbuff;
	self->fifo_tx.length = txbufflen;
	self->fifo_tx.head = 0;
	self->fifo_tx.tail = 0;
	self->fifo_tx.empty = true;
}

sx1268_status_t sx1268_init(sx1268_t * self)
{
	volatile uint8_t status;
	_cmd_GetStatus(self, &status);

	_cmd_SetStandby(self, false);

	_cmd_GetStatus(self, &status);

	_cmd_SetDIO3AsTCXOCtrl(self, 0x01, 320); //'magic' values from mbed driver
	_cmd_GetStatus(self, &status);
	_cmd_Calibrate(self, 0x7F); //also mbed magic
	_cmd_SetDIO2AsRfSwitchCtrl(self, true);
	_cmd_CalibrateImage(self, 0x6B, 0x6F); //430-440 MHz, according to datasheet
	_cmd_GetStatus(self, &status);
	_cmd_SetRfFrequency(self, RFFREQ_CALC(433000000));
	_cmd_GetStatus(self, &status);

	_cmd_SetPacketType(self, false); //set gfsk
	_cmd_GetStatus(self, &status);
	sx1268_modparams_gfsk_t modparams;
	uint32_t br = 32 * 32000000 / 4800;
	UINT24_T_FORM(br, modparams.br0, modparams.br1, modparams.br2);
	UINT24_T_FORM(1024, modparams.Fdev0, modparams.Fdev1, modparams.Fdev2);
	modparams.Bandwidth = 0x1D;
	modparams.PulseShape = 0x09;
	_cmd_SetModulationParams(self, (uint8_t *) &modparams);
	_cmd_GetStatus(self, &status);

	_sendpackparams(self, 255);
	_cmd_GetStatus(self, &status);

	uint8_t syncstring[] = "  antonloh";
	syncstring[0] = 0x06;
	syncstring[1] = 0xC0;
	_cmd_WriteRegister_burst(self, syncstring, 10);
	_cmd_GetStatus(self, &status);

	uint16_t TXRXDONEANDTIMEOUT = (1 << 0) | (1 << 1) | (1 << 9);
	_cmd_SetDioIrqParams(self, TXRXDONEANDTIMEOUT, TXRXDONEANDTIMEOUT, 0, 0);
	_cmd_GetStatus(self, &status);

	return SX1268_OK; //TODO
}

sx1268_status_t sx1268_send(sx1268_t * self, uint8_t * data, int len)
{
	if( _readbusypin(self) )
	{
		return _fifo_write(&self->fifo_tx, data, len);
	}

	uint8_t status;
	_cmd_GetStatus(self, &status);

	if(STATUS_CHIPMODE(status) != STATUS_CHIPMODE_STBY_RC)
		_cmd_SetStandby(self, false);

	_dotx(self, data, MIN(len, 255));
	_cmd_GetStatus(self, &status);

	if(len > 255) //we can send only 255 bytes in one packet, so everything except should be saved to fifo
	{
		_fifo_write(&self->fifo_tx, data + 255, len - 255);
	}

	return SX1268_OK;
}

sx1268_status_t sx1268_receive(sx1268_t * self, uint8_t * data, int len)
{
	if(FIFO_USEDSPACE((&self->fifo_rx)) < len)
		return SX1268_ERR_BUFSIZE;

	return _fifo_read(&self->fifo_rx, data, len);
}

void sx1268_event(sx1268_t * self)
{
	volatile uint16_t irqstatus;
	volatile uint8_t status;
	uint8_t buff[256];
	_cmd_GetIrqStatus(self, &status, &irqstatus);
	_cmd_ClearIrqStatus(self, irqstatus);

	if(irqstatus & IRQFLAG_RXDONE)
	{
		if(STATUS_COMMAND(status) == STATUS_COMMAND_AVAIL)
		{
			uint8_t start, len;
			_cmd_GetRxBufferStatus(self, &status, &start, &len);
			_cmd_ReadBuffer(self, start, buff, len);
			_fifo_write(&self->fifo_rx, buff, len);
		}
	}

	if(!self->fifo_tx.empty)
	{
		int len = FIFO_USEDSPACE((&self->fifo_tx));
		len = MIN(len, 255);

		_fifo_read(&self->fifo_tx, buff, len);
		_dotx(self, buff, len);
	}
}
