//Timer definitions
const unsigned long COMBINE_PERIOD = 100;

//Enumeration


//Tick Function
//Change the name of the function according to assignment
typedef enum CombineStates {combine_start, update } CombineStates;

int CombineLEDsSM(int state) {
	// Get input (HAL)
	
	//Variables
	unsigned char combination = 0x00;

	//State switches
	//Computation
	switch (state) {
		case combine_start:
			state = update;
			break;
		case update:
			state = update;
			break;
		default:
			state = combine_start;
			break;
	}
	//Action
	switch (state) {
		case combine_start:
			combination = blinkingLED | threeLEDs;
			break;
		case update:
			combination = blinkingLED | threeLEDs;
			break;
	}

	// Output (HAL)
	PORTB = combination;
	return state;
}
