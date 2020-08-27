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

#include "scheduler.h"
#include "pwm.h"
#include "softPWM.h"

int main(void) {
	/* Insert DDR and PORT initializations */
	DDRB = 0xFF; PORTB = 0x00;
	DDRA = 0x00; PORTA = 0xFF;
	/* Load Tasks */
	//loadTask(PWM_start,PWM_PERIOD, &softPWM);
	/* Scheduler */
	//setPeriod();
	PERIOD = 100;
	TimerSet(PERIOD);
	TimerOn();
	set_sleep_mode(SLEEP_MODE_IDLE);
	sleep_enable();
	/* pwm */
	PWM_on();

	/*variables*/
	unsigned char button;
	double duty_Cycle = 0;
	/* Insert your solution below */
	while (1) {
		//sleep_cpu();
		//hal
		/*button = ~PINA & 0x01;
		if (button) {
			PORTB = 0x80;
		} else {
			PORTB = 0x00;
		}*/
		//heal
		set_PWM(90);
 	}
    	return 1;
}
