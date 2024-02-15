
#include <avr/io.h>
#include<util/delay.h>
#include <avr/interrupt.h>


ISR(TIMER0_OVF_vect)
{

	PORTA = 0x01; 

}

ISR(TIMER0_COMP_vect)
{
	PORTB ^= 0x01; 
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

    TIMSK |= (1<<OCIE0) | (1<<TOIE0) ;

    sei();

    while (1)

    {
       PORTA^= 0x01; 
	_delay_ms(5000);
	
    }

    return 0;
}
