/*
 * spi 1.c
 *
 * Created: 06-08-2024 12:32:39
 * Author : Vikas
 */ 

#define F_CPU 16000000LU
#include <avr/io.h>
#include <util/delay.h>


void SPI_MasterInit(void)
{
	DDRB = (1<<DDB3)|(1<<DDB5)|(1<<DDB2);

	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}

void SPI_MasterTransmit(char cData)
{
	PORTB &= ~(1<<DDB2);
	SPDR = cData;
	while(!(SPSR & (1<<SPIF)))
	;
	PORTB |=(1<<DDB2);
	_delay_ms(1000);
}

int main(void)
{
	SPI_MasterInit();
	while (1)
	{
		SPI_MasterTransmit('A');
	}
	
	
}

