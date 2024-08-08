/*
 * pwm.c
 *
 * Created: 30-07-2024 13:07:27
 * Author : Vikas
 */

#include <avr/io.h>
#include <util/delay.h>


// 	  int main(void)
// 	  {
// 		  DDRD |=1<<3;
// 		  PORTD|=1<<3;
// 		  OCR0A=0xBF;
// 		  TCCR0A=0x83;
// 		  TCCR0B=0x01;
// 		  while(1);
// 		  return 0;
// 	  
// 	}

int main(void)
{
	DDRD |= (1 << 6);
	
// 		while(1){
// 		
// 				OCR0A =255 ;
// 				TCCR0A |= (1 << COM0A1);
// 				TCCR0A |= (1 << WGM01) | (1 << WGM00);
// 				TCCR0B |= (1 << CS00);
// 			
// 				_delay_ms(10000);
// 		
// 				OCR0A =50 ;
// 				TCCR0A |= (1 << COM0A1);
// 				TCCR0A |= (1 << WGM01) | (1 << WGM00);
// 				TCCR0B |= (1 << CS00);
// 			
// 				_delay_ms(10000);
// 	
// 		}
	
		int z;
		
		for(z=0;z<=255;z+=5){
			OCR0A =z;
			_delay_ms(1000);
			TCCR0A |= (1 << COM0A1);
			TCCR0A |= (1 << WGM01) | (1 << WGM00);
			TCCR0B |= (1 << CS00);
		}
}


