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
#ifndef KEYPADSM_H
#define KEYPADSM_H

#include "keypad.h"
//Timer
const unsigned long KEYPADSM_PERIOD = 100;

//Global variables
unsigned char button_0;
unsigned char button_1;
unsigned char button_2;
unsigned char button_3;
unsigned char button_4;
unsigned char button_5;
unsigned char button_6;
unsigned char button_7;
unsigned char button_8;
unsigned char button_9;
unsigned char button_A;
unsigned char button_B;
unsigned char button_C;
unsigned char button_D;
unsigned char button_S;
unsigned char button_H;
//Enumeration
typedef enum KeypadStates {keypadSM_start, getInput} KeypadStates;

//Tick Function
//Change the name of the function according to assignment
int KeypadSM(int state) {
	// Get input (HAL)
	//Variables

	//Check keys in col 1
	PORTC = 0xEF; // Enable col 1, PC4 with 0, disavle others with 1's
	asm("nop"); // add a delay yo allow PORTC to stabilise before checking
	button_1 = (GetBit(PINC,0) == 0) ? 0x01 : 0x1F;
	button_4 = (GetBit(PINC,1) == 0) ? 0x04 : 0x1F;
	button_7 = (GetBit(PINC,2) == 0) ? 0x07 : 0x1F;
	button_S = (GetBit(PINC,3) == 0) ? 0x0E : 0x1F; 

	//Check keys in col 1
	PORTC = 0xDF; // Enable col 2, PC5 with 0, disavle others with 1's
	asm("nop"); // add a delay yo allow PORTC to stabilise before checking
	button_2 = (GetBit(PINC,0) == 0) ? 0x02 : 0x1F;
	button_5 = (GetBit(PINC,1) == 0) ? 0x05 : 0x1F;
	button_8 = (GetBit(PINC,2) == 0) ? 0x08 : 0x1F;
	button_0 = (GetBit(PINC,3) == 0) ? 0x00 : 0x1F;
	
	//Check keys in col 1
	PORTC = 0xBF; // Enable col 3,PC6 with 0, disavle others with 1's
	asm("nop"); // add a delay yo allow PORTC to stabilise before checking
	button_3 = (GetBit(PINC,0) == 0) ? 0x03 : 0x1F;
	button_6 = (GetBit(PINC,1) == 0) ? 0x06 : 0x1F;
	button_9 = (GetBit(PINC,2) == 0) ? 0x09 : 0x1F;
	button_H = (GetBit(PINC,3) == 0) ? 0x0F : 0x1F;

	//Check keys in col 1
	PORTC = 0x7F; // Enable col 4,PC7 with 0, disavle others with 1's
	asm("nop"); // add a delay yo allow PORTC to stabilise before checking
	button_A = (GetBit(PINC,0) == 0) ? 0x0A : 0x1F;
	button_B = (GetBit(PINC,1) == 0) ? 0x0B : 0x1F;
	button_C = (GetBit(PINC,2) == 0) ? 0x0C : 0x1F;
	button_D = (GetBit(PINC,3) == 0) ? 0x0D : 0x1F;

	return('\0'); // default value
	//State switches
	//Computation
	switch (state) {
		case keypadSM_start:
			state = getInput;
			break;
		case getInput:
			state = getInput;
			break;
		default:
			state = keypadSM_start;	
			break;
	}
	//Action
	switch (state) {
		case keypadSM_start:
			break;
		case getInput:
			break;
	}
	// Output (HAL)	
	
	return state;
}

#endif
