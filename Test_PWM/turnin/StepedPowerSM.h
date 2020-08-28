#ifndef STEPEDPOWERSM_H
#define STEPEDPOWERSM_H
/* #defines */
#define LEVEL0 0
#define LEVELSTART 30
#define STEP 10
#define LOWESTLEVEL 30
#define HIGHESTLEVEL 80

/* Timing */
const unsigned long STEPEDPOWERSM_PERIOD = 250;

/* States */
enum StepedPowerSMStates { StepedPowerSM_start, waitPower, rest, levelUp,waitLevelUp, levelDown, waitLevelDown};

int StepedPowerSM(int state) {
	/* HAL */
	unsigned char buttonUp = ~PINA & 0x02;
	unsigned char buttonDown = ~PINA & 0x04;

	/* Variables */
	static unsigned char dutyCycle = 0;
	static unsigned char previousDutyCycle = 0;
	/* States */
	/* Computations */
	switch (state) {
		case StepedPowerSM_start:
			state = waitPower;
			break;
		case waitPower:
			state = (reset) ? waitPower : rest;
			break;
		case rest:
			state = (buttonUp && !buttonDown) ? levelUp : 
				(!buttonUp && buttonDown) ? levelDown :
			       	(reset) ? waitPower :
				rest;	
			break;
		case levelUp:
			state =  (buttonUp && !buttonDown) ? waitLevelUp : 
			       	(reset) ? waitPower :
				rest;			
			break;
		case waitLevelUp:
			state = (buttonUp) ? waitLevelUp : rest;
			break;
		case levelDown:
			state =  (!buttonUp && buttonDown) ? waitLevelDown : 
			       	(reset) ? waitPower :
				rest;			
			break;
		case waitLevelDown:
			state = (buttonDown) ? waitLevelDown : rest;
			break;
		default:
			state = StepedPowerSM_start;
			break;
	}

	switch (state) {
		case StepedPowerSM_start:
			break;
		case waitPower:
			dutyCycle = LEVEL0;
			break;
		case rest:
			dutyCycle = (previousDutyCycle) ? previousDutyCycle : LEVELSTART;
			break;
		case levelUp:
			if (dutyCycle < HIGHESTLEVEL ) {
				dutyCycle = dutyCycle + STEP;
				previousDutyCycle = dutyCycle;	
			}	
			break;
		case waitLevelUp:
			break;
		case levelDown:
			if ( dutyCycle > LOWESTLEVEL ) {
				dutyCycle = dutyCycle - STEP;
				previousDutyCycle = dutyCycle;
			}
			break;
		case waitLevelDown:
			break;
	}
	/* HAL */
	set_PWM(dutyCycle);

	return state;
}	

#endif // STEPEDPOWERSM_H
