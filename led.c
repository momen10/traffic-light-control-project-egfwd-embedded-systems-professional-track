/******************************************************************************
 *
 * Module: LED
 *
 * File Name: Led.c
 *
 * Description: source file for the Led driver
 *
 * Author: Mo'men Ahmed
 *
 *******************************************************************************/
#ifndef LED_C_
#define LED_C_
#include "Led.h"

void Led_on (led_port_id , led_pin_id)
{
	GPIO_writePin(led_port_id, led_pin_id, LOGIC_HIGH);
}
void Led_off (led_port_id , led_pin_id)
{
	GPIO_writePin(led_port_id, led_pin_id, LOGIC_LOW);
}

#endif /* LED_C_ */
