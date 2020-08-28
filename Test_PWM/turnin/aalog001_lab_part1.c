/*	Author: lab
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
#include "PCpwm.h"
#include "onOffSM.h"


int main(void) {
	/* Insert DDR and PORT initializations */
	DDRB = 0xFF; PORTB = 0x00;
	DDRA = 0x00; PORTA = 0xFF;
	/* Load Tasks */
	loadTask(onOffSM_start,ONOFFSM_PERIOD, &onOffSM);
	/* Scheduler */
	setPeriod();
	TimerSet(PERIOD);
	TimerOn();
	set_sleep_mode(SLEEP_MODE_IDLE);
	sleep_enable();
	/* pwm */
	PWM_on();


	/* Insert your solution below */
	while (1) {
		sleep_cpu();
		
 	}
    	return 1;
}
