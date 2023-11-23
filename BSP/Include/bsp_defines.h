/**
 * @file    bsp_defines.h
 * @author  Nikolay Shevyrev
 * @brief   Header containing all defines for bsp 
 * @ingroup BSP
 */


#ifndef BSP_DEFINES_H
#define BSP_DEFINES_H

#ifdef __cplusplus
 extern "C" {
#endif


/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "Board.h"

/* Private defines -----------------------------------------------------------*/
#define DEFAULT_PWM_FREQ        10000U

/* Interrupt Priorities */
#define PWM_TIMER_INT_PRIORITY  2U

/* PWM Outputs and Timer */
#define PWM_TIMER       TMR1
#define PWM_IRQn        TMR1_UP_TMR10_IRQn 
#define PWM_IRQHandler  TMR1_UP_TMR10_IRQHandler

#define PWM_TIMER_RCM   RCM_APB2_PERIPH_TMR1

#define PWM_CH_U        TMR_CHANNEL_1
#define PWM_CH_V	    TMR_CHANNEL_2
#define PWM_CH_W	    TMR_CHANNEL_3

#define PWM_UL_PIN      GPIO_PIN_8
#define PWM_UH_PIN      GPIO_PIN_9

#define PWM_VL_PIN      GPIO_PIN_10
#define PWM_VH_PIN      GPIO_PIN_11

#define PWM_WL_PIN      GPIO_PIN_12
#define PWM_WH_PIN      GPIO_PIN_13

#define PWM_AF          GPIO_AF_TMR1

#define PWM_UL_PIN_SOURCE   GPIO_PIN_SOURCE_8
#define PWM_UH_PIN_SOURCE   GPIO_PIN_SOURCE_9

#define PWM_VL_PIN_SOURCE   GPIO_PIN_SOURCE_10
#define PWM_VH_PIN_SOURCE   GPIO_PIN_SOURCE_11

#define PWM_WL_PIN_SOURCE   GPIO_PIN_SOURCE_12
#define PWM_WH_PIN_SOURCE   GPIO_PIN_SOURCE_13

#define PWM_PORT_RCM    RCM_AHB1_PERIPH_GPIOE
#define PWM_PORT        GPIOE
#define PWM_PINS        BITS(8,13)


/* Can 1 */
#define CAN_PORT_RCM    RCM_AHB1_PERIPH_GPIOB

#define CAN1_PORT       GPIOB

#define CAN1_RX_PIN     GPIO_PIN_8
#define CAN1_TX_PIN     GPIO_PIN_9
#define CAN1_PINS       BITS(8,9)

#define CAN1_AF         GPIO_AF_CAN1

#define CAN1_RX_PIN_SOURCE   GPIO_PIN_SOURCE_8
#define CAN1_TX_PIN_SOURCE   GPIO_PIN_SOURCE_9

/* Can 2 */
#define CAN2_PORT       GPIOB

#define CAN2_RX_PIN     GPIO_PIN_5
#define CAN2_TX_PIN     GPIO_PIN_6
#define CAN2_PINS       BITS(5,6)

#define CAN2_AF         GPIO_AF_CAN2

#define CAN2_RX_PIN_SOURCE   GPIO_PIN_SOURCE_5
#define CAN2_TX_PIN_SOURCE   GPIO_PIN_SOURCE_6



#ifdef __cplusplus
}
#endif

#endif /* BSP_DEFINES_H */



