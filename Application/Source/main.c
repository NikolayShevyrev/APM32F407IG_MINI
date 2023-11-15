/**
 * @file    main.c
 * @author  Nikolay Shevyrev
 * @brief   Main function body
 */


/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "Board.h"
#include "bsp_delay.h"
#include "systick.h"
#include "bsp.h"

#include "simple_profiler.h"


/* Private variables ---------------------------------------------------------*/
uint32_t led_delay = 100;
uint8_t key_state[2] = {RESET, RESET};

SimpleProfiler_t profiler;

uint32_t temp_priority;

/**
 * @brief Main function
 * 
 * @param[in]   none
 * @param[out]  none
 * @return      none
 */
int main(void)
{
	bsp_config();
    
	APM_MINI_LEDInit(LED2);
	APM_MINI_LEDInit(LED3);

	APM_MINI_PBInit(BUTTON_KEY1, BUTTON_MODE_EINT);
	APM_MINI_PBInit(BUTTON_KEY2, BUTTON_MODE_EINT);

    while (1)
    {
		/* CODE */
    }
}

