/*
 * 006spi_testing.c
 *
 *  Created on: 29-Jul-2022
 *      Author: DOES
 */


#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


#include"stm32f407xx.h"
void SPI_GPIO_Inits(void);
char *data="Hello World";


int main(void)
{
	SPI_GPIO_Inits();

	return 0;
}

void SPI_GPIO_Inits(void)
{
GPIO_Handle_t SPI_pins;
	/*
	 * PB14 = MISO
	 * PB15 = MOSI
	 * PB13 = SCK
	 * PB12 = NSS
	 */
	SPI_pins.pGPIOx= GPIOB;


	SPI_pins.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
	SPI_pins.GPIO_PinConfig.GPIO_PinAltFunMode= 5;
	SPI_pins.GPIO_PinConfig.GPIO_PinOPType= GPIO_OP_TYPE_PP;
	SPI_pins.GPIO_PinConfig.GPIO_PinPuPdControl= GPIO_NO_PUPD;
	SPI_pins.GPIO_PinConfig.GPIO_PinSpeed= GPIO_SPEED_HIGH;

	//1. SCLK Pin PB13
	SPI_pins.GPIO_PinConfig.GPIO_PinNumber= GPIO_PIN_NO_13;
	GPIO_Init(&SPI_pins);

	//2. MOSI Pin PB15
		SPI_pins.GPIO_PinConfig.GPIO_PinNumber= GPIO_PIN_NO_15;
		GPIO_Init(&SPI_pins);

	//3. MISO Pin PB14
		SPI_pins.GPIO_PinConfig.GPIO_PinNumber= GPIO_PIN_NO_14;
		GPIO_Init(&SPI_pins);

	//2. NSS Pin PB12
		SPI_pins.GPIO_PinConfig.GPIO_PinNumber= GPIO_PIN_NO_12;
		GPIO_Init(&SPI_pins);


}
