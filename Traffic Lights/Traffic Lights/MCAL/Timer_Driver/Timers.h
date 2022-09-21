/*
 * Timers.h
 *
 * Created: 9/5/2022 8:40:26 PM
 *  Author: khaled
 */ 


#ifndef TIMERS_H_
#define TIMERS_H_
#ifndef F_CPU
#define  F_CPU 1000000U
#endif
#include "../../RegisterFile.h"
#include "../../HAL/LED_Driver/LED.h"

#include <stdbool.h>

//#include "../Delay_Driver/Delay.h"
/************************************************************************/
/*							 Pins definitions                           */
/************************************************************************/
#define  FOC0				7 
#define  WGM00				6
#define  COM01				5
#define  COM00				4
#define  WGM01				3
#define  CS02				2
#define  CS01				1
#define  CS00				0
#define  OCIE0				1
#define  TOIE0				0
#define	 PSR10				0
#define	 TOV0				0
#define	 OCF0				1


#define  FOC2				7
#define  WGM20				6
#define  COM21				5
#define  COM20				4
#define  WGM21				3
#define  CS22				2
#define  CS21				1
#define  CS20				0
#define  OCIE2				7
#define  TOIE2				6
#define	 PSR				1
#define	 TOV2				6
#define	 OCF2				7
/************************************************************************/
/*							 Timer Modes                                */
/************************************************************************/
typedef enum{
	NORMAL_MODE,
	PHASECORRECT_MODE,
	CTC_MODE,
	FASTPWM_MODE
	}TimerMode_t;

/************************************************************************/
/*		    	      On Compare Action  for CTC Mode                   */
/************************************************************************/
typedef enum {
	DISCONNECTED,
	TOGGLEonCOMPARE,
	CLEARonCOMPARE,
	SETonCompare
	}OnCompareMode_t;
/************************************************************************/
/*		    	      On Compare Action  for PWM Mode                   */
/************************************************************************/
typedef enum {
	DISCONNEC,
	CLEARatCOMPARE = 2,
	SETatCompare
}OnComparePWM_t;
/************************************************************************/
/*		    	           Selecting The Prscaler                       */
/************************************************************************/
typedef enum{
	NO_CLOCK,						// Stop the timer / counter 
	InternalCLK_NoPrescaling,		// using the internal clk 
	InternalCLK_8Prescaling,		// using 8 as prescaling then the Timer_CLK = CPU_CLK/8 
	InternalCLK_64Prescaling,		// using 64 as prescaling then the Timer_CLK = CPU_CLK/64 
	InternalCLK_256Prescaling,		// using 256 as prescaling then the Timer_CLK = CPU_CLK/256 
	InternalCLK_1024Prescaling,		// using 1024 as prescaling then the Timer_CLK = CPU_CLK/1024 
	ExternalCLk_OnFallingEdge,		// using T0 as External CLK source 
	ExternalCLK_OnRisingEdge		// using T0 as External CLK source 
}CLK_SOURCE_t;
/************************************************************************/
/*		    	      Selecting Te Iterrupt Type                        */
/************************************************************************/
typedef enum{
	OVERFLOW = 1,
	COMPARE_MATCH
}InterruptType_t ;
/************************************************************************/
/*		    			  Timer 0 Normal Mode	     	                */
/************************************************************************/
typedef void(*fptr_t)(void); 
fptr_t Timer0_callBack_fptr ;								// pointer For Callback Function 
fptr_t Timer2_callBack_fptr ;								// pointer For Callback Function


/*
 * Function Timer0_Stop
 * Desc     Function To Stop the Timer 
 * Input    nothing
 * Output   nothing
 */
void Timer0_Stop();



/*
 * Function Timer0_InitNormal_Polling
 * Desc     Function To Initialize Timer0 in normal Mode and Polling  
 * Input    nothing
 * Output   nothing
 */
void Timer0_InitNormal_Polling();



/*
 * Function Timer0_InitNormal_Interrupt
 * Desc     Function To Initialize Timer0 in normal Mode With Interrupts
 * Input    interrupt Type
 * Output   nothing
 */
