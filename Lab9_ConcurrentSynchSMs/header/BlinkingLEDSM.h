//Timer #define s
const unsigned long BLINK_PERIOD = 1000;

//Enumeration

//Global output
unsigned char blinkingLED = 0;
//Tick Function
//Change the name of the function according to assignment
typedef enum LEDStates {blink_start, on, off} LEDStates;

int BlinkingLEDSM(int state) {
	// Get input (HAL)
	
	//Variables
	const unsigned char ON = 0x08;
	const unsigned char OFF = 0x00;

	//State switches
	//Computation
	switch (state) {
		case blink_start:
			state = off;
			break;
		case off:
			state = on;
			break;
		case on:
			state = off;
			break;
		default:
			state = blink_start;
			break;
	}
	//Action
	switch (state) {
		case blink_start:
			break;
		case off:
			blinkingLED = OFF;
			break;
		case on:
			blinkingLED = ON;
			break;
	}

	// Output (HAL)
	
	return state;
}
