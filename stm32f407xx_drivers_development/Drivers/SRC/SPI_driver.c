/*
 * SPI_driver.c
 *
 *  Created on: १० डिसें, २०२०
 *      Author: Nitin Gaikwad
 */


#include "SPI_driver.h"


/*
 * SPI device mode*/
#define SPI_DEVICE_MODE_MASTER		1
#define SPI_DEVICE_MODE_SLAVE		0

/*
 * SPI Bus Config
 * */

#define SPI_BUS_CONFIG_FD					1
#define SPI_BUS_CONFIG_HD					2
#define SPI_BUS_CONFIG_SIMPLEX_TXONLY		3
#define SPI_BUS_CONFIG_SIMPLEX_RXONLY		4


/*
 * SPI Bus Config
 * */

#define SPI_SCLK_DIV2
#define SPI_SCLK_DIV4
#define SPI_SCLK_DIV6
#define SPI_SCLK_DIV8
#define SPI_SCLK_DIV16
#define SPI_SCLK_DIV32
#define SPI_SCLK_DIV64
#define SPI_SCLK_DIV128
#define SPI_SCLK_DIV256




// 1. SPI Initialization and De-initialization

void SPI_Init(SPI_Handle_t *pSPIHandle);

void SPI_DeInit(SPI_RegDef_t *pSPIx);

/*
 * @brief SPI Clock Control for GPIO
 * @param  *pSPIx 	: SPI base address
 * @param  EnorDi   :  Enable or disable clock of given SPI
 * @return void		: None
 */
void SPI_PeriClockControl(SPI_RegDef_t *pSPIx, uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{
		if(pSPIx == SPI1)
		{
			SPI1_PCLK_EN();
		}
		else if(pSPIx == SPI2)
		{
			SPI2_PCLK_EN();
		}
		else if(pSPIx == SPI3)
		{
			SPI3_PCLK_EN();
		}
	}
	else
	{
		if(pSPIx == SPI1)
		{
			SPI1_PCLK_DI();
		}else if(pSPIx == SPI2)
		{
			SPI2_PCLK_DI();
		}else if(pSPIx == SPI3)
		{
			SPI3_PCLK_DI();
		}
	}
}

// 3. SPI Recieve
uint16_t  SPI_Receive(SPI_RegDef_t *pSPIx, uint8_t *pRxBuffer, uint32_t Len)
{

	return 0;
}
// 4. SPI Transmitt
void SPI_SendData(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t Len)
{

}
// 5. SPI Interrupt

// 6. SPI Interrupt Handler

/**
	* @brief  Configure the interrupt for a given IRQNumber number
	* @param  IRQNumber : IRQNumber number
	* @param  EnorDi   :  Enable or disable a given IRQNumber number
	* @retval None
	*/
void SPI_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi)
{

}
/**
	* @brief  Configure the interrupt Priority
	* @param  IRQNumber : IRQNumber number
	* @param  IRQPriority   :  Priority level of IRQ
	* @retval None
	*/
void SPI_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority)
{

}

/**
	* @brief  SPI IRQ Handler
	* @param  *pHandle : pointer to SPI handle type
	* @retval None
	*/
void SPI_IRQHandling(SPI_Handle_t *pHandle)
{

}

