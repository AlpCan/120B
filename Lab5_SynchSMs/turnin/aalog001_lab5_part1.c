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
#include <avr/interrupt.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

volatile unsigned char TimerFlag = 0; // TimerIRS() sets this to 1. C programmer should clear to 0.

// Internal variables for mapping AVR's IRS to our cleaner TimerIRS model.
unsigned long _avr_timer_M = 1; // Start count from here, down to 0. Default is 1 ms.
unsigned long _avr_timer_cntcurr = 0; // Current internal count of 1 ms ticks 

void TimerOn() {
	// AVR timer/counter controller register TCCR1
	TCCR1B = 0x0B;	// bit3 = 0 : CTC mode (clear timer on compare)
			// bit2bit1bit0=011 : pre-scaler /64
			// 00001011: 0x0B
			// So, 8 Mhz clock or 8000000 / 64 = 125,000 ticks/s
			// Thus TCNT1 register will count at 125,000 ticks/s
	
	// AVR output compare to register ORC1A
	OCR1A = 125;	// Timer interupt will be generated when TCNT1 == ORC1A
       			// We want a 1ms tick. 0.001 s * 125,000 ticks/s = 125
			// So when TCNT1 register equals to 125,
			// 1 ms has passed. Thus, we compare to 125.

	// AVR timer interrupt mask register.
	TIMSK1 = 0x02;	// bit1: ORC1A -- enables compare match interrupt

	//Initialize avr counter
	TCNT1 = 0;

	_avr_timer_cntcurr = _avr_timer_M;
	// TimerISR will be called every _avr_timer_cntcurr miliseconds
	
	// Enable global interups
	SREG |= 0x80; 	// 0x80: 10000000
}

void TimerOff() {
	TCCR1B = 0x00;	// bit3bit1bit0-000: timer off
}

void TimerISR() {
	TimerFlag = 1;
}

//In our approach, the C programmer does not touch this IRS, but rather TimerIRS()
ISR(TIMER1_COMPA_vect) {
	// CPU automatically calls when TCNT1 == OCR1 (every 1ms per TimerOn settings)
	_avr_timer_cntcurr--;	// Count down to 0 rather than up to TOP
	if(_avr_timer_cntcurr == 0) {	// Result in more efficient compare
		TimerISR();		// Call the IRS thet user uses
		_avr_timer_cntcurr = _avr_timer_M;
	}
}

// Set TimerIRS() to tick every M ms
void TimerSet(unsigned long M) {
	_avr_timer_M = M;
	_avr_timer_cntcurr = _avr_timer_M;
}
//State Mashine
//States

enum States {start, led_b0, led_b1, led_b2 } state;
void Tick() {
	unsigned char led = 0;
	switch(state) {
		case start:
			state = led_b0;
			break;
		case led_b0:
			state = led_b1;
			break;
		case led_b1:
			state = led_b2;
			break;
		case led_b2:
			state = led_b0;
			break;
		default:
			state = start;
			break;
	}
	switch(state) {
		case start:
			break;
		case led_b0:
			led = 0x01;
			break;
		case led_b1:
			led = 0x02;
			break;
		case led_b2:
			led = 0x04;
			break;
	}
	PORTB = led;

}
int main(void) {
	/* Insert DDR and PORT initializations */
	DDRB = 0xFF; 	// Set port B to output
	PORTB = 0x00;	// Init port B to 0s
	TimerSet(1000);
	TimerOn();
	state = start;	
	/* Insert your solution below */
	while (1) {
		Tick();
		while(!TimerFlag); // wait 1 sec
		TimerFlag = 0;
	}
	return 1;
}
