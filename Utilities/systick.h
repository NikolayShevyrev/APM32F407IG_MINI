/**
  ******************************************************************************
  * @file    systick.h
  * @author  Nikolay Shevyrev
  * @brief   Header file for systick.c
  ******************************************************************************
*/

#ifndef SYS_TICK_H
#define SYS_TICK_H

#ifdef __cplusplus
 extern "C" {
#endif


/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include "main.h"


/* Private defines -----------------------------------------------------------*/
#define TICKS_PER_SECOND 1000U /* [Hz] */
#define HEART_BEAT_LED_FREQ (TICKS_PER_SECOND * 1U) 
#define SYSTICK_IRQ_PRIORITY    0U


/* Private function prototypes -----------------------------------------------*/
uint8_t systick_config(void);

uint32_t get_tick(void);

void delay_1ms(uint32_t delay);

void tick_increment(void);

void heart_beat_led(void);


#ifdef __cplusplus
}
#endif

#endif /* SYS_TICK_H */
