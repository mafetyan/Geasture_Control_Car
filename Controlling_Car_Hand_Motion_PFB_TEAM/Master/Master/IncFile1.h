/*
 * IncFile1.h
 *
 * Created: 1/6/2022 11:50:00 PM
 *  Author: HP
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_
/*********************************  DIO  ********************************/

#define   DDRA    (*(volatile TU08*)(0x3A))
#define   PORTA   (*(volatile TU08*)(0x3B))
#define   PINA    (*(volatile TU08*)(0x39))

#define   DDRB    (*(volatile TU08*)(0x37))
#define   PORTB   (*(volatile TU08*)(0x38))
#define   PINB    (*(volatile TU08*)(0x36))

#define   DDRC    (*(volatile TU08*)(0x34))
#define   PORTC   (*(volatile TU08*)(0x35))
#define   PINC    (*(volatile TU08*)(0x33))
							  
#define  PORTD    (*(volatile TU08*)(0x32))
#define  PIND     (*(volatile TU08*)(0x30))
#define  DDRD     (*(volatile TU08*)(0x31))






#endif /* INCFILE1_H_ */