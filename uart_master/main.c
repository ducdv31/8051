#include "regx51.h"
#include "..\Lib\Delay.h"

void Send_Text(char c)
{
	SBUF = c;
	while(!TI);
	TI = 0;

}
void main()
{
	TMOD = 0x20; //Timer1,mode 2 autoreload
	TH1 = TL1 = 0xE6; //Timer1, baudrate 1200
	SCON = 0x60; // 8bit - timer1, SM2 = 1
	TR1 = 1; // Khoi dong timer1
	IE = 0x90;  //  EA = 1, ES = 1
	
	while(1)
	{
		Send_Text("i");
	}
}