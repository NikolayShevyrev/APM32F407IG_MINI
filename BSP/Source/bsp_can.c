/**
 * @file    bsp_can.c
 * @author  Nikolay Shevyrev
 * @brief   CAN Bus Configuration
 * @ingroup BSP
 */


/* Includes ------------------------------------------------------------------*/
#include "bsp_can.h"
#include "bsp_defines.h"
#include "Board.h"



void can_loopback_config(CAN_T * can)
{
    CAN_Config_T CAN_ConfigStruct;
    CAN_FilterConfig_T CAN_FilterConfigStruct;

    if (can == CAN1)
    {
        RCM_EnableAPB1PeriphClock(CAN1_RCM);
    }
    else
    {
        RCM_EnableAPB1PeriphClock(CAN2_RCM);
    }

    CAN_Reset(can);

    CAN_ConfigStructInit(&CAN_ConfigStruct);

    CAN_ConfigStruct.autoBusOffManage   = DISABLE;
    CAN_ConfigStruct.autoWakeUpMode     = DISABLE;
    CAN_ConfigStruct.nonAutoRetran      = DISABLE;
    CAN_ConfigStruct.rxFIFOLockMode     = DISABLE;
    CAN_ConfigStruct.txFIFOPriority     = DISABLE;

    CAN_ConfigStruct.mode   = CAN_MODE_LOOPBACK;

    /* configure baudrate to 500 kbps */
    CAN_ConfigStruct.syncJumpWidth  = CAN_SJW_1;
    CAN_ConfigStruct.timeSegment1   = CAN_TIME_SEGMENT1_8;
    CAN_ConfigStruct.timeSegment2   = CAN_TIME_SEGMENT2_3;
    CAN_ConfigStruct.prescaler      = 7;
    CAN_Config(can, &CAN_ConfigStruct);

}