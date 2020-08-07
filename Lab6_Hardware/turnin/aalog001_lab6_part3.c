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
#include <math.h>

enum States {start, wait, nextSec, waitRelease} state;
// States are named relative to PB0
void tick (){
	unsigned char button = ~PINA & 0x01;
	static unsigned char counter = 0;
	static unsigned char leds = 0;
	switch(state){
		case start:
			state = wait;
			break;
		case wait:
			state = (button) ? nextSec : wait;
			break;
		case nextSec:
				state = waitRelease;
			break;
		case waitRelease:
			if(button) {
				state = waitRelease;
			} 
			else {
				state = wait;
				++counter;
			}
			break;
		default:
			state = start;
			break;	
	}
	switch(state) {
		case start:
			break;
		case wait:
			if (counter >=12) {
				counter = 0;
			}
			break;
		case nextSec:
			leds = (counter == 0)? leds | 0x01 :
				(counter < 6) ? leds * 2 :
				(counter >= 6 && counter <12) ? leds / 2:
				0x00; 
			break;
		case waitRelease:
			break;
	}
	PORTB = leds;
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
