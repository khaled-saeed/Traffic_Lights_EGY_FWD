/*
 * Traffic_Lights.c
 *
 * Created: 9/11/2022 10:03:49 PM
 *  Author: khaled
 */ 

#include "Traffic_lights.h"
STATE_t Traffic_State; 
extern ButtonStatus INT0_Button ; 
fptr States[5]= {&CarGo,&PedestrianGo ,&BothYellow ,&Wait_5s ,&YellowBlinks };
void TrafficLights_init(void) 
{
		/* Initialize the Led Pins*/
	LED_init(CARS_RED,PORT_A);
	LED_init(CARS_GREEN,PORT_A);
	LED_init(CARS_YELLOW,PORT_A);
	LED_init(PEDESTRIAN_RED,PORT_A);
	LED_init(PEDESTRIAN_GREEN,PORT_A);
	LED_init(PEDESTRIAN_YELLOW,PORT_A);
	/* Initialize the Button Pin*/
	BUTTON_init(PEDESTRIAN_BUTTON,PORT_D); 
	/* Initialize External Interrupt*/
	EX_INT0_init(RISING_EDGE);
	/* Initialize Timer0 in normal mode*/
	Timer0_InitNormal_Polling();
	/* Set the callback function for the interrupt*/
	setCallBackFunc_INT0(&INT0_Handler); 
	Traffic_State.activeState = Car_GO;
	Traffic_State.PreviousState = Car_GO ; 
	sei(); 
}
void TrafficLights_app(void) 
{
	(*States[Traffic_State.activeState])();
	switch(Traffic_State.activeState)
	{
		case Car_GO:
				if (INT0_Button == BTN_PRESSED)
				{
					Traffic_State.activeState = Yellow_Blinks ;
					Traffic_State.PreviousState = Car_GO; 
					INT0_Button = BTN_UNPRESSED;
				}
				else
				{
					Traffic_State.activeState = Both_Yellow ;
					Traffic_State.PreviousState = Car_GO; 
				}
		break;
		case Pedestrian_Go:
				if (INT0_Button == BTN_PRESSED)
				{
					Traffic_State.activeState = Hold_5s ; 
					Traffic_State.PreviousState = Pedestrian_Go; 
					INT0_Button = BTN_UNPRESSED;
				}
				else
				{
					Traffic_State.activeState = Both_Yellow ;
					Traffic_State.PreviousState = Pedestrian_Go; 
				}
		break;
		case Both_Yellow:
				if (INT0_Button == BTN_PRESSED)
				{
					Traffic_State.activeState = Yellow_Blinks ;
					Traffic_State.PreviousState = Both_Yellow; 
					INT0_Button = BTN_UNPRESSED;
				}
				else
				{
					if (Traffic_State.PreviousState == Car_GO)
					{
						Traffic_State.activeState= Pedestrian_Go ;
						Traffic_State.PreviousState = Both_Yellow;  
					}
					else
					{
						Traffic_State.activeState = Car_GO ;
						Traffic_State.PreviousState = Both_Yellow;  
					}
				}
		break;
		case Hold_5s:
					Traffic_State.activeState = Yellow_Blinks ; 
					Traffic_State.PreviousState = Hold_5s;
		break;
		case Yellow_Blinks:
				if (Traffic_State.PreviousState == Hold_5s)
				{
					Traffic_State.activeState = Car_GO ; 
					Traffic_State.PreviousState = Yellow_Blinks;
				}
				else
				{
					Traffic_State.activeState = Pedestrian_Go ; 
					Traffic_State.PreviousState = Yellow_Blinks;
				}
		break;
	}
}
void CarGo(void)
{
	INT0_Button = BTN_UNPRESSED; 
	LED_on(PEDESTRIAN_RED,PORT_A); 
	LED_on(CARS_GREEN,PORT_A);
	LED_off(CARS_RED,PORT_A);
	LED_off(CARS_YELLOW,PORT_A);
	LED_off(PEDESTRIAN_GREEN,PORT_A);
	LED_off(PEDESTRIAN_YELLOW,PORT_A);
	Timer0_Delay_ms(5000);
}
void PedestrianGo(void)
{
	LED_on(PEDESTRIAN_GREEN,PORT_A);
	LED_on(CARS_RED,PORT_A);
	LED_off(CARS_GREEN,PORT_A);
	LED_off(CARS_YELLOW,PORT_A);
	LED_off(PEDESTRIAN_RED,PORT_A);
	LED_off(PEDESTRIAN_YELLOW,PORT_A);
	Timer0_Delay_ms(5000);
}
void BothYellow(void)
{
	LED_on(PEDESTRIAN_YELLOW,PORT_A);
	LED_on(CARS_YELLOW,PORT_A);
	LED_off(CARS_GREEN,PORT_A);
	LED_off(CARS_RED,PORT_A);
	LED_off(PEDESTRIAN_RED,PORT_A);
	LED_off(PEDESTRIAN_GREEN,PORT_A);
	Timer0_Delay_ms(5000);
}
void Wait_5s(void)
{
	Timer0_Delay_ms(5000); 
}
void YellowBlinks(void)
{
	LED_off(CARS_GREEN,PORT_A);
	LED_off(CARS_RED,PORT_A);
	LED_off(PEDESTRIAN_RED,PORT_A);
	LED_off(PEDESTRIAN_GREEN,PORT_A);
	int i = 5 ; 
	while(i--)
	{
		blinkYellow();
	}

	
	

}
void blinkYellow(void)
{
	Timer0_InitNormal_Polling();
	LED_toggle(PEDESTRIAN_YELLOW,PORT_A);	
	LED_toggle(CARS_YELLOW,PORT_A);	
	Timer0_Delay_ms(500);
	LED_toggle(PEDESTRIAN_YELLOW,PORT_A);
	LED_toggle(CARS_YELLOW,PORT_A);
	Timer0_Delay_ms(500);
}