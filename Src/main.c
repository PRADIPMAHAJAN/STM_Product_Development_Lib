#include "stm32f4xx.h"											/// STM3F4 series Library
#include "Drivers/GPIO/gpioDriver.h"							/// Gpio Driver Library
#include "Drivers/Uart/uart.h"									/// UART Driver Library

/// --------------------- GPIO OUTPUT DRIVER BEGIN ---------------------
/// GPIO Input and Output Handle
#define 			GPIOAEN 			(1U << 0)				/// Select the port A for clock enable
#define 			PIN5    			(1U << 5)				/// Set Pin for digital Output

/// set output gpio as a output by using moder
#define 			OUTPUT_F_PIN 		(1U << 10)				/// Moder first register output
#define 			OUTPUT_S_PIN		(1U << 11)				/// Moder Second register 
#define 			LED_PIN   			PIN5					/// assign a name that will understandable
#define 			BLINK_DELAY     	1000000					/// Delay in ms
/// --------------------- GPIO OUTPUT DRIVER END ------------------------

/// ----------------- GPIO INPUT DRIVER DEFINE BEGIN --------------------
#define 			GPIOCEN				(1U<<2)					/// Select the port C for clock enable
#define 			PIN13				(1U<<13)				/// Set Pin for digital Input

#define 			INPUT_F_PIN 		(1U<<26)				/// Moder first register input
#define 			INPUT_S_PIN 		(1U<<27)				/// Moder second register input
#define 			BTN_PIN				PIN13					/// Set pin for digital input
/// -------------- GPIO INPUT DRIVER DEFINE END ---------------------

/// -------------- UART Configuration Begin--------------------------
#define 			UART_BAUDRATE		115200					/// UART Baudrate
/// -------------- UART Configuration End ---------------------------

char readBuff[RX_BUFFER] = {0};									/// Read buffer for read data from rx line

int main()
{
	 InitGpioOutputPort(GPIOAEN, OUTPUT_F_PIN, OUTPUT_S_PIN); 	/// Output Initialize
	 InitGpioInputPort(GPIOCEN, INPUT_F_PIN, INPUT_S_PIN);		/// Input  Initialize

	Uart2TXInit(UART_BAUDRATE);									/// UART2 Initialization
	uart2RXInit(UART_BAUDRATE);									/// 
	while(1)
	{
		Uart2WriteString("hello this is from STM32F4\r\n");		/// UART Send data on tx line
		for(int i=0; i<1000000; i++){}

		/ --------- GPIO Input and Output operation -----------
		 if(GpioInputHigh(BTN_PIN))
		 {
		 	GpioOutputHigh(LED_PIN);
		 }
		 else
		 {
		 	GpioOutputLow(LED_PIN);
		 }

	/// ------------------ Read single character and perform the operation -------------------
		char key1 =  Uart2ReadChar();
		if(key == "ON")
		{
			GpioOutputHigh(LED_PIN);
		}
		else{
			GpioOutputLow(LED_PIN);
		}	

	/// ------------------ Read String and sentance -------------------
		char *received_sentence = Uart2ReadString();
		if (received_sentence != NULL) {
    	sprintf(readBuff, received_sentence);
    	free(received_sentence); // Free the dynamically allocated memory
		} else {
    	// Handle error: failed to read sentence
			}
		
	}
}
