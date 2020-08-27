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
#include <avr/sleep.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

#include "scheduler_part2.h"
#include "keypad.h"
#include "keypadSM.h"
#include "LockSM.h"
#include "DisplaySM_part2.h"


int main(void) {
    	/* Insert DDR and PORT initializations */
	DDRB = 0x7F; PORTB = 0x80; // PORTB set to output, output init 0s
	DDRC = 0xF0; PORTC = 0x0F; // PC7..4 outputs init 0s, PC3...0 inputs init 1s
	
	/* Load timers */
	loadTask (keypadSM_start, KEYPADSM_PERIOD, &KeypadSM);
	loadTask (LockSM_start, LOCKSM_PERIOD, &LockSM);
	loadTask (DisplaySM_start, DISPLAYSM_PERIOD, &DisplaySM);

	/* scheduler */
	setPeriod();
	TimerSet(PERIOD);
	TimerOn();
	set_sleep_mode(SLEEP_MODE_IDLE);
	sleep_enable();


    	while (1) {
		sleep_cpu();
	}
    	return 1;
}
