/*
 * IncFile1.h
 *
 * Created: 9/3/2022 12:49:11 PM
 *  Author: khaled
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_
#include <stdint.h>
/***************************************************************************************************************************
*												ATMEGA32A Register File                                                    *
***************************************************************************************************************************/

/***************************************************************************************************************************
*												     GPIO Registers                                                        *
***************************************************************************************************************************/


// PORT A Registers 
#define DDRA	(*((volatile uint8_t*)(0x3A)))
#define PORTA	(*((volatile uint8_t*)(0x3B)))
#define PINA	(*((volatile uint8_t*)(0x39)))

// PORT B Registers 
#define DDRB	(*((volatile uint8_t*)(0x37)))
#define PORTB	(*((volatile uint8_t*)(0x38)))
#define PINB	(*((volatile uint8_t*)(0x36)))

// PORT C Registers 
#define DDRC	(*((volatile uint8_t*)(0x34)))
#define PORTC	(*((volatile uint8_t*)(0x35)))
#define PINC	(*((volatile uint8_t*)(0x33)))

// PORT D Registers 
#define DDRD	(*((volatile uint8_t*)(0x31)))
#define PORTD	(*((volatile uint8_t*)(0x32)))
#define PIND	(*((volatile uint8_t*)(0x30)))


/***************************************************************************************************************************
*												     Timers Registers                                                      *
***************************************************************************************************************************/

// Timer 0 
#define TCCR0	(*((volatile uint8_t*)(0x53)))
#define TCNT0	(*((volatile uint8_t*)(0x52)))
#define TIMSK	(*((volatile uint8_t*)(0x59)))
#define TIFR	(*((volatile uint8_t*)(0x58)))
#define SFIOR	(*((volatile uint8_t*)(0x50)))
#define OCR0	(*((volatile uint8_t*)(0x5C)))


//Timer 1 
#define TCCR1A	(*((volatile uint8_t*)(0x4F)))
#define TCCR1B	(*((volatile uint8_t*)(0x4E)))
#define TCNT1L	(*((volatile uint8_t*)(0x4C)))
#define TCNT1H	(*((volatile uint8_t*)(0x4D)))
#define OCR1AH	(*((volatile uint8_t*)(0x4B)))
#define OCR1AL	(*((volatile uint8_t*)(0x4A)))
#define OCR1BH	(*((volatile uint8_t*)(0x49)))
#define OCR1BL	(*((volatile uint8_t*)(0x48)))
#define ICR1L	(*((volatile uint8_t*)(0x46)))
#define ICR1H	(*((volatile uint8_t*)(0x47)))

//Timer 2
#define TCCR2	(*((volatile uint8_t*)(0x45)))
#define TCNT2	(*((volatile uint8_t*)(0x44)))
#define OCR2	(*((volatile uint8_t*)(0x43)))
#define ASSR	(*((volatile uint8_t*)(0x42)))


/***************************************************************************************************************************
*												     Interrupts Registers                                                  *
***************************************************************************************************************************/

#define MCUCR	(*((volatile uint8_t*)(0x55)))
#define MCUCSR	(*((volatile uint8_t*)(0x54)))
#define GICR	(*((volatile uint8_t*)(0x5B)))
#define GIFR	(*((volatile uint8_t*)(0x5A)))




/***************************************************************************************************************************
*												     ADC Registers                                                         *
****************************************************************************************************************************/

#define ADMUX	(*((volatile uint8_t*)(0x27)))
#define ADCSRA	(*((volatile uint8_t*)(0x26)))
#define ADCL	(*((volatile uint8_t*)(0x24)))
#define ADC		(*((volatile uint8_t*)(0x24)))
#define ADCH	(*((volatile uint8_t*)(0x25)))
#define SFIOR	(*((volatile uint8_t*)(0x50)))



#endif /* INCFILE1_H_ */