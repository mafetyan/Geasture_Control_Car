#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef enum {
	NO_ERROR = 1,
	ERROR    = 2
	
	}Errot_t;

#define NULL   0

typedef unsigned char TU08;
typedef signed char TS08;

typedef unsigned short int TU16;
typedef signed short int TS16;

typedef unsigned long int TU32;
typedef signed long int Ts16;

typedef void (*VoidFunPtr)(void) ;

#endif
