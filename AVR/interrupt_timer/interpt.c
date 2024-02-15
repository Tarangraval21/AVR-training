

#include<avr/io.h>
#include<util/delay.h>
#include <avr/interrupt.h>
ISR(INT0_vect)
{
	PORTA ^= 0x0F;
}

int main()
{
	int count=0;
DDRB = 0x07;
MCUCR = 0x00;
DDRA = 0x03;
DDRD = 0x04;
GICR = 1 << INT0;
SREG =	0x80; 
	while(1)
	{	
		if(count%5 == 0){
			PORTD = (0<<PD2);
			}
		PORTD = 0x04;
		PORTB=0x01;
		_delay_ms(1000);
		
		PORTB=0x00;
		_delay_ms(1000);
		
		count++;
	}
return 0;
}

/*

#include<avr/io.h>
#include<util/delay.h>
#include <avr/interrupt.h>
ISR(INT0_vect)
{
        PORTA = 0x0F;
	_delay_ms(3000);

	PORTA &= 0x00;
	_delay_ms(1000);
}

int main()
{
DDRB = 0x07;
DDRA = 0x03;
MCUCR = 0x00;
GICR = 1 << INT0;
SREG =  0x80;
DDRC = 0x80;

PORTC = 0x80;

while(1)
        {
	
                PORTB=0x01;
                _delay_ms(1000);

                PORTB=0x00;
                _delay_ms(1000);

        }
return 0;
}



*/