void Timer0_InitNormal_Interrupt(InterruptType_t);




/*
 * Function Timer0_SetValue_ms
 * Desc     Function To set Timer 0 for a Certain Time in milliseconds , used only in interrupt mode
 * Input    Time in milliseconds
 * Output   nothing
 */
void Timer0_SetValue_ms(uint32_t);


/*
 * Function Timer0_SetValue_micro
 * Desc     Function To set Timer 0 for a Certain Time in microSeconds , used only in interrupt mode
 * Input    Time in  microSeconds
 * Output   nothing
 */
void Timer0_SetValue_micro(uint32_t); 


/*
 * Function Timer0_Delay_ms
 * Desc     Function To set a delay using Timer 0 in milliseconds
 * Input    Time in  milliseconds
 * Output   nothing
 */
void Timer0_Delay_ms(uint32_t ms);



/*
 * Function Timer0_Delay_micro
 * Desc     Function To set a delay using Timer 0 in microSeconds
 * Input    Time in  microSeconds
 * Output   nothing
 */
void Timer0_Delay_micro(uint32_t micro);


/*
 * Function Timer0_setCallBackFunc
 * Desc     Function used to set the callback function for the interrupt ISR 
 * Input    nothing
 * Output   nothing
 */
void Timer0_setCallBackFunc(fptr_t);


/*
 * Function Timer01_PrescalerReset
 * Desc     Function To reset the timer 0 prescaler 
 * Input    nothing
 * Output   nothing
 */
void Timer01_PrescalerReset(); 


/*
 * Function Timer0_NormalMode_Handler
 * Desc     The Timer 0 Interrupt ISR Handler 
 * Input    nothing
 * Output   nothing
 */
void Timer0_NormalMode_Handler(void);

/************************************************************************/
/*		    			    Timer 0 CTC Mode	     	                */
/************************************************************************/



/*
 * Function Timer0_CTC_init
 * Desc     Function To set the Timer 0 in CTC mode to create a square wave with a specific frequency 
 * Input    the Action at compare and the frequency of the generated square wave
 * Output   nothing
 */
void Timer0_CTC_init(OnCompareMode_t,uint32_t );


/************************************************************************/
/*		    			  Timer 0 Fast PWM Mode	     	                */
/************************************************************************/

/*
 * Function Timer0_FastPWM_init
 * Desc     Function To set the Timer 0 in Fast PWM mode to create a square wave with a specific duty cycle
 * Input     the Action at compare and the duty cycle of the generated square wave 
 * Output   nothing
 */
void Timer0_FastPWM_init(OnComparePWM_t onCompare,uint8_t dutyCycle);


/*
 * Function Timer0_PhaseCorrect_init
 * Desc     Function To set the Timer 0 in Phase Correct PWM mode to create a square wave with a specific duty cycle
 * Input    the Action at compare and the duty cycle of the generated square wave 
 * Output   nothing
 */
void Timer0_PhaseCorrect_init(OnComparePWM_t onCompare,uint8_t dutyCycle);


/*
 * Function Timer0_EventCount_init
 * Desc     Function To set the Timer 0 event counting  mode , 
 * Input    nothing
 * Output   nothing
 */
void Timer0_EventCount_init();



/*
 * Function Timer0_Counter_Handler
 * Desc     Function To handle the ISR of counter mode interrupt
 * Input    nothing
 * Output   nothing
 */
void Timer0_Counter_Handler(void);


/************************************************************************/
/*					             Timer 2                                */
/************************************************************************/
 void Timer2_Start(CLK_SOURCE_t clkSrc);
 void Timer2_Stop();
void Timer2_InitNormal_Polling();
void Timer2_InitNormal_Interrupt(InterruptType_t interrupt);
void Timer2_SetValue_ms(uint32_t ms);
void Timer2_NormalMode_Handler(void);
void Timer2_setCallBackFunc(fptr_t callBackFunc);


#endif /* TIMERS_H_ */