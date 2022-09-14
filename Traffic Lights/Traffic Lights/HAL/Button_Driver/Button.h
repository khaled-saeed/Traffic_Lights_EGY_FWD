/*
 * Button.h
 *
 * Created: 9/4/2022 12:12:43 PM
 *  Author: khaled 
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
#include "../DIO_Driver/DIO.h"
/************************************************************************/
/*				              Button Status                             */
/************************************************************************/
typedef enum {
	UNPRESSED,
	PRESSED
	}ButtonStatus_t;

/************************************************************************/
/*				               Button Type                              */
/************************************************************************/
typedef enum {
	ACTIVE_LOW,
	ACTIVE_HIGH
	}ActiveStatus_t;

/************************************************************************/
/*				         Button Control Functions                       */
/************************************************************************/

/* 
 * Function BUTTON_init
 * Desc     initialize a pin as a button
 * Input    pin number and port
 * Output   none
 */
void BUTTON_init(PIN_t ,PORT_t); 


/* 
 * Function BUTTON_read
 * Desc     Function To read the status of a button 
 * Input    pin number and the port
 * Output   the button status
 */
ButtonStatus_t BUTTON_read(PIN_t,PORT_t); 




#endif /* BUTTON_H_ */