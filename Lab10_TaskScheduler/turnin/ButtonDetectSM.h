#ifndef BUTTONDETECTSM_H
#define BUTTONDETECTSM_H
//Timer #define s
const unsigned long BUTTONDETECTSM_PERIOD = 100;


//Global variable
unsigned char buttonDetect;
//Enumeration
typedef enum ButtonDetectStates {ButtonDetectSM_start, waitPress, detect } ButtonDetectStates;



//Tick Function
//Change the name of the function according to assignment
int ButtonDetectSM(int state) {
	// Get input (HAL)
	
	//Variables
	const unsigned char DETECT = 0x80;
	const unsigned char NODETECT = 0x00;

	//State switches
	//Computation
	switch (state) {
		case ButtonDetectSM_start:
			state = waitPress;
			break;
		case waitPress:
			state = (button_0 == 0x1F &&
					button_1 == 0x1F &&
					button_2 == 0x1F &&
					button_3 == 0x1F &&
					button_4 == 0x1F &&
					button_5 == 0x1F &&
					button_6 == 0x1F &&
					button_7 == 0x1F &&
					button_8 == 0x1F &&
					button_9 == 0x1F &&
					button_A == 0x1F &&
					button_B == 0x1F &&
					button_C == 0x1F &&
					button_D == 0x1F &&
					button_S == 0x1F &&
					button_H == 0x1F) ? waitPress : detect;
			break;
		case detect:
			state = (button_0 == 0x1F &&
					button_1 == 0x1F &&
					button_2 == 0x1F &&
					button_3 == 0x1F &&
					button_4 == 0x1F &&
					button_5 == 0x1F &&
					button_6 == 0x1F &&
					button_7 == 0x1F &&
					button_8 == 0x1F &&
					button_9 == 0x1F &&
					button_A == 0x1F &&
					button_B == 0x1F &&
					button_C == 0x1F &&
					button_D == 0x1F &&
					button_S == 0x1F &&
					button_H == 0x1F) ? waitPress: detect;
			break;
		default:
			state = ButtonDetectSM_start;
			break;
	}
	//Action
	switch (state) {
		case ButtonDetectSM_start:
			state = waitPress;
			break;
		case waitPress:
			buttonDetect = NODETECT;
			break;
		case detect:
			buttonDetect = DETECT;
			break;
	}

	// Output (HAL)
	
	return state;
}
#endif // BUTTONDETECTSM_H
