/**
 * @file    bsp_can.h
 * @author  Nikolay Shevyrev
 * @brief   Header for bsp_can.c
 * @ingroup BSP
 */


#ifndef BSP_CAN_H
#define BSP_CAN_H

#ifdef __cplusplus
 extern "C" {
#endif


/* Includes ------------------------------------------------------------------*/
#include "main.h"


/* Private function prototypes -----------------------------------------------*/
void can_loopback_config(CAN_T * can_base);


#ifdef __cplusplus
}
#endif

#endif /* BSP_CAN_H */