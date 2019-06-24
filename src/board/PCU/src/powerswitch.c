/*
 * powerswitch.c
 *
 *  Created on: Jun 10, 2019
 *      Author: kirs
 */
#include <stdbool.h>

#include <stm32f10x_gpio.h>

#include <mavlink/zikush/mavlink.h>

#define POWERSWITCH_PORT	GPIOA
#define POWERSWITCH_ICU_PIN	GPIO_Pin_2
#define POWERSWITCH_SCU_PIN	GPIO_Pin_1
#define POWERSWITCH_CCU_PIN	GPIO_Pin_0
#define POWERSWITCH_AMP_PIN	GPIO_Pin_4
#define POWERSWITCH_HEATER_PIN	GPIO_Pin_3
#define POWERSWITCH_SHUTDOWN_PIN	GPIO_Pin_9

static uint8_t powerswitch_pinmap[] = {POWERSWITCH_ICU_PIN, POWERSWITCH_SCU_PIN, POWERSWITCH_CCU_PIN, POWERSWITCH_AMP_PIN, POWERSWITCH_HEATER_PIN};

void powerswitch_init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

	GPIO_InitTypeDef gpioinit =
	{
		.GPIO_Mode = GPIO_Mode_Out_OD,
		.GPIO_Pin = POWERSWITCH_ICU_PIN | POWERSWITCH_SCU_PIN | POWERSWITCH_CCU_PIN | POWERSWITCH_AMP_PIN \
							| POWERSWITCH_HEATER_PIN | POWERSWITCH_SHUTDOWN_PIN,
		.GPIO_Speed = GPIO_Speed_2MHz
	};

	GPIO_SetBits(POWERSWITCH_PORT, POWERSWITCH_ICU_PIN | POWERSWITCH_SCU_PIN | POWERSWITCH_CCU_PIN | POWERSWITCH_SHUTDOWN_PIN);
	GPIO_ResetBits(POWERSWITCH_PORT, POWERSWITCH_AMP_PIN | POWERSWITCH_HEATER_PIN);

	GPIO_Init(POWERSWITCH_PORT, &gpioinit);
}

void powerswitch_shutdown(void)
{
	GPIO_ResetBits(POWERSWITCH_PORT, POWERSWITCH_SHUTDOWN_PIN);
}

void powerswitch_set(ZIKUSH_CONTROLLER bus, bool enable)
{
	GPIO_WriteBit(POWERSWITCH_PORT, powerswitch_pinmap[bus], enable);
}
