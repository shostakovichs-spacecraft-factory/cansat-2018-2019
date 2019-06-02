#ifndef ZIKUSH_CONFIG
#define ZIKUSH_CONFIG

#define CCU_SPECTRUM_WIDTH	376
#define CCU_SPECTRUM_HEIGHT	240

#define CCU_SPECTRUM_Y_START	0
#define CCU_SPECTRUM_Y_END		240
#define CCU_SPECTRUM_X_START	0
#define CCU_SPECTRUM_X_END		376

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
