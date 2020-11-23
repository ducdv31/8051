#include "regx51.h"
void delay(unsigned int h)
{
	unsigned int k;
	while(h--)
	{
		for(k = 0;k < 83;k++)
		{
		}
	}
	
}
int t = 0;
void Ngat() interrupt 1 //Ngat timer 0
{
	int a = 10000;
	t++; // Dem thoi gian
	TH0 = 0xFC;
	TL0 = 0x18;
	TR0 = 1; // Khoi dong timer
	if(t>=5000)
	{
		t = 0;
		P1_3 = 1; // Bat led chan P1_3
		while(a--); // delay 10s
		P1_3 = 0; // Tat led chan P1_3
	}
}
void main()
{
	TMOD = 0x01; // Timer 0, Mode 1 16bit
	ET0 = 1; // Enable ngat timer0
	TR0 = 1;
	EA = 1; // Cho phep ngat toan cuc
	while(1)
	{
	P2 = 0;
	delay(2000);
	P2 = 0xFF;
	delay(2000);
	}
}