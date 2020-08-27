// Returns '/0' if no key pressed, else returns char '1', '2', ... , '9' , 'A' , ...
// If multiple key pressed, returns leftmost-topmost one
// Key must be connected to port C
// Keypad Aragement
/*	  PC4 PC5 PC6 PC7
 * col->   1   2   3   4
 * row V
 * PC0 1   1   2   3   A
 * PC1 2   4   5   6   B
 * PC2 3   7   8   9   C
 * PC3 4   *   0   #   D
 */
#ifndef KEYPADMULTIPRESS_H
#define KEYPADMULTIPRESS_H

#include "bit.h"

unsigned char CheckKeypadMultiPress() {
	unsigned char press = 0;
	unsigned char multiPress = 0;
	//Check keys in col 1
	PORTC = 0xEF; // Enable col 1, PC4 with 0, disavle others with 1's
	asm("nop"); // add a delay yo allow PORTC to stabilise before checking
	if (GetBit(PINC,0) == 0) { ++press; }
	if (GetBit(PINC,1) == 0) { ++press; }
	if (GetBit(PINC,2) == 0) { ++press; }
	if (GetBit(PINC,3) == 0) { ++press; }

	//Check keys in col 1
	PORTC = 0xDF; // Enable col 2, PC5 with 0, disavle others with 1's
	asm("nop"); // add a delay yo allow PORTC to stabilise before checking
	if (GetBit(PINC,0) == 0) { ++press; }
	if (GetBit(PINC,1) == 0) { ++press; }
	if (GetBit(PINC,2) == 0) { ++press; }
	if (GetBit(PINC,3) == 0) { ++press; }
	
	//Check keys in col 1
	PORTC = 0xBF; // Enable col 3,PC6 with 0, disavle others with 1's
	asm("nop"); // add a delay yo allow PORTC to stabilise before checking
	if (GetBit(PINC,0) == 0) { ++press; }
	if (GetBit(PINC,1) == 0) { ++press; }
	if (GetBit(PINC,2) == 0) { ++press; }
	if (GetBit(PINC,3) == 0) { ++press; }

	//Check keys in col 1
	PORTC = 0x7F; // Enable col 4,PC7 with 0, disavle others with 1's
	asm("nop"); // add a delay yo allow PORTC to stabilise before checking
	if (GetBit(PINC,0) == 0) { ++press; }
	if (GetBit(PINC,1) == 0) { ++press; }
	if (GetBit(PINC,2) == 0) { ++press; }
	if (GetBit(PINC,3) == 0) { ++press; }

	if ( press > 1 ) { multiPress = 1; }

	return multiPress; // default value
}
#endif // KEYPADMULTIPRESS_H
