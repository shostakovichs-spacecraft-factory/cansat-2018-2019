#include <stm32f4xx_hal.h>

#include "lsm6ds3.h"
#include "i2c.h"
#include "bme280.h"
#include <stdio.h>
#include <diag/Trace.h>
#include "i2c.h"
#include "ads1x1x.h"
#include "mpx2100ap.h"
#include "ds18b20.h"
#include "Time.h"
#include "spi.h"
#include "lsm6ds3.h"
#include "lsm303c.h"
#include "mag_calib.h"
#include <math.h>
#include "MadgwickAHRS.h"
#include "ahrs.h"
#include "my_uart.h"

#include "thread.h"

void
__initialize_hardware(void);

typedef struct{
	float ds_temp;
	float bme_temp;
	float bme_pres;
	float bme_hum;
	float mpx_pres;
} data_struct_t;

CAN_HandleTypeDef hcan;
void CAN_Send(data_struct_t * data);

void bmp_test(I2C_HandleTypeDef * Hi2c);

void adc_iternal();

void uart_test();

void ads1115_test(I2C_HandleTypeDef * hi2c);

int lsm6ds3_test()
{

	SPI_HandleTypeDef hspi;
	spi_config_default(&hspi);
	hspi.Instance = SPI1;
	spi_pin_miso_init(&hspi, GPIOA, GPIO_PIN_6);
	spi_pin_mosi_init(&hspi, GPIOA, GPIO_PIN_7);
	spi_pin_sck_init(&hspi, GPIOA, GPIO_PIN_5);
	spi_pin_nss_init(&hspi, GPIOA, GPIO_PIN_4);

	spi_init(&hspi);



	struct lsm6ds3_dev_s hlsm6;
	lsm6ds3_conf_default(&hlsm6);
	lsm6ds3_register_spi(&hlsm6, &hspi);
	HAL_Delay(50);
	lsm6ds3_push_conf(&hlsm6);
	//hspi.Instance->CR2 |= SPI_CR2_SSOE;
	//hspi.Instance->CR1 &= ~SPI_CR1_SSM;
	HAL_Delay(50);
	int rc = 0;
	uint8_t reg_ctrl7;
	uint8_t reg_ctrl4;
	uint8_t reg_ctrl2;

	rc = lsm6ds3_read_regn(&hlsm6, 0x16, &reg_ctrl7, 1);
	if (rc < 0)
		return rc;

	rc = lsm6ds3_read_regn(&hlsm6, 0x13, &reg_ctrl4, 1);
		if (rc < 0)
			return rc;

	rc = lsm6ds3_read_regn(&hlsm6, 0x11, &reg_ctrl2, 1);
	if (rc < 0)
		return rc;
	while(1)
	{
		HAL_Delay(10);
		struct lsm6ds3_raw_data_s rd = {{0,0,0},{0,0,0}};
		lsm6ds3_gxl_pull(&hlsm6, &rd);
		float dd[3];
		lsm6ds3_scale_g(&hlsm6.conf.g, rd.g, dd, 3);
		trace_printf("Gyro: %5.5f %5.5f %5.5f   ", dd[0], dd[1], dd[2]);

	    //lsm6ds3_read_regn(&hlsm6, 0x22, (uint8_t*)&rd, sizeof(rd)/2);
		lsm6ds3_scale_xl(&hlsm6.conf.xl, rd.xl, dd, 3);
		trace_printf("Axel: %5.5f %5.5f %5.5f\n", dd[0], dd[1], dd[2]);

	}
	return 0;
}

void toEulerAngle(quaternion_t *q, double *roll, double *pitch, double *yaw)
{
	// roll (x-axis rotation)
	double sinr_cosp = +2.0 * (q->w * q->x + q->y * q->z);
	double cosr_cosp = +1.0 - 2.0 * (q->x * q->x + q->y * q->y);
	*roll = atan2(sinr_cosp, cosr_cosp);

	// *pitch (y-axis rotation)
	double sinp = +2.0 * (q->w * q->y - q->z * q->x);
	if (fabs(sinp) >= 1)
		*pitch = copysign(M_PI / 2, sinp); // use 90 degrees if out of range
	else
		*pitch = asin(sinp);

	// *yaw (z-axis rotation)
	double siny_cosp = +2.0 * (q->w * q->z + q->x * q->y);
	double cosy_cosp = +1.0 - 2.0 * (q->y * q->y + q->z * q->z);
	*yaw = atan2(siny_cosp, cosy_cosp);
}

