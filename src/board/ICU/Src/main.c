/**
  Main for ICU
  */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include "main.h"


volatile int16_t zikush_runsessnum = -1;


void ICU_task (void *pvParameters);
static StaticTask_t ICU_task_tcb;
static StackType_t ICU_stack[ICU_TASKS_ICU_STACKSIZE];
static StaticQueue_t ICU_task_queue;
static mavlink_message_t ICU_task_queue_buffer[ICU_TASKS_ICU_QUEUE_SIZE];
TaskHandle_t ICU_task_handle;
QueueHandle_t	ICU_queue_handle;

void can_task (void *pvParameters);
static StaticTask_t can_task_tcb;
static StackType_t can_stack[ICU_TASKS_CAN_STACKSIZE];
static StaticQueue_t can_task_queue;
static mavlink_message_t can_task_queue_buffer[ICU_TASKS_ICU_QUEUE_SIZE];
TaskHandle_t radio_task_handle;
QueueHandle_t	radio_queue_handle;

void sd_task (void *pvParameters);
static StaticTask_t sd_task_tcb;
static StackType_t sd_stack[ICU_TASKS_SD_STACKSIZE];
static StaticQueue_t sd_task_queue;
static mavlink_message_t sd_task_queue_buffer[ICU_TASKS_ICU_QUEUE_SIZE];
TaskHandle_t radio_task_handle;
QueueHandle_t	radio_queue_handle;

void radio_task (void *pvParameters);
static StaticTask_t radio_task_tcb;
static StackType_t radio_stack[ICU_TASKS_RADIO_STACKSIZE];
static StaticQueue_t radio_task_queue;
static mavlink_message_t radio_task_queue_buffer[ICU_TASKS_ICU_QUEUE_SIZE];
TaskHandle_t radio_task_handle;
QueueHandle_t	radio_queue_handle;


void SystemClock_Config(void);
static void MX_GPIO_Init(void);


int main(void)
{
	HAL_Init();
	SystemClock_Config();
	MX_GPIO_Init();

	ICU_task_handle = xTaskCreateStatic(ICU_task, (const char *)"ICU", ICU_TASKS_ICU_STACKSIZE, NULL, \
										ICU_TASKS_ICU_TASKPRIORITY, ICU_stack, &ICU_task_tcb);
	ICU_queue_handle = xQueueCreateStatic(ICU_TASKS_ICU_QUEUE_SIZE, sizeof(mavlink_message_t), (uint8_t *)ICU_task_queue_buffer, &ICU_task_queue);

	vTaskStartScheduler();

	while(1)
	{
		mavlink_message_t msg;
		mavlink_heartbeat_t heartbeat =
		{
			.type = MAV_TYPE_FREE_BALLOON,
			.autopilot = MAV_AUTOPILOT_INVALID,
			.base_mode = MAV_MODE_FLAG_TEST_ENABLED,
			.system_status = MAV_STATE_ACTIVE
		};
		mavlink_msg_heartbeat_encode(0, ZIKUSH_ICU, &msg, &heartbeat);

		//router_route(&msg);

		HAL_Delay(80);

		mavlink_scaled_pressure_t pressure =
		{
			.press_abs = 100.0f,
			.press_diff = 0,
			.temperature = 2213,
			.time_boot_ms = HAL_GetTick(),
		};
		mavlink_msg_scaled_pressure_encode(0, ZIKUSH_ICU, &msg, &pressure);

		//router_route(&msg);

		HAL_Delay(1000);
	}
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
