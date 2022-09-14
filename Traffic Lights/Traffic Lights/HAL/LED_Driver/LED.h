/*
 * LED.h
 *
 * Created: 9/4/2022 10:59:09 AM
 *  Author: khaled
 */ 

#ifndef LED_H_
#define LED_H_


#include "../DIO_Driver/DIO.h"
#include "../../MCAL/Timer_Driver/Timers.h"
//#include "../../Delay_Driver/Delay.h"
/************************************************************************/
/*				         Control LED Functions                          */
/************************************************************************/

/*
 * Function LED_init
 * Desc     Function To Initialize a led 
 * Input    the Port and the Pin 
 * Output   nothing
 */
void LED_init(PIN_t,PORT_t); 

/*
 * Function LED_on
 * Desc     Function To set a led on
 * Input    the Port and the Pin 
 * Output   nothing
 */
void LED_on(PIN_t,PORT_t); 

/*
 * Function LED_off
 * Desc     Function To set a led off
 * Input    the Port and the Pin 
 * Output   nothing
 */
void LED_off(PIN_t,PORT_t); 

/*
 * Function LED_toggle
 * Desc     Function To toggle a led 
 * Input    the Port and the Pin 
 * Output   nothing
 */
void LED_toggle(PIN_t,PORT_t);

/*
 * Function LED_blink
 * Desc     Function To blink a led
 * Input    Port and the Pin and the between blinks
 * Output   nothing
 */
void LED_blink(PIN_t,PORT_t,uint32_t);  
#endif /* LED_H_ */