//Timer definitions
const unsigned long SOUND_PERIOD = 1;

//Enumeration
typedef enum SoundStates {sound_start, wait, low, high} SoundStates;

// Global Varibales
unsigned char pwm = 0;
//unsigned char L = 2;
//unsigned char H = 2;
unsigned char i = 0;
//Tick Function
//Change the name of the function according to assignment
int soundSM(int state) {
	// Get input (HAL)
	//Variables
	//unsigned char switchOn = ~PINA & 0x04;
	const unsigned char LOW = 0x00;
	const unsigned char HIGH = 0x10;
	 
	//State switches
	//Computation
	switch (state) {
		case sound_start:
			state = wait;
			break;
		case wait:
			if (switchOn) {
				i = 0;
				state = low;
			}
			else {
			       	state = wait;
			}
			break;
		case low:
			if (switchOn && i < L) {
				++i;
				state = low;
			}
			else if (switchOn) {
			       	i = 0;
				state = high;
			}
			else {
				state = wait;
			}
			break;
		case high:
			if (switchOn && i < H) {
				++i;
				state = high;
			}
			else if (switchOn) {
				i = 0;
				state = low;
			}
			else {
			       	state = wait;
			}
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
