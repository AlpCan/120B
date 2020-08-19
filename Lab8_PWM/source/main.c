/*	Author: Alp Alloglu
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

#include "timer.h"
#include "pwm.h"
#include "melody.h"

int main(void) {
    	/* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	//DDRC = 0xFF; PORTC = 0x00; //Debug tool for states
	// Timer setup
	const unsigned long PERIOD = 25;
	TimerSet(PERIOD);
	TimerOn();

	//PWM setup
	PWM_on();
	
	//Initialize States
	MelodyStates melodyState = init;
	/* Insert your solution below */
    	while (1) {
		melodyState = melodyTick(melodyState);
		// Output
		//PORTC = melodyState; //debug
		set_PWM(frequency);
		while (!TimerFlag) { } // wait for "period" amount of time
		TimerFlag = 0; //Handshake

	}
	return 1;
}
