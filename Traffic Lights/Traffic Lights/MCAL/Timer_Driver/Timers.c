/*
 * Timers.c
 *
 * Created: 9/5/2022 8:40:10 PM
 *  Author: khaled
 */ 
#include "Timers.h"
// Comon Functions 
uint32_t NO_ofOverFlows;
extern uint8_t  Stop_Delay; 
void Timer0_setCallBackFunc(fptr_t callBackFunc)
{
	Timer0_callBack_fptr = callBackFunc ;
}
static void Timer0_Start(CLK_SOURCE_t clkSrc)
{
	TCCR0 |= (clkSrc<<CS00) ;
}
void Timer0_Stop()
{
	
	TCCR0 &=~(3U<<COM00);
	TCCR0 &= ~(7<<CS00) ;
}
void Timer01_PrescalerReset()
{
	TCCR0 &= ~(1U<<CS00) ; 
}






// Timer 0 in Normal Mode
void Timer0_InitNormal_Polling()
{
	TCCR0 |= (NORMAL_MODE<<WGM00);		//select Normal Mode 

}
void Timer0_InitNormal_Interrupt(InterruptType_t interrupt)
{
	TCCR0 |= (NORMAL_MODE<<WGM00);		//select Normal Mode
	TIMSK |=(interrupt<<TOIE0);			// enable the interrpt either compare match or overflow 
}

void Timer0_Delay_ms(uint32_t ms)
{
	/*	for 1 ms  we use no prescaler then T tick  = 1 micro sec  as CLK = 1 MHz 
		then 1 overflow takes 256 tick  and 256 micro seconds 
		to achieve 1 ms we get 4 overflows and initial value of 6  
	*/
	uint8_t NoOfOverFlows = 0 ; 
	TCNT0 = 6 ;									// initial value 
	Timer0_Start(InternalCLK_NoPrescaling);		// start Timer0 with no prescaling 
	while(ms-- && !Stop_Delay)
	{
		while(NoOfOverFlows <4)
		{
			while((TIFR&(1U<<TOV0)>>TOV0 ) != 1);
			NoOfOverFlows++ ; 
			TIFR |= (1U<<TOV0); 
		}
		NoOfOverFlows = 0 ; 
	}
	Stop_Delay = 0 ; 
	Timer0_Stop(); 
}
void Timer0_Delay_micro(uint32_t micro)
{
	int NoOfOverFlows = (micro/256 ) +1;
	TCNT0 = 0 ;
	Timer0_Start(InternalCLK_NoPrescaling);
	while(NoOfOverFlows--)
	{
		while((TIFR&(1U<<TOV0)>>TOV0) != 1); 
		TIFR |= (1U<<TOV0);
	}
	Timer0_Stop(); 
}


void Timer0_NormalMode_Handler(void)
{
	static volatile  uint32_t NoOfOverFlows = 0 ; 
	if (NoOfOverFlows++>= NO_ofOverFlows )
	{
		LED_toggle(PIN2,PORT_A); 
		NoOfOverFlows = 0 ; 
	}
	
}
void Timer0_SetValue_ms(uint32_t ms)
{
	float TickTime =(float)1/F_CPU;
	NO_ofOverFlows = (uint32_t)(ms/(256*TickTime*1000)) +1;
	TCNT0 = (uint8_t)((NO_ofOverFlows*256) - (ms*1000))/NO_ofOverFlows; 
	Timer0_Start(InternalCLK_NoPrescaling);
}
void Timer0_SetValue_micro(uint32_t micro)
{
	  if(micro < 256)
	  {
		  TCNT0 = 256 - micro ; 
		  Timer0_Start(InternalCLK_NoPrescaling);
		  NO_ofOverFlows= 0 ; 
	  } 
	  else
	  {
		   NO_ofOverFlows= (micro/256) +1 ; 
		   TCNT0 = (uint8_t)((NO_ofOverFlows*256) - micro)/NO_ofOverFlows;
	  }
	  Timer0_Start(InternalCLK_NoPrescaling);
}





// Timer 0 in Clear Timer at Compare Mode       This mode is used to generate square waves with different frequancies 

void Timer0_CTC_init(OnCompareMode_t mode,uint32_t freq)
{
	uint16_t prescalerarr[5] = {1,8,64,256,1024} ; 
	uint16_t prescaler = prescalerarr[0];  
	uint32_t intialVal,i=1 ; 
	TCCR0 |= (1U<<WGM01);				// select the CTC mode 
	TCCR0 |= (1U<<FOC0) ;				// force output compare
	TCCR0 |=(mode<<COM00);				// what happens  on compare for non PWM mode 
	intialVal = F_CPU/(2*freq*prescaler); 
	while (intialVal > 255)
	{
		prescaler = prescalerarr[i];  
		intialVal = F_CPU/(2*freq*prescaler);  // as two timer cycles are needed to do one output cycle 
		i++ ; 
	}
	OCR0 = intialVal ; 
	if (prescaler == 1)
	{
		TCCR0 |=(InternalCLK_NoPrescaling<<CS00);
	}
	else if (prescaler == 8)
	{
		TCCR0 |=(InternalCLK_8Prescaling<<CS00);
	}
	else if (prescaler == 64)
	{
		TCCR0 |=(InternalCLK_64Prescaling<<CS00);
	}
	else if (prescaler == 256)
	{
		TCCR0 |=(InternalCLK_256Prescaling<<CS00);
	}
	else if (prescaler == 1024)
	{
		TCCR0 |=(InternalCLK_1024Prescaling<<CS00);
	}
}


// Timer 0 in Fast PWM Mode
void Timer0_FastPWM_init(OnComparePWM_t onCompare,uint8_t dutyCycle)
{
	TCCR0 &=  ~(1U<<FOC0); 
	TCCR0 |= (1U<<WGM00);
	TCCR0 |= (1U<<WGM01);
	TCCR0 |=(onCompare<<COM00);
	OCR0  = dutyCycle * 255 /100 ; 
	TCCR0 |=(InternalCLK_64Prescaling<<CS00); 
}






// Timer 0 in Phase Correct PWM Mode
void Timer0_PhaseCorrect_init(OnComparePWM_t onCompare,uint8_t dutyCycle)
{
	TCCR0 &=  ~(1U<<FOC0);
	TCCR0 |= (1U<<WGM00);
	TCCR0 |=(onCompare<<COM00);
	OCR0  = dutyCycle * 255 /100 ;
	TCCR0 |=(InternalCLK_64Prescaling<<CS00); 
}






// Timer 0 in Event Count Mode
void Timer0_EventCount_init()
{
	DDRB &= ~(1U<<0) ; 
	TIMSK |= (3U<<0); 
	OCR0 = 10;
	TCNT0 = 0 ; 
	//TCCR0 |= (1U<<WGM01);				// select the CTC mode 
	TCCR0 |=(7U<<CS00);			// external clock at T0 
	
}

void Timer0_Counter_Handler(void)
{
	LED_toggle(PIN3,PORT_B);
	TCNT0 = 0 ; 
}

