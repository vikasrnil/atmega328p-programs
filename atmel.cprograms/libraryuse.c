/*
 * test.c
 *
 * Created: 01-08-2024 23:55:03
 * Author : Vikas
 */ 

#include <avr/io.h>
#include "library.h"


int main(void)
{
	uartinit();
// 		float ans=chartofloat("1002.456");
// 		char ar[30] = {0};
// 		sprintf(ar,"%f\n",ans);
// 		while(1){
// 			char c=uart_char_rec();
// 			uart_char_trans(c);
// 		}
	
	while (1){
		float ans=uart_char_rec();
		//char ar[30] = {0};
		//sprintf(ar,"%f\n",ans);
		uart_char_trans(ans);
	}
	//readchar();
}




















