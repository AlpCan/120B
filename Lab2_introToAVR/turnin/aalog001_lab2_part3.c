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
    DDRA = 0x00; PORTA = 0xFF; 	//Configure port A's 8 pin as inputs
    DDRC = 0xFF; PORTC = 0x00;  //Configure port C's 8 pins as output, initialize to 0
    unsigned char avail = 0x00; //Variable to hold sensor reading from PINA
    unsigned char cntavail = 0x00; //Variable to hold the number of available parking spaces
    unsigned char notAvail = 0x00; // Variable to hold availability
    /* Insert your solution below */
    while (1) {
	// 1) Read input
	avail = PINA & 0x0F; //reading input from PINA to avail variable
	cntavail = 4; //initializing available spaces
	// 2) Perform computation
	// if PA0 = 1 (door open) and PA1 = 0 (sun down), set PB0 = 1 else = 0
	for( int i = 0 ; i < 4 ; ++i) {
		if( ((avail>>i) & 0x01) == 0x01 ) {
			cntavail = cntavail - 1;
		}
	}
	if (cntavail == 0) {
		notAvail = 1;
	} else {
		notAvail = 0;
	}
	// 3) Write output
	PORTC = cntavail + (notAvail << 7);
    }
    return 1;
}
