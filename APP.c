/******************************************************************************
 *
 * Module: application
 *
 * File Name: App.c
 *
 * Description: source file for the the application
 *
 * Author: Mo'men Ahmed
 *
 *******************************************************************************/
#include "App.h"

volatile uint8 ticks=0;
uint8 normal_mode=1;

cars_traffic_light cars_traffic;

pedestrian_traffic_light pedestrian_traffic;

int main(void)
{
	ST_MY_INT_DATA my_interrupt ={INT_0 , RISING_EDGE};
	INT0_INIT(&my_interrupt);
	sei(); //setting the i bit to 1
	setting_output_pins();
	Timer1_SetCallBack(control_traffic_lights);

	Timer1_Config my_timer1 = {0 ,15625 , COMPARE_MODE, F_CPU_64 \
			,DISCONNECT_OC1A ,DISCONNECT_OC1B
	};
	normal_mode =1;
	Timer1_init(&my_timer1);  //start counting time
	while (1)
	{

	}

}

void setting_output_pins(void)
{
	GPIO_setupPinDirection(PORTA_ID, PIN0_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTA_ID, PIN1_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTA_ID, PIN2_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID, PIN0_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID, PIN1_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID, PIN2_ID, PIN_OUTPUT);
}


ISR(INT0_vect)
{
normal_mode =0;
ticks=0;
}


uint8 ped_mode_1_ended = 0;
uint8 ped_mode_2_ended = 0;

