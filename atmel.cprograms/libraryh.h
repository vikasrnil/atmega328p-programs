/*
 * library.h
 *
 * Created: 01-08-2024 23:48:46
 *  Author: Vikas
 */ 


#ifndef LIBRARY_H_
#define LIBRARY_H_

int delay(void);
float chartofloat(char* str);
void read(char c);
void uartinit();
void uart_char_trans(char c);
void transmit(char*s);
char uart_char_rec();


#endif /* LIBRARY_H_ */