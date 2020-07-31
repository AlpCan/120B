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
	DDRA = 0x00; PORTA = 0xFF; // Set A's pins to input
	DDRB = 0x00; PORTB = 0xFF; // Set B's pins to input
	DDRC = 0xFF; PORTC = 0x00; // Set C's pins to output, initialize to 0
	unsigned char inA = 0x00; // holds the input from PINA
	unsigned char inB = 0x00; // holds the input from PINB
	unsigned char count = 0x00; // Counter for 1's
	/* Insert your solution below */
	while (1) {
		//1) Read in inputs
		inA = PINA;
		inB = PINB;
		count = 0x00;
		//2) logical operations
		if((inA & 0x01) == 0x01) {
			count = count + 1;
		}
		if((inA & 0x02) == 0x02) {
			count = count + 1;
		}
		if((inA & 0x04) == 0x04) {
			count = count + 1;
		}
		if((inA & 0x08) == 0x08) {
			count = count + 1;
		}
		if((inA & 0x10) == 0x10) {
			count = count + 1;
		}
		if((inA & 0x20) == 0x20) {
			count = count + 1;
		}
		if((inA & 0x40) == 0x40) {
			count = count + 1;
		}
		if((inA & 0x80) == 0x80) {
			count = count + 1;
		}
		if((inB & 0x01) == 0x01) {
			count = count + 1;
		}
		if((inB & 0x02) == 0x02) {
			count = count + 1;
		}
		if((inB & 0x04) == 0x04) {
			count = count + 1;
		}
		if((inB & 0x08) == 0x08) {
			count = count + 1;
		}
		if((inB & 0x10) == 0x10) {
			count = count + 1;
		}
		if((inB & 0x20) == 0x20) {
			count = count + 1;
		}
		if((inB & 0x40) == 0x40) {
			count = count + 1;
		}
		if((inB & 0x80) == 0x80) {
			count = count + 1;
		}
		//3) Output
		PORTC = count;		
	}
    	return 1;
}
