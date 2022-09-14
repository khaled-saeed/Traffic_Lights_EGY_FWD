/*
 * Button.c
 *
 * Created: 9/4/2022 12:12:28 PM
 *  Author: khaled
 */ 
#include "Button.h"

void BUTTON_init(PIN_t pin,PORT_t port)
{
	switch(port)
	{
		case PORT_A:	DDRA &= ~(1U<<pin); 
		break;
		case PORT_B:	DDRB &= ~(1U<<pin); 
		break;
		case PORT_C:	DDRC &= ~(1U<<pin); 
		break;
		case PORT_D:	DDRD &= ~(1U<<pin); 
		break;
	}
	
}
ButtonStatus_t BUTTON_read(PIN_t pin,PORT_t port)
{
		switch(port)
		{
			case PORT_A: return ((PINA&(1U<<pin))>>pin) ;
			break;
			case PORT_B: return ((PINB&(1U<<pin))>>pin);
			break;
			case PORT_C: return ((PINC&(1U<<pin))>>pin);
			break;
			case PORT_D: return ((PIND&(1U<<pin))>>pin);
			break;
		}
}