void madgwick_test();
int main()
{

	trace_printf("\n\nHello world!!!\n");
	__initialize_hardware();
	//uint32_t t1 = HAL_GetTick();
	//int *arr = malloc(sizeof(*arr) * 30000);
	//trace_printf("%d, %d", HAL_GetTick() - t1, arr);
	// Call the CSMSIS system clock routine to store the clock frequency
	// in the SystemCoreClock global RAM location.
	//SystemCoreClockUpdate();
	__GPIOB_CLK_ENABLE();
	__GPIOA_CLK_ENABLE();
	__GPIOC_CLK_ENABLE();
	__GPIOD_CLK_ENABLE();

	__I2C1_CLK_ENABLE();
	__CAN1_CLK_ENABLE();

	madgwick_test();

	return 0;
}

float maxf(float a, float b)
{
	return a > b ? a : b;
}
float minf(float a, float b)
{
	return a < b ? a : b;
}

void madgwick_test()
{
	SPI_HandleTypeDef hspi;
	spi_config_default(&hspi);
	hspi.Instance = SPI1;
	spi_pin_miso_init(&hspi, GPIOA, GPIO_PIN_6);
	spi_pin_mosi_init(&hspi, GPIOA, GPIO_PIN_7);
	spi_pin_sck_init(&hspi, GPIOA, GPIO_PIN_5);
	spi_pin_nss_init(&hspi, GPIOA, GPIO_PIN_4);

	spi_init(&hspi);

	struct lsm6ds3_dev_s hlsm6;
	lsm6ds3_conf_default(&hlsm6);
	lsm6ds3_register_spi(&hlsm6, &hspi);
	HAL_Delay(50);
	lsm6ds3_push_conf(&hlsm6);


	I2C_HandleTypeDef hi2c;
	i2c_pin_scl_init(GPIOB, GPIO_PIN_6);
	i2c_pin_sda_init(GPIOB, GPIO_PIN_7);
	i2c_config_default(&hi2c);
	hi2c.Instance = I2C1;
	i2c_init(&hi2c);

	struct lsm303c_handler_s hlsm3;
	lsm303c_m_conf_default(&hlsm3);
	lsm303c_register_i2c(&hlsm3, &hi2c);
	lsm303c_m_push_conf(&hlsm3, &hlsm3.conf.m);



	__USART3_CLK_ENABLE();
	__USART2_CLK_ENABLE();
	__USART1_CLK_ENABLE();

	GPIO_InitTypeDef pa_init;
	pa_init.Alternate = GPIO_AF7_USART3;
	pa_init.Mode = GPIO_MODE_AF_PP;
	pa_init.Pin = GPIO_PIN_10;
	pa_init.Pull = GPIO_NOPULL;
	pa_init.Speed = GPIO_SPEED_FAST;
	HAL_GPIO_Init(GPIOC, &pa_init);

	pa_init.Pin = GPIO_PIN_11;
	HAL_GPIO_Init(GPIOC, &pa_init);

	UART_HandleTypeDef huart;
	uart_config_default(&huart);
	huart.Instance = USART3;
	huart.Init.BaudRate = 9600;
	uart_init(&huart);





	trace_printf("\n%s\n", "Hi!");
	HAL_Delay(5000);
	mag_calib_init();
	//trace_printf("%s\n", "Begin mag calibration");
	//mag_calib_calibrate_lsm303c(&hlsm3, 500, 100);
	//trace_printf("%s\n", "End mag calibration");
	//HAL_Delay(5000);

	struct lsm303c_raw_data_m_s rdm;
	struct lsm6ds3_raw_data_s rd = {{0,0,0},{0,0,0}};
	float ddx[3], ddg[3], ddm[3];
	vector_t vx, vg, vm;

	lsm303c_m_pull(&hlsm3, &rdm);
	lsm303c_scale_m(&hlsm3, rdm.m, ddm, 3);
	mag_calib_scale(ddm, ddm);

	ahrs_init();
	ahrs_setKoefB(2.0);
	ahrs_vectorActivate(AHRS_LIGHT, 0);
	ahrs_vectorActivate(AHRS_MAG, 1);
	ahrs_vectorActivate(AHRS_ACCEL, 1);

	lsm6ds3_gxl_pull(&hlsm6, &rd);
	lsm6ds3_scale_xl(&hlsm6.conf.xl, rd.xl, ddx, 3);


	vx.x = ddx[0];
	vx.y = ddx[1];
	vx.z = ddx[2];
	vec_normalize(&vx);

	vm.x = ddm[0];
	vm.y = ddm[1];
	vm.z = ddm[2];
	vec_normalize(&vm);
	ahrs_updateVecReal(AHRS_ACCEL, vx);
	ahrs_updateVecReal(AHRS_MAG, vm);

	uint32_t time_prev = HAL_GetTick();
	HAL_Delay(10);

	volatile float best_mag_values[3][2];
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 2; j++)
			best_mag_values[i][j] = 0;/*
	while(1)
	{
		lsm303c_m_pull(&hlsm3, &rdm);
		lsm303c_scale_m(&hlsm3, rdm.m, ddm, 3);

		trace_printf("%.3f\t%.3f\t%.3f\n", ddm[0], ddm[1], ddm[2]);
		for(int i = 0; i < 3; i++)
		{
			best_mag_values[i][0] = maxf(ddm[i], best_mag_values[i][0]);
			best_mag_values[i][1] = minf(ddm[i], best_mag_values[i][1]);
		}
	}*/

	while(1)
	{
		uint32_t time_now = HAL_GetTick();

		lsm303c_m_pull(&hlsm3, &rdm);
		lsm6ds3_gxl_pull(&hlsm6, &rd);

		lsm303c_scale_m(&hlsm3, rdm.m, ddm, 3);
		lsm6ds3_scale_g(&hlsm6.conf.g, rd.g, ddg, 3);
		lsm6ds3_scale_xl(&hlsm6.conf.xl, rd.xl, ddx, 3);
		for(int i = 0; i < 3; i++)
		{
			ddg[i] *= 2 * M_PI;
		}
		mag_calib_scale(ddm, ddm);
		trace_printf("%.3f\t%.3f\t%.3f\n", ddm[0], ddm[1], ddm[2]);
		//char str[100];
		//int count = sprintf(str, "%.2f\t%.2f\t%.2f\n", ddm[0], ddm[1], ddm[2]);
		//HAL_UART_Transmit(&huart, str, count, 2000);\

		//trace_printf("Gyro: \t%8.3f %8.3f %8.3f \n", ddg[0], ddg[1], ddg[2]);

	    //lsm6ds3_read_regn(&hlsm6, 0x22, (uint8_t*)&rd, sizeof(rd)/2);
		//trace_printf("Axel: \t%8.3f %8.3f %8.3f \n", ddx[0], ddx[1], ddx[2]);




		vx.x = ddx[0];
		vx.y = ddx[1];
		vx.z = ddx[2];
		vec_normalize(&vx);

		vm.x = ddm[0];
		vm.y = ddm[1];
		vm.z = ddm[2];
		vec_normalize(&vm);
		//trace_printf("Mag: \t%8.3f %8.3f %8.3f \n", vm.x, vm.y, vm.z);
		ahrs_updateVecMeasured(AHRS_ACCEL, vx);
		ahrs_updateVecMeasured(AHRS_MAG, vm);
		ahrs_updateGyroData(vec_init(0,0,0));
		ahrs_calculateOrientation((time_now - time_prev)/1000.0);

		sampleFreq = 1000 / (float)(time_now - time_prev);
		MadgwickAHRSupdate(0, 0, 0, vx.x, vx.y, vx.z, vm.x, vm.y, vm.z);
		//quaternion_t result = quat_init(q0, q1, q2, q3);
		quaternion_t result = ahrs_getOrientation();
		double r[3];
		toEulerAngle(&result, &r[0], &r[1], &r[2]);
		for(int i = 0; i < 3; i++)
		{
			r[i] *= 180 / M_PI;
		}
		trace_printf("\t%8.3lf %8.3lf %8.3lf \n", r[0], r[1], r[2]);
		HAL_Delay(50);
		time_prev = time_now;

	}
}

