#include "avr/io.h"
int main ( )
{
	DDRB = DDRB|(1<<3);	/* PB3 (OC0) as output */	
	TCCR0 = 0x19;		/* CTC mode, toggle on compare match,
                      		clk- no pre-scaling */ 
	OCR0 = 200;  		/* compare value */
	while (1);
}
