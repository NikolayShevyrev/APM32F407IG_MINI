/**
 * @file    bsp.c
 * @author  Nikolay Shevyrev
 * @brief   BSP Configuration
 * @ingroup BSP
 */


/* Includes ------------------------------------------------------------------*/
#include "bsp.h"
#include "Board.h"


/**
 * @brief Configure all peripherals
 * 
 * @param[in]   none
 * @param[out]  none
 * @return      none
 */
void bsp_config()
{
    SystemCoreClockUpdate();

    NVIC_ConfigPriorityGroup(NVIC_PRIORITY_GROUP_4);  /* Preprio: 3 bits, Subprio: 0 bits */

    bsp_gpio_config();
    bsp_timer1_config();
}

