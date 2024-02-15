/*

#include "avr/io.h"
int main ( )
{
	DDRB |= (1<<3);			
	while (1)
	{
		OCR0 = 69;		
		TCCR0 = 0x3D;	    
		while ((TIFR&(1<<OCF0)) == 0);  
		TIFR = (1<<OCF0);
		OCR0 = 99;		
		TCCR0 = 0x2D;	   
		while ((TIFR&(1<<OCF0)) == 0); 
		TIFR = (1<<OCF0);
		}
}
*/
/*
//PROGRAM 1 : 

#include<avr/io.h>
#include<util/delay.h>
#include <avr/interrupt.h>
int count;
ISR(TIMER0_OVF_vect)
{	
	TCNT0=0x00;
	count ++;
	if(count ==5){
	PORTB ^= 0x01;
	count = 0;}
	
}
int main() 
{
	TIMSK=0x01;
	TCNT0=0x00;
	TCCR0 =0x05; // 000 0101
	sei();
	DDRA = 0x01;
	DDRB = 0x01; 
	while(1)
	{
		PORTA ^= 0X01;
		_delay_ms(1000);
	}
 
}
*/

/*

//PROGRAM 2:
#include <avr/io.h>

void T0delay()
{
	TCNT0 = 0xB2;                                        //	1 Tick = 1024 / 8MHz = 128us
	TCCR0 = (1<<CS02) | (1<<CS00);//1024 prescale 
	
	// for 10 ms delay require cycle = 10ms/128us = 78.125 =78  TCNTO = 256-78 = 178 = B2 in hex
	                                         
	while((TIFR&0x01)==0);  
	TCCR0 = 0;
	TIFR = 0x1;  
}

int main(void)
{
	DDRB = 0xFF;
	
    	while(1)  	
    	{
		PORTB=0x55;
		for(int i =0 ; i<100 ; i++){
		T0delay(); }
		PORTB=0xAA;
		for(int i =0 ; i<100 ; i++){
		T0delay();}
    	}
}





*/

//PROGRAM 3:

#include <avr/io.h>
#include<util/delay.h>
#include <avr/interrupt.h>
//volatile uint16_t timeElapsed = 0;

//ISR(TIMER0_COMPA_vect)
//{
//	TCNT0=0x00;
//    timeElapsed++;
//    if (timeElapsed >= 2000) // 2 seconds
//    {
//        PORTB ^= 0x01; // Toggle PORTB bit 0
//        timeElapsed = 0; // Reset the time elapsed
//    }
//}



ISR(TIMER0_OVF_vect)
{

	PORTA = 0x01; 

}

ISR(TIM0_COMPA_vect)
{
	PORTB = 0x01; 
	TCNT0=0x00;
}



int main()
{
    DDRA = 0x01;
    
    TCNT0=0x00;
    DDRB = 0x01;

    TCCR0 = 0x05;  

    //OCR0 = TIMER_COUNT_4S;
    OCR0 =195;

    TIMSK |= (1<<OCIE0);

    sei();

    while (1)

    {
       // PORTA^= 0x01; 
	_delay_ms(5000);
	
    }

    return 0;
}
//*/
