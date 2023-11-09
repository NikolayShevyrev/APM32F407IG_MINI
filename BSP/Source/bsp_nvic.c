/**
 * @file    bsp_nvic.c
 * @author  Nikolay Shevyrev
 * @brief   NVIC Configuration
 * @ingroup BSP
 */


/* Includes ------------------------------------------------------------------*/
#include "bsp_nvic.h"
#include "apm32f4xx_misc.h"
#include "apm32f4xx.h"

/**
 * @brief NVIC Configuration
 * 
 * @param[in]   none
 * @param[out]  none
 * @retval      none
 */
void bsp_nvic_config(void)
{
    NVIC_ConfigPriorityGroup(BSP_NVIC_PRIORITY_GROUP);
}


/**
 * @brief Enable irq and configure preemtive and sub priorities
 * 
 * @param irq 
 * @param priority 
 * @param subpriority 
 */
void bsp_nvic_irq_enable(IRQn_Type irq, uint8_t priority, uint8_t subpriority)
{
    uint32_t temp_priority = NVIC_EncodePriority(5U, 1U, 2U);

}

