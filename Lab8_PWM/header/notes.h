//#defines 
#define C 261.63
#define D 293.66
#define E 329.63
#define F 349.23
#define G 392.00
#define A 440.00
#define B 493.88
#define C_5 523.25
//Timing

//Enumeration
typedef enum NoteStates {init ,wait, nextNote, preNote, waitRelease } NoteStates;

//Global Result
double frequency = 0;

//NoteArray
const double note [] = { C, D, E, F, G, A, B , C_5 };
const unsigned char SIZE = 8;
//Tick Function
//Change the name of the function according to assignment
int notesTick(int state) {
	// Get input (HAL)
	unsigned char buttonUp = ~PINA & 0x02;
	unsigned char buttonDown = ~PINA & 0x04;
	//Variables
	static unsigned char i = 0;

	//State switches
	//Computation
	switch (state) {
		case init:
			state = wait;
			frequency = note[i];
			break;
		case wait:
			state = (buttonUp && !buttonDown) ? nextNote:
				(!buttonUp && buttonDown) ? preNote:
				wait;			
			break;
		case nextNote:
			state = waitRelease;
			break;
		case preNote:
			state = waitRelease;
			break;
		case waitRelease:
			state = (buttonUp || buttonDown) ? waitRelease : wait;
			break;
		default:
			state = start;
			break;

	}
	//Action
	switch (state) {
		case init:
			break;
		case wait:
			break;
		case nextNote:
			if ( i < 7 ) {
				++i;
			}
			frequency = note[i];
			break;
		case preNote:
			if ( i > 0 ) {
				--i;
			}
			frequency = note[i];
			break;
		case waitRelease:
			break;
	}

	// Output (HAL)
	return state;
}
