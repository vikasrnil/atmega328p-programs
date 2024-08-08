/*
 * uart receiver.c
 *
 * Created: 01-08-2024 11:45:41
 * Author : Vikas
 */ 

#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>


int main(void)
{
	PORTD = 0xFF;
	unsigned int ubrr = 103;
	
	UBRR0L= ubrr;
	UBRR0H= 0;
	
	UCSR0C = 0x06;
	
	UCSR0B=(1<<RXEN0);
	
	while(1){
		while (!(UCSR0A & (1<<RXC0)));
		
		switch(UDR0)
		{
			case 'A' :	DDRD  |= (1<<4);
						PORTD |= (1<<4);
						_delay_ms(10000);
						PORTD &= ~(1<<4);
						break;
			case 'B' : 	DDRD  |= (1<<5);
						PORTD |= (1<<5);
						_delay_ms(10000);
						PORTD &= ~(1<<5);
						break;
			
			default  :
						break;
			
		}
		
	}
	
}

