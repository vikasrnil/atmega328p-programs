	/*
 * spi slave.c
 *
 * Created: 07-08-2024 12:55:53
 * Author : Vikas
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


char SPI_SlaveReceive(void)
{
	while(!(SPSR & (1<<SPIF)));
	return SPDR;
}

void SPI_SlaveInit(void)
{
	
	
	DDRB |=(1<<DDB4);
	
	SPCR |= (1<<SPE);
	
}

int main(void)
{
	SPI_SlaveInit();
	DDRD |=(1<<5);
	char c=SPI_SlaveReceive();
	while(1)
	if(c=='A'){
			PORTD=(1<<5);
			_delay_ms(1000);
			PORTD &= ~(1<<5);
			_delay_ms(1000);
	}
}


