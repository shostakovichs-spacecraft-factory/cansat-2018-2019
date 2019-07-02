/**
  Main for ICU
  */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include "main.h"

mavlink_zikush_icu_stats_t global_stats = {0};
volatile int16_t zikush_runsessnum = -1;


void heartbeat_task(void *pvParameters);
static StaticTask_t heartbeat_task_tcb;
static StackType_t heartbeat_stack[ICU_TASKS_HEARTBEAT_STACKSIZE];
TaskHandle_t heartbeat_task_handle = NULL;

void ICU_task(void *pvParameters);
static StaticTask_t ICU_task_tcb;
static StackType_t ICU_stack[ICU_TASKS_ICU_STACKSIZE];
static StaticQueue_t ICU_task_queue;
static mavlink_message_t ICU_task_queue_buffer[ICU_TASKS_ICU_QUEUE_SIZE];
TaskHandle_t ICU_task_handle = NULL;
QueueHandle_t	ICU_queue_handle = NULL;

void can_task(void *pvParameters);
static StaticTask_t can_task_tcb;
static StackType_t can_stack[ICU_TASKS_CAN_STACKSIZE];
static StaticQueue_t can_task_queue;
static mavlink_message_t can_task_queue_buffer[ICU_TASKS_ICU_QUEUE_SIZE];
TaskHandle_t can_task_handle = NULL;
QueueHandle_t	can_queue_handle = NULL;

void sd_task(void *pvParameters);
static StaticTask_t sd_task_tcb;
static StackType_t sd_stack[ICU_TASKS_SD_STACKSIZE];
static StaticQueue_t sd_task_queue;
static mavlink_message_t sd_task_queue_buffer[ICU_TASKS_ICU_QUEUE_SIZE];
TaskHandle_t sd_task_handle = NULL;
QueueHandle_t	sd_queue_handle = NULL;

void radio_task(void *pvParameters);
static StaticTask_t radio_task_tcb;
static StackType_t radio_stack[ICU_TASKS_RADIO_STACKSIZE];
static StaticQueue_t radio_task_queue;
static mavlink_message_t radio_task_queue_buffer[ICU_TASKS_ICU_QUEUE_SIZE];
TaskHandle_t radio_task_handle = NULL;
QueueHandle_t	radio_queue_handle = NULL;

void gps_task(void *pvParameters);
static StaticTask_t gps_task_tcb;
static StackType_t gps_stack[ICU_TASKS_RADIO_STACKSIZE];
TaskHandle_t gps_task_handle = NULL;

void iridium_task(void *pvParameters);
static StaticTask_t iridium_task_tcb;
static StackType_t iridium_stack[ICU_TASKS_IRIDIUM_STACKSIZE];
static StaticQueue_t iridium_task_queue;
static mavlink_message_t iridium_task_queue_buffer[ICU_TASKS_IRIDIUM_QUEUE_SIZE];
TaskHandle_t iridium_task_handle = NULL;
QueueHandle_t	iridium_queue_handle = NULL;


void SystemClock_Config(void);
static void MX_GPIO_Init(void);


int main(void)
{
	HAL_Init();
	SystemClock_Config();
	MX_GPIO_Init();

	heartbeat_task_handle = xTaskCreateStatic(heartbeat_task, (const char *)"heartbeat", ICU_TASKS_HEARTBEAT_STACKSIZE, NULL, \
										ICU_TASKS_HEARTBEAT_TASKPRIORITY, heartbeat_stack, &heartbeat_task_tcb);

	ICU_task_handle = xTaskCreateStatic(ICU_task, (const char *)"ICU", ICU_TASKS_ICU_STACKSIZE, NULL, \
										ICU_TASKS_ICU_TASKPRIORITY, ICU_stack, &ICU_task_tcb);
	ICU_queue_handle = xQueueCreateStatic(ICU_TASKS_ICU_QUEUE_SIZE, sizeof(mavlink_message_t), (uint8_t *)ICU_task_queue_buffer, &ICU_task_queue);

	can_task_handle = xTaskCreateStatic(can_task, (const char *)"can", ICU_TASKS_CAN_STACKSIZE, NULL, \
										ICU_TASKS_CAN_TASKPRIORITY, can_stack, &can_task_tcb);
	can_queue_handle = xQueueCreateStatic(ICU_TASKS_CAN_QUEUE_SIZE, sizeof(mavlink_message_t), (uint8_t *)can_task_queue_buffer, &can_task_queue);

	sd_task_handle = xTaskCreateStatic(sd_task, (const char *)"sd", ICU_TASKS_SD_STACKSIZE, NULL, \
										ICU_TASKS_SD_TASKPRIORITY, sd_stack, &sd_task_tcb);
	sd_queue_handle = xQueueCreateStatic(ICU_TASKS_SD_QUEUE_SIZE, sizeof(mavlink_message_t), (uint8_t *)sd_task_queue_buffer, &sd_task_queue);

	radio_task_handle = xTaskCreateStatic(radio_task, (const char *)"radio", ICU_TASKS_RADIO_STACKSIZE, NULL, \
									   ICU_TASKS_RADIO_TASKPRIORITY, radio_stack, &radio_task_tcb);
	radio_queue_handle = xQueueCreateStatic(ICU_TASKS_RADIO_QUEUE_SIZE, sizeof(mavlink_message_t), (uint8_t *)radio_task_queue_buffer, &radio_task_queue);

	iridium_task_handle = xTaskCreateStatic(iridium_task, (const char *)"irid", ICU_TASKS_IRIDIUM_STACKSIZE, NULL, \
											ICU_TASKS_IRIDIUM_TASKPRIORITY, iridium_stack, &iridium_task_tcb);
	iridium_queue_handle = xQueueCreateStatic(ICU_TASKS_IRIDIUM_QUEUE_SIZE, sizeof(mavlink_message_t), (uint8_t *)iridium_task_queue_buffer, &iridium_task_queue);

	gps_task_handle = xTaskCreateStatic(gps_task, (const char *)"gps", ICU_TASKS_GPS_STACKSIZE, NULL, \
										   ICU_TASKS_GPS_TASKPRIORITY, gps_stack, &gps_task_tcb);


	vTaskStartScheduler();
}

void vApplicationGetIdleTaskMemory(StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize)
{
	static StaticTask_t idle_task_tcb;
	static StackType_t idle_stack[configMINIMAL_STACK_SIZE];

	*ppxIdleTaskTCBBuffer = &idle_task_tcb;
	*ppxIdleTaskStackBuffer = idle_stack;
	*pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
}

/**
  * @brief System Clock Configuration
  */
void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct = {0};
	RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

	/** Initializes the CPU, AHB and APB busses clocks
	*/
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSEState = RCC_HSE_ON;
	RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
	{
		Error_Handler();
	}
	/** Initializes the CPU, AHB and APB busses clocks
	*/
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
							  |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
	{
		Error_Handler();
	}
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOB_CLK_ENABLE();

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(LEDPIN_GPIO_Port, LEDPIN_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pins : RADIO_NSS_Pin LEDPIN_Pin */
	GPIO_InitStruct.Pin = LEDPIN_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{}
