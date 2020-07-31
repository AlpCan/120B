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
	DDRC = 0xFF; PORTC = 0x00; // Set C's pins to input, initialize to 0
	unsigned char fuelLvl = 0x00; // holds the fuel level read from PINA
	unsigned char leds = 0x00; // varaibale to hold led output
	/* Insert your solution below */
	while (1) {
		//1) Read in inputs
		fuelLvl = PINA & 0x0F;
		//2) logical operations
		switch(fuelLvl) {
		case 0:
			leds = 0x40;
			break;
		case 1:
		case 2:
			leds = 0x60;
			break;
		case 3:
		case 4:
			leds = 0x70;
			break;
		case 5:
		case 6:
			leds = 0x38;
			break;
		case 7:
		case 8:
		case 9:
			leds = 0x3C;
			break;
		case 10:
		case 11:
		case 12:
			leds = 0x3E;
			break;
		case 13:
		case 14:
		case 15:
			leds = 0x3F;
			break;
		default:
			leds = 0xFF; // Error
			break;
		}
		//3) Output
		PORTC = leds;		
	}
    	return 1;
}
