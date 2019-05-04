#include <stm32f4xx_hal.h>

#include "lsm6ds3.h"
#include "i2c.h"
#include "bme280.h"
#include <stdio.h>
#include <diag/Trace.h>
#include "i2c.h"
#include "ads1x1x.h"

void SysTick_Handler(void)
{
	HAL_IncTick();
}

int main()
	{
	HAL_Init();

	// Enable HSE Oscillator and activate PLL with HSE as source
	SystemClock_Config();

	// Call the CSMSIS system clock routine to store the clock frequency
	// in the SystemCoreClock global RAM location.
	//SystemCoreClockUpdate();
	//__GPIOB_CLK_ENABLE();

	//__I2C1_CLK_ENABLE();

	//I2C_HandleTypeDef Hi2c;
	//i2c_pin_scl_init(GPIOB, GPIO_PIN_6);
	//i2c_pin_sda_init(GPIOB, GPIO_PIN_7);
	//i2c_config_default(&Hi2c);
	//i2c_init(&Hi2c);
/*
	ads_hi2c = &Hi2c;
	ADS1x1x_config_t ads;
	ads.chip = ADS1115;
	ads.i2c_address = 0b10010010;
    ADS1x1x_set_os(&ads,OS_SINGLE);
	ADS1x1x_set_multiplexer(&ads, MUX_DIFF_2_3);
	ADS1x1x_set_pga(&ads, PGA_4096);
	ADS1x1x_set_mode(&ads, MODE_SINGLE_SHOT);
	ADS1x1x_set_data_rate(&ads, DATA_RATE_ADS111x_860);
	ADS1x1x_set_threshold_lo(&ads, 0);
	ADS1x1x_set_threshold_hi(&ads, 1);
	ADS1x1x_set_comparator_polarity(&ads, COMPARATOR_POLARITY_ACTIVE_HI);
	ADS1x1x_set_comparator_queue(&ads, COMPARATOR_QUEUE_1);

	//ADS1x1x_init(&ads, ads.chip,ads.i2c_address,,)


	HAL_I2C_Master_Receive(&Hi2c,0,0,0,100);
	while(1)
	{
		ADS1x1x_start_conversion(&ads);
		HAL_Delay(20);
		int16_t data = ADS1x1x_read(&ads);
		float result = data / 4096;

		trace_printf("pressure: %8.4f\n", result);

	}
*/




/*
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
	float pressure = 0;
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


*/






/*
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
	UART_InitTypeDef uartIniter;

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


	const char data[] = "hello world\n";
	while(1)
	{
		HAL_UART_Transmit(&uartHandler, data, sizeof(data)-1, HAL_MAX_DELAY);
	}*/





	struct bme280_dev_s descr_bme280;

	I2C_HandleTypeDef i2c_handler = I2C_init_for_bme280(1);
	bme280_register_i2c(&descr_bme280, &i2c_handler, BME280_I2C_ADDR_SDO_LOW);
	bme280_init(&descr_bme280);

	struct bme280_float_data_s data;
	while(1)
	{
		bme280_read(&descr_bme280, (char*)&data, sizeof(data));
		trace_printf("%9f %9f %9f \n", data.pressure, data.temperature, data.humidity);
	}

	bme280_deinit(&descr_bme280);
	I2C_deinit(&i2c_handler);

	return 0;
}

