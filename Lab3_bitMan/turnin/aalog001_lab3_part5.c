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

int main(void) {
	/* Insert DDR and PORT initializations */
	DDRB = 0xFE; PORTB = 0x01; // Set B's 1st pin to input, rest to output initialize to 0
	DDRD = 0x00; PORTD = 0xFF; // Set D's pins to input, initialize to 0
	unsigned short weight = 0x00;
	unsigned char sensOut = 0x00; // sensor output
		/* Insert your solution below */
	while (1) {
		//1) Read in inputs
		weight = PIND;
		weight = (weight << 1) | (PINB & 0x01);
		//2) logical operations
		if( weight <= 5 ) {
			sensOut = 0x00;
		} 
		else if (weight <70) {
			sensOut = 0x04;
		} 
		else {
			sensOut = 0x02;
		}	
		//3) Output
		PORTB = sensOut;		
	}
    	return 1;
}
