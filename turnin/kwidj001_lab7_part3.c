/*	Author: lab
 *  Partner(s) Name:
 *	Lab Section:
 *	Assignment: Lab 7  Exercise 2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned char tmpA = 0x00;
unsigned char tmpB = 0x00;
unsigned char tmpD = 0x00;
unsigned short x; //for ADC
unsigned short MAX = 0; //unable to get value due to hardware issues
unsigned short MIN = 0; //unable to get value due to hardware issues
void ADC_init(){
  ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
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
      if(x >= MAX/2){
        tmpB = 0x01;
        PORTB = tmpB;
      }else if(x < MAX/2){
        tmpB = 0x00;
        PORTB = tmpB;
      }
    }
    return 1;
}
