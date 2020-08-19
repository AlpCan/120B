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

void ADC_init() {
	ADCSRA |= ( 1 << ADEN ) | ( 1 << ADSC ) | ( 1 << ADATE );
	// ADEN: setting this bit enables analog to digital conversion.
	// ADSC: setting this bit starts the first conversion.
	// ADATE: setting this bit enables auto-triggering. since we are
	// 	  in Free Running Mode, a new conversion will trigger whenever
	// 	  the previous conversion complete
}

int main(void) {
    	/* Insert DDR and PORT initializations */
	DDRB = 0xFF; PORTB = 0x00;
	/* ADC initialization*/
	ADC_init();
	/*Variable initializations*/
	unsigned char led = 0;
	const unsigned short MAX = 96;
   	/* Insert your solution below */
    while (1) {
	unsigned short light_sens = ADC;
	//Update led variables
	if ( light_sens > (MAX)) {
		led = 0xFF;
	} 
	else if ( light_sens > (MAX/8 * 7)) {
		led = 0x7F;
	}
	else if ( light_sens > (MAX/8 * 6)) {
		led = 0x3F;
	}
	else if ( light_sens > (MAX/8 * 5)) {
		led = 0x1F;
	}
	else if ( light_sens > (MAX/8 * 4)) {
		led = 0x0F;
	}
	else if ( light_sens > (MAX/8 * 3)) {
		led = 0x07;
	}
	else if ( light_sens > (MAX/8 * 2)) {
		led = 0x03;
	}
	else if ( light_sens > (MAX/8)) {
		led = 0x01;
	}
	else {
		led = 0x00;
	}

	PORTB = led;
    }
    return 1;
}
