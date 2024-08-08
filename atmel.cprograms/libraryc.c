/*
 * mylib.c
 *
 * Created: 01-08-2024 23:47:41
 * Author : Vikas
 */ 

#include <avr/io.h>
#include "library.h"



/* Replace with your library code */
int delay(void){
	for(int i=0;i<1000;i++){
		TCNT0 = 10;
		TCCR0A = 0;
		TCCR0B |=(1<<CS00)|(1<<CS01);
		
		while ( (TIFR0 & (1<<TOV0)) ==0);
		TIFR0 |= (1<<TOV0);
		TCCR0B =0;
	}
	
	return 0;
}

void uartinit(){
	unsigned int ubrr = 103;
	UBRR0L= ubrr;
	UBRR0H= 0;
	
	UCSR0C = 0x06;
	
	UCSR0B=(1<<TXEN0|1<<RXEN0);
}

void transmit(char*s){
	while(*s>0){
		uart_char_trans(*s++);
	}
}

void uart_char_trans(char c){
	while(!(UCSR0A & (1<<UDRE0)));
	UDR0=c;
}

char uart_char_rec(){
	while (!(UCSR0A & (1<<RXC0)));
	return UDR0;
}

float chartofloat(char* str){
	
	// 		unsigned int ubrr = 103;
	// 		UBRR0L= ubrr;
	// 		UBRR0H= 0;
	// 		UCSR0C = 0x06;
	// 		UCSR0B=(1<<TXEN0);

	float result = 0.0;
	float decimal_place = 0.1;

	while (*str !=0&& *str!='.') {
		result = result * 10 + (*str - '0');
		str++;
	}

	if (*str == '.') {
		str++;
		while (*str!=0) {
			result += (*str - '0') * decimal_place;
			decimal_place *= 0.1;
			str++;
		}
	}

	return result;
}

 
// 	 void glow(){
// 		 switch(UDR0)
// 		 {
// 			 case 'A' :	DDRD  |= (1<<4);
// 			 PORTD |= (1<<4);
// 			 break;
// 			 case 'B' : 	DDRD  |= (1<<5);
// 			 PORTD |= (1<<5);
// 			 break;
// 			 default  :
// 			 break;
// 		 
// 		 }
// 	 }



