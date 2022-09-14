/*
 * LED.c
 *
 * Created: 9/4/2022 10:58:53 AM
 *  Author: khaled
 */ 
#include "LED.h"

void LED_init(PIN_t pin,PORT_t port)
{
	DIO_init(pin,port,OUTPUT);
}
void LED_on(PIN_t pin,PORT_t port)
{
	DIO_write(pin,port,HIGH); 
}
void LED_off(PIN_t pin,PORT_t port)
{
	DIO_write(pin,port,LOW); 
}
void LED_toggle(PIN_t pin,PORT_t port)
{
	DIO_toggle(pin,port); 
}
void LED_blink(PIN_t pin,PORT_t port,uint32_t delay)
{
	Timer0_InitNormal_Polling();
	LED_toggle(pin,port);	
	Timer0_Delay_ms(delay);
	LED_toggle(pin,port); 
	Timer0_Delay_ms(delay);
}