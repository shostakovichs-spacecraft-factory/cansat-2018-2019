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
#include "madgwick/MadgwickAHRS.h"
#include "madgwick/ahrs.h"
#include "camera/camera_interface.h"

#include "thread.h"

void __initialize_hardware(void);

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
int main()
{
	__GPIOA_CLK_ENABLE();
	__GPIOB_CLK_ENABLE();
	__GPIOC_CLK_ENABLE();
	__GPIOD_CLK_ENABLE();

	__I2C1_CLK_ENABLE();
	__CAN1_CLK_ENABLE();

	__USART3_CLK_ENABLE();
	__USART2_CLK_ENABLE();
	MY_UART huart3;
	uart_pin_rx_init(GPIOC, GPIO_PIN_11);
	uart_pin_tx_init(GPIOC, GPIO_PIN_10);
	uart_config_default(&huart3.huart);
	huart3.huart.Instance = USART3;
	uart_init(&huart3);


	MY_UART huart2;

	GPIO_InitTypeDef pa_init;
	pa_init.Alternate = GPIO_AF7_USART2;
	pa_init.Mode = GPIO_MODE_AF_PP;
	pa_init.Pin = GPIO_PIN_5;
	pa_init.Pull = GPIO_NOPULL;
	pa_init.Speed = GPIO_SPEED_FAST;
	HAL_GPIO_Init(GPIOD, &pa_init);

	pa_init.Pin = GPIO_PIN_6;
	HAL_GPIO_Init(GPIOD, &pa_init);

	uart_config_default(&huart2.huart);
	huart2.huart.Instance = USART2;
	uart_init(&huart2);

	HAL_Delay(3000);
	CAMERA hcam;
	camera_init(&hcam, &huart3);

	camera_reset(&hcam);
	//HAL_Delay(3000);
	trace_printf("\nTake picture\n");
	camera_restore_picture(&hcam);
	camera_set_image_size(&hcam, VC0706_640x480);
	HAL_Delay(1000);
	camera_take_picture(&hcam);



	const size_t buf_size = 200;
	uint8_t buffer[buf_size];
	for(int i = 0; i < buf_size; i++)
		buffer[i] = 0;
	HAL_Delay(3000);
	camera_prepare_to_read(&hcam);
	camera_load_image_size(&hcam);

/*
	uint8_t args[] = {0x0, 0x0F,
	                  0, 0, 0, 1,
	                  0, 0, 0, 4,
	                  0, 0x0F
					};


	for(int i = 0; i < 10; i++)
		if(camera_run_command(&hcam, 0x32, args, sizeof(args), buffer, 11, 0))
			trace_printf("can't run command: read buffer\n");*/

	trace_printf("\Send picture\n");
	while(!camera_is_all_image_loaded(&hcam))
	{

		int length = camera_read_picture(&hcam, buffer, buf_size);
		//trace_write((char*)(buffer + 5), buf_size - 10);
		HAL_UART_Transmit(&huart2.huart, buffer + 5, buf_size - 10, 3000);
		HAL_Delay(100);
	}
	camera_restore_picture(&hcam);

	return 0;
}


int main_spring_show()
{
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


	while(1)
	{
		{
			thread_update_bme280(&hbme, arg);

			struct bme280_float_data_s *d = (struct bme280_float_data_s*)(arg + 4);

			Data.bme_pres = d->pressure;
			Data.bme_hum = d->humidity;
			Data.bme_temp = d->temperature;
		}

		{
			thread_update_ds18b20(&hds, arg);

			float *d = (float*)(arg + 1);

			Data.ds_temp = *d;
		}

		{
			thread_update_mpx2100ap(&ads, arg);

			float *d = (float*)(arg + 1);

			Data.mpx_pres = *d;
		}

		CAN_Send(&Data);
	}

	return 0;
}
