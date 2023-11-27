/**
 * @file    bsp_spi.c
 * @author  Nikolay Shevyrev
 * @brief   SPI Configuration
 * @ingroup BSP
 */


/* Includes ------------------------------------------------------------------*/
#include "bsp_spi.h"
#include "bsp_defines.h"
#include "Board.h"


void bsp_spi_config(void)
{
    SPI_Config_T  SPI_InitStruct;
    SPI_ConfigStructInit(&SPI_InitStruct);

    RCM_EnableAPB1PeriphClock(SPI1_RCM);

    bsp_spi_gpios_config();

    SPI_InitStruct.direction        = SPI_DIRECTION_1LINE_TX;
    SPI_InitStruct.mode             = SPI_MODE_MASTER;
    SPI_InitStruct.length           = SPI_DATA_LENGTH_8B;
    SPI_InitStruct.polarity         = SPI_CLKPOL_LOW;
    SPI_InitStruct.phase            = SPI_CLKPHA_1EDGE;
    SPI_InitStruct.nss              = SPI_NSS_HARD;
    SPI_InitStruct.baudrateDiv      = SPI_BAUDRATE_DIV_8;
    SPI_InitStruct.firstBit         = SPI_FIRSTBIT_MSB;
    SPI_Config(SPI2, &SPI_InitStruct);

    SPI_EnableSSOutput(SPI1);

    SPI_ConfigBiDirectionalLine(SPI1, SPI_DIRECTION_TX);

    SPI_DisableCRC(SPI1);

    SPI_Enable(SPI1);
}


void bsp_spi_gpios_config(void)
{
    GPIO_Config_T GPIO_ConfigStruct;
    GPIO_ConfigStructInit(&GPIO_ConfigStruct);

    RCM_EnableAHB1PeriphClock(SPI1_PINS_RCM);

    GPIO_ConfigPinAF(SPI1_PORT, SPI1_NSS_PIN_SOURCE, SPI1_AF);
    GPIO_ConfigPinAF(SPI1_PORT, SPI1_SCK_PIN_SOURCE, SPI1_AF);
    GPIO_ConfigPinAF(SPI1_PORT, SPI1_MISO_PIN_SOURCE, SPI1_AF);
    GPIO_ConfigPinAF(SPI1_PORT, SPI1_MOSI_PIN_SOURCE, SPI1_AF);

    GPIO_ConfigStruct.pin   = SPI1_PINS;
    GPIO_ConfigStruct.mode  = GPIO_MODE_AF;
    GPIO_ConfigStruct.otype = GPIO_OTYPE_PP;
    GPIO_ConfigStruct.speed = GPIO_SPEED_100MHz;
    GPIO_ConfigStruct.pupd  = GPIO_PUPD_NOPULL;
    GPIO_Config(SPI1_PORT, &GPIO_ConfigStruct);
}

