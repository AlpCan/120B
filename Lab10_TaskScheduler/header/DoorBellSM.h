//#defines 
//Notes
#define C 261.63
#define D 293.66
#define E 329.63
#define F 349.23
#define G 392.00
#define A 440.00
#define B 493.88
#define C_5 523.25
#define S 0

//Time defines
#define dnote 79
#define hnote 19
#define fnote 39
#define qnote 9
#define pause 1
//Timing
const unsigned long DOORBELLSM_PERIOD =25;
//Melodies Array
// Friend (toy story)
//Jingle Bells
const unsigned char TONE_SIZE = 10;
const double bellTone [] = { E, E, E,
				E, E, E,
				E, G, C, D};
const unsigned char times[] = { hnote, hnote, fnote,
					hnote, hnote, fnote,
					hnote, hnote, hnote, hnote};
//Enumeration
typedef enum MelodyStates {DoorBellSM_start ,waitTone , 
				doorBellRing, keepNote, notePause,
				waitRelease} MelodyState;

//Global Result
double frequency = 0;

//Tick Function
//Change the name of the function according to assignment
int DoorBellSM(int state) {
	// Get input (HAL)
	//unsigned char buttonDoorBell = ~PINA & 0x01;
	//Variables
	
	static unsigned char i = 0;
	static unsigned char j = 0;
	//State switches
	//Computation
	switch (state) {
		case DoorBellSM_start:
			state = waitTone;
			set_PWM(0);
			break;
		case waitTone:
			state = (buttonDoorBell) ? doorBellRing : waitTone; 
			break;
		case doorBellRing:
			if(i>=TONE_SIZE && buttonDoorBell) {
				state = waitRelease;
			}
			else if (i >=TONE_SIZE) {
				state = waitTone;
			}
			else {
				state = keepNote;
				j = 0;
			}
			break;
		case keepNote:
			if ( j < times[i]) {
				state = keepNote;
			}
			else {
				state = notePause;
				j = 0;
			}
			break;
		case notePause:
			if ( j < pause ) {
				state = pause;
			}
			else {
				state = doorBellRing;
			}
			break;
		case waitRelease:
			state = (buttonDoorBell) 
				? waitRelease : waitTone;
			break;
		default:
			state = DoorBellSM_start;
			break;

	}
	//Action
	switch (state) {
		case DoorBellSM_start:
			state = waitTone;
			break;
		case waitTone:
			frequency = 0;
			i = 0;	
			break;
		case doorBellRing:
			frequency = bellTone[i];
			break;
		case keepNote:
			++j;
			break;
		case notePause:
			frequency = 0;
			++j;
			++i;
			break;
		case waitRelease:
			frequency = 0;
			break;
	}

	// Output (HAL)
	set_PWM(frequency);

	return state;
}
