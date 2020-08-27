#ifndef DOORBELLBUTTONSM_H
#define DOORBELLBUTTONSM_H
//Timer #define s
const unsigned long DOORBELLBUTTONSM_PERIOD =200;

//Global Variables
unsigned char buttonDoorBell = 0;
//Enumeration
typedef enum DoorBellButtonStates {DoorBellButtonSM_start, waitButton, hold } DoorBellButtonState ;

//Tick Function
//Change the name of the function according to assignment


int DoorBellButtonSM(int state) {
	// Get input (HAL)
	unsigned char button = ~PINA & 0x01;
	//Variables
	unsigned char ringTime = 15;
	static unsigned char i = 0;

	//State switches
	//Computation
	switch (state) {
		case DoorBellButtonSM_start:
			state = waitButton;
			break;
		case waitButton:
			state = (button) ? hold : waitButton;
			break;
		case hold:
			state = (i < ringTime || button) ? hold : waitButton;
			break;
		default:
			state = DoorBellButtonSM_start;
			break;
	}
	//Action
	switch (state) {
		case DoorBellButtonSM_start:
			break;
		case waitButton:
			i = 0;
			buttonDoorBell = 0;
			break;
		case hold:
			buttonDoorBell = 1;
			++i;
			break;
	}

	// Output (HAL)
	return state;
}
#endif // DOORBELLBUTTON_SM
