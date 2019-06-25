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
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
	HAL_IncTick();

	FreeRTOS_SysTick_Handler();
}
