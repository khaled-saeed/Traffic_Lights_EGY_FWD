/*
 * Interrupt.c
 *
 * Created: 9/6/2022 1:36:51 PM
 *  Author: khaled
 */ 
#include "Interrupt.h"
#include "../../HAL/DIO_Driver/DIO.h"
ButtonStatus INT0_Button = BTN_UNPRESSED ;
uint8_t Stop_Delay = 0 ; 
void EX_INT0_init(SenseControl_t IntSrc) 
{
	DDRD &= ~(1U<<2); 
	MCUCR |=(IntSrc<<ISC00); // setting the interrupt trigger source 
	GICR |= (1U<<INT0_EN);	// enable interrupt 
}

void EX_INT1_init(SenseControl_t IntSrc) 
{
	DDRD &= ~(1U<<3); 
	MCUCR |=(IntSrc<<ISC10);	// setting the interrupt trigger source 
	GICR |= (1U<<INT1_EN);	// enable interrupt 
}
void EX_INT2_init(INT2_SenseControl_t IntSrc) 
{
	DDRB &= ~(1U<<2); 
	MCUCSR |=(IntSrc<<ISC2);	// setting the interrupt trigger source 
	GICR |= (1U<<INT2_EN);	// enable interrupt 
}
void setCallBackFunc_INT0(CallBackFpt_t callBackFunction)
{
	CallBackFuncINT0_ptr = callBackFunction ; 
}
void setCallBackFunc_INT1(CallBackFpt_t callBackFunction)
{
	CallBackFuncINT1_ptr = callBackFunction ; 
}
void setCallBackFunc_INT2(CallBackFpt_t callBackFunction)
{
	CallBackFuncINT2_ptr = callBackFunction ; 
}

void INT0_Handler(void)
{
	INT0_Button = BTN_PRESSED ; 
	Stop_Delay = 1 ; 
}

void INT1_Handler(void)
{
	LED_toggle(PIN1,PORT_A);
}

void INT2_Handler(void)
{
	LED_toggle(PIN2,PORT_A);
}