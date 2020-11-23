#include "Lcd.c"
#ifndef _LCD_H
#define _LCD_H
void Lcd_Cmd(unsigned char cmd);
void Lcd_Char_Cp(char c);
void Lcd_Out_Cp(char *str);
void Lcd_Out(unsigned char row, unsigned char col, char *str);


#endif