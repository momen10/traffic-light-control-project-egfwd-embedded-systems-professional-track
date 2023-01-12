/******************************************************************************
 *
 * Module: application
 *
 * File Name: App.h
 *
 * Description: header file for the the application
 *
 * Author: Mo'men Ahmed
 *
 *******************************************************************************/

#ifndef APP_H_
#define APP_H_

#include "gpio.h"
#include "Timer1.h"
#include "std_types.h"
#include <util/delay.h>
#include "avr/io.h"
#include <avr/interrupt.h>
#include "Led.h"
#include "Interrupt.h"

#define CARS_LEDS_PORT_ID    PORTA_ID
#define PED_LEDS_PORT_ID     PORTB_ID
#define RED_LEDS_PIN_ID      PIN0_ID
#define YELLOW_LEDS_PIN_ID   PIN1_ID
#define GREEN_LEDS_PIN_ID    PIN2_ID


typedef enum {
	RED_CARS , YELLOW_CARS , GREEN_CARS
}cars_traffic_light;

typedef enum {
	RED_PED , YELLOW_PED, GREEN_PED
}pedestrian_traffic_light;

void setting_output_pins(void);
void control_traffic_lights(void);

#endif /* APP_H_ */
