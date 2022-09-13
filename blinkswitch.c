/*****************************************************************************
* blinkswitch.c - This program is for blinking two LEDs, green and red when their respective switch is 
* pressed. Switch 3 controls the RED led, switch 5 controls the green GREEN and switch 7 when pressed,
* both LEDs will blink. If two buttons are pressed at the same time, no LEDs will blink.
* Revision
* Date          Author              Revision
* 02/27/2022    Khushkumar Jajoo    Writing the code
* 03/02/2022    Khushkumar Jajoo    Touching up the code and adding comments
* 03/01/2022    Khushkumar Jajoo    Running the code on arduino and testing it on the circuit

REFERENCE
* ECE 231 Spring 22, Lecture slides 7,8,9 from the professor, David McLaughlin
* ECE 231, Spring 22 - Blinkswitch.c source code from the professor, David McLaughlin
******************************************************************************/

#include <avr/io.h>
#include <util/delay.h>
#define DURATION 50

int main(void){
    DDRD = 1<<DDD4 | 1<<DDD6;     // D4 for red and D6 for green are outputs others are inputs
    PORTD = 1<<PORTD3 | 1<<PORTD5 | 1<<PORTD7 ;  // Set internal pullup resistor on D3, D5, D7

    // blink the LEDs
    while(1){
         
        if((!(PIND & (1<<PIND3))&&!(PIND & (1<<PIND5)))|| ((!(PIND & (1<<PIND3))&&!(PIND & (1<<PIND7)))) || ((!(PIND & (1<<PIND5))&&!(PIND & (1<<PIND7))))){ // if two switches are pressed at the same time then no LED will be blinked
            PORTD &= ~(1<<PORTD4); // turn off red LED
            PORTD &= ~(1<<PORTD6); // turn off green LED
            _delay_ms(DURATION);        
        }

        else if(!(PIND & (1<<PIND3))){ // if switch 3 is pressed
            _delay_ms(DURATION);  
            _delay_ms(DURATION);  
            PORTD ^= 1<<PORTD4;   // toggle red LED
        }
        else if(!(PIND & (1<<PIND5))){ // if switch 5 is pressed
            _delay_ms(DURATION);
            _delay_ms(DURATION);  
            PORTD ^= 1<<PORTD6;   // toggle green LED
            
        }
        else if(!(PIND & (1<<PIND7))){ // if switch 7 is pressed
            _delay_ms(DURATION);
            _delay_ms(DURATION);  
            PORTD ^= 1<<PORTD4;   // toggle red LED
            PORTD ^= 1<<PORTD6;   // and also toggle green LED
            
        }
       
        else{                      // if no switch is pressed
            PORTD &= ~(1<<PORTD4); // turn off red LED
            PORTD &= ~(1<<PORTD6); // turn off green LED
        }
    }
} 