//
//int main_spring_show()
//{
//
//	__initialize_hardware();
//
//
//	// Call the CSMSIS system clock routine to store the clock frequency
//	// in the SystemCoreClock global RAM location.
//	//SystemCoreClockUpdate();
//	__GPIOB_CLK_ENABLE();
//	__GPIOA_CLK_ENABLE();
//
//	__I2C1_CLK_ENABLE();
//	__CAN1_CLK_ENABLE();
//	//__CAN2_CLK_ENABLE();
//
//	I2C_HandleTypeDef hi2c;
//	i2c_pin_scl_init(GPIOB, GPIO_PIN_6);
//	i2c_pin_sda_init(GPIOB, GPIO_PIN_7);
//	i2c_config_default(&hi2c);
//	hi2c.Instance = I2C1;
//	i2c_init(&hi2c);
//
//	/*CAN initialisation*/
//	GPIO_InitTypeDef gpio_init =
//	{
//		.Mode = GPIO_MODE_AF_PP,
//		.Alternate = GPIO_AF9_CAN1,
//		.Pull = GPIO_NOPULL,
//		.Speed = GPIO_SPEED_LOW,
//		.Pin = GPIO_PIN_12
//	};
//	HAL_GPIO_Init(GPIOA, &gpio_init);
//
//	gpio_init.Mode = GPIO_MODE_INPUT;
//	gpio_init.Pin = GPIO_PIN_11;
//	HAL_GPIO_Init(GPIOA, &gpio_init);
//
//	GPIOA->AFR[1] &= ~(0x0F << 12);
//	GPIOA->AFR[1] |= GPIO_AF9_CAN1 << 12;
//
//	GPIOA->MODER &= ~GPIO_MODER_MODER11;
//	GPIOA->MODER |= GPIO_MODER_MODER11_1;
//
//	hcan.Instance = CAN1;
//	hcan.Init.Prescaler = 466;
//	hcan.Init.Mode = CAN_MODE_NORMAL;
//	hcan.Init.SJW = CAN_SJW_1TQ;
//	hcan.Init.BS1 = CAN_BS1_5TQ;
//	hcan.Init.BS2 = CAN_BS2_2TQ;
//	hcan.Init.TTCM = DISABLE;
//	hcan.Init.ABOM = DISABLE;
//	hcan.Init.AWUM = DISABLE;
//	hcan.Init.NART = ENABLE;
//	hcan.Init.RFLM = DISABLE;
//	hcan.Init.TXFP = DISABLE;
//	HAL_CAN_Init(&hcan);
//
//	mavlink_get_channel_status(MAVLINK_COMM_0)->flags |= MAVLINK_STATUS_FLAG_OUT_MAVLINK1;
//
//
//	ADS1x1x_config_t ads;
//	ADS1x1x_config_default(&ads);
//	ADS1x1x_register_i2c(&ads, &hi2c, ADS1x1x_I2C_ADDRESS_ADDR_TO_GND << 1);
//	ADS1x1x_init(&ads);
//
//	delay_init();
//	onewire_t how;
//	onewire_Init(&how, GPIOB, GPIO_PIN_3);
//
//	struct bme280_dev_s hbme;
//	thread_init_bme280(&hbme, &hi2c);
//
//	ds18b20_config_t hds;
//	thread_init_ds18b20(&hds, &how);
//
//	thread_init_mpx2100ap(&ads);
//
//	data_struct_t Data;
//	uint8_t isGood[3] = {1,};
//	uint8_t arg[100];
//	while(1)
//	{
//		{
//			thread_update_bme280(&hbme, arg);
//
//			struct bme280_float_data_s *d = (struct bme280_float_data_s*)(arg + 4);
//
//			Data.bme_pres = d->pressure;
//			Data.bme_hum = d->humidity;
//			Data.bme_temp = d->temperature;
//		}
//
//		{
//			thread_update_ds18b20(&hds, arg);
//
//			float *d = (float*)(arg + 1);
//
//			Data.ds_temp = *d;
//		}
//
//		{
//			thread_update_mpx2100ap(&ads, arg);
//
//			float *d = (float*)(arg + 1);
//
//			Data.mpx_pres = *d;
//		}
//
//		CAN_Send(&Data);
//
//		HAL_Delay(1000); //Stupid but simple
//	}
//
//	return 0;
//}


