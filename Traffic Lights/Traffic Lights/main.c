/*
 * GPIO.c
 *
 * Created: 9/3/2022 12:48:41 PM
 * Author : khaled Saeed Tawfik
 */ 


#include "APP/Traffic_lights.h"


int main(void)
{
	
	TrafficLights_init();
	while (1)
	{
		TrafficLights_app(); 
	}
}

ISR(INT0_vect)
{
	(*CallBackFuncINT0_ptr)(); 
}
ISR(TIMER2_OVF_vect)
{
	(*Timer2_callBack_fptr)(); 
}