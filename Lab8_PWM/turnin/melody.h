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

//Melodies Array
// Friend (toy story)
static unsigned char SIZE1 = 20;
const double melody1 [] = { E, G, E, A, G, 
				E,S,S,
				A,C_5,A,C_5,A,
				G,S,S,
				A,F,G,C,};
const unsigned char times1 [] = { hnote, qnote, qnote, hnote, hnote ,
					hnote, hnote, fnote, 
					hnote, qnote, qnote, hnote, hnote,
					hnote, hnote, fnote, 
					hnote, hnote, hnote, hnote};
//Jingle Bells
const unsigned char SIZE2 = 15;
const double melody2 [] = { E, E, E,
				E, E, E,
				E, G, C_5, D,
				E,
				F,F,F,F};
const unsigned char times2 [] = { hnote, hnote, fnote,
					hnote, hnote, fnote,
					hnote, hnote, hnote, hnote,
					dnote,
					hnote, hnote, hnote, hnote};
//Twinkle twinkle
const unsigned char SIZE3 = 18;
const double melody3 [] = { C, C, G, G,
				A, A, G,
				F, F, E, E,
				D, D, C,
				G, G, F, F};
const unsigned char times3[] = { hnote, hnote, hnote, hnote,
				hnote, hnote, fnote,
				hnote, hnote, hnote, hnote,
				hnote, hnote, fnote,
				hnote, hnote, hnote};


//Enumeration
typedef enum MelodyStates {init ,wait, 
				mOneNote, keepNote, notePause,
				mTwoNote, keepTwoNote, noteTwoPause,
				mThreeNote, keepThreeNote, noteThreePause,
				waitRelease} MelodyStates;

//Global Result
double frequency = 0;

//Tick Function
//Change the name of the function according to assignment
int melodyTick(int state) {
	// Get input (HAL)
	unsigned char buttonMelOne = ~PINA & 0x01;
	unsigned char buttonMelTwo = ~PINA & 0x02;
	unsigned char buttonMelThree = ~PINA & 0x04;
	//Variables
	
	static unsigned char i = 0;
	static unsigned char j = 0;
	//State switches
	//Computation
	switch (state) {
		case init:
			state = wait;
			set_PWM(0);
			break;
		case wait:
			if(buttonMelOne) {
				state = mOneNote;				
			}
			else if (buttonMelTwo) {
				state = mTwoNote;
			}
			else if (buttonMelThree) {
				state = mThreeNote;
			}
			else {
				state = wait;
			}		
			break;
		case mOneNote:
			if(i>=SIZE1 && buttonMelOne) {
				state = waitRelease;
			}
			else if (i >=SIZE1) {
				state = wait;
			}
			else {
				state = keepNote;
				j = 0;
			}
			break;
		case keepNote:
			if ( j < times1[i]) {
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
				state = mOneNote;
			}
			break;
		case mTwoNote:
			if(i>=SIZE2 && buttonMelTwo) {
				state = waitRelease;
			}
			else if (i >=SIZE2) {
				state = wait;
			}
			else {
				state = keepTwoNote;
				j = 0;
			}
			break;
		case keepTwoNote:
			if ( j < times2[i]) {
				state = keepTwoNote;
			}
			else {
				state = noteTwoPause;
				j = 0;
			}
			break;
		case noteTwoPause:
			if(j<pause ) {
				state = noteTwoPause;
			}
			else {
				state = mTwoNote;
			}
			break;
		case mThreeNote:
			if(i>=SIZE3 && buttonMelThree) {
				state = waitRelease;
			}
			else if (i >=SIZE3) {
				state = wait;
			}
			else {
				state = keepThreeNote;
				j = 0;
			}
			break;
		case keepThreeNote:
			if ( j < times3[i]) {
				state = keepThreeNote;
			}
			else {
				state = noteThreePause;
				j = 0;
			}
			break;
		case noteThreePause:
			if(j<pause ) {
				state = noteThreePause;
			}
			else {
				state = mThreeNote;
			}
			break;
		case waitRelease:
			state = (buttonMelOne || buttonMelTwo || buttonMelThree) 
				? waitRelease : wait;
			break;
		default:
			state = init;
			break;

	}
	//Action
	switch (state) {
		case init:
			state = wait;
			break;
		case wait:
			frequency = 0;
			i = 0;	
			break;
		case mOneNote:
			frequency = melody1[i];
			break;
		case keepNote:
			++j;
			break;
		case notePause:
			frequency = 0;
			++j;
			++i;
			break;
		case mTwoNote:
			frequency = melody2[i];
			break;
		case keepTwoNote:
			++j;
			break;
		case noteTwoPause:
			frequency = 0;
			++j;
			++i;
			break;
		case mThreeNote:
			frequency = melody3[i];
			break;
		case keepThreeNote:
			++j;
			break;
		case noteThreePause:
			frequency = 0;
			++j;
			++i;
			break;
		case waitRelease:
			frequency = 0;
			break;
	}

	// Output (HAL)
	

	return state;
}