////////////////////
//Test functions and some other stuff
///////////////
void ads1115_test(I2C_HandleTypeDef * hi2c)
{

	ADS1x1x_config_t ads;
	ADS1x1x_config_default(&ads);
	ADS1x1x_register_i2c(&ads, hi2c, ADS1x1x_I2C_ADDRESS_ADDR_TO_GND << 1);
	ADS1x1x_init(&ads);

	while(1)
	{
		ADS1x1x_start_conversion(&ads);
		HAL_Delay(200);
		uint16_t data = ADS1x1x_read(&ads);

		float result = mpx2100ap_compensate_pressure_flt(data);
		trace_printf("pressure: %3.1f kPa %4X\n", result/1000, data);
	}

}

void uart_test()
{
	UART_HandleTypeDef uartHandler;
		uartHandler.Instance = USART1;
		uartHandler.Init.BaudRate = 115200;
		uartHandler.Init.HwFlowCtl = UART_HWCONTROL_NONE;
		uartHandler.Init.Mode = UART_MODE_TX_RX;
		uartHandler.Init.OverSampling = UART_OVERSAMPLING_16;
		uartHandler.Init.Parity = UART_PARITY_NONE;
		uartHandler.Init.StopBits = UART_STOPBITS_1;
		uartHandler.Init.WordLength = UART_WORDLENGTH_8B;


		HAL_UART_Init(&uartHandler);

		SPI_HandleTypeDef spiHandler;
		spiHandler.Instance = SPI1;

		spiHandler.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_256;
		spiHandler.Init.Direction = SPI_DIRECTION_2LINES;
		spiHandler.Init.CLKPhase = SPI_PHASE_2EDGE;
		spiHandler.Init.CLKPolarity = SPI_POLARITY_HIGH;
		spiHandler.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLED;
		spiHandler.Init.DataSize = SPI_DATASIZE_8BIT;
		spiHandler.Init.FirstBit = SPI_FIRSTBIT_LSB;
		spiHandler.Init.NSS = SPI_NSS_SOFT;
		spiHandler.Init.TIMode = SPI_TIMODE_DISABLED;
		spiHandler.Init.Mode = SPI_MODE_MASTER;

		HAL_SPI_Init(&spiHandler);


		char data[] = "hello world\n";
		while(1)
		{
			HAL_UART_Transmit(&uartHandler, (uint8_t*)data, sizeof(data)-1, HAL_MAX_DELAY);
		}
}

