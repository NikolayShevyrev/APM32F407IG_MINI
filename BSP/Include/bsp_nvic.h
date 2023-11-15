/**
 * @file    bsp_nvic.h
 * @author  Nikolay Shevyrev
 * @brief   Header for bsp_nvic.c
 * @ingroup BSP
 */


#ifndef BSP_NVIC_H
#define BSP_NVIC_H

#ifdef __cplusplus
 extern "C" {
#endif


/* Includes ------------------------------------------------------------------*/
#include "main.h"


/* Private defines -----------------------------------------------------------*/
#define BSP_NVIC_PRIORITY_GROUP     NVIC_PRIORITY_GROUP_4


/* Private function prototypes -----------------------------------------------*/
void bsp_nvic_config(void);


#ifdef __cplusplus
}
#endif

#endif /* BSP_NVIC_H */

