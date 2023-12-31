/**
 * @file    interrupts.c
 * @author  Nikolay Shevyrev
 * @brief   User Interrupt Handlers
 */


/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "Board.h"
#include "bsp.h"
#include "bsp_delay.h"
#include "systick.h"


/* Private variables ---------------------------------------------------------*/
extern uint8_t key_state[];


/**
 * @brief PWM Timer 1 Update Interrupt Handler
 * 
 * @param[in]   none
 * @param[out]  none
 * @return      none
 */
void PWM_IRQHandler(void)
{
    APM_MINI_LEDToggle(LED3);

    TMR_ClearIntFlag(PWM_TIMER, TMR_INT_UPDATE);
}


/*!
 * @brief   This function handles External line 0 Handler Button 2
 *
 * @param   None
 *
 * @retval  None
 *
 */
void EINT0_IRQHandler(void)
{
    if(EINT_ReadIntFlag(EINT_LINE_0))
    {
        //APM_LEDToggle(LED2);
        if (key_state[BUTTON_KEY2] == SET)
        {
            key_state[BUTTON_KEY2] = RESET;
        }
        else
        {
            key_state[BUTTON_KEY2] = SET;
        }

        /* Debounce delay */
        delay_1ms(10);

        /*Clear EINT_LINE0 interrupt flag*/
        EINT_ClearIntFlag(EINT_LINE_0);
    }
}


/*!
 * @brief   This function handles External lines 1 Handler Button 1
 *
 * @param   None
 *
 * @retval  None
 *
 */
void EINT1_IRQHandler(void)
{
    if(EINT_ReadIntFlag(EINT_LINE_1))
    {
        //APM_LEDToggle(LED3);
        if (key_state[BUTTON_KEY1] == SET)
        {
             key_state[BUTTON_KEY1] = RESET;
        }
        else
        {
            key_state[BUTTON_KEY1] = SET;
        }

        /* Debounce delay */
        delay_1ms(10);

        /*Clear EINT_LINE0 interrupt flag*/
        EINT_ClearIntFlag(EINT_LINE_1);
    }
}

