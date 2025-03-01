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

enum States {start, lock, waitUnlock, waitReleaseUnlock, waitReleaseLock, unlock} state;
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
				(buttonHash) ? waitReleaseUnlock :
			       	(buttonIn || buttonX) ? lock : waitUnlock;
			break;
		case waitReleaseUnlock:
			state = (buttonHash) ? waitReleaseUnlock :
				(!buttonHash && !buttonY && !buttonX) ? waitUnlock :
				(!buttonHash && (buttonY || buttonX)) ? waitReleaseLock : lock;
			break;
		case waitReleaseLock:
			state = (buttonY || buttonX) ? waitReleaseLock:
				(!buttonHash && !buttonY && !buttonX) ? lock : lock;
		       break;	
		case unlock:
			state = (buttonIn) ? lock : unlock;
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
		case waitReleaseUnlock:
			break;
		case waitReleaseLock:
			break;
		case unlock:
			bolt = 1;
			break;

	}
	PORTB = bolt;
	PORTC = buttonIn;
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
