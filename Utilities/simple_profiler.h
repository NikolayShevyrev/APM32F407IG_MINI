/**
  ******************************************************************************
  * @file    simple_profiler.h
  * @author  Nikolay Shevyrev
  * @brief   Header file for simple_profiler.c
  ******************************************************************************
*/

#ifndef PROFILER_H
#define PROFILER_H

#ifdef __cplusplus
 extern "C" {
#endif


/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include <stdint.h>
#include <stdio.h>

/* Private type definition ---------------------------------------------------*/
typedef struct 
{
	uint32_t time_start;
	uint32_t time_stamp;
	uint32_t time_cc;
	float time_us;
} SimpleProfiler_t;

/* Private function prototypes -----------------------------------------------*/

void simple_profiler_start(SimpleProfiler_t * const me);

void simple_profiler_stop(SimpleProfiler_t * const me);


#ifdef __cplusplus
}
#endif

#endif /* PROFILER_H */

