/*	Author: Alp Can Aloglu
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

#include "keypadMultiPress.h"
#include "keypad.h"
#include "scheduler_part1.h"
#include "keypadSM.h"
#include "ButtonDetectSM.h"
#include "DisplaySM_part1.h"

int main(void) {
    	/* Insert DDR and PORT initializations */
	DDRB = 0xFF; PORTB = 0x00; // PORTB set to output, output init 0s
	DDRC = 0xF0; PORTC = 0x0F; // PC7..4 outputs init 0s, PC3...0 inputs init 1s
	
	/* Load timers */
	loadTask (keypadSM_start, KEYPADSM_PERIOD, &KeypadSM);
	loadTask (ButtonDetectSM_start, BUTTONDETECTSM_PERIOD, &ButtonDetectSM);
	loadTask (DisplaySM_start, DISPLAYSM_PERIOD, &DisplaySM);

	/* scheduler */
	setPeriod();
	TimerSet(PERIOD);
	TimerOn();


    	while (1) {
		
    	}
    	return 1;
}
