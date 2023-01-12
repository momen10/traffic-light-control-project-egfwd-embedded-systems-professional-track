 /******************************************************************************
 *
 * Module: TIMER1
 *
 * File Name: Timer1.h
 *
 * Description: Header file for the timer 1 driver
 *
 * Author: Mo'men Ahmed
 *
 *******************************************************************************/
#ifndef TIMER1_H_
#define TIMER1_H_
#include "std_types.h"

/*******************************************************************************
 *                   configurations                                   *
 *******************************************************************************/
typedef enum{
	NORMAL_MODE, COMPARE_MODE=4
}Timer1_Mode;

typedef enum{
	NO_CLOCK_SOURCE, F_CPU_1, F_CPU_8, F_CPU_64,\
	F_CPU_256, F_CPU_1024
}Timer1_Clock_Select;

typedef enum{
	DISCONNECT_OC1A, TOGGLE_OC1A, CLEAR_OC1A, SET_OC1A
}OC1A_Special_func;

typedef enum{
	DISCONNECT_OC1B, TOGGLE_OC1B, CLEAR_OC1B, SET_OC1B
}OC1B_Special_func;

typedef struct{
	uint16 initial_value;
	uint16 compare_value;
	Timer1_Mode mode;
	Timer1_Clock_Select clock_select;
	OC1A_Special_func OC1A_func;
	OC1B_Special_func OC1B_func;
}Timer1_Config;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void Timer1_init (const Timer1_Config *);
void Timer1_DeInit (void);
void Timer1_SetCallBack (void (*a_ptr) (void));
#endif /* TIMER1_H_ */
