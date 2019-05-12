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

typedef struct{
	float ds_temp;
	float bme_temp;
	float bme_pres;
	float bme_hum;
	float mpx_pres;
} data_struct_t;

void CAN_Send(uint8_t *data, size_t count)
{
	data_struct_t *d = (data_struct_t*)data;
	trace_printf("pres bme: %6.0f /tpres mpx: %6.0f /ttemp bme: %3.3f /ttemp ds: %3.3f /thum bme: %3.3f \n",
			d->bme_pres, d->mpx_pres, d->bme_temp, d->ds_temp, d->bme_hum);
}

int main()
{

	__initialize_hardware();


	// Call the CSMSIS system clock routine to store the clock frequency
	// in the SystemCoreClock global RAM location.
	//SystemCoreClockUpdate();
	__GPIOB_CLK_ENABLE();

	__I2C1_CLK_ENABLE();

	I2C_HandleTypeDef hi2c;
	i2c_pin_scl_init(GPIOB, GPIO_PIN_6);
	i2c_pin_sda_init(GPIOB, GPIO_PIN_7);
	i2c_config_default(&hi2c);
	hi2c.Instance = I2C1;
	i2c_init(&hi2c);


	ADS1x1x_config_t ads;
	ADS1x1x_config_default(&ads);
	ADS1x1x_register_i2c(&ads, &hi2c, ADS1x1x_I2C_ADDRESS_ADDR_TO_GND << 1);
	ADS1x1x_init(&ads);

	delay_init();
	onewire_t how;
	onewire_Init(&how, GPIOB, GPIO_PIN_3);

	struct bme280_dev_s hbme;
	thread_init_bme280(&hbme, &hi2c);

	ds18b20_config_t hds;
	thread_init_ds18b20(&hds, &how);

	thread_init_mpx2100ap(&ads);

	data_struct_t Data;
	uint8_t isGood[3] = {1,};
	uint8_t arg[100];
	while(1)
	{

		if(isGood[0])
		{
			thread_update_bme280(&hbme, arg);

			struct bme280_float_data_s *d = (struct bme280_float_data_s*)(arg + 1);

			Data.bme_pres = d->pressure;
			Data.bme_hum = d->humidity;
			Data.bme_temp = d->temperature;

			isGood[0] = !arg[0];
			arg[0] = 0;
		}
		if(isGood[1])
		{
			thread_update_ds18b20(&hds, arg);

			float *d = (float*)(arg + 1);

			Data.ds_temp = *d;

			isGood[1] = !arg[0];
			arg[0] = 0;
		}
		if(isGood[2])
		{
			thread_update_mpx2100ap(&ads, arg);

			float *d = (float*)(arg + 1);

			Data.mpx_pres = *d;

			isGood[2] = !arg[0];
			arg[0] = 0;
		}
		int test = 0;
		for(int i = 0; i < 3; i++)
			if(isGood[i])
				test = 1;

		if(test)
		{
			for(int i = 0; i < 3; i++)
				isGood[i] = 1;
			CAN_Send((uint8_t*)&Data, sizeof(Data));

		}
	}


	//bmp_test(&Hi2c);
	//ads1115_test(&Hi2c);
	/*
	delay_init();
	ds18b20_config_t hds;
	hds.resolution = ds18b20_Resolution_12bits;
	onewire_t how;
	onewire_Init(&how, GPIOB, GPIO_PIN_3);
	onewire_ReadRom(&how, &hds.rom);

	hds.how = &how;
	ds18b20_SetResolution(&hds, hds.resolution);
	float temp = 0;*//*
	while(1)
	{
		int a = 0;
		a = ds18b20_GetResolution(&hds);
		ds18b20_StartAll(&hds);
		HAL_Delay(500);
		while(!ds18b20_Read(&hds, &temp));
		trace_printf("temp: %8.5f %d\n", temp, a);
	}*/

/*
	GPIO_InitTypeDef gp;
	gp.Mode = GPIO_MODE_INPUT;
	gp.Pin = GPIO_PIN_3;
	gp.Pull = GPIO_PULLUP;
	gp.Speed = GPIO_SPEED_FAST;

	HAL_GPIO_Init(GPIOB, &gp);

	while(1)
	{
		int i = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3);
		trace_printf("%d\n", i);
		HAL_Delay(200);
	}*/

	return 0;
}

//void HAL_TIM_Base_MspInit()




