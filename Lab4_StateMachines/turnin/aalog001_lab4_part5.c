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

enum States {start, lock, waitUnlock, waitReleaseUnlock , unlock, waitLock, waitReleaseLock} state;
// States are named relative to PB0
void tick (){
	unsigned char buttonX = PINA & 0x01;
	unsigned char buttonY = ( PINA & 0x02 );
	unsigned char buttonHash = (PINA & 0x04);
	unsigned char buttonIn = (PINA & 0x80);
	static unsigned char bolt = 0;
	static unsigned char countPass = 0;
	const unsigned char password[3] = {0x01,0x02,0x01};
	switch(state){
		case start:
			state = lock;
			break;
		case lock:
			state = (buttonHash) ? waitUnlock : lock;
			break;
		case waitUnlock:
			if ( buttonIn ) {
				state = lock;
			}
			else if (buttonY) {
				if(countPass<3) {
					if(password[countPass] == buttonY) {
					        if(countPass == 2){
							state = unlock;
						} 
						else {
							state = waitReleaseUnlock;
						}
						countPass = countPass + 1;
					}
			 		else {
						state = lock;
					}		
				}
				else {
					state = lock;
				}
			}
			else if(buttonX) {
				if(countPass<3) {
					if(password[countPass] == buttonX) {
					        if(countPass == 2){
							state = unlock;
						} 
						else {
							state = waitReleaseUnlock;
						}
						countPass = countPass + 1;
					}
			 		else {
						state = lock;
					}		
				}
				else {
					state = lock;
				}
	
			} 
			else if (buttonHash) {
				state = waitReleaseUnlock;
			}
			else {
				state = waitUnlock;
			}
	 		break;
		case waitReleaseUnlock:
			if (!buttonY && !buttonX && !buttonHash ) {
				state = waitUnlock;
			}
			break;	
		case unlock:
			state = (buttonIn) ? lock :
			       	(buttonHash) ? waitLock : unlock;
			break;
		case waitLock:
			if ( buttonIn ) {
				state = lock;
			}
			else if (buttonY) {
				if(countPass<3) {
					if(password[countPass] == buttonY) {
					        if(countPass == 2){
							state = lock;
						} 
						else {
							state = waitReleaseLock;
						}
						countPass = countPass + 1;
					}
			 		else {
						state = unlock;
					}		
				}
				else {
					state = unlock;
				}
			}
			else if(buttonX) {
				if(countPass<3) {
					if(password[countPass] == buttonX) {
					        if(countPass == 2){
							state = lock;
						} 
						else {
							state = waitReleaseLock;
						}
						countPass = countPass + 1;				
					}
			 		else {
						state = unlock;
					}		
				}
				else {
					state = unlock;
				}
	
			} 
			else if (buttonHash) {
				state = waitReleaseLock;
			}
			else {
				state = waitLock;
			}
			break;
		case waitReleaseLock:
			if (!buttonY && !buttonX && !buttonHash ) {
				state = waitLock;
			}
			break;
		default:
			state = start;
			break;	
	}
	switch(state) {
		case start:
			break;
		case lock:
			//countPass = 0;
			bolt = 0;
			break;
		case waitUnlock:
			break;
		case waitReleaseUnlock:
			break;
		case unlock:
			countPass = 0;
			bolt = 1;
			break;
		case waitLock:
			break;
		case waitReleaseLock:
			break;

	}
	PORTB = bolt;
	PORTC = countPass;
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
