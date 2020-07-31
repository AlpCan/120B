// All code should be written for the Atmega1284
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main() {
	// Initialization: The lower nibble of B should be output, the upper nibble should be input
	DDRB = 0x0F; PORTB = 0xF0;
	// Write a program that will
	unsigned char temp = 0; 
	//  set output of the lower nibble of B to the value on the input of the upper nibble of B
	while(1){
		//1)Read
		temp = (PINB & 0xF0) >> 4;
		//2)write
		PORTB = temp;
	}
	return 1;
}
