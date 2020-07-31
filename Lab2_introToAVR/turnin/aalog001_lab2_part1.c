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
    DDRB = 0xFF; PORTB = 0x00;  //Configure port B's 8 pins as output, initialize to 0
    unsigned char led = 0x00; //Variable to hold led state
    unsigned char sun = 0x00; //Variable to hold sensor reading from PA1
    unsigned char door = 0x00; //Variable to hold door sensor reading from PA0
    /* Insert your solution below */
    while (1) {
	// 1) Read input
	sun = (PINA & 0x02) >> 1; //reading input from PA1 to sun variable
	door = (PINA & 0x01); //reading input from PA0 to door variable
	// 2) Perform computation
	// if PA0 = 1 (door open) and PA1 = 0 (sun down), set PB0 = 1 else = 0
	led =  ( !sun & door ) ? 0x01 : 0x00;
	// 3) Write output
	PORTB = led;
    }
    return 1;
}
