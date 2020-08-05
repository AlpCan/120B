// All code should be written for the Atmega1284
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif
int main() {
	// Initialization: A should be set to input, B should be set to output
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	unsigned char leds = 0; // Change <type> to the correct data type
    // Write a program that will set a variable "leds" (above) to the following:
    while(1){
	//1)read inpput
    	//  leds[7:5] <- port A[2:0]
	leds = leds | ((PINA & 0x07) << 5);
    	//  leds[4:3] <- inverse of port A[4:3] (1->0, 0->1)
	leds = leds | (~PINA & 0x18);
    	//  leds[2:0] <- port A[7:5]
	leds = leds | ((PINA & 0xE0) >> 5);
    	//  output leds on port B
	PORTB = leds;
	}
    return 1;
}
