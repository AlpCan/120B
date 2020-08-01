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

enum States {start, lock, waitUnlock, unlock, waitLock} state;
// States are named relative to PB0
void tick (){
	unsigned char buttonX = PINA & 0x01;
	unsigned char buttonY = ( PINA & 0x02 );
	unsigned char buttonHash = (PINA & 0x04);
	unsigned char buttonIn = (PINA & 0x80);
	static unsigned char bolt = 0;
	switch(state){
		case start:
			state = lock;
			break;
		case lock:
			state = (buttonHash) ? waitUnlock : lock;
			break;
		case waitUnlock:
			state = (buttonY) ? unlock :
				(buttonHash) ? waitUnlock :
			        (buttonX || buttonIn ) ? lock : waitUnlock;
			break;
		case unlock:
			state = (buttonIn) ? lock :
			       	(buttonHash) ? waitLock : unlock;
			break;
		case waitLock:
			state = (buttonY) ? lock :
				(buttonHash) ? waitLock :
			        (buttonX) ? unlock :
				(buttonIn) ? lock : waitLock;
			break;
		default:
			state = start;
			break;	
	}
	switch(state) {
		case start:
			break;
		case lock:
			bolt = 0;
			break;
		case waitUnlock:
			break;
		case unlock:
			bolt = 1;
			break;
		case waitLock:
			break;

	}
	PORTB = bolt;
	PORTC = buttonX;
}
int main(void) {
	/* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0xFF; PORTC = 0x00;

	state = start;
	/* Insert your solution below */
	while (1) {
		tick();
	}
	return 1;
}
