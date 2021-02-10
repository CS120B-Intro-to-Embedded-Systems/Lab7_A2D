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

unsigned char tmpA = 0x00, tmpB = 0x00, tmpD = 0x00;
unsigned short x; //for ADC

void ADC_init(){
  ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
  //ADEN: setting this bit enables analog-to-digital conversion.
  //ADSC: setting this bit starts the first conversion.
  //ADATE: setting this bit enables auto-triggering. Since we Partner
  //       in Free Running Mode, a new conversion will trigger whenever
  //       the previous conversion completes.
}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF; //PORTA as input (potentiometer)
    DDRB = 0xFF; PORTB = 0x00; //PORTB as output (7:0) (led lights)
    DDRD = 0xFF; PORTD = 0x00; //PORTD as output (1:0) (led lights)
    ADC_init();
    /* Insert your solution below */
    while (1) {
      x = ADC; 
      tmpB = (char)(x);
      PORTB = ~tmpB;
      tmpD = (char)(x >> 8); //get upper bits and set to tmpD
      PORTD = ~ tmpD;
    }
    return 1;
}
