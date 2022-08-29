/*
 * SPI_driver.h
 *
 *  Created on: १० डिसें, २०२०
 *      Author: Nitin Gaikwad
 */

#ifndef INC_SPI_DRIVER_H_
#define INC_SPI_DRIVER_H_

#include "stm32f407xx.h"



/*
 * SPI device mode*/
#define SPI_DEVICE_MODE_MASTER		1
#define SPI_DEVICE_MODE_SLAVE		0

/*
 * SPI Bus Config
 * */

#define SPI_BUS_CONFIG_FD					1
#define SPI_BUS_CONFIG_HD					2
#define SPI_BUS_CONFIG_SIMPLEX_RXONLY		3


/*
 * SPI Bus Config
 * */

#define SPI_SCLK_DIV2				0
#define SPI_SCLK_DIV4				1
#define SPI_SCLK_DIV8				2
#define SPI_SCLK_DIV16				3
#define SPI_SCLK_DIV32				4
#define SPI_SCLK_DIV64				5
#define SPI_SCLK_DIV128				6
#define SPI_SCLK_DIV256				7



/*
 * SPI Data Frame Format
 *
 *
 *   */
#define SPI_DFF_8BIT				0
#define SPI_DFF_16BIT				1

/*
 * SPI CLOCK POLARITY
 *
 *
 *   */
#define SPI_CPOL_LOW				0
#define SPI_CPOL_HIGH				1

/*
 * SPI CLOCK PHASE
 *
 *
 *   */
#define SPI_CPHA_LOW				0
#define SPI_CPHA_HIGH				1


/*
 * SPI SLAVE SELECT MANAGEMENT (SSM)
 *
 *
 *   */
#define SPI_SSM_EN	1
#define SPI_SSM_DI	0


#define SPI_TXE_FLAG	(1<<SPI_SR_TXE)
#define SPI_RXNE_FLAG	(1<<SPI_SR_RXNE)
#define SPI_BUSY_FLAG	(1<<SPI_SR_BSY)

/*
 * Configuration  structure for SPI
 */

typedef struct
{
	__vo uint32_t SPI_DeviceMode;
	__vo uint32_t SPI_BusConfig;
	__vo uint32_t SPI_SclkSpeed;
	__vo uint32_t SPI_DFF;
	__vo uint32_t SPI_CPOL;
	__vo uint32_t SPI_CPHA;
	__vo uint32_t SPI_SSM;
}SPI_config_t;


/*
 * Handle  structure for SPIx Peripheral
 */

typedef struct
{
	SPI_RegDef_t *pSPIx;
	SPI_config_t SPIConfig;
	}SPI_Handle_t;


// 1. SPI Initialization and De-initialization

void SPI_Init(SPI_Handle_t *pSPIHandle);

void SPI_DeInit(SPI_RegDef_t *pSPIx);
/*
 * @brief SPI Clock Control for GPIO
 * @param  *pSPIx 	: SPI base address
 * @param  EnorDi   :  Enable or disable clock of given SPI
 */
void SPI_PeriClockControl(SPI_RegDef_t *pSPIx, uint8_t EnorDi);
// 3. SPI Recieve
uint16_t  SPI_Receive(SPI_RegDef_t *pSPIx, uint8_t *pRxBuffer, uint32_t Len);
// 4. SPI Transmitt
void SPI_SendData(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t Len);
// 5. SPI Interrupt

// 6. SPI Interrupt Handler

/**
	* @brief  Configure the interrupt for a given IRQNumber number
	* @param  IRQNumber : IRQNumber number
	* @param  EnorDi   :  Enable or disable a given IRQNumber number
	* @retval None
	*/
void SPI_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi);
/**
	* @brief  Configure the interrupt Priority
	* @param  IRQNumber : IRQNumber number
	* @param  IRQPriority   :  Priority level of IRQ
	* @retval None
	*/
void SPI_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);

/**
	* @brief  SPI IRQ Handler
	* @param  *pHandle : pointer to SPI handle type
	* @retval None
	*/
void SPI_IRQHandling(SPI_Handle_t *pHandle);

uint8_t SPI_GetFlagStatus(SPI_RegDef_t *pSPIx, uint32_t FlagName);

#endif /* INC_SPI_DRIVER_H_ */
