#ifndef POWERSM_H
#define POWERSM_H
/* #defines */
#define LEVEL0 0
#define LEVEL1 30
#define LEVEL2 45
#define LEVEL3 75
/* Timing */
const unsigned long POWERSM_PERIOD = 300;

/* States */
enum PowerSMStates { PowerSM_start, waitPower, levelOne, levelOneRelease, 
						levelTwo, levelTwoRelease,
						levelThree, levelThreeRelease};

int PowerSM(int state) {
	/* HAL */
	unsigned char level1 = ~PINA & 0x02;
	unsigned char level2 = ~PINA & 0x04;
	unsigned char level3 = ~PINA & 0x08;

	/* Variables */
	static unsigned char dutyCycle = 0;
	/* States */
	/* Computations */
	switch (state) {
		case PowerSM_start:
			state = waitPower;
			break;
		case waitPower:
			state = (reset) ? waitPower : levelOne;
			break;
		case levelOne:
			state = (level1 && !level2 && !level3) ? levelOneRelease : 
				(!level1 && level2 && !level3) ? levelTwoRelease :
				(!level1 && !level2 && level3 ) ? levelThreeRelease :
				(reset) ? waitPower :
				levelOne;			
			break;
		case levelOneRelease:
			state = (reset) ? waitPower :
				(level1 || level2 || level3 ) ? levelOneRelease : 
				levelOne;
			break;	
		case levelTwo:
			state = (level1 && !level2 && !level3) ? levelOneRelease : 
				(!level1 && level2 && !level3) ? levelTwoRelease :
				(!level1 && !level2 && level3 ) ? levelThreeRelease :
				(reset) ? waitPower :
				levelTwo;			
			break;
		case levelTwoRelease:
			state = (reset) ? waitPower :
				(level1 || level2 || level3 ) ? levelTwoRelease : 
				levelTwo;
			break;	
		case levelThree:
			state = (level1 && !level2 && !level3) ? levelOneRelease : 
				(!level1 && level2 && !level3) ? levelTwoRelease :
				(!level1 && !level2 && level3 ) ? levelThreeRelease :
				(reset) ? waitPower :
				levelThree;			
			break;
		case levelThreeRelease:
			state = (reset) ? waitPower :
				(level1 || level2 || level3 ) ? levelThreeRelease : 
				levelThree;
			break;		
		default:
			state = PowerSM_start;
			break;
	}

	switch (state) {
		case PowerSM_start:
			dutyCycle = LEVEL0;
			break;
		case waitPower:
			dutyCycle = LEVEL0;
			break;
		case levelOne:
			dutyCycle = LEVEL1;			
			break;
		case levelOneRelease:
			dutyCycle = LEVEL1;
			break;	
		case levelTwo:
			dutyCycle = LEVEL2;			
			break;
		case levelTwoRelease:
			dutyCycle = LEVEL2;
			break;	
		case levelThree:
			dutyCycle = LEVEL3;			
			break;
		case levelThreeRelease:
			dutyCycle = LEVEL3;
			break;
	}
	/* HAL */
	set_PWM(dutyCycle);

	return state;
}	

#endif // POWERSM_H
