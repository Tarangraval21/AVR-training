/*
#include <avr/io.h>

#define F_CPU 8000000
#include <util/delay.h>


int main(void)
{
       DDRA = 0X07;     //0000 0011
        while (1)
        {
               // LED on/off    
#if 0
                PORTA = 0X01; // 0000 0001
                _delay_ms(1000);
                PORTA =  0X02; // //0000 0010
                _delay_ms(1000);
                PORTA = 0X04; // 0000 0001
                _delay_ms(1000);
                PORTA = 0X07; // 0000 0001
                _delay_ms(1000);
                PORTA = 0X0;
                _delay_ms(1000);
#else
                        // Switch iNput
                if ((PINA & 0x80)) //  PINA & 1000 000==0
                {
                        PORTA |= 0X01;
                }
                else
                {
                        PORTA = 0X00;
                }
#endif
        }
}
                                                          
                                                          
                                                          
                                                          */
  
#include <avr/io.h>
#include <util/delay.h>

int main() {

    PORTB = (1 << PB7) | (1 << PB6) |(1 << PB1) | (1 << PB0);  
    DDRB = (1 << DDB3) | (1 << DDB2) |(1 << DDB1) |(1 << DDB0);
    return 0;
}

/*
#include <avr/io.h>
#include <util/delay.h> // Include this for _NOP() and _delay_ms()

int main() {
    // Set Port B pins 0 and 1 high
    PORTB |= (1 << PB0) | (1 << PB1);

    // Set Port B pins 2 and 3 low
    PORTB &= ~((1 << PB2) | (1 << PB3));

    // Define Port B pins 4 to 7 as input with pull-ups enabled on pins 6 and 7
    PORTB |= (1 << PB6) | (1 << PB7); // Enable pull-ups on pins 6 and 7
    DDRB &= ~(0xF0); // Define pins 4 to 7 as input

    // Add a delay to ensure pull-ups are enabled before reading back values
    _delay_ms(1);

    // Read back the pin values
    uint8_t pinValues = PINB; // Read the pin values of Port B

    // Now pinValues holds the value representing the state of Port B pins.

    // Avoid compiler warnings for unused variable 'pinValues'
    (void)pinValues;

    return 0;
}
*/
