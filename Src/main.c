#include "stm32f4xx.h"						/// STM3F4 series library
#include "Drivers/gpioDriver.h"				/// Gpio Driver library

/// --------------------- GPIO OUTPUT DRIVER BEGIN -------------------
/// GPIO Input and Output Handle
#define 		GPIOAEN 		(1U << 0)	/// Select the port A for clock enable
#define 		PIN5    		(1U << 5)	/// Set Pin for digital Output

/// set output gpio as a output by using moder
#define 		OUTPUT_F_PIN 			(1U << 10)
#define 		OUTPUT_S_PIN			(1U << 11)

#define 		LED_PIN   		PIN5		/// assign a name that will understandable
#define 		BLINK_DELAY     1000000		/// Delay ms
/// --------------------- GPIO OUTPUT DRIVER END -------------------

/// ----------------- GPIO INPUT DRIVER DEFINE BEGIN --------------------
#define 		GPIOCEN			(1U<<2)
#define 		PIN13			(1U<<13)

#define 		INPUT_F_PIN 	(1U<<26)
#define 		INPUT_S_PIN 	(1U<<27)

#define 		BTN_PIN			PIN13
/// ----------------- GPIO INPUT DRIVER DEFINE END --------------------


int main()
{
	InitGpioOutputPort(GPIOAEN, OUTPUT_F_PIN, OUTPUT_S_PIN); 	/// Output Init
	InitGpioInputPort(GPIOCEN, INPUT_F_PIN, INPUT_S_PIN);		/// Input Init
	while(1)
	{
		if(GpioInputHigh(BTN_PIN))
		{
			GpioOutputHigh(LED_PIN);
		}
		else
		{
			GpioOutputLow(LED_PIN);
		}
	}
}
