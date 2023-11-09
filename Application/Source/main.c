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

#include "simple_profiler.h"


/* Private variables ---------------------------------------------------------*/
uint32_t led_delay = 100;
uint8_t key_state[2] = {RESET, RESET};

SimpleProfiler_t profiler;

/**
 * @brief Main function
 * 
 * @param[in]   none
 * @param[out]  none
 * @return      none
 */
int main(void)
{
	NVIC_ConfigPriorityGroup(NVIC_PRIORITY_GROUP_2);
    
	APM_MINI_LEDInit(LED2);
	APM_MINI_LEDInit(LED3);

	APM_MINI_PBInit(BUTTON_KEY1, BUTTON_MODE_EINT);
	APM_MINI_PBInit(BUTTON_KEY2, BUTTON_MODE_EINT);

	//APM_DelayInit();
	systick_config();


    while (1)
    {
		if (key_state[BUTTON_KEY1] == SET)
		{
			APM_MINI_LEDToggle(LED2);
		}
		if (key_state[BUTTON_KEY2] == SET)
		{
			APM_MINI_LEDToggle(LED3);
		}
		simple_profiler_start(&profiler);
		//APM_DelayMs(led_delay);
		delay_1ms(led_delay);
		simple_profiler_stop(&profiler);
    }
}

