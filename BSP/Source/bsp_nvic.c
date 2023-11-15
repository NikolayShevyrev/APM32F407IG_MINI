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
#include "bsp_defines.h"
#include "systick.h"

/**
 * @brief NVIC Configuration
 * 
 * @param[in]   none
 * @param[out]  none
 * @retval      none
 */
void bsp_nvic_config(void)
{
    NVIC_ConfigPriorityGroup(NVIC_PRIORITY_GROUP_4);  /* Preprio: 3 bits, Subprio: 0 bits */

    NVIC_EnableIRQRequest(PWM_IRQn, PWM_TIMER_INT_PRIORITY, 0U);

    //NVIC_EnableIRQRequest(SysTick_IRQn, 0U, 0U);
}



