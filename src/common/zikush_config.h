#ifndef ZIKUSH_CONFIG
#define ZIKUSH_CONFIG

/* Params for ICU */
#define ICU_SD_SESSFOLDERNAMEFMT	"0:/zikush/sess%04d"
#define ICU_SD_SESSNUMBOUNDARY	10000

#define ICU_SD_TELFILENAMEFMT	"0:/zikush/sess%04d/%s%02d.bin"

#define ICU_SD_MAXFILENAMELEN	32
#define ICU_SD_MAXFILELEN	4000000000



/* Params for PCU */
#define PCU_INA_ICU_ADDR	INA219_I2CADDR_A1_GND_A0_GND //FIXME dummy addresses, specify real ones
#define PCU_INA_SCU_ADDR	INA219_I2CADDR_A1_GND_A0_GND
#define PCU_INA_CCU_ADDR	INA219_I2CADDR_A1_GND_A0_GND

#define PCU_MEASFREQ_Hz	1

#define PCU_HEARTBEATSENDPERIOD_CYCL	1
#define PCU_CURRSENDPERIOD_CYCL	1
#define PCU_POWERSENDPERIOD_CYCL	10

#define PCU_CAN_TIMEOUT_MS	100

/* Params for CCU */
#define CCU_SPECTRUM_WIDTH	376
#define CCU_SPECTRUM_HEIGHT	240

#define CCU_SPECTRUM_Y_START	0
#define CCU_SPECTRUM_Y_END		240
#define CCU_SPECTRUM_X_START	0
#define CCU_SPECTRUM_X_END		376

#define CCU_TESTMODE	//Take picture every second and enable UART output

// params directly from Flow config. Better explanation could be found in datasheet
// TODO maybe we should implement on-the-fly parameters change?
#define CCU_SPECTRUM_PARAM_GAIN_MAX					16
#define CCU_SPECTRUM_PARAM_EXPOSURE_MAX				500
#define CCU_SPECTRUM_PARAM_SHTR_W_1					443
#define CCU_SPECTRUM_PARAM_SHTR_W_2					473
#define CCU_SPECTRUM_PARAM_SHTR_W_TOT				480
#define CCU_SPECTRUM_PARAM_HDR						1
#define CCU_SPECTRUM_PARAM_AEC						1
#define CCU_SPECTRUM_PARAM_AGC						1
#define CCU_SPECTRUM_PARAM_BRIGHT					20
#define CCU_SPECTRUM_PARAM_IMAGE_ROW_NOISE_CORR		1
#define CCU_SPECTRUM_PARAM_IMAGE_TEST_PATTERN		0

#endif // #ifndef ZIKUSH_CONFIG
