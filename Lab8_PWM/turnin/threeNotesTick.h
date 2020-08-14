//#defines 
#define C 261.63
#define D 293.66
#define E 329.63

//Timing

//Enumeration
typedef enum States {start, wait, noteC, noteD, noteE } NoteStates;



//Tick Function
//Change the name of the function according to assignment
int threeNotesTick(int state) {
	// Get input (HAL)
	unsigned char buttonC = ~PINA & 0x01;
	unsigned char buttonD = ~PINA & 0x02;
	unsigned char buttonE = ~PINA & 0x04;
	double frequency = 0;
	//Variables
	

	//State switches
	//Computation
	switch (state) {
		case start:
			state = wait;
			break;
		case wait:
			if ( buttonC && !buttonD && !buttonE) {
				state = noteC;
			}
			else if ( !buttonC && buttonD && !buttonE) {
				state = noteD;
			}
			else if ( !buttonC && !buttonD && buttonE) {
				state = noteE;
			}
			else {
				state = wait;
			}
			break;
		case noteC:
			if ( buttonC && !buttonD && !buttonE) {
				state = noteC;
			} 
			else {
				state = wait;
			}
			break;
		case noteD:
			if ( !buttonC && buttonD && !buttonE) {
				state = noteD;
			} 
			else {
				state = wait;
			}
			break;
		case noteE:
			if ( !buttonC && !buttonD && buttonE) {
				state = noteE;
			} 
			else {
				state = wait;
			}
			break;
		default:
			state = start;
			break;

	}
	//Action
	switch (state) {
		case start:
			break;
		case wait:
			frequency = 0;
			break;
		case noteC:
			frequency = C;
			break;
		case noteD:
			frequency = D;
			break;
		case noteE:
			frequency = E;
			break;
	}

	// Output (HAL)
	set_PWM(frequency);
	return state;
}
