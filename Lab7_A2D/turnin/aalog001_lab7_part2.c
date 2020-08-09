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
	DDRD = 0xFF; PORTD = 0x00;
	/* ADC initialization*/
	ADC_init();
	/*Variable initializations*/
	unsigned char led8bit = 0;
	unsigned char led2bit = 0;
   	/* Insert your solution below */
    while (1) {
	unsigned short aReading = ADC;
	//Undate led variables
	led8bit = (char)aReading;
	led2bit = (char)(aReading >> 8);

	PORTB = led8bit;
	PORTD = led2bit;
    }
    return 1;
}
