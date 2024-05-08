#ifndef UART_H
#define UART_H

/**
 * @file uart.h
 * @brief Hnadling all the uart related operation transmit and receive
 * @author pradip mahajan
 * @date Apr 21, 2024
 */
#include<stdint.h>								    /// Standard integer uint8_t, uint16_t etc.
#include "stm32f4xx.h"							    /// stm functions
#include<stdio.h>								    /// standard input and output

/// UART Config Macros
/// ----------------- TRANSMIT MACROS BEGIN -----------------------------------
#define 		GPIOAEN				(1U<<0)		    /// GPIO PORT A Clock Enable
#define 		UART2EN				(1U<<17)	    /// UART2 PORT Clock Enable

#define 		CR1_TE				(1U<<3)		    /// Control register transmit enable
#define 		CR1_UE				(1U<<13)	    /// Control register UART Enable
#define 		SR_TXE				(1U<<7)		    /// Status register transmit data register empty

#define 		SYS_FREQ			16000000	    /// Clock frequency
#define 		APB1_CLK			SYS_FREQ
/// ----------------- TRANSMIT MACROS END -----------------------------------

/// ----------------- RECEIVE MACROS BEGIN -----------------------------------
#define         CR1_RE			    (1U<<2)         /// Enable Control register receiver enable
#define         SR_RXNE			    (1U<<5)         /// Status register receiver data register empty
#define         RX_BUFFER           128             /// RX Buffer 
/// ----------------- RECEIVE MACROS END -----------------------------------

/// Functions Declarations

/// @brief function is used to store the baudrate in the baudrate register
/// @param USARTx UART Number Port
/// @param PeriphClk APB1_CLK
/// @param BaudRate Baudrate for transmit and receive the data
static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk,  uint32_t BaudRate);

/// @brief Claculate the baud rate by using the clock frequency
/// @param PeriphClk peripherals clock frequency
/// @param BaudRate Baudrate for transmit and receive the data
/// @return Baudrate return
static uint16_t compute_uart_bd(uint32_t PeriphClk, uint32_t BaudRate);

/// @brief UART2 Initialization and configuration
/// @param uartBaudrate Baudrate for transmit and receive the data
void Uart2TXInit(uint32_t uartBaudrate);

/// @brief To send the characters to the uart port
/// @param ch character/string to send 
void Uart2WriteChar(int ch);

/// @brief Send the string/sentence on the uart
/// @param str String and sentence to send
void Uart2WriteString(const char *str);

/// ---------------------- Receive Functions -------------------------

/// @brief Receiver initialization
/// @param uartBaudrate Buadrate
void uart2RXInit(uint32_t uartBaudrate);

/// @brief Function is used to read the character from uart on rx line
/// @param  void
/// @return return char that read from rx line
char Uart2ReadChar(void);

/// @brief Function is used to read the whole sting/sentance
/// @param  void
/// @return string or sentance that read from the rx line
char *Uart2ReadString(void);

#endif
