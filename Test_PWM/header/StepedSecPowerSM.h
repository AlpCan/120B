#ifndef STEPEDPOWERSM_H
#define STEPEDPOWERSM_H
/* #defines */
#define LEVEL0 0
#define STEP 10
#define LOWESTLEVEL 30
#define HIGHESTLEVEL 80
#define WAIT 5
/* Timing */
const unsigned long STEPEDSECPOWERSM_PERIOD = 200;

/* States */
enum StepedSecPowerSMStates { StepedSecPowerSM_start, waitPower, rest, levelUp,waitLevelUp, levelDown, waitLevelDown};

int StepedSecPowerSM(int state) {
	/* HAL */
	unsigned char buttonUp = ~PINA & 0x02;
	unsigned char buttonDown = ~PINA & 0x04;

	/* Variables */
	static unsigned char timer = 0;
	static unsigned char dutyCycle = 0;
	static unsigned char previousDutyCycle = 0;
	/* States */
	/* Computations */
	switch (state) {
		case StepedSecPowerSM_start:
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
			if (buttonUp && !buttonDown) {
				state = waitLevelUp;
			       	timer = 0;
			}
			else if (reset) {
				state = waitPower ;
			}
			else {
				state = rest;
			}			
			break;
		case waitLevelUp:
			state = (reset) ? waitPower :
				(buttonUp && timer < WAIT) ? waitLevelUp : 
				(buttonUp && !(timer < WAIT))? levelUp:
				rest;
			break;
		case levelDown:
			if (!buttonUp && buttonDown) {
				state = waitLevelDown;
			       	timer = 0;
			}
			else if (reset) {
				state = waitPower ;
			}
			else {
				state = rest;
			}			
			break;
		case waitLevelDown:
			state = (reset) ? waitPower:
				(buttonDown && timer < 9) ? waitLevelDown : 
				(buttonDown && !(timer < 9))? levelDown:
				rest;
			break;
		default:
			state = StepedSecPowerSM_start;
			break;
	}

	switch (state) {
		case StepedSecPowerSM_start:
			break;
		case waitPower:
			dutyCycle = LEVEL0;
			break;
		case rest:
			dutyCycle = (previousDutyCycle) ? previousDutyCycle : LOWESTLEVEL;
			break;
		case levelUp:
			if (dutyCycle < HIGHESTLEVEL ) {
				dutyCycle = dutyCycle + STEP;
				previousDutyCycle = dutyCycle;	
			}	
			break;
		case waitLevelUp:
			++timer;
			break;
		case levelDown:
			if ( dutyCycle > LOWESTLEVEL ) {
				dutyCycle = dutyCycle - STEP;
				previousDutyCycle = dutyCycle;
			}
			break;
		case waitLevelDown:
			++timer;
			break;
	}
	/* HAL */
	set_PWM(dutyCycle);

	return state;
}	

#endif // STEPEDPOWERSM_H
