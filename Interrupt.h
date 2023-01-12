/******************************************************************************
 *
 * Module: Interrupt
 *
 * File Name: interrupt.h
 *
 * Description: header file for the interrupt driver
 *
 * Author: Mo'men Ahmed
 *
 *******************************************************************************/

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

typedef enum EXTERNAL_INTERRUPTS{
	INT_2 = 5 , INT_0 , INT_1
}EN_my_interrupt_type;


typedef enum INT0_sense_control {
	FALLING_EDGE=3 , RISING_EDGE
}EN_my_INT_sense_control;

typedef struct INT_data{
EN_my_interrupt_type type;
EN_my_INT_sense_control sense_control;
}ST_MY_INT_DATA;

void INT0_INIT(ST_MY_INT_DATA *);

#endif /* INTERRUPT_H_ */
