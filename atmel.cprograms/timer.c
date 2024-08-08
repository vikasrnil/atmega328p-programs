// 	/*
// 	 * timer.c
// 	 *
// 	 * Created: 31-07-2024 09:25:41
// 	 * Author : Vikas
// 	 */ 
// 

#include <avr/io.h>

void delay(){
	for(int i=0;i<1000;i++){
		TCNT0 = 10;
		TCCR0A = 0;
		TCCR0B |=(1<<CS00)|(1<<CS01);
		
		while ( (TIFR0 & (1<<TOV0)) ==0)
		{
		}
		TIFR0 |= (1<<TOV0);
		TCCR0B =0;
	}
	
	
}
 	
 
 	int main(void)
 	{

 		DDRD=0xFF;
 		while (1)
 		{
			PORTD=0xFF;
			delay();
			PORTD=0;
			delay();
			 
 		}
 		return 0;
 
 	}

