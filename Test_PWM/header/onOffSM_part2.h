#ifndef ONOFFSM_PART2_H
#define ONOFFSM_PART2_H
/* #defines */

/* Timing */
const unsigned long ONOFFSM_PERIOD = 200;

/* States */
enum onOffSMStates { onOffSM_start, off, waitReleaseOn, on, waitReleaseOff};

/* Global Variables */
unsigned char reset;

int onOffSM(int state) {
	/* HAL */
	unsigned char button = ~PINA & 0x01;

	/* Variables */
	const unsigned char ON = 1;
	const unsigned char OFF = 0;
	/* States */
	/* Computations */
	switch (state) {
		case onOffSM_start:
			state = off;
			break;
		case off:
			state = (button) ? waitReleaseOn : off;
			break;
		case waitReleaseOn:
			state = (button) ? waitReleaseOn : on;
			break;
		case on:
			state = (button) ? waitReleaseOff : on;
			break;
		case waitReleaseOff:
			state = (button) ? waitReleaseOff : off;
			break;		
		default:
			state = onOffSM_start;
			break;
	}

	switch (state) {
		case onOffSM_start:
			reset = ON;
			break;
		case off:
			reset = ON;
			break;
		case waitReleaseOn:
			reset = OFF;
			break;
		case on:
			reset = OFF;
			break;
		case waitReleaseOff:
			reset = ON;
			break;
	}
	/* HAL */

	return state;
}	

#endif // ONOFFSM_PART2_H
