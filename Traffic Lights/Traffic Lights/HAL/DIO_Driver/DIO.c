/*
 * DIO.c
 *
 * Created: 9/4/2022 9:30:37 AM
 *  Author: khaled
 */ 
#include "DIO.h"

void DIO_init(PIN_t pin, PORT_t port,DIR_t dir)
{
	switch(port)
	{
		case PORT_A:
			switch(dir)
			{
				case INPUT : DDRA &= ~(1U<<pin); 
				break;
				case OUTPUT :DDRA |= (1U<<pin);
				break;
			}
					
		break;
		case PORT_B:
			switch(dir)
			{
				case INPUT :DDRB &= ~(1U<<pin); 
				break;
				case OUTPUT :DDRB |= (1U<<pin);
				break;
			}
		break ; 
		case PORT_C:
			switch(dir)
			{
				case INPUT :DDRC &= ~(1U<<pin); 
				break;
				case OUTPUT :DDRC |= (1U<<pin);
				break;
			}
		break ; 
		case PORT_D:
			switch(dir)
			{
				case INPUT :DDRD &= ~(1U<<pin); 
				break;
				case OUTPUT :DDRD |= (1U<<pin);
				break;
			}
		break ; 
		
	}
	
}
void DIO_write(PIN_t pin,PORT_t port,STATUS_t status)
{
	switch(port)
	{
		case PORT_A:
			switch(status)
			{
				case LOW :PORTA &= ~(1U<<pin);
				break;
				case HIGH :PORTA |= (1U<<pin);
				break;
			}
		break;
		case PORT_B:
			switch(status)
			{
				case LOW :PORTB &= ~(1U<<pin);
				break;
				case HIGH :PORTB |= (1U<<pin);
				break;
			}
		break ;
		case PORT_C:
			switch(status)
			{
				case LOW :PORTC &= ~(1U<<pin);
				break;
				case HIGH :PORTC |= (1U<<pin);
				break;
			}
		break ;
		case PORT_D:
			switch(status)
			{
				case LOW :PORTD &= ~(1U<<pin);
				break;
				case HIGH :PORTD |= (1U<<pin);
				break;
			}
		break ;
		
	}
	
}
STATUS_t DIO_read(PIN_t pin, PORT_t port)
{
	switch(port)
	{
		case PORT_A:	return((PINA&(1U<<pin))>>pin);
		break;
		case PORT_B:	return((PINB&(1U<<pin))>>pin);
		break ;
		case PORT_C:	return((PINC&(1U<<pin))>>pin);
		break ;
		case PORT_D:	return((PIND&(1U<<pin))>>pin);
		break ;
	}
}
void DIO_toggle(PIN_t pin,PORT_t port)
{
	switch(port)
	{
		case PORT_A:	PORTA ^= (1U<<pin);
		break;
		case PORT_B:	PORTB ^= (1U<<pin);
		break ;
		case PORT_C:	PORTC ^= (1U<<pin);
		break ;
		case PORT_D:	PORTD ^= (1U<<pin);
		break ;
		
	}
	
}