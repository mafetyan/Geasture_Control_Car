/*
 * Master.c
 *
 * Created: 1/7/2022 12:03:42 AM
 * Author : youss
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include "UART.h"
#include "PLATFORM_TYPES.h"
#include "util/delay.h"
#include "BIT_MATH.h"

int main(void)
{

	DDRC = 0b11111100;
	DDRD = 0b00110000;
	Uart_init(9600);
	int x;
	
    while (1) 
    {
		x = UART_recieve_byte();
		if (x == 0b00000001)
		{
			PORTD = 0b00110000;
			PORTC = 0b00101100;
		}
		
		else if (x == 0b00000010)
		{
			PORTD = 0b00110000;
			PORTC = 0b11010000;
		}
		
		else if (x == 0b00000100)
		{
			PORTD = 0b00110000;
			PORTC = 0b10110000;
		}
		else if (x == 0b00001000)
		{
			PORTD = 0b00110000;
			PORTC = 0b11001000;
		}
		else if (x == 0b00010000)
		{
			PORTD = 0b00000000;
			PORTC = 0b00000000;
		}
	
    }
}

