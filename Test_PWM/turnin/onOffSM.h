/* #defines */
#define ON 50
#define OFF 0

/* Timing */
const unsigned long ONOFFSM_PERIOD = 200;

/* States */
enum onOffSMStates { onOffSM_start, off, waitReleaseOn, on, waitReleaseOff};

int onOffSM(int state) {
	/* HAL */
	unsigned char button = ~PINA & 0x01;

	/* Variables */
	static unsigned char dutyCycle = 0;
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
			dutyCycle = OFF;
			break;
		case off:
			dutyCycle = OFF;
			break;
		case waitReleaseOn:
			dutyCycle = ON;
			break;
		case on:
			dutyCycle = ON;
			break;
		case waitReleaseOff:
			dutyCycle = OFF;
			break;
	}
	/* HAL */

	set_PWM(dutyCycle);

	return state;
}	
