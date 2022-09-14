/*
 * Traffic_lights.h
 *
 * Created: 9/14/2022 3:36:30 PM
 *  Author: khale
 */ 


#ifndef TRAFFIC_LIGHTS_H_
#define TRAFFIC_LIGHTS_H_
#include "../HAL/LED_Driver/LED.h"
#include "../HAL/Button_Driver/Button.h"
#include "../MCAL/Timer_Driver/Timers.h"
#include "../MCAL/Interrupts_Driver/Interrupt.h"
#define  PEDESTRIAN_BUTTON	2

enum Leds{
	CARS_RED,
	CARS_YELLOW,
	CARS_GREEN,
	PEDESTRIAN_RED,
	PEDESTRIAN_YELLOW,
	PEDESTRIAN_GREEN
	};
typedef enum {
	Car_GO,
	Pedestrian_Go,
	Both_Yellow,
	Hold_5s,
	Yellow_Blinks
}TrafficLightsStates_t;
typedef struct{
	TrafficLightsStates_t activeState ;
	TrafficLightsStates_t PreviousState ;
}STATE_t;

typedef void(*fptr)(void); 
void TrafficLights_init(void) ;
void TrafficLights_app(void) ; 
void CarGo(void);
void PedestrianGo(void);
void BothYellow(void);
void Wait_5s(void);
void YellowBlinks(void);
void blinkYellow(void);
#endif /* TRAFFIC_LIGHTS_H_ */