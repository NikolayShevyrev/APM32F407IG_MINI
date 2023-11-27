/**
 * @file    bsp_spi.h
 * @author  Nikolay Shevyrev
 * @brief   Header for bsp_spi.c
 * @ingroup BSP
 */


#ifndef BSP_SPI_H
#define BSP_SPI_H

#ifdef __cplusplus
 extern "C" {
#endif


/* Includes ------------------------------------------------------------------*/
#include "main.h"


/* Private function prototypes -----------------------------------------------*/
void bsp_spi_config(void);

void bsp_spi_gpios_config(void);


#ifdef __cplusplus
}
#endif

#endif /* BSP_SPI_H */

