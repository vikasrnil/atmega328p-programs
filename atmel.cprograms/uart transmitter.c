/*
 * uart transmitter.c
 *
 * Created: 01-08-2024 11:11:27
 * Author : Vikas
 */ 

#include <avr/io.h>
#include <stdio.h>


int main(void)
{
	int i;
	unsigned int ubrr = 103;
	
	unsigned char data[] = "VIKAS";
	
	UBRR0L= ubrr;
	UBRR0H= 0;
	
	UCSR0C = 0x06;
	
	UCSR0B=(1<<TXEN0);
	
	while(1){
		i=0;
		while(data[i]!=0){
			while(!(UCSR0A & (1<<UDRE0)));
			UDR0=data[i];
			i++;
		}
		while(!(UCSR0A & (1<<UDRE0)));
		UDR0='\n';
	}
	
}