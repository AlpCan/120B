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

enum States {start, rest, increment, incWait, decrement, decWait, reset} state;
// States are named relative to PB0
void tick (){
	unsigned char button1 = PINA & 0x01;
	unsigned char button2 = ( PINA & 0x02 ) >> 1;
	static unsigned char counter = 7;
	switch(state){
		case start:
			state = rest;
			break;
		case rest:
			state = ( !button1 && !button2 ) ? rest : 
				( button1 && !button2 ) ? increment:
				( !button1 && button2 ) ? decrement:
				( button1 && button2 ) ? reset : start;
			break;
		case increment:
			state = incWait;
			break;
		case incWait:
			state = ( !button1 && !button2 ) ? rest : 
				( button1 && !button2 ) ? incWait:
				( !button1 && button2 ) ? decrement:
				( button1 && button2 ) ? reset : start;
			break;	
		case decrement:
			state = decWait;
			break;
		case decWait:
			state = ( !button1 && !button2 ) ? rest : 
				( button1 && !button2 ) ? increment:
				( !button1 && button2 ) ? decWait:
				( button1 && button2 ) ? reset : start;
			break;
		case reset:
			state = ( !button1 && !button2 ) ? rest : 
				( button1 && !button2 ) ? increment:
				( !button1 && button2 ) ? decrement:
				( button1 && button2 ) ? reset : start;
			break;
		default:
			state = start;
			break;	
	}
	switch(state) {
		case start:
			break;
		case rest:
			break;
		case increment:
			if (counter < 9) {
			       counter = counter + 1;
			}
			break;
		case incWait:
			break;
		case decrement:
			if (counter > 0) {
				counter = counter - 1;
			}
			break;
		case decWait:
			break;
		case reset:
			counter = 7;
			break;
	}
	PORTC = counter;
}
int main(void) {
	/* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;

	state = start;
	/* Insert your solution below */
	while (1) {
		tick();
	}
	return 1;
}
