 /******************************************************************************
 *
 * Module: TIMER1
 *
 * File Name: Timer1.h
 *
 * Description: source file for the timer 1 driver
 *
 * Author: Mo'men Ahmed
 *
 *******************************************************************************/

#include "Timer1.h"
#include "avr/io.h"
#include <avr/interrupt.h>

static volatile void (*g_ptr_func) (void) =NULL_PTR;

/*******************************************************************************
 *                      Functions Definitions	                                   *
 *******************************************************************************/

void Timer1_init (const Timer1_Config * timer1_ptr)
{
	TCCR1A |= (1<<FOC1A) | (1<<FOC1B);

	if(timer1_ptr->mode == COMPARE_MODE)
	{
		TCCR1A= ((timer1_ptr->OC1A_func)<<6) | ((timer1_ptr->OC1B_func)<<4);
		TCCR1B = (1<<WGM12);
		OCR1A = timer1_ptr -> compare_value;
		TIMSK = (1<<OCIE1A);
	}
	else if(timer1_ptr->mode == NORMAL_MODE)
	{
		TIMSK = (1<<TOIE1);
	}
TCCR1B = (TCCR1B & 0xf8) |  (timer1_ptr->clock_select);
TCNT1 = timer1_ptr->initial_value;
}

void Timer1_DeInit (void)
{
	TCCR1A=0;
	TCCR1B=0;
	TCNT1=0;
	OCR1A=0;
	TIMSK=0;
}

void Timer1_SetCallBack (void (*a_ptr) (void))
{
	g_ptr_func = a_ptr;
}

ISR (TIMER1_OVF_vect)
{
	if(g_ptr_func != NULL_PTR)
	  (*g_ptr_func)();
}

ISR (TIMER1_COMPA_vect)
{
	if(g_ptr_func != NULL_PTR)
	  (*g_ptr_func)();
}
