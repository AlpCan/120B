#include <avr/io.h>
#include "timer.h" // assume all timer functions are defined in here (same one provided to you)

// make a global variable 'state' that will hold the state of the sm
enum States { start, wait, first_press, valid, long_press} state;

// Complete the following tick function
void tick() {
	unsigned char button = ~PINA & 0x01;

	unsigned char light = 0;
	static unsigned char i = 0;
	switch(state) {
		case start:
			state = wait;
			break;
		case wait:
			state = (button) ? first_press : wait;
			break;
		case first_press:
			state = (button) ? valid : wait;
			break;
		case valid:
			state = (i < 16) ? valid :
				(button && !(i<16)) ? long_press :
				wait;
			break;
		case long_press:
			state = (button) ? long_press : wait;
			break;
		default:
			state = start;
			break;

	}
	switch(state) {
		case start:
			break;
		case wait:
			light = 0;
			break;
		case first_press:
			i = 0;
			light = 0;
			break;
		case valid:
			++i;
			light = 1;
			break;
		case long_press:
			light = 0;
			break;
	}
	PORTB = light;
}

// Complete the main function
int main() {
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	
	
	const unsigned long PERIOD  = 125;

	TimerSet(PERIOD);
	TimerOn();
    	while (1) {
		tick();
		while(!TimerFlag);
		TimerFlag = 0;
    	}
}
