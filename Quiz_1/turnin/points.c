// All code should be written for the Atmega1284
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif 
int main() {
    	// Initialization: A should be set to input, B and C should be set to output
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0xFF; PORTC = 0x00;
	typedef unsigned short points;
	points score = 0;
	unsigned char tempRead= 0; // holds PORT A reading
    // Write a program to do the following:
    //  Create an alias for a 'short' type called points
    //  Declare a variable 'score' of type points
    //  Change the value of 'score' based on the input on A according to:
    //      0x01: +1
    //      0x02: +2
    //      0x04: +5
    //      0x08: +10
    //      Anything else: -1
    //  Output the upper byte of score onto B
    //  Output the lower byte of score onto C

    	while(1){
		//1)Read 
		tempRead = PINA;
		//2)Logic
		if((tempRead & 0x0F) != 0x00){
			if((tempRead & 0x01) == 0x01) {
				score = score + 1;
			}
			if((tempRead & 0x02) == 0x02) {
				score = score + 2;
			}
			if((tempRead & 0x04) == 0x04) {
				score = score + 5;
			}
			if((tempRead & 0x08) == 0x08) {
				score = score + 10;
			}
		}
		else {
			score = score - 1;
		}
		//3) output
		PORTB = (score & 0xFF00) >> 8;
		PORTC = score & 0x00FF;
	}
		

    return 1;
}
