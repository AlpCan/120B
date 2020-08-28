/* Phase Corrected PWM */
// Runing duty cycle is between [0,100],
// passing 0 will set OCR0A to 0, which makes pwm output LOW,
// passing 100 will set OCR0A to 255, which makes pwm output HIGH,
// passing anything in between sets OCR0A according to duty cycle.
void set_PWM(double dutyCycle) {
	static double current_dutyCycle; // Keeps track of the current set duty cycle
	// Will only update the registers when the duty cyle changes, otherwise allows
	// pwm output with current duty cycle.
	if (dutyCycle != current_dutyCycle) {
		//if (!dutyCycle) { TCCR0B &= 0x08; } // stops timer/counter
		//else { TCCR0B |= 0x03; } // resumes/continues timer/counter

		// 0 is the smallest duty cycle that will not result in underflow
		if (dutyCycle < 0) { OCR0A = 0x00; }

		// 0 is largest duty cycle that will not result in overflow
		else if (dutyCycle > 100) { OCR0A = 0xFF; }

		// set OCR3A based on desired duty cycle
		else { OCR0A = (char)((0xFF/100) * dutyCycle); }

		TCNT0 = 0; // resets counter
		current_dutyCycle = dutyCycle; // Update the current duty cycle
	}
}

void PWM_on() {
	TCCR0A = (1 << COM0A1) | (1 << WGM00);
		// COM0A1: Toggle PB# on compare match between counter and OCR0A
		// WFM00: When counter (TCNT0) matches OCR0A, toggles OC0 counter continues untill TOP
	TCCR0B =(1 << CS01) | (1 << CS00);
		// CS31 & CS30: Set prescaler of 64, this sets up the runing frecuency
	set_PWM(0);
}

void PWM_off() {
	TCCR0A = 0x00;
	TCCR0B = 0x00;
}
