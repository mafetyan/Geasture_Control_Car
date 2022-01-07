

#ifndef LCD_H_
#define LCD_H_
#include "STD_TYPES.h"

#include "LCD_Cfg.h"
//#define  F_CPU   16000000
#include <util/delay.h>



void LCD_Init(void);

void LCD_WriteCommand(TU08 cmd);

void LCD_WriteChar(TU08 chr);

void LCD_WriteString(TU08* str);

void LCD_GoTo(TU08 row , TU08 col);

void LCD_Clear(void);

void LCD_WriteInteger(TS08 num);



#endif /* LCD_H_ */