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

#include "scheduler_part4.h"
#include "InputProcess.h"
#include "BlinkingLEDSM.h"
#include "ThreeLEDsSM_part2.h"
#include "sound_part4.h"
#include "CombineLEDsSM_part4.h"


int main(void) {
	/* Insert DDR and PORT initializations */
	DDRB = 0xFF; PORTB = 0x00; //Set pins of B as output
	DDRA = 0x00; PORTA = 0xFF; //Set pins of A as input
	/* State Initialization*/
	loadTask (input_start, INPUT_PERIOD, &InputProcessSM);
	loadTask (blink_start, BLINK_PERIOD, &BlinkingLEDSM);
	loadTask (threeled_start, THREELED_PERIOD, &ThreeLEDsSM);
	loadTask (sound_start, SOUND_PERIOD, &soundSM);
	loadTask (combine_start, COMBINE_PERIOD, &CombineLEDsSM);

	/* Timing */
	PERIOD = 1; //GDC of al tasks
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
