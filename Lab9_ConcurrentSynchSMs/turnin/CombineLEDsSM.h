//Timer #define s



//Enumeration


//Tick Function
//Change the name of the function according to assignment
typedef enum CombineStates {init, update } CombineStates;

int CombineLEDsSM(int state) {
	// Get input (HAL)
	
	//Variables
	unsigned char combination = 0x00;

	//State switches
	//Computation
	switch (state) {
		case init:
			state = update;
			break;
		case update:
			state = update;
			break;
		default:
			state = init;
			break;
	}
	//Action
	switch (state) {
		case init:
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
