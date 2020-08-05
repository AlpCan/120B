// All code should be written for the Atmega1284
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main() {
	// Initialization: A should be set to input, B should be set to output
	DDRB = 0xFF; PORTB = 0x00;
	DDRA = 0x00; PORTA = 0xFF;
	unsigned char butA0 = 0;
	unsigned char swiA7 = 0;
	unsigned char result = 0;
	// Write a program that sets B to all 1's WHILE a button on A0 is held down
	// BUT ONLY IF a switch on A7 is flipped on.
	// Otherwise, B should output all 0's
	// You must use the ternary operator
	while(1){
		//1) Read
		butA0 = PINA & 0x01;
		swiA7 = (PINA & 0x80) >> 7;
		// 2) logic
		result = ( butA0 & swiA7 ) ? 0xFF : 0x00;
		// alternative (PINA&0x81)==0x81
		// 3) Output
		PORTB = result;
	}
	return 1;
}
