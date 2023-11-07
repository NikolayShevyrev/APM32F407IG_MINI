/**
 * @file    main.c
 * @author  Nikolay Shevyrev
 * @brief   Main function body
 */


/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "Board.h"
#include "bsp_delay.h"


/* Private variables ---------------------------------------------------------*/
uint32_t led_delay = 100;
uint8_t key_state[2] = {RESET, RESET};

/**
 * @brief Main function
 * 
 * @param[in]   none
 * @param[out]  none
 * @return      none
 */
int main(void)
{
	APM_MINI_LEDInit(LED2);
	APM_MINI_LEDInit(LED3);

	APM_MINI_PBInit(BUTTON_KEY1, BUTTON_MODE_EINT);
	APM_MINI_PBInit(BUTTON_KEY2, BUTTON_MODE_EINT);

	APM_DelayInit();

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
		APM_DelayMs(led_delay);
    }
}

