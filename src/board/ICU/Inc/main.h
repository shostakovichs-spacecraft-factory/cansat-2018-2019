#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f1xx_hal.h"

#include <zikush_config.h>

void Error_Handler(void);

#define RADIO_BUSY_Pin GPIO_PIN_12
#define RADIO_BUSY_GPIO_Port GPIOE
#define RADIO_DIO2_Pin GPIO_PIN_13
#define RADIO_DIO2_GPIO_Port GPIOD
#define RADIO_TXEN_Pin GPIO_PIN_13
#define RADIO_TXEN_GPIO_Port GPIOE
#define RADIO_NRST_Pin GPIO_PIN_14
#define RADIO_NRST_GPIO_Port GPIOE
#define RADIO_RXEN_Pin GPIO_PIN_15
#define RADIO_RXEN_GPIO_Port GPIOE
#define RADIO_NSS_Pin GPIO_PIN_12
#define RADIO_NSS_GPIO_Port GPIOB
#define RADIO_IRQ_Pin GPIO_PIN_15
#define RADIO_IRQ_GPIO_Port GPIOD
#define RADIO_IRQ_EXTI_IRQn EXTI15_10_IRQn
#define LEDPIN_Pin GPIO_PIN_6
#define LEDPIN_GPIO_Port GPIOB

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
