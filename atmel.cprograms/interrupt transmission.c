/*
 * interrupt transmission.c
 *
 * Created: 05-08-2024 10:25:59
 * Author : Vikas
 */ 


#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

volatile uint8_t USART_TransmitBuffer;

void USART_Init()
{
	UBRR0H = 0;
	UBRR0L = 103;
	
	UCSR0C = 0x06;
	
	UCSR0B = (1<<RXEN0) | (1<<TXEN0);
	
	sei();
}

void USART_TransmitInterrupt(uint8_t Buffer)
{
	USART_TransmitBuffer = Buffer;
	UCSR0B |= (1<<UDRIE0);
}

int main(void)
{
    DDRB |= 1 << 5;
    uint8_t LocalData = 'a';
    USART_Init();
    USART_TransmitInterrupt(LocalData);
    
    while (1)
    {
	    PORTB |= 1<<5;
	    //_delay_ms(500);
	    //PORTB &= ~(1<<5);
	    //_delay_ms(500);
    }
    
    return 0;
}

ISR(USART_UDRE_vect)
{
	UDR0 = USART_TransmitBuffer;
	while(!(UCSR0A & (1<<UDRE0))){
		DDRD|=(1<<4);
		PORTD |= 1<<4;
		_delay_ms(1000);
		PORTD &= ~(1<<4);
		_delay_ms(1000);
	}
	//UCSR0B &= ~UDRIE0;
}

