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
#include <avr/sleep.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

#include "scheduler.h"
#include "BlinkingLEDSM.h"
#include "ThreeLEDsSM_part2.h"
#include "CombineLEDsSM_part2.h"

int main(void) {
	/* Insert DDR and PORT initializations */
	DDRB = 0xFF; PORTB = 0x00; //Set ppins of B as output

	/* State Initialization*/
	loadTask (blink_start, BLINK_PERIOD, &BlinkingLEDSM);
	loadTask (threeled_start, THREELED_PERIOD, &ThreeLEDsSM);
	loadTask (combine_start, COMBINE_PERIOD, &CombineLEDsSM);
	
	/* Timing */
	PERIOD = 100;
	TimerSet(PERIOD);
	TimerOn();
	set_sleep_mode(SLEEP_MODE_IDLE);
	sleep_enable();

	

	/* Insert your solution below */
	while (1) {
		sleep_cpu();	
	}
	return 1;
}
