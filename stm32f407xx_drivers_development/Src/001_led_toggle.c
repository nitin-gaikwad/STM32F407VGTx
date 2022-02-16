/*
 * 001_led_toggle.c
 *
 *  Created on: Sep 26, 2020
 *      Author: Nitin Gaikwad
 */




#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


#include"stm32f407xx.h"
void delay(void)
{
	uint32_t i;
	for(i=0;i<500000;i++);
}

int main(void)
{

	GPIO_Handle_t led;

	led.pGPIOx = GPIOD;

	led.GPIO_PinConfig.GPIO_PinNumber		=	GPIO_PIN_NO_14;
	led.GPIO_PinConfig.GPIO_PinMode 		=	GPIO_MODE_OUT;
	led.GPIO_PinConfig.GPIO_PinSpeed 		=	GPIO_SPEED_FAST;
	led.GPIO_PinConfig.GPIO_PinOPType		=	GPIO_OP_TYPE_PP;
	led.GPIO_PinConfig.GPIO_PinPuPdControl	=	GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&led);
	/* Loop forever */
	while(1)
	{
		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_14);
		delay();
	}
}
