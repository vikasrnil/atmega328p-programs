/*
 * LEDBLINK.c
 *
 * Created: 26-07-2024 11:33:15
 * Author : Vikas
 */ 

#include <avr/io.h>
void delay();

int main(void)
{
	DDRD=0xFF;
	
	while(1){
		PORTD=PORTD^(1<<4);
		delay();
	}
	
	return 0;
}

void delay(){
	TCNT0=0x03;
	TCCR0A=0x01;
	
	while((TIFR0&1)==0);
	TCCR0A=0;
	TIFR0=0x01;
}

