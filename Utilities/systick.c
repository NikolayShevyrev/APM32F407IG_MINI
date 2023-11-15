/**
  ******************************************************************************
  * @file    systick.c
  * @author  Nikolay Shevyrev
  * @brief   System Timer Config and Delay
  ******************************************************************************
*/

/* Includes ------------------------------------------------------------------*/
#include "systick.h"
#include "Board.h"


/* Private variables ---------------------------------------------------------*/
static  volatile uint32_t tick_cnt;


/**
 * @brief Systick Configuration
 * 
 * @param[in]   none
 * @param[out]  none
 * @return      uint8_t
 */
uint8_t systick_config(void)
{
    SystemCoreClockUpdate();
    /* setup systick timer for 1000Hz interrupts */
    if (SysTick_Config(SystemCoreClock / TICKS_PER_SECOND))
    {
        /* capture error */
        return ERROR;
    }
    /* configure the systick handler priority */
    NVIC_SetPriority(SysTick_IRQn, SYSTICK_IRQ_PRIORITY);

    return SUCCESS;
}


/**
 * @brief Get tick_cnt value
 * 
 * @param[in]   none
 * @param[out]  none
 * @return      none 
 */
uint32_t get_tick(void) 
{
    uint32_t tick;

    __disable_irq();
    tick = tick_cnt;
    __enable_irq();

    return tick;
}

/**
 * @brief Delay a time in milliseconds
 * 
 * @param[in]   count: count in milliseconds
 * @param[out]  None
 * @return      None 
 */
void delay_1ms(uint32_t delay)
{
    uint32_t start = get_tick();
    while ((get_tick() - start) < delay) 
    {
    }
}

/**
 * @brief Tick increment
 * 
 * @param[in]   none
 * @param[out]  none
 * @return      none 
 */
void tick_increment(void)
{
   ++tick_cnt;
}


/**
 * @brief Toggle HeartBeat Led
 * 
 * @param[in]   none
 * @param[out]  none
 * @return      none
 */
void heart_beat_led(void)
{
    static uint32_t count = 0;

    if (count++ > HEART_BEAT_LED_FREQ)
    {
        APM_MINI_LEDToggle(LED2);
        count = 0;
    }
}

