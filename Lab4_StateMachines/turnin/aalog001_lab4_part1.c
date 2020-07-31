/*	Author: lab
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum States {start, buttonReleaseOff, buttonPressOn, buttonReleaseOn, buttonPressOff } state;
// States are named relative to PB0
void tick (){
	unsigned char button = PINA & 0x01;
	static unsigned char led_one =0;
	static unsigned char led_zero = 0;
	switch(state){
		
		case start:
			state = buttonReleaseOff;
			break;
		case buttonReleaseOff:
			state = (button) ? buttonPressOn : buttonReleaseOff;
			break;
		case buttonPressOn:
			state = (button) ? buttonPressOn : buttonReleaseOn;
			break;
		case buttonReleaseOn:
			state = (button) ? buttonPressOff : buttonReleaseOn;
			break;	
		case buttonPressOff:
			state = (button) ? buttonPressOff : buttonReleaseOff;
			break;
		default:
			state = start;
			break;	
	}
	switch(state) {
		case start:
			break;
		case buttonReleaseOff:
			led_zero = 1;
			led_one = 0;
			break;
		case buttonPressOn:
			led_zero = 0;
			led_one = 1;
			break;
		case buttonReleaseOn:
			break;
		case buttonPressOff:
			led_zero = 1;
			led_one = 0;
			break;

	}
	PORTB = led_zero | (led_one << 1);
}
int main(void) {
	/* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;

	state = start;
	/* Insert your solution below */
	while (1) {
		tick();
	}
	return 1;
}
