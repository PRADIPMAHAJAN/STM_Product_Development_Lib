#ifndef GPIODRIVER_H
#define GPIODRIVER_H

/**
 * @file gpioDriver.h
 * @brief
 * @author pradip mahajan
 * @date Apr 13, 2024
 */

#include<stdint.h>
#include "stm32f4xx.h"

/// Functions Declarations

/// @brief This function is used to initialized a GPIO Port
/// @param Gpio Port example A, B, C and D
/// @param Moder 1st
/// @param Moder 2nd
/// @return nothing
void InitGpioOutputPort(uint8_t gpioPortEn, uint16_t fPin, uint16_t sPin);

/// @brief Function which is used to blink the led
/// @param Pin number for digital high/Low
/// @param Delay LED blink
/// @return nothing
void GpioOutputBlink(uint8_t pin, uint32_t delay);

/// @brief Function to high the digital pin
/// @param Pin number for digital high
/// @return nothing
void GpioOutputHigh(uint8_t pin);

/// @brief Function to Low the digital pin
/// @param Pin number for digital Low
/// @return nothing
void GpioOutputLow(uint8_t pin);

/// @brief Function used to initialize a input port enbale and disable for the GPIO
/// @param gpioPortEn port which is going to enable and disable
/// @param fPin first address for moder 
/// @param sPin second address for moder
void InitGpioInputPort(uint8_t gpioPortEn, uint8_t fPin, uint8_t sPin);

/// @brief Function is used to get the GPIO input
/// @param inpPin GPIO Pin for read INPUT state
/// @return return state of input state 1 = input received, 0 = not received
uint8_t GpioInputHigh(uint16_t inpPin);

#endif
