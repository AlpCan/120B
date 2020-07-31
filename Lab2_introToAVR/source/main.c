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
    DDRA = 0x00; PORTA = 0xFF; 	//Configure port A's 8 pins as inputs
    DDRB = 0x00; PORTB = 0xFF; 	//Configure port B's 8 pins as inputs
    DDRC = 0x00; PORTC = 0xFF;  //Configure port C's 8 pins as inputs
    DDRD = 0xFF; PORTD = 0x00;  //Configure port D's 8 pins as output, initialized to 0
    unsigned char seatA = 0x00; //Variable to hold weight sensor reading from PINA   
    unsigned char seatB = 0x00; //Variable to hold weight sensor reading from PINB
    unsigned char seatC = 0x00; //Variable to hold weight sensor reading from PINC
    unsigned char tWeight = 140; // Variable to hold totalWeight
    unsigned char bLimit = 80; //Variable to hold valance limit
    unsigned char result = 0x00; //varibale to hold output
    unsigned char tempT = 0;
    /* Insert your solution below */
    while (1) {
	// 1) Read input
	seatA = PINA;
	seatB = PINB;
	seatC = PINC;
	result = 0;
	tempT = seatA + seatB + seatC;
	// 2) Perform computation
	// if PINA + PINB + PINC > total wight limit, set PD0 = 1 else = 0
	if( (tempT) > tWeight ) {
		result = result | 0x01;
	} 
	else {
		result = result | 0x00;
	}
	// if  -80 <= PINA - PINC <= 80 , set PD1 = 0 , else = 1
	if ((seatA - seatC) > bLimit || (seatA - seatC) < -bLimit) {
		result = result | (0x01 << 1 );
	}
	// PINA + PINB + PINC shifted right 2 and assing to result
	result = result | (((tempT) >>2) & 0xFC);
	// 3) Write output
	PORTD = result;
    }
    return 1;
}
