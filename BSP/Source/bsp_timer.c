/**
 * @file    bsp_timer.c
 * @author  Nikolay Shevyrev
 * @brief   Timers Configuration
 * @ingroup BSP
 */


/* Includes ------------------------------------------------------------------*/
#include "bsp_timer.h"
#include "bsp_defines.h"
#include "Board.h"


/**
 * @brief Timer1 configuration
 * 
 * @param[in]   none
 * @param[out]  none
 * @return      none
 */
void bsp_timer1_config(void)
{
    TMR_BaseConfig_T TMR_TimeBaseStruct;
    TMR_OCConfig_T OCcongigStruct;
    TMR_BDTConfig_T BDTConfigStruct;

    uint32_t timer_period = (SystemCoreClock/DEFAULT_PWM_FREQ)/2-1;

    RCM_EnableAPB2PeriphClock(PWM_TIMER_RCM);

    TMR_TimeBaseStruct.clockDivision        = TMR_CLOCK_DIV_1;
    TMR_TimeBaseStruct.countMode            = TMR_COUNTER_MODE_CENTER_ALIGNED1;
    TMR_TimeBaseStruct.division             = 0U;
    TMR_TimeBaseStruct.period               = timer_period;
    TMR_TimeBaseStruct.repetitionCounter    = 1;
    TMR_ConfigTimeBase(PWM_TIMER, &TMR_TimeBaseStruct);

    OCcongigStruct.outputState  = TMR_OC_STATE_ENABLE;
    OCcongigStruct.outputNState = TMR_OC_NSTATE_ENABLE;
    OCcongigStruct.idleState    = TMR_OC_IDLE_STATE_RESET;
    OCcongigStruct.nIdleState   = TMR_OC_NIDLE_STATE_RESET;
    OCcongigStruct.polarity     = TMR_OC_POLARITY_HIGH;
    OCcongigStruct.nPolarity    = TMR_OC_NPOLARITY_HIGH;
    OCcongigStruct.mode         = TMR_OC_MODE_PWM1;
    OCcongigStruct.pulse        = timer_period/2;
    TMR_ConfigOC1(PWM_TIMER, &OCcongigStruct);
    TMR_ConfigOC2(PWM_TIMER, &OCcongigStruct);
    TMR_ConfigOC3(PWM_TIMER, &OCcongigStruct);

    TMR_ConfigBDTStructInit(&BDTConfigStruct);
    BDTConfigStruct.deadTime = 0xC3; /* 0b11000011 t = 1.6 us */
    TMR_ConfigBDT(PWM_TIMER, &BDTConfigStruct);

    TMR_ConfigOC1Preload(PWM_TIMER, TMR_OC_PRELOAD_ENABLE);
    TMR_EnableAutoReload(PWM_TIMER);

    TMR_EnableInterrupt(PWM_TIMER, TMR_INT_UPDATE);

    TMR_Enable(PWM_TIMER);
    TMR_EnablePWMOutputs(PWM_TIMER);
}

