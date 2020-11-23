#include "regx51.h"
#include "..\Lib\Lcd.h"

char Temp;

//char Rev_Data()
//{
//	char rev = 0;
//	while(!RI);
//	rev = SBUF;
//	return rev;
//}
void Interrrupt_Uart_Rev_Data() interrupt 4
{
	if(RI == 1)
	{
		Temp = SBUF;
		RI = 0;
	}
	
}
void main()
{
	TMOD = 0x20; //Timer1,mode 2 autoreload
	TH1 = TL1 = 0xE6; //Timer1, baudrate 1200
	SCON = 0x60; // 8bit - timer1, SM2 = 1
	TR1 = 1; // Khoi dong timer1
	IE = 0x90;  //  EA = 1, ES = 1
	Lcd_Init();
	Lcd_Out(1,1,Temp);
}