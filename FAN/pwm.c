 /******************************************************************************
 *
 * Module: PWM
 *
 * File Name: pwm.c
 *
 * Description: source file for the ATmega32 PWM driver
 *
 * Author: Nada Hefnawy
 *
 *******************************************************************************/
#include "pwm.h"
#include "avr/io.h"
#include "std_types.h"
/* Description:
 * calculating the duty cycle by multiplying the percentage of speed by timer maximum counter.
 * initialize timer counter with zero.
 * assign the calculated duty cycle to the compare match register.
 * setup the direction of PB3 pin to be output pin.
 * configure timer0 with  non inverting fast PWM mode with prescaler 8.
 */
void PWM_Timer0_Start(uint8 duty_cycle) {
	TCNT0 = 0; // Set Timer Initial Value to 0

	OCR0 = (uint8)(((uint16)(255*duty_cycle))/100); // Set Compare Value

	DDRB = DDRB | (1 << PB3); // Configure PB3/OC0 as output pin --> pin where the PWM signal is generated from MC

	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */
	TCCR0 = (1 << WGM00) | (1 << WGM01) | (1 << COM01) | (1 << CS01);

}
