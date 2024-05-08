/*
 * uart.c
 *
 *  Created on: Apr 21, 2024
 *      Author: Pradip
 */
#include "uart.h"			

/// ---------------------------- UART TRANSMIT BEGIN ------------------------------
int __io_putchar(int ch)
{
	Uart2Write(ch);
	return ch;
}

void Uart2TXInit(uint32_t uartBaudrate)
{
	/****************Configure uart gpio pin***************/
	/*Enable clock access to gpioa */
	RCC->AHB1ENR |= GPIOAEN;

	/*Set PA2 mode to alternate function mode*/
	GPIOA->MODER &=~(1U<<4);
	GPIOA->MODER |= (1U<<5);

	/*Set PA2 alternate function type to UART_TX (AF07)*/
	GPIOA->AFR[0] |= (1U<<8);
	GPIOA->AFR[0] |= (1U<<9);
	GPIOA->AFR[0] |= (1U<<10);
	GPIOA->AFR[0] &= ~(1U<<11);

	/****************Configure uart module ***************/
	/*Enable clock access to uart2 */
	RCC->APB1ENR |= UART2EN;

	/*Configure baudrate*/
	uart_set_baudrate(USART2,APB1_CLK,uartBaudrate);

	/*Configure the transfer direction*/
	 USART2->CR1 =  CR1_TE;

	/*Enable uart module*/
	 USART2->CR1 |= CR1_UE;
}

void uart2RXInit(uint32_t uartBaudrate)
{
	/****************Configure uart gpio pin***************/
	/*Enable clock access to gpioa */
	RCC->AHB1ENR |= GPIOAEN;

	/*Set PA2 mode to alternate function mode*/
	GPIOA->MODER &=~(1U<<4);
	GPIOA->MODER |= (1U<<5);

	/*Set PA2 alternate function type to UART_TX (AF07)*/
	GPIOA->AFR[0] |= (1U<<8);
	GPIOA->AFR[0] |= (1U<<9);
	GPIOA->AFR[0] |= (1U<<10);
	GPIOA->AFR[0] &= ~(1U<<11);


	/*Set PA3 mode to alternate function mode*/
	GPIOA->MODER &=~(1U<<6);
	GPIOA->MODER |= (1U<<7);

	/*Set PA3 alternate function type to UART_RX (AF07)*/
	GPIOA->AFR[0] |= (1U<<12);
	GPIOA->AFR[0] |= (1U<<13);
	GPIOA->AFR[0] |= (1U<<14);
	GPIOA->AFR[0] &= ~(1U<<15);

	/****************Configure uart module ***************/
	/*Enable clock access to uart2 */
	RCC->APB1ENR |= UART2EN;

	/*Configure baudrate*/
	uart_set_baudrate(USART2,APB1_CLK,uartBaudrate);

	/*Configure the transfer direction*/
	 USART2->CR1 =  (CR1_TE | CR1_RE);

	/*Enable uart module*/
	 USART2->CR1 |= CR1_UE;
}

char Uart2ReadChar(void)
{
	  /*Make sure the receive data register is not empty*/
	while(!(USART2->SR & SR_RXNE)){}

	/*Read data*/
	return USART2->DR;
}

char *Uart2ReadString(void) {
    char *sentence = (char *)malloc(RX_BUFFER * sizeof(char));
    if (sentence == NULL) {
        // Handle memory allocation error
        return NULL;
    }
    int index = 0;

    while (1) {
        // Make sure the receive data register is not empty
        while (!(USART2->SR & SR_RXNE)) {}

        // Read data
        char received_char = USART2->DR;

        // Check if the received character is a newline or carriage return
        if (received_char == '\n' || received_char == '\r') {
            sentence[index] = '\0'; // Null-terminate the string
            break; // Exit the loop, end of sentence reached
        }

        // Add the character to the sentence
        sentence[index] = received_char;

        // Move to the next position in the sentence
        index++;

        // Check if the sentence exceeds maximum length
        if (index >= RX_BUFFER - 1) {
            // Handle error: sentence too long
            break;
        }
    }
    return sentence;
}

void Uart2WriteChar(int ch)
{
  /*Make sure the transmit data register is empty*/
	while(!(USART2->SR & SR_TXE)){}

  /*Write to transmit data register*/
	USART2->DR	=  (ch & 0xFF);
}

void Uart2WriteString(const char *str) {
    while (*str) {
        /* Wait for the transmit data register to be empty */
        while (!(USART2->SR & SR_TXE)) {}

        /* Write to transmit data register */
        USART2->DR = (*str & 0xFF);

        /* Move to the next character */
        str++;
    }
}

static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk,  uint32_t BaudRate)
{
	USARTx->BRR =  compute_uart_bd(PeriphClk,BaudRate);
}

static uint16_t compute_uart_bd(uint32_t PeriphClk, uint32_t BaudRate)
{
	return ((PeriphClk + (BaudRate/2U))/BaudRate);
}


