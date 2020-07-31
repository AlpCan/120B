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
	DDRA = 0x00; PORTA = 0xFF; // Set A's pins to output
	DDRB = 0xFF; PORTB = 0x00; // Set B's pins to input, initialize to 0
	DDRC = 0xFF; PORTC = 0x00; // Set C's pins to input, initialize to 0
	unsigned char upperNib = 0x00;
	unsigned char lowerNib = 0x00;
		/* Insert your solution below */
	while (1) {
		//1) Read in inputs
		upperNib = PINA & 0xF0;
		lowerNib = PINA & 0x0F;
		//2) logical operations
		upperNib = upperNib >> 4;
		lowerNib = lowerNib << 4;
		//3) Output
		PORTB = upperNib;
		PORTC = lowerNib;		
	}
    	return 1;
}
