/*

//
#include<avr/io.h>
#include <util/delay.h>
#define LED PD4
int main()
{
	DDRD |= (1<<LED) ;         //configure led as outpout
	TCCR1B = (1<<CS10) | (1<<CS12); //set the pre-scalar as 1024
	OCR1A = 1562; 	   //100ms delay
	TCNT1 = 0;
	while(1)
	{
		//If flag is set toggle the led
		while((TIFR & (1<<OCF1A)) == 0);// wait till the timer overflow flag is SET
		PORTD ^= (1<< LED);
		TCNT1 = 0;
		TIFR |= (1<<OCF1A) ; //clear timer1 overflow flag
	}
}
*/

#include <avr/io.h>
#include<util/delay.h>
#include <avr/interrupt.h>
void func()
{
        PORTB^=0x01;
}
int main()
{
    int count =0;
    DDRA = 0x01;

    TCNT0=0x00;
    DDRB = 0x01;

    TCCR0 = 0x05;

    //OCR0 = TIMER_COUNT_4S;
    OCR0 =255;

    TIMSK |= (1<<OCIE0);

    sei();

    while (1)

    {
	if (TIFR & 0x02){
		count++;
		if(count==10){
			func();
			count = 0;
			}}

        PORTA^= 0x01;
        _delay_ms(2000);

    }

    return 0;
}

