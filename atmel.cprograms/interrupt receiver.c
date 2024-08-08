/*
 * interrupt receiver.c
 *
 * Created: 05-08-2024 11:19:25
 * Author : Vikas
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
void blink();

volatile char USART_ReceiveBuffer;

void USART_Init()
{
	UBRR0H = 0;
	UBRR0L = 103;
	
	UCSR0C = 0x06;
	
	UCSR0B = (1<<RXEN0) | (1<<TXEN0);
	
	sei();
}


int main(void)
{
    DDRB|=(1<<5);
	DDRD|=(1<<4);
	USART_Init();
	UCSR0B|=(1<<RXCIE0);
	while(1){
		PORTB=(1<<5);
	}
	return 0;
}

ISR(USART_UDRE_vect)
{
	
	while (!(UCSR0A & (1<<RXC0)))
	{
		
		PORTD|= (1<<4);
		_delay_ms(2000);
		PORTD &= ~(1<<4);
		_delay_ms(2000);
	}
	
	USART_ReceiveBuffer=UDR0;
	
	//blink();0
}

//void blink(){
	//if (USART_ReceiveBuffer == 'a')
	//{
		//PORTB |= (1<<5);
		//_delay_ms(1000);
		//PORTB &= ~(1<<5);
	//}
	//else
	//{
		//PORTB=0;
	//}
//}
