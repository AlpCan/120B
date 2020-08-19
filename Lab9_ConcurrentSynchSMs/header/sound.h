//Timer definitions
const unsigned long SOUND_PERIOD = 2;

//Enumeration
typedef enum SoundStates {sound_start, wait, low, high} SoundStates;

// Global Varibales
unsigned char pwm = 0;
//Tick Function
//Change the name of the function according to assignment
int soundSM(int state) {
	// Get input (HAL)
	unsigned char switchOn = ~PINA & 0x04;
	//Variables
	const unsigned char LOW = 0x00;
	const unsigned char HIGH = 0x10;
	//State switches
	//Computation
	switch (state) {
		case sound_start:
			state = wait;
			break;
		case wait:
			state = (switchOn) ? low : wait;
		case low:
			state = (switchOn) ? high : wait;
			break;
		case high:
			state = (switchOn) ? low : wait;
			break;
		default:
			state = sound_start;
			break;
	}
	//Action
	switch (state) {
		case sound_start:
			break;
		case wait:
			pwm = LOW;
			break;
		case low:
			pwm = LOW;
			break;
		case high:
			pwm = HIGH;
			break;
	}
	// Output (HAL)
	return state;
}
