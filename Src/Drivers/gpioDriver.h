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
/// @param
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


void InitGpioInputPort(uint8_t gpioPortEn, uint8_t fPin, uint8_t sPin);
uint8_t GpioInputHigh(uint16_t inpPin);

#endif
