#include <avr/io.h>
 
#define F_CPU 1000000
#include <util/delay.h>
 
 
int main(void)
{
       DDRA = 0X07;     //0000 0011
        while (1)
        {
               // LED on/off    
#if 1 
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
