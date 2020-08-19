//Timer definitions
const unsigned long INPUT_PERIOD = 1;

//Enumeration
typedef enum InputStates {input_start, input_wait, buttonUpP, buttonUpR, buttonDownP, buttonDownR} InputStates;
// P: press
// R: release

// Global Varibales
unsigned char switchOn = 0;
unsigned char L = 1;
unsigned char H = 1;
//Tick Function
//Change the name of the function according to assignment
int InputProcessSM(int state) {
	// Get input (HAL)
	switchOn = ~PINA & 0x04;
	unsigned char buttonUp = ~PINA & 0x01;
	unsigned char buttonDown = ~PINA & 0x02;
	//Variables
	
	//State switches
	//Computation
	switch (state) {
		case input_start:
			state = input_wait;
			break;
		case input_wait:
			state = (buttonUp && !buttonDown)? buttonUpP :
				(!buttonUp && buttonDown)? buttonDownP :
				input_wait;
			break;
		case buttonUpP:
			state = (buttonUp) ? buttonUpR : input_wait;
			break;
		case buttonUpR:
			state = (buttonUp) ? buttonUpR : input_wait;
			break;
		case buttonDownP:
			state = (buttonDown) ? buttonDownR : input_wait;
			break;
		case buttonDownR:
			state = (buttonDown) ? buttonDownR : input_wait;
			break;
		default:
			state = input_start;
			break;
	}
	//Action
	switch (state) {
		case input_start:
			break;
		case input_wait:
			break;
		case buttonUpP:
			++H;
			++L;
			break;
		case buttonUpR:
			break;
		case buttonDownP:
			if (H>1 && L >1) {
				--H;
				--L;
			}
			break;
		case buttonDownR:
			break;
	}

	// Output (HAL)
	return state;
}
