 /******************************************************************************
 *
 * Module: LED
 *
 * File Name: Led.h
 *
 * Description: header file for the Led driver
 *
 * Author: Mo'men Ahmed
 *
 *******************************************************************************/

#ifndef LED_H_
#define LED_H_

#include "gpio.h"
#include "std_types.h"

void Led_on (led_port_id , led_pin_id);
void Led_off (led_port_id , led_pin_id);

#endif /* LED_H_ */
