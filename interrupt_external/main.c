#include "regx51.h"
void delay(unsigned int t)
{while(t--){
	TMOD = 0x01; // Timer0, mode 1
	TH0 = 0xFC;
	TL0 = 0x18;
	TR0 = 1;
	while(!TF0);
	TF0 = 0;
	TR0 = 0;
}
}
void main()
{
	EX0 = 1; // Cho phep ngat ngoai 0
	EA = 1; //Cho phep ngat toan cuc
	IT0 = 1; // Chuyển sang ngắt theo sườn
	while(1)
	{
	P2 = 0x00;
	delay(500);
	P2 = 0xFF;
	delay(500);
	}
}
void ngat() interrupt 0{
	int a = 10000;
	unsigned int i;
	for( i = 0;i<5; i++)
	{
	P1_0 = 0;
	while(a--);
	P1_0 = 1;
	}
	
}