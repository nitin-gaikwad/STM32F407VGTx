/*
 * SPI_driver.h
 *
 *  Created on: १० डिसें, २०२०
 *      Author: Nitin Gaikwad
 */

#ifndef INC_SPI_DRIVER_H_
#define INC_SPI_DRIVER_H_

#include "stm32f407xx.h"
// 1. SPI Initialization and Deinitialization

void SPI_Init(SPI_Handle_t *pSPIHandle);

void SPI_DeInit(SPI_RegDef_t *pSPIx);
/*
 * @brief SPI Clock Control for GPIO
 * @param  *pSPIx 	: SPI base address
 * @param  EnorDi   :  Enable or disable clock of given SPI
 */
void SPI_PeriClockControl(SPI_RegDef_t *pSPIx, uint8_t EnorDi);
// 3. SPI Recieve
uint16_t  SPI_Receive();
// 4. SPI Transmitt
void SPI_Transmitt();
// 5. SPI Interrupt

// 6. SPI Interrupt Handler

#endif /* INC_SPI_DRIVER_H_ */
