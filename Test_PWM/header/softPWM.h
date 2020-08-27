const unsigned long PWM_PERIOD = 4;

unsigned char pwm;

enum PwmStates { PWM_start, LOW, HIGH};

int softPWM (int state) {
	static char H =2;
	static char L =2;
	static unsigned char i = 0;

	switch (state) {
		case PWM_start:
			state = LOW;
			break;
		case LOW:
			if ( i < L ) {
				state = LOW;
			}
			else { 
				state = HIGH;
				i = 0;
			}
			break;
		case HIGH:
			if ( i < H ) {
				state = HIGH;
			}
			else { 
				state = LOW;
				i = 0;
			}
			break;
		default:
			state = PWM_start;
			break;
	}

	switch (state) {
		case PWM_start:
			break;
		case LOW:
			 ++i;
 			pwm = 0;
			break;
		case HIGH:
			++i;
			pwm = 1;
			break;
	}

	return state;
}	