void adc_iternal()
{
	ADC_HandleTypeDef h;
	h.Instance = ADC1;
	h.Init.ClockPrescaler        = ADC_CLOCKPRESCALER_PCLK_DIV2;
	h.Init.Resolution            = ADC_RESOLUTION_12B;
	h.Init.ScanConvMode          = ENABLE;
	h.Init.ContinuousConvMode    = ENABLE;
	h.Init.DiscontinuousConvMode = DISABLE;
	h.Init.NbrOfDiscConversion   = 0;
	h.Init.ExternalTrigConvEdge  = ADC_EXTERNALTRIGCONVEDGE_NONE;
	h.Init.ExternalTrigConv      = ADC_EXTERNALTRIGCONV_T2_CC2;
	h.Init.DataAlign             = ADC_DATAALIGN_RIGHT;
	h.Init.NbrOfConversion       = 2;
	h.Init.DMAContinuousRequests = DISABLE;
	h.Init.EOCSelection          = ADC_EOC_SINGLE_CONV;
	HAL_ADC_Init(&h);

	//__HAL_ADC_ENABLE(&h);
	//h.Init.

	ADC_ChannelConfTypeDef adc_ch;
	adc_ch.Channel = ADC_CHANNEL_0;
	adc_ch.Rank = 1;
	adc_ch.SamplingTime = ADC_SAMPLETIME_480CYCLES;
	HAL_ADC_ConfigChannel(&h, &adc_ch);
	//adc_ch.

	adc_ch.Channel = ADC_CHANNEL_1;
	adc_ch.Rank = 2;
	HAL_ADC_ConfigChannel(&h, &adc_ch);

	float s = 1 << 12;

	int pa = 0;
	int pb = 0;
	//float pressure = 0;
	int sum = 0;
	int k = 0;
	while(1)
	{
		int rc = 0;

		HAL_ADC_Start(&h);
		rc = HAL_ADC_PollForConversion(&h, 3000);
		if(rc)
			trace_printf("First is bad\n");
		else
		{
			pa = HAL_ADC_GetValue(&h);
		}
		HAL_ADC_Start(&h);


		rc = HAL_ADC_PollForConversion(&h, 3000);
		if(rc)
			trace_printf("Second is bad\n");
		else
		{
			pb = HAL_ADC_GetValue(&h);

		}

		int n = 10000;
		if(k == n)
		{

			trace_printf("pressure: %8.4f\n", sum / s / (float)n);
			k = 0;
			sum = 0;
		}
		sum += pa - pb;


		//pressure = (float)(pa - pb) / s;

		k++;

	}
}

