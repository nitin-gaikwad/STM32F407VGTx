/*
 * SPI_driver.c
 *
 *  Created on: १० डिसें, २०२०
 *      Author: Nitin Gaikwad
 */


#include "SPI_driver.h"



// 1. SPI Initialization and De-initialization

void SPI_Init(SPI_Handle_t *pSPIHandle)
{

	uint32_t tempreg=0;

	//1. configure device mode
	tempreg |= pSPIHandle->SPIConfig.SPI_DeviceMode <<2;
	//pSPIHandle->pSPIx->SPI_CR1|=tempreg;

	//2. Configure Bus Config
	if(pSPIHandle->SPIConfig.SPI_BusConfig ==  SPI_BUS_CONFIG_FD)
	{
		//BIDI mode should be cleared
		tempreg &= ~(1<<SPI_CR1_BIDIMODE);
		//pSPIHandle->pSPIx->SPI_CR1 |=  tempreg;

	}else if(pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_HD)
	{
		//BIDI mode should be SET
		tempreg |= (1<< SPI_CR1_BIDIMODE);
	}else if(pSPIHandle->SPIConfig.SPI_BusConfig ==  SPI_BUS_CONFIG_SIMPLEX_RXONLY)
	{
	//	BIDI mode should be CLEARED and
		tempreg &= ~(1<<SPI_CR1_BIDIMODE);

		// RX ONLY bit should be SET
		tempreg |= (1<< SPI_CR1_RXONLY);


	}

	//3. Configure SPI Serial Clock
		tempreg |= pSPIHandle->SPIConfig.SPI_SclkSpeed << SPI_CR1_BR;

	//4. Configure SPI data frame format
		tempreg |= pSPIHandle->SPIConfig.SPI_DFF << SPI_CR1_DFF;

	//5. Configure SPI Clock Polarity
		tempreg |= pSPIHandle->SPIConfig.SPI_CPOL <<SPI_CR1_POL;

	//6. Configure SPI Clock Phase
		tempreg |= pSPIHandle->SPIConfig.SPI_CPHA << SPI_CR1_CPHA;

		pSPIHandle->pSPIx->SPI_CR1 = tempreg;
}

void SPI_DeInit(SPI_RegDef_t *pSPIx)
{
	if(pSPIx == SPI1)
	{
		SPI1_REG_RESET();
	}else if(pSPIx == SPI2)
	{
		SPI2_REG_RESET();
	}else if(pSPIx == SPI3)
	{
		SPI3_REG_RESET();
	}
}

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

// 3. SPI Receive
uint16_t  SPI_Receive(SPI_RegDef_t *pSPIx, uint8_t *pRxBuffer, uint32_t Len)
{

	return 0;
}
// 4. SPI Transmit
void SPI_SendData(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t Len)
{
	while(Len>0)
	{
		//1. wait until TXE is SET

		while(SPI_GetFlagStatus(pSPIx, SPI_TXE_FLAG) ==  FLAG_RESET);
		//2. Check DFF bit in CR1
		if(pSPIx->SPI_CR1 & (1<< SPI_CR1_DFF))
		{
			//16bit DFF
			pSPIx->SPI_DR = *((uint16_t*)pTxBuffer);
			Len--;
			Len--;
			(uint16_t*)pTxBuffer++;
		}
		else
		{
			// 8bit DFF
			pSPIx->SPI_DR = *pTxBuffer;
			Len--;
			pTxBuffer++;

		}
	}


}


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

uint8_t SPI_GetFlagStatus(SPI_RegDef_t *pSPIx, uint32_t FlagName)
{
	if(pSPIx->SPI_SR & FlagName)
	{
		return FLAG_SET;
	}

	return FLAG_RESET;
}

