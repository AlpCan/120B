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

int main(void) {
	/* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF; // Set A's pins to output
	DDRC = 0xFF; PORTC = 0x00; // Set C's pins to input, initialize to 0
	unsigned char fuelLvl = 0x00; // holds the fuel level read from PINA
	unsigned char leds = 0x00; // varaibale to hold led output
	/* Insert your solution below */
	while (1) {
		//1) Read in inputs
		fuelLvl = ~PINA & 0x0F;
		//2) logical operations
		//fuel level calculation
		switch(fuelLvl) {
		case 0:
			leds = 0x40;
			break;
		case 1:
		case 2:
			leds = 0x60;
			break;
		case 3:
		case 4:
			leds = 0x70;
			break;
		case 5:
		case 6:
			leds = 0x38;
			break;
		case 7:
		case 8:
		case 9:
			leds = 0x3C;
			break;
		case 10:
		case 11:
		case 12:
			leds = 0x3E;
			break;
		case 13:
		case 14:
		case 15:
			leds = 0x3F;
			break;
		default:
			leds = 0xFF; // Error
			break;
		}
		//3) Output
		PORTC = leds;		
	}
    	return 1;
}
