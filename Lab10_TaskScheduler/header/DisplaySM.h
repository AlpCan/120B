#ifndef DISPLAYSM_H
#define DISPLAYSM_H
//Timer
const unsigned long DISPLAYSM_PERIOD = 100;


//Enumeration
typedef enum DisplayStates {DisplaySM_start, display } DisplayState;



//Tick Function
//Change the name of the function according to assignment
int DisplaySM(int state) {
	// Get input (HAL)
	
	//Variables
	static unsigned char displayOut = 0;

	//State switches
	//Computation
	switch (state) {
		case DisplaySM_start:
			state = display;
			break;
		case display:
			state = display;
			break;
		default:
			state = DisplaySM_start;
			break;
	}
	//Action
	switch (state) {
		case DisplaySM_start:
			break;
		case display:
			displayOut = bolt;
			break;
	}

	// Output (HAL)
	PORTB = displayOut;
	PORTB = PORTB | 0x80;
	return state;
}
#endif
