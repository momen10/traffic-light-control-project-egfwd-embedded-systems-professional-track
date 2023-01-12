/******************************************************************************
 *
 * Module: Interrupt
 *
 * File Name: interrupt.h
 *
 * Description: source file for the interrupt driver
 *
 * Author: Mo'men Ahmed
 *
 *******************************************************************************/


#include "Interrupt.h"
#include "avr/io.h"

void INT0_INIT(ST_MY_INT_DATA * my_int)
{
	if (my_int->type ==INT_0)
	{
		DDRD &= ~(1<<INT_0); //pin INT0 is input
		GICR |= (1<<INT_0); //enable INT0 external interrupt
        if(my_int ->sense_control ==RISING_EDGE)
        {
        	MCUCR &= 0xfc;   //clearing first 2 bits
            MCUCR |= RISING_EDGE; //from data sheet INT0: rising edge
        }
        else if (my_int ->sense_control ==FALLING_EDGE)
        {
        	MCUCR |= 0x0c;   //clearing first 2 bits
            MCUCR |= FALLING_EDGE; //from data sheet INT0: falling edge
        }
	}
	if(my_int->type ==INT_1)
	{
		DDRD &= ~(1<<INT_1); //pin INT1 is input
		GICR |= (1<<INT_1); //enable INT0 external interrupt
        if(my_int ->sense_control ==RISING_EDGE)
        {
        	MCUCR &= 0xf4;   //clearing bits 3 and 4
            MCUCR |= (RISING_EDGE<<2); //from data sheet INT1: rising edge
        }
        else if (my_int ->sense_control ==FALLING_EDGE)
        {
        	MCUCR &= 0xf4;   //clearing bits 3 and 4
            MCUCR |= (FALLING_EDGE<<2); //from data sheet INT01: falling edge
        }
	}
	if(my_int->type ==INT_2)
	{
		DDRD &= ~(1<<INT_2); //pin INT0 is input
		GICR |= (1<<INT_2); //enable INT0 external interrupt
        if(my_int ->sense_control ==RISING_EDGE)
        {
        	MCUCSR |= (1<<ISC2);
        }
        else if (my_int ->sense_control ==FALLING_EDGE)
        {
        	MCUCSR &= ~(1<<ISC2);
        }
	}
}
