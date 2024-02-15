#include <avr/io.h>
#include <avr/interrupt.h>
#include<util/delay.h>
/* timer0 overflow interrupt */
ISR(TIMER0_OVF_vect)
{
	PORTB ^=0x01;		/* Toggle PORTB */
	TCNT0 = 0x00;
}


int main( void )
{
	DDRB=0xFF;  		/* Make port B as output */
	DDRA = 0x01;
	sei();
	TIMSK=(1<<TOIE0);  	/* Enable Timer0 overflow interrupts */
		
	TCNT0 = 0x00;  		/* Load TCNT0, count for 10ms*/
	TCCR0 = (1<<CS02) | (1<<CS00); /* Start timer0 with /1024 prescaler*/
	while(1){
		PORTA ^= 0x01;
		_delay_ms(1000);}
}
