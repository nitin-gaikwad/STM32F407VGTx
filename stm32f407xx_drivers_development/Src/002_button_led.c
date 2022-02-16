/*
 * 002_button_led.c
 *
 *  Created on: 27-Sep-2020
 *      Author: Nitin Gaikwad
 */



#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


#include"stm32f407xx.h"

#define BTN_PRESSED		HIGH
void delay(void)
{
	uint32_t i;
	for(i=0;i<500000/2;i++);
}

int main(void)
{

	GPIO_Handle_t led,button;

	led.pGPIOx = GPIOD;

	led.GPIO_PinConfig.GPIO_PinNumber		=	GPIO_PIN_NO_12;
	led.GPIO_PinConfig.GPIO_PinMode 		=	GPIO_MODE_OUT;
	led.GPIO_PinConfig.GPIO_PinSpeed 		=	GPIO_SPEED_FAST;
	led.GPIO_PinConfig.GPIO_PinOPType		=	GPIO_OP_TYPE_PP;
	led.GPIO_PinConfig.GPIO_PinPuPdControl	=	GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&led);
	//led.pGPIOx = GPIOD;
	led.GPIO_PinConfig.GPIO_PinNumber		=	GPIO_PIN_NO_13;
	led.GPIO_PinConfig.GPIO_PinMode 		=	GPIO_MODE_OUT;
	led.GPIO_PinConfig.GPIO_PinSpeed 		=	GPIO_SPEED_FAST;
	led.GPIO_PinConfig.GPIO_PinOPType		=	GPIO_OP_TYPE_PP;
	led.GPIO_PinConfig.GPIO_PinPuPdControl	=	GPIO_NO_PUPD;
	GPIO_Init(&led);

	led.GPIO_PinConfig.GPIO_PinNumber		=	GPIO_PIN_NO_14;
	led.GPIO_PinConfig.GPIO_PinMode 		=	GPIO_MODE_OUT;
	led.GPIO_PinConfig.GPIO_PinSpeed 		=	GPIO_SPEED_FAST;
	led.GPIO_PinConfig.GPIO_PinOPType		=	GPIO_OP_TYPE_PP;
	led.GPIO_PinConfig.GPIO_PinPuPdControl	=	GPIO_NO_PUPD;
	GPIO_Init(&led);

	led.GPIO_PinConfig.GPIO_PinNumber		=	GPIO_PIN_NO_15;
	led.GPIO_PinConfig.GPIO_PinMode 		=	GPIO_MODE_OUT;
	led.GPIO_PinConfig.GPIO_PinSpeed 		=	GPIO_SPEED_FAST;
	led.GPIO_PinConfig.GPIO_PinOPType		=	GPIO_OP_TYPE_PP;
	led.GPIO_PinConfig.GPIO_PinPuPdControl	=	GPIO_NO_PUPD;
	GPIO_Init(&led);

	button.pGPIOx = GPIOA;

	button.GPIO_PinConfig.GPIO_PinNumber		=	GPIO_PIN_NO_0;
	button.GPIO_PinConfig.GPIO_PinMode			=	GPIO_MODE_IN;
	button.GPIO_PinConfig.GPIO_PinSpeed 		=	GPIO_SPEED_FAST;
	button.GPIO_PinConfig.GPIO_PinPuPdControl   =   GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOA, ENABLE);
	GPIO_Init(&button);
	/* Loop forever */
	while(1)
	{
		if(GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0)== BTN_PRESSED)
		{

			delay();
			GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
			GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13);
			GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_14);
			GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_15);
			//GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, HIGH);
			//GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, HIGH);
		}
		else
		{
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, LOW);
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, LOW);
		}

	}
}
