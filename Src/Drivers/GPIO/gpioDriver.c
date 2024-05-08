/*
 * gpioDriver.c
 *
 *  Created on: Apr 13, 2024
 *      Author: Pradip
 */

#include "gpioDriver.h"

/// ---------------- OUTPUT DRIVERS FUNCTIONS BEGIN -----------------------

void InitGpioOutputPort(uint8_t gpioPortEn, uint16_t fPin, uint16_t sPin)
{
	RCC->AHB1ENR |= gpioPortEn;		/// Set the bit for port A enable
	GPIOA->MODER |= fPin;			/// set a bit
	GPIOA->MODER &=~ sPin;			/// clear a bit
}

void GpioOutputBlink(uint8_t pin, uint32_t delay)
{
	GPIOA->ODR |= pin;				/// digital set the pin to high pin
	for(int i=0; i<delay; i++){}	/// put a delay
	GPIOA->ODR &=~ pin;
	for(int i=0; i<delay; i++){}
}

void GpioOutputHigh(uint8_t pin)
{
	GPIOA->ODR |= pin;
}

void GpioOutputLow(uint8_t pin)
{
	GPIOA->ODR &=~ pin;
}
/// ---------------- OUTPUT DRIVERS FUNCTIONS END -----------------------


void InitGpioInputPort(uint8_t gpioPortEn, uint8_t fPin, uint8_t sPin)
{
	RCC->AHB1ENR |= gpioPortEn;		/// Set the bit for port A enable
	GPIOC->MODER &=~fPin;
	GPIOC->MODER &=~sPin;
}

uint8_t GpioInputHigh(uint16_t inpPin)
{
	/*Check if BTN is pressed*/
	if(GPIOC->IDR & inpPin)
	{
		return 1;
	}
	else{
		return 0;
	}
}