void control_traffic_lights(void)
{
	if(normal_mode==1)
	{
	ticks++;
    if(ticks >= 1 && ticks <=5)
	{
    	Led_off(CARS_LEDS_PORT_ID, RED_LEDS_PIN_ID);  //red off
    	Led_off(CARS_LEDS_PORT_ID, YELLOW_LEDS_PIN_ID);   //yellow off
    	Led_on(CARS_LEDS_PORT_ID, GREEN_LEDS_PIN_ID);   //green on
    	cars_traffic =GREEN_CARS;

    	Led_on(PED_LEDS_PORT_ID, RED_LEDS_PIN_ID);  //red on
    	Led_off(PED_LEDS_PORT_ID, YELLOW_LEDS_PIN_ID);   //yellow off
    	Led_off(PED_LEDS_PORT_ID, GREEN_LEDS_PIN_ID);   //green off
    	pedestrian_traffic =RED_PED;
	}

    else if(ticks==6 || ticks == 8 || ticks ==10)
	{
    	Led_off(CARS_LEDS_PORT_ID, RED_LEDS_PIN_ID);  //red off
    	Led_on(CARS_LEDS_PORT_ID, YELLOW_LEDS_PIN_ID);   //yellow on
    	Led_off(CARS_LEDS_PORT_ID, GREEN_LEDS_PIN_ID);   //green off

		cars_traffic = YELLOW_CARS;

    	Led_off(PED_LEDS_PORT_ID, RED_LEDS_PIN_ID);  //red off
    	Led_on(PED_LEDS_PORT_ID, YELLOW_LEDS_PIN_ID);   //yellow on
    	Led_off(PED_LEDS_PORT_ID, GREEN_LEDS_PIN_ID);   //green off

		pedestrian_traffic = YELLOW_PED;
	}
	else if(ticks==7 || ticks == 9)
	{
    	Led_off(CARS_LEDS_PORT_ID, RED_LEDS_PIN_ID);  //red off
    	Led_off(CARS_LEDS_PORT_ID, YELLOW_LEDS_PIN_ID);   //yellow off
    	Led_off(CARS_LEDS_PORT_ID, GREEN_LEDS_PIN_ID);   //green off

    	Led_off(PED_LEDS_PORT_ID, RED_LEDS_PIN_ID);  //red off
    	Led_off(PED_LEDS_PORT_ID, YELLOW_LEDS_PIN_ID);   //yellow off
    	Led_off(PED_LEDS_PORT_ID, GREEN_LEDS_PIN_ID);   //green off
	}
	else if(ticks >= 11 && ticks <=15)
	{
		Led_on(CARS_LEDS_PORT_ID, RED_LEDS_PIN_ID);  //red on
		Led_off(CARS_LEDS_PORT_ID, YELLOW_LEDS_PIN_ID);   //yellow off
		Led_off(CARS_LEDS_PORT_ID, GREEN_LEDS_PIN_ID);   //green off

		cars_traffic = RED_CARS;

    	Led_off(PED_LEDS_PORT_ID, RED_LEDS_PIN_ID);  //red off
    	Led_off(PED_LEDS_PORT_ID, YELLOW_LEDS_PIN_ID);   //yellow off
    	Led_on(PED_LEDS_PORT_ID, GREEN_LEDS_PIN_ID);   //green on

		pedestrian_traffic = GREEN_PED;
	}
	else if(ticks==16 || ticks == 18 )
	{
    	Led_off(CARS_LEDS_PORT_ID, RED_LEDS_PIN_ID);  //red off
    	Led_on(CARS_LEDS_PORT_ID, YELLOW_LEDS_PIN_ID);   //yellow on
    	Led_off(CARS_LEDS_PORT_ID, GREEN_LEDS_PIN_ID);   //green off

		cars_traffic = YELLOW_CARS;

		Led_off(PED_LEDS_PORT_ID, RED_LEDS_PIN_ID);  //red off
		Led_on(PED_LEDS_PORT_ID, YELLOW_LEDS_PIN_ID);   //yellow on
		Led_off(PED_LEDS_PORT_ID, GREEN_LEDS_PIN_ID);   //green off

		pedestrian_traffic = YELLOW_PED;
	}
	else if(ticks == 17 || ticks ==19)
	{
    	Led_off(CARS_LEDS_PORT_ID, RED_LEDS_PIN_ID);  //red off
    	Led_off(CARS_LEDS_PORT_ID, YELLOW_LEDS_PIN_ID);   //yellow off
    	Led_off(CARS_LEDS_PORT_ID, GREEN_LEDS_PIN_ID);   //green off

    	Led_off(PED_LEDS_PORT_ID, RED_LEDS_PIN_ID);  //red off
    	Led_off(PED_LEDS_PORT_ID, YELLOW_LEDS_PIN_ID);   //yellow off
    	Led_off(PED_LEDS_PORT_ID, GREEN_LEDS_PIN_ID);   //green off
	}
	else if(ticks==20)
	{
    	Led_off(CARS_LEDS_PORT_ID, RED_LEDS_PIN_ID);  //red off
    	Led_on(CARS_LEDS_PORT_ID, YELLOW_LEDS_PIN_ID);   //yellow on
    	Led_off(CARS_LEDS_PORT_ID, GREEN_LEDS_PIN_ID);   //green off
		cars_traffic = YELLOW_CARS;

    	Led_off(PED_LEDS_PORT_ID, RED_LEDS_PIN_ID);  //red off
    	Led_on(PED_LEDS_PORT_ID, YELLOW_LEDS_PIN_ID);   //yellow on
    	Led_off(PED_LEDS_PORT_ID, GREEN_LEDS_PIN_ID);   //green off
		pedestrian_traffic = YELLOW_PED;

		ticks=0;
	}
	}


	else if(normal_mode ==0)
	{
		ticks++;
		if(cars_traffic == RED_CARS)   //pedestrian can pass (ped mode 1)
		{
		  if(ticks >=1 && ticks <=5)
		  {
			  Led_on(CARS_LEDS_PORT_ID, RED_LEDS_PIN_ID);  //red on
			  Led_off(CARS_LEDS_PORT_ID, YELLOW_LEDS_PIN_ID);   //yellow off
			  Led_off(CARS_LEDS_PORT_ID, GREEN_LEDS_PIN_ID);   //green off

			  Led_off(PED_LEDS_PORT_ID, RED_LEDS_PIN_ID);  //red off
			  Led_off(PED_LEDS_PORT_ID, YELLOW_LEDS_PIN_ID);   //yellow off
			  Led_on(PED_LEDS_PORT_ID, GREEN_LEDS_PIN_ID);   //green on

			  cars_traffic = RED_CARS;
			  pedestrian_traffic = GREEN_PED;
			  if(ticks==5)
			  {
				  ped_mode_1_ended =1;
				  ticks=11;
			  }
		  }
		}
		else if(cars_traffic == YELLOW_CARS || cars_traffic == GREEN_CARS) //(ped mode 2)
		{
	         if(ticks ==1)
	         {
	        	 Led_off(CARS_LEDS_PORT_ID, RED_LEDS_PIN_ID);  //red off
	        	 Led_off(CARS_LEDS_PORT_ID, YELLOW_LEDS_PIN_ID);   //yellow off
	        	 Led_off(CARS_LEDS_PORT_ID, GREEN_LEDS_PIN_ID);   //green off

	        	 Led_on(PED_LEDS_PORT_ID, RED_LEDS_PIN_ID);  //red on
	        	 Led_off(PED_LEDS_PORT_ID, YELLOW_LEDS_PIN_ID);   //yellow off
	        	 Led_off(PED_LEDS_PORT_ID, GREEN_LEDS_PIN_ID);   //green off

	         }
	         else if(ticks ==2 || ticks ==4 || ticks ==6)
	         {
	        	 Led_off(CARS_LEDS_PORT_ID, RED_LEDS_PIN_ID);  //red off
	        	 Led_on(CARS_LEDS_PORT_ID, YELLOW_LEDS_PIN_ID);   //yellow on
	        	 Led_off(CARS_LEDS_PORT_ID, GREEN_LEDS_PIN_ID);   //green off

	        	 Led_off(PED_LEDS_PORT_ID, RED_LEDS_PIN_ID);  //red off
	        	 Led_on(PED_LEDS_PORT_ID, YELLOW_LEDS_PIN_ID);   //yellow on
	        	 Led_off(PED_LEDS_PORT_ID, GREEN_LEDS_PIN_ID);   //green off
	         }
	         else if(ticks ==3 || ticks ==5)
	         {
	        	 Led_off(CARS_LEDS_PORT_ID, RED_LEDS_PIN_ID);  //red off
	        	 Led_off(CARS_LEDS_PORT_ID, YELLOW_LEDS_PIN_ID);   //yellow off
	        	 Led_off(CARS_LEDS_PORT_ID, GREEN_LEDS_PIN_ID);   //green off

	        	 Led_off(PED_LEDS_PORT_ID, RED_LEDS_PIN_ID);  //red off
	        	 Led_off(PED_LEDS_PORT_ID, YELLOW_LEDS_PIN_ID);   //yellow off
	        	 Led_off(PED_LEDS_PORT_ID, GREEN_LEDS_PIN_ID);   //green off

	         }
	         else if(ticks >=6 && ticks <=11)
	         {
	        	 Led_on(CARS_LEDS_PORT_ID, RED_LEDS_PIN_ID);  //red on
	        	 Led_off(CARS_LEDS_PORT_ID, YELLOW_LEDS_PIN_ID);   //yellow off
	        	 Led_off(CARS_LEDS_PORT_ID, GREEN_LEDS_PIN_ID);   //green off

	        	 Led_off(PED_LEDS_PORT_ID, RED_LEDS_PIN_ID);  //red off
	        	 Led_off(PED_LEDS_PORT_ID, YELLOW_LEDS_PIN_ID);   //yellow off
	        	 Led_on(PED_LEDS_PORT_ID, GREEN_LEDS_PIN_ID);   //green on

	        	 if(ticks==11)
	        	 {
	        		 ped_mode_2_ended =1;
	        	 }
	         }
		}

		if(ped_mode_1_ended ==1 || ped_mode_2_ended ==1)
		{
    		if (ticks >16)
    		{
    			ticks = 0;
    			normal_mode =1;
    		}
    		if(ticks == 12 || ticks ==14 || ticks ==16)
    		{
    			Led_off(CARS_LEDS_PORT_ID, RED_LEDS_PIN_ID);  //red off
    			Led_on(CARS_LEDS_PORT_ID, YELLOW_LEDS_PIN_ID);   //yellow on
    			Led_off(CARS_LEDS_PORT_ID, GREEN_LEDS_PIN_ID);   //green off

    			Led_off(PED_LEDS_PORT_ID, RED_LEDS_PIN_ID);  //red off
    			Led_on(PED_LEDS_PORT_ID, YELLOW_LEDS_PIN_ID);   //yellow on
    			Led_on(PED_LEDS_PORT_ID, GREEN_LEDS_PIN_ID);   //green on
    		}
    		else if(ticks ==13 || ticks ==15)
    		{
    			Led_off(CARS_LEDS_PORT_ID, RED_LEDS_PIN_ID);  //red off
    			Led_off(CARS_LEDS_PORT_ID, YELLOW_LEDS_PIN_ID);   //yellow off
    			Led_off(CARS_LEDS_PORT_ID, GREEN_LEDS_PIN_ID);   //green off

    			Led_off(PED_LEDS_PORT_ID, RED_LEDS_PIN_ID);  //red off
    			Led_off(PED_LEDS_PORT_ID, YELLOW_LEDS_PIN_ID);   //yellow off
    			Led_on(PED_LEDS_PORT_ID, GREEN_LEDS_PIN_ID);   //green on
    		}
		}
	}
}
