/**
 * @file    bsp_gpio.c
 * @author  Nikolay Shevyrev
 * @brief   GPIOs Configuration
 * @ingroup BSP
 */


/* Includes ------------------------------------------------------------------*/
#include "bsp_gpio.h"
#include "bsp_defines.h"
#include "Board.h"


/**
 * @brief GPIO configuration
 * 
 * @param[in]   none
 * @param[out]  none
 * @return      none
 */
void bsp_gpio_config(void)
{
    GPIO_Config_T GPIO_ConfigStruct;
    GPIO_ConfigStructInit(&GPIO_ConfigStruct);

    /* PWM Outputs */
    RCM_EnableAHB1PeriphClock(PWM_PORT_RCM);

    GPIO_ConfigPinAF(PWM_PORT, PWM_UH_PIN_SOURCE, PWM_AF);
    GPIO_ConfigPinAF(PWM_PORT, PWM_VH_PIN_SOURCE, PWM_AF);
    GPIO_ConfigPinAF(PWM_PORT, PWM_WH_PIN_SOURCE, PWM_AF);

    GPIO_ConfigPinAF(PWM_PORT, PWM_UL_PIN_SOURCE, PWM_AF);
    GPIO_ConfigPinAF(PWM_PORT, PWM_VL_PIN_SOURCE, PWM_AF);
    GPIO_ConfigPinAF(PWM_PORT, PWM_WL_PIN_SOURCE, PWM_AF);

    GPIO_ConfigStruct.pin   = PWM_PINS;
    GPIO_ConfigStruct.mode  = GPIO_MODE_AF;
    GPIO_ConfigStruct.otype = GPIO_OTYPE_PP;
    GPIO_ConfigStruct.speed = GPIO_SPEED_100MHz;
    GPIO_ConfigStruct.otype = GPIO_PUPD_NOPULL;
    GPIO_Config(PWM_PORT, &GPIO_ConfigStruct);

    /* CAN Bus */
    // RCM_EnableAHB1PeriphClock(RCM_AHB1_PERIPH_GPIOB);

    // GPIO_ConfigPinAF(CAN1_PORT, CAN1_RX_PIN_SOURCE, CAN1_AF);
    // GPIO_ConfigPinAF(CAN1_PORT, CAN1_TX_PIN_SOURCE, CAN1_AF);

    // GPIO_ConfigStruct.pin   = CAN1_PINS;
    // GPIO_ConfigStruct.mode  = GPIO_MODE_AF;
    // GPIO_ConfigStruct.otype = GPIO_OTYPE_PP;
    // GPIO_ConfigStruct.speed = GPIO_SPEED_100MHz;
    // GPIO_ConfigStruct.otype = GPIO_PUPD_UP;
    // GPIO_Config(CAN1_PORT, &GPIO_ConfigStruct);

    // GPIO_ConfigPinAF(CAN2_PORT, CAN2_RX_PIN_SOURCE, CAN2_AF);
    // GPIO_ConfigPinAF(CAN2_PORT, CAN2_TX_PIN_SOURCE, CAN2_AF);

    // GPIO_ConfigStruct.pin   = CAN2_PINS;
    // GPIO_ConfigStruct.mode  = GPIO_MODE_AF;
    // GPIO_ConfigStruct.otype = GPIO_OTYPE_PP;
    // GPIO_ConfigStruct.speed = GPIO_SPEED_100MHz;
    // GPIO_ConfigStruct.otype = GPIO_PUPD_UP;
    // GPIO_Config(CAN2_PORT, &GPIO_ConfigStruct);
}

