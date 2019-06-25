#include "main.h"
#include "stm32f1xx_it.h"

#include <stm32f1xx_hal_can.h>

#include "sx1268.h"

#include <mavlink/zikush/mavlink.h>
#include <canmavlink_hal.h>

#include <router.h>

extern CAN_HandleTypeDef hcan;
extern sx1268_t radio;

/******************************************************************************/
/*           Cortex-M3 Processor Interruption and Exception Handlers          */ 
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
	while (1)
	{}
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
	while (1)
	{}
}

/**
  * @brief This function handles Prefetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
	while (1)
	{}
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
	while (1)
	{}
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
	HAL_IncTick();
}

/******************************************************************************/
/* STM32F1xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f1xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles USB low priority or CAN RX0 interrupts.
  */
void USB_LP_CAN1_RX0_IRQHandler(void)
{
	static volatile int counter = 0;
	counter++;
	volatile canmavlink_RX_frame_t frame;
	static volatile mavlink_message_t msg;
	static volatile mavlink_status_t status;

	HAL_CAN_GetRxMessage(&hcan, 0, &( frame.Header ), frame.Data);

	volatile uint8_t result = canmavlink_parse_frame(&frame, &msg, &status);

	if(result == MAVLINK_FRAMING_OK)
		router_route(&msg);

	return;
}

/**
  * @brief This function handles EXTI line[15:10] interrupts.
  */
void EXTI15_10_IRQHandler(void)
{
	if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_15) != RESET)
	{
		__HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_15);
		sx1268_event(&radio);
	}

	return;
}