void bmp_test(I2C_HandleTypeDef * Hi2c)
{
	struct bme280_dev_s descr_bme280;

	I2C_HandleTypeDef i2c_handler = *Hi2c;//I2C_init_for_bme280(1);
	bme280_register_i2c(&descr_bme280, &i2c_handler, BME280_I2C_ADDR_SDO_LOW << 1);
	bme280_init(&descr_bme280);

	struct bme280_float_data_s data;
	while(1)
	{
		bme280_read(&descr_bme280, (char*)&data, sizeof(data));
		trace_printf("%9f %9f %9f \n", data.pressure, data.temperature, data.humidity);
	}

	bme280_deinit(&descr_bme280);
	i2c_deinit(&i2c_handler);
}


void CAN_Send(data_struct_t * data)
{
	trace_printf("%f %f %f\n", data->ds_temp, data->bme_temp, data->bme_hum);
	/*mavlink_message_t mavlink_msg;
	CANMAVLINK_TX_FRAME_T frames[34];

	mavlink_heartbeat_t heartbeat =
	{
		.type = MAV_TYPE_ONBOARD_CONTROLLER,
		.autopilot = MAV_AUTOPILOT_INVALID,
		.base_mode = MAV_MODE_FLAG_TEST_ENABLED,
		.system_status = MAV_STATE_ACTIVE
	};

	mavlink_scaled_pressure_t pressuretemp_internal =
	{
		.press_abs = data->bme_pres,
		.press_diff = NAN,
		.temperature = (int16_t)(data->bme_temp * 100),
		.time_boot_ms = HAL_GetTick()
	};

	mavlink_scaled_pressure2_t pressuretemp_external =
	{
		.press_abs = data->mpx_pres,
		.press_diff = NAN,
		.temperature = (int16_t)(data->ds_temp * 100),
		.time_boot_ms = HAL_GetTick()
	};


	mavlink_msg_heartbeat_encode(0, ZIKUSH_SCU, &mavlink_msg, &heartbeat);
	volatile uint8_t framecount = canmavlink_msg_to_frames(frames, &mavlink_msg);
	for(int i = 0; i < framecount; i++) //FIXME rewrite with IRQs
	{
		hcan.pTxMsg = frames + i; //DELICIOUS!!
		HAL_CAN_Transmit(&hcan, 1000);
	}

	mavlink_msg_scaled_pressure_encode(0, ZIKUSH_SCU, &mavlink_msg, &pressuretemp_internal);
	framecount = canmavlink_msg_to_frames(frames, &mavlink_msg);
	for(int i = 0; i < framecount; i++) //FIXME rewrite with IRQs
	{
		hcan.pTxMsg = frames + i; //DELICIOUS!!
		HAL_CAN_Transmit(&hcan, 1000);
	}

	mavlink_msg_scaled_pressure2_encode(0, ZIKUSH_SCU, &mavlink_msg, &pressuretemp_external);
	framecount = canmavlink_msg_to_frames(frames, &mavlink_msg);
	for(int i = 0; i < framecount; i++) //FIXME rewrite with IRQs
	{
		hcan.pTxMsg = frames + i; //DELICIOUS!!
		HAL_CAN_Transmit(&hcan, 1000);
	}*/

}
