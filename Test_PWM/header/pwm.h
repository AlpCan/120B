
// 0.954 hz is lowest frequency with this function,
// based on settings in PWM_on()
// Passing in 0 as frequency will stop the speaker from generating sound
void set_PWM(double dutyCycle) {
	static double current_dutyCycle; // Keeps track of the current set frequency
	// Will only update the registers when the frequency changes, otherwise allows
	// music to play uninterrupted.
	if (dutyCycle != current_dutyCycle) {
		if (!dutyCycle) { TCCR0B &= 0x08; } // stops timer/counter
		else { TCCR0B |= 0x03; } // resumes/continues timer/counter

		// prevents OCR3A from overflowing, using prescaler 64
		// 0.954 is smallest frequency that will not result in overflow
		if (dutyCycle < 0) { OCR0A = 0x00; }

		// prevents OCR3A from underflowing, using prescaler 64
		// 31250 is largest frequency that will not result in underflow
		else if (dutyCycle > 100) { OCR0A = 0xFF; }

		// set OCR3A based on desired frequency
		else { OCR0A = (char)((0xFF/100) * dutyCycle); }

		TCNT0 = 0; // resets counter
		current_dutyCycle = dutyCycle; // Update the current frequency
	}
}

void PWM_on() {
	TCCR0A = (1 << COM0A1) | (1 << WGM00);
		// COM3A0: Toggle PB# on compare match between counter and OCR3A:
	TCCR0B =(1 << CS01) | (1 << CS00);
		// WGM32: When counter (TCNT3) matches OCR3A, reset counter
		// CS31 & CS30: Set prescaler of 1024
	set_PWM(0);
}

void PWM_off() {
	TCCR0A = 0x00;
	TCCR0B = 0x00;
}
