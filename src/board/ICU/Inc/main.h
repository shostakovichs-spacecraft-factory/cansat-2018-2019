#ifndef __MAIN_H
#define __MAIN_H

#include <FreeRTOS.h>
#include <queue.h>

#include "stm32f1xx_hal.h"

#include <mavlink/zikush/mavlink.h>
#include <router.h>

#include <zikush_config.h>


extern volatile int16_t zikush_runsessnum;

extern TaskHandle_t heartbeat_task_handle;
extern TaskHandle_t ICU_task_handle;
extern QueueHandle_t	ICU_queue_handle;
extern TaskHandle_t can_task_handle;
extern QueueHandle_t	can_queue_handle;
extern TaskHandle_t sd_task_handle;
extern QueueHandle_t	sd_queue_handle;
extern TaskHandle_t radio_task_handle;
extern QueueHandle_t	radio_queue_handle;
extern TaskHandle_t iridium_task_handle;
extern QueueHandle_t	iridium_queue_handle;


#define RADIO_NOTIFICATION_SEND	(1<<0)
#define RADIO_NOTIFICATION_EVT	(1<<1)

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


#endif /* __MAIN_H */
