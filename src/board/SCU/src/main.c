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


int main()
{

	//__initialize_hardware();


	// Call the CSMSIS system clock routine to store the clock frequency
	// in the SystemCoreClock global RAM location.
	//SystemCoreClockUpdate();
	__GPIOB_CLK_ENABLE();
	__GPIOA_CLK_ENABLE();

	__I2C1_CLK_ENABLE();
	__CAN1_CLK_ENABLE();
	//__CAN2_CLK_ENABLE();



	return 0;
}

//
//int main_spring_show()
//{
//
//	//__initialize_hardware();
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
