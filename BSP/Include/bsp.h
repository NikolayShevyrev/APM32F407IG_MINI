/**
 * @file    bsp.h
 * @author  Nikolay Shevyrev
 * @brief   Header for bsp.c
 * @ingroup BSP
 */


#ifndef BSP_H
#define BSP_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

#include "bsp_defines.h"
#include "bsp_nvic.h"
#include "bsp_gpio.h"
#include "bsp_timer.h"


/* Private function prototypes -----------------------------------------------*/
void bsp_config(void);


#ifdef __cplusplus
}
#endif

#endif /* BSP_H */

