/*
 * DIO.h
 *
 * Created: 9/4/2022 9:30:49 AM
 *  Author: khaled
 */ 

#ifndef DIO_H_
#define DIO_H_
#include "../../RegisterFile.h"

/************************************************************************/
/*						 Atmega 32 Ports                                */
/************************************************************************/
typedef enum{
	PORT_A,
	PORT_B,
	PORT_C,
	PORT_D
}PORT_t;
/************************************************************************/
/*				       Atmega 32 Pins directions                        */
/************************************************************************/
typedef enum{
	INPUT,
	OUTPUT
}DIR_t;

/************************************************************************/
/*				        	Atmega 32 Pins Numbers                      */
/************************************************************************/

typedef enum{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
}PIN_t;

/************************************************************************/
/*						    Atmega 32 Pins Status                       */
/************************************************************************/
typedef enum{
	LOW,
	HIGH
}STATUS_t;
/************************************************************************/
/*						    DIO Functions                               */
/************************************************************************/


/*
 * Function DIO_init
 * Desc     Function To Initialize a the direction of specific pin in a specific port  
 * Input    the Port and the Pin and the direction
 * Output   nothing
 */
void DIO_init(PIN_t , PORT_t ,DIR_t); 

/*
 * Function DIO_write
 * Desc     Function To Write to a pin either high or low
 * Input    the Port and the Pin and the pin status
 * Output   nothing
 */
void DIO_write(PIN_t,PORT_t,STATUS_t);


/*
 * Function DIO_read
 * Desc     Function To Read  a pin status in a specific port 
 * Input    the Port and the Pin
 * Output   the Pin status
 */
STATUS_t DIO_read(PIN_t , PORT_t); 

/*
 * Function DIO_toggle
 * Desc     Function To toggle the status of a pin in a specific port 
 * Input    the Port and the Pin 
 * Output   nothing
 */
void DIO_toggle(PIN_t,PORT_t); 



#endif /* DIO_H_ */