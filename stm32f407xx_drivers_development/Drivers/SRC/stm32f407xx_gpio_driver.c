/*
 * stm32f407xx_gpio_driver.c
 *
 *  Created on: Sep 26, 2020
 *      Author: Nitin Gaikwad
 */


#include "stm32f407xx_gpio_driver.h"




/******************************************************************************************
 *								APIs supported by this driver
 *		 For more information about the APIs check the function definitions
 ******************************************************************************************/

/*
 * @brief Peripheral Clock Control for GPIO
 * @param  *GPIOx 	: GPIO Port Base address
 * @param  EnorDi   :  Enable or disable clock of given PORT
 */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi)
{

	if(EnorDi == ENABLE )
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_EN();
		}else if(pGPIOx == GPIOB)
		{
			GPIOB_PCLK_EN();
		}else if(pGPIOx == GPIOC)
		{
			GPIOC_PCLK_EN();
		}else if(pGPIOx == GPIOD)
		{
			GPIOD_PCLK_EN();
		}else if(pGPIOx == GPIOE)
		{
			GPIOE_PCLK_EN();
		}else if(pGPIOx == GPIOF)
		{
			GPIOF_PCLK_EN();
		}else if(pGPIOx == GPIOG)
		{
			GPIOG_PCLK_EN();
		}else if(pGPIOx == GPIOH)
		{
			GPIOH_PCLK_EN();
		}else if(pGPIOx == GPIOI)
		{
			GPIOI_PCLK_EN();
		}
	}
	else
	{
		if(pGPIOx == GPIOA)
				{
					GPIOA_PCLK_DI();
				}else if(pGPIOx == GPIOB)
				{
					GPIOB_PCLK_DI();
				}else if(pGPIOx == GPIOC)
				{
					GPIOC_PCLK_DI();
				}else if(pGPIOx == GPIOD)
				{
					GPIOD_PCLK_DI();
				}else if(pGPIOx == GPIOE)
				{
					GPIOE_PCLK_DI();
				}else if(pGPIOx == GPIOF)
				{
					GPIOF_PCLK_DI();
				}else if(pGPIOx == GPIOG)
				{
					GPIOG_PCLK_DI();
				}else if(pGPIOx == GPIOH)
				{
					GPIOH_PCLK_DI();
				}else if(pGPIOx == GPIOI)
				{
					GPIOI_PCLK_DI();
				}
	}
}

/**
	* @brief  Initializes the gpio pin
	* @param  *GPIOHandle : GPIO Port Handle
	* @retval None
	*/
void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
	uint32_t temp;
// 1. configure the mode of GPIO pin
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG)
	{
		temp=pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2* pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
		pGPIOHandle->pGPIOx->MODER &= ~(0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber); // clearing
		pGPIOHandle->pGPIOx->MODER |= temp; // setting

	}
	else
	{
		// configuring the interrupt
		if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_IT_FT)
		{
			//1. configure the Falling edge Trigger Selection register
			EXTI->FTSR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
			// CLEAR THE RTSR  BIT
			EXTI->RTSR &= ~(1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
		}else if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_IT_RT)
		{
			//1. configure the Rising edge Trigger Selection register
			EXTI->RTSR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
			// CLEAR THE FTSR  BIT
			EXTI->FTSR &= ~(1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
		}else if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_IT_RFT)
		{
			//1. configure the both Rising and Falling Trigger Selection register
			EXTI->FTSR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
			EXTI->RTSR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);

		}

		//2.Configure the GPIO port Selection in SYSCFG_EXTICR
		uint8_t temp1= pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber/4;
		uint8_t temp2= pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber%4;
		uint8_t portcode = GPIO_BASEADDR_TO_CODE(pGPIOHandle->pGPIOx);
		SYSCFG_PCLK_EN();
		SYSCFG->EXTICR[temp1] = portcode << (temp2 * 4);
		//3. Enable the EXTI Interrupt delivery using IMR
		EXTI->IMR |= (1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	}
	temp=0;
// 2. configure the speed of GPIO pin
	temp= pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed);
	pGPIOHandle->pGPIOx->OSPEEDR &= ~(0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->OSPEEDR |= temp;

	temp=0;
// 3. configure the PULL UP PULL DOWN  setting
	temp= pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl <<(2* pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl);
	pGPIOHandle->pGPIOx->PUPDR &= ~(0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->PUPDR |=temp;

	temp=0;
// 4. configure the output type
	temp= pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType <<(pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType);
	pGPIOHandle->pGPIOx->OTYPER &= ~(0x1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->OTYPER |=temp;

	temp=0;
// 5. configure the alternate functionality
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN)
	{
		uint32_t temp1,temp2;
		temp1= pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber/8;
		temp2= pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber%8;
		pGPIOHandle->pGPIOx->AFR[temp1] &=  ~(0xF << ( 4 * temp2 ) ); //clearing
		pGPIOHandle->pGPIOx->AFR[temp1] |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode << (4 * temp2));

	}
}

/**
	* @brief  De-Initializes the gpio pin
	* @param  *GPIOHandle : GPIO Port Handle
	* @retval None
	*/
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{
		if(pGPIOx == GPIOA)
			{
				GPIOA_REG_RESET();

			}else if(pGPIOx == GPIOB)
			{
				GPIOB_REG_RESET();

			}else if(pGPIOx == GPIOC)
			{
				GPIOC_REG_RESET();

			}else if(pGPIOx == GPIOD)
			{
				GPIOD_REG_RESET();

			}else if(pGPIOx == GPIOE)
			{
				GPIOE_REG_RESET();
			}else if(pGPIOx == GPIOF)
			{
				GPIOF_REG_RESET();
			}else if(pGPIOx == GPIOG)
			{
				GPIOG_REG_RESET();
			}else if(pGPIOx == GPIOH)
			{
				GPIOH_REG_RESET();
			}else if(pGPIOx == GPIOI)
			{
				GPIOI_REG_RESET();
			}


}

/**
	* @brief  Read a value from a  given pin number
	* @param  *GPIOx 	: GPIO Port Base address
	* @param  PinNumber : GPIO pin number
	* @retval uint8_t	: Value read
	*/
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	uint8_t value;
	value =(uint8_t)((pGPIOx->IDR >>PinNumber) & 0x00000001);
	return value;
}

/**
	* @brief  Read a value from a  given PORT
	* @param  *GPIOx 	: GPIO Port Base address
	* @retval uint16_t	: Value read
	*/
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{
	uint16_t value;
	value = (uint16_t)pGPIOx->IDR;
	return value;
}

/**
	* @brief  Write a value to given pin number
	* @param  *pGPIOx : GPIO Port Base address
	* @param  PinNumber : GPIO pin number
	* @param  value   : value to be written
	* @retval None
	*/
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value)
{
	if(Value == GPIO_PIN_SET)
	{
		pGPIOx->ODR |= (1<< PinNumber);
	}else
	{
		pGPIOx->ODR &= ~(1<< PinNumber);
	}
}

/**
	* @brief  Write a value to given PORT
	* @param  *pGPIOx : GPIO Port Base address
	* @param  value   : value to be written
	* @retval None
	*/

void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value)
{

	pGPIOx->ODR= Value;
}

/**
	* @brief  Toggle a value to given pin number
	* @param  *pGPIOx : GPIO Port Base address
	* @param  PinNumber : GPIO pin number
	* @retval None
	*/
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{

		pGPIOx->ODR ^= (1<< PinNumber);
}


/**
	* @brief  Configure the interrupt for a given IRQNumber number
	* @param  IRQNumber : IRQNumber number
	* @param  EnorDi   :  Enable or disable a given IRQNumber number
	* @retval None
	*/
void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi)
{

	if(EnorDi == ENABLE)
	{
		if(IRQNumber <= 31)
		{
			//program ISER0 register
			*NVIC_ISER0 |= ( 1 << IRQNumber );

		}else if(IRQNumber > 31 && IRQNumber < 64 ) //32 to 63
		{
			//program ISER1 register
			*NVIC_ISER1 |= ( 1 << (IRQNumber % 32) );
		}
		else if(IRQNumber >= 64 && IRQNumber < 96 )
		{
			//program ISER2 register //64 to 95
			*NVIC_ISER2 |= ( 1 << (IRQNumber % 64) );
		}
	}else
	{
		if(IRQNumber <= 31)
		{
			//program ICER0 register
			*NVIC_ICER0 |= ( 1 << IRQNumber );
		}else if(IRQNumber > 31 && IRQNumber < 64 )
		{
			//program ICER1 register
			*NVIC_ICER1 |= ( 1 << (IRQNumber % 32) );
		}
		else if(IRQNumber >= 64 && IRQNumber < 96 )
		{
			//program ICER2 register
			*NVIC_ICER2 |= ( 1 << (IRQNumber % 64) );
		}
	}

}

/**
	* @brief  Configure the interrupt Priority
	* @param  IRQNumber : IRQNumber number
	* @param  IRQPriority   :  Priority level of IRQ
	* @retval None
	*/
void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority)
{
	// first find out the Interrupt Priority Register
	uint8_t iprx = IRQNumber/4;
	uint8_t iprx_section = IRQNumber %4;
	uint8_t shift_amount = (8 * iprx_section) + (8 - NO_PR_BITS_IMPLEMENTED);
	*(NVIC_PR_BASE_ADDR + iprx * 4) |= (IRQPriority << shift_amount);


}
/**
	* @brief  GPIO IRQ Handler
	* @param  PinNumber : PinNumber number
	* @retval None
	*/
void GPIO_IRQHandling(uint8_t PinNumber)
{


}
