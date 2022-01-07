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

#include <stdlib.h>
#include <util/delay.h>
#include "STD_TYPES.h"

uint16_t adc_valueX;
uint16_t adc_valueY;

void adc_init(void);            //Function to initialize/configure the ADC
uint16_t read_adc(uint8_t channel);    //Function to read an arbitrary analog channel/pin


int main(void)
{
    adc_init();
    LCD_Init();
    _delay_ms(50);
    LCD_Clear();
    LCD_WriteString("   Direction");
    _delay_ms(10);
    LCD_GoTo(1,0);
    LCD_WriteString("Speed=");
    _delay_ms(10);
    LCD_GoTo(1,11);
    LCD_WriteString("RPM");
    _delay_ms(10);
	
	Uart_init(9600);
	
	
	
    while (1) 
    {
		adc_valueX = read_adc(0);
		adc_valueY = read_adc(1);
		
		if ((adc_valueX > 550) && (470 < adc_valueY < 550))
		{
			LCD_GoTo(0,11);
			LCD_WriteString("F");
			_delay_ms(10);
			LCD_GoTo(1,7);
			LCD_WriteString("255");
			_delay_ms(10);
			
			UART_send_byte(0b00000001);
		}
		else if ((adc_valueX < 470) && (470 < adc_valueY < 550))
		{
			LCD_GoTo(0,11);
			LCD_WriteString("B");
			_delay_ms(10);
			LCD_GoTo(1,7);
			LCD_WriteString("255");
			_delay_ms(10);
			
			UART_send_byte(0b00000010);
		}
		else if ((adc_valueY > 550) && (470 < adc_valueX < 550))
		{
			LCD_GoTo(0,11);
			LCD_WriteString("R");
			_delay_ms(10);
			LCD_GoTo(1,7);
			LCD_WriteString("255");
			_delay_ms(10);
			
			UART_send_byte(0b00000100);	
		}
		else if ((adc_valueY < 470) && (470 < adc_valueX < 550))
		{
			LCD_GoTo(0,11);
			LCD_WriteString("L");
			_delay_ms(10);
			LCD_GoTo(1,7);
			LCD_WriteString("255");
			_delay_ms(10);
			
			UART_send_byte(0b00001000);	
		}
		else
		{
			LCD_GoTo(0,11);
			LCD_WriteString("S");
			_delay_ms(10);
			LCD_GoTo(1,7);
			LCD_WriteString("000");
			_delay_ms(10);
			UART_send_byte(0b00010000);	
		}	
    }
}

void adc_init(void){
	ADCSRA |= ((1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0));   // 16Mhz/128 = 125Khz the ADC reference clock
	ADMUX |= (1<<REFS0);                            // Voltage reference from Avcc (5v)
	ADCSRA |= (1<<ADEN);                            // Turn on ADC
	ADCSRA |= (1<<ADSC);                            // Do an initial conversion because this one is the slowest and to ensure that everything is up and running
}

uint16_t read_adc(uint8_t channel){
	ADMUX &= 0xF0;                            // Clear the older channel that was read
	ADMUX |= channel;                            // Defines the new ADC channel to be read
	ADCSRA |= (1<<ADSC);                            // Starts a new conversion
	while(ADCSRA & (1<<ADSC));                        // Wait until the conversion is done
	return ADCW;                                // Returns the ADC value of the chosen channel
}