/*
 * Camera backbone task. Receives pictures over UART2 and reintegrates it to on-board network
 */

#include <FreeRTOS.h>
#include <task.h>
#include <semphr.h>

#include "fatfs.h"

#include <main.h>

#include <stm32f1xx_hal_uart.h>
#include <stm32f1xx_hal_rcc.h>

#include <zikush_config.h>

typedef struct {
	uint8_t data[ICU_CBBNE_BUFFLEN];
	uint16_t txpointer;
	void * next;
} cbbne_buffer_t;

static cbbne_buffer_t buffers[ICU_CBBNE_BUFFCOUNT];

cbbne_buffer_t * cbbne_list_root = buffers + 0;

static UART_HandleTypeDef huart2;

static void uart_init(void);

cbbne_buffer_t * linkedlist_last(cbbne_buffer_t * root)
{
	while(root->next != NULL)
		root = (cbbne_buffer_t *) root->next;
	return root;
}

cbbne_buffer_t * linkedlist_firstnotfull(cbbne_buffer_t * root)
{
	while(root->next != NULL && root->txpointer == ICU_CBBNE_BUFFLEN)
		root = (cbbne_buffer_t *) root->next;
	return root;
}

void cbbne_task (void *pvParameters)
{
	static FIL file;
	static int16_t filenum = -1;

	buffers[ICU_CBBNE_BUFFCOUNT - 1].txpointer = 0;
	for(int i = 0; i < ICU_CBBNE_BUFFCOUNT - 1; i++)
	{
		buffers[i].next = buffers + i + 1;
		buffers[i].txpointer = 0;
	}

	uart_init();

	static uint32_t allwritten;

	while(1)
	{
		if(cbbne_list_root->txpointer == ICU_CBBNE_BUFFLEN)
		{
			xSemaphoreTake(sd_mutex_handle, portMAX_DELAY);

			if(file.fs == NULL || file.fsize > ICU_SD_MAXFILELEN)
			{
				filenum += 1;

				if(file.fs != NULL)
				{
					f_sync(&file);
					f_close(&file);
				}

				char filename[ICU_SD_MAXFILENAMELEN];
				sprintf(filename, ICU_SD_TELFILENAMEFMT, zikush_runsessnum, "spectr", filenum);

				f_open(&file, filename, FA_CREATE_NEW | FA_WRITE);
			}

			UINT infactwritten;
			FRESULT result = f_write(&file, cbbne_list_root->data, ICU_CBBNE_BUFFLEN, &infactwritten);
			allwritten += infactwritten;

			result = f_sync(&file);

			xSemaphoreGive(sd_mutex_handle);

			HAL_NVIC_DisableIRQ(USART2_IRQn);
			linkedlist_last(cbbne_list_root)->next = cbbne_list_root;
			cbbne_buffer_t * nextroot = (cbbne_buffer_t *) cbbne_list_root->next;
			cbbne_list_root->next = NULL;
			cbbne_list_root->txpointer = 0;
			cbbne_list_root = nextroot;
			HAL_NVIC_EnableIRQ(USART2_IRQn);
		}

		vTaskDelay(ICU_CBBNE_PERIOD_MS * portTICK_PERIOD_MS);
	}

	vTaskDelete(NULL);
}

/**
  * @brief This function handles USB low priority or CAN RX0 interrupts.
  */
void USART2_IRQHandler(void)
{
	UART_HandleTypeDef * const huart = &huart2;
	BaseType_t callcontextswitch = false;

	uint32_t isrflags   = READ_REG(huart->Instance->SR);
	uint32_t errorflags = 0x00U;

	/* If no error occurs */
	errorflags = (isrflags & (uint32_t)(USART_SR_PE | USART_SR_FE | USART_SR_ORE | USART_SR_NE));
	/* UART in mode Receiver -------------------------------------------------*/
	if( (isrflags & USART_SR_RXNE) != RESET) //TODO while
	{
		cbbne_buffer_t * buff = linkedlist_firstnotfull(cbbne_list_root);
		if(buff->txpointer == ICU_CBBNE_BUFFLEN)
			goto buffers_full;
		buff->data[buff->txpointer++] = (uint8_t)(huart->Instance->DR & 0xFF);
	}

buffers_full:

	/* If some errors occur */
	if(errorflags != RESET)
	{
		// Если у нас случилась ошибка и зажегся какой-то бит ошибки
		// никто за нас его не снимет
		// Сдалем вид что не было никакой ошибки и продолжим работать
		// Ошибки пускай ловит драйвер выше. Тут слишком геморно передавать наверх что случилось

		// Сбрасываем все биты ошибок
		// Согласно даташиту такая последовательность должна помочь
		__disable_irq();
		READ_REG(huart->Instance->SR);
		READ_REG(huart->Instance->DR); // надеемся, что там ничего не повяилось с тех пор как мы проверяли последний раз
		__enable_irq();
	} /* End if some error occurs */
}

//Those functions has been fetched from CubeMX generated code
/**
  * @brief CAN Initialization Function
  * @param None
  * @retval None
  */
static void uart_init(void)
{
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_USART2_CLK_ENABLE();

	GPIO_InitTypeDef gpio_init =
	{
		.Mode = GPIO_MODE_AF_INPUT,
		.Speed = GPIO_SPEED_FREQ_MEDIUM,
		.Pull = GPIO_NOPULL,
		.Pin = GPIO_PIN_3,
	};
	HAL_GPIO_Init(GPIOA, &gpio_init);

	huart2.Instance = USART2;
	huart2.Init.Mode = UART_MODE_RX;
	huart2.Init.BaudRate = ICU_CBBNE_BAUDRATE;
	huart2.Init.WordLength = UART_WORDLENGTH_8B;
	huart2.Init.StopBits = UART_STOPBITS_1;
	huart2.Init.Parity = UART_PARITY_NONE;
	huart2.Init.OverSampling = UART_OVERSAMPLING_16;
	huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	HAL_UART_Init(&huart2);

	__HAL_UART_ENABLE_IT(&huart2, UART_IT_RXNE);
	__HAL_UART_ENABLE_IT(&huart2, UART_IT_ERR);

	HAL_NVIC_SetPriority(USART2_IRQn, ICU_CBBNE_IRQ_PRIO, 0);
	HAL_NVIC_EnableIRQ(USART2_IRQn);
}
