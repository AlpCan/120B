/*	Author: Alp Aloglu
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

#include "scheduler_part1.h"
#include "BlinkingLEDSM.h"
#include "ThreeLEDsSM.h"
#include "CombineLEDsSM.h"

int main(void) {
	/* Insert DDR and PORT initializations */
	DDRB = 0xFF; PORTB = 0x00; //Set ppins of B as output

	/* Timing */
	
	PERIOD = 1000;
	TimerSet(PERIOD);
	TimerOn();

	/* State Initialization*/
	loadTask (blink_start, BLINK_PERIOD, &BlinkingLEDSM);
	loadTask (threeled_start, THREELED_PERIOD, &ThreeLEDsSM);
	loadTask (combine_start, COMBINE_PERIOD, &CombineLEDsSM);

	/* Insert your solution below */
	while (1) {
		while(!TimerFlag) {}
		TimerFlag = 0;	
	}
	return 1;
}
