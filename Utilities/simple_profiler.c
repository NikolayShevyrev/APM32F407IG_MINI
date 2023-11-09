/**
  ******************************************************************************
  * @file    simple_profiler.c
  * @author  Nikolay Shevyrev
  * @brief   File containing profiler functions
  ******************************************************************************
*/


/* Includes ------------------------------------------------------------------*/
#include "simple_profiler.h"


/**
 * @brief Start simple profiler 
 * 
 * @param me 
 */
void simple_profiler_start(SimpleProfiler_t * const me)
{
	/* Check if DWT is already on */
	if (!(CoreDebug->DEMCR & CoreDebug_DEMCR_TRCENA_Msk))
	{
		CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
		DWT->CYCCNT = 0U;
		DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk; 
	}
	me->time_start = DWT->CYCCNT;
}


/**
 * @brief Stop simple profiler
 * 
 * @param me 
 */
void simple_profiler_stop(SimpleProfiler_t * const me)
{
	me->time_stamp = DWT->CYCCNT;

	uint32_t tick_per_1us = SystemCoreClock / 1000000U;
	me->time_cc = (me->time_stamp - me->time_start);// / tick_per_1us;
	me->time_us = (float)me->time_cc / (float)tick_per_1us;
}

