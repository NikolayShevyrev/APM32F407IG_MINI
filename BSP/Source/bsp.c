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

    /*!< 3 bits for pre-emption priority,0 bits for subpriority */
    NVIC_ConfigPriorityGroup(NVIC_PRIORITY_GROUP_4); 

    bsp_gpio_config();
}