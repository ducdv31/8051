#include "regx51.h"
#include "..\Lib\Delay.h"
sbit LED1 = P2^0;
sbit LED2 = P2^1;
sbit LED3 = P2^2;
sbit LED4 = P2^3;
unsigned int count = 0,t = 0,f,k,delay = 10;
unsigned char LED7SEG[10] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};

void dem_xung() interrupt 0
{
	count++;
}
void doc_xung() interrupt 3
{
	t++;
	TH1 = 0xFC;
	TL1 = 0x18;
	TR1 = 1;
	if(t>=1000)
	{
		f = count;
		count = 0;
		t =0;
	}
}
void OSC_Out(unsigned int dem)
{
	unsigned int i;
	unsigned char nghin,tram,chuc,dv;
	nghin = dem/1000;
	tram = (dem%1000)/100;
	chuc = (dem%100)/10;
	dv = dem%10;
	for(i = 0;i < 20;i++)
	{
	LED1 = 0;
	P0 = LED7SEG[nghin];
	delay2(10);
	LED1 = 1;
 
	LED2 = 0;
	P0 = LED7SEG[tram];
	delay2(10);
	LED2 = 1;
 
	LED3 = 0;
	P0 = LED7SEG[chuc];
	delay2(10);	
	LED3 = 1;
 
	LED4 = 0;
	P0 = LED7SEG[dv];
	delay2(10);
	LED4 = 1;
	}
}
void main (void)
{
	TMOD = 0x10; //Timer1, mode 1
	P3_2 =1;
	EX0 = 1; // Khoi dong ngat ngoai 0
	ET1 = 1; // Bat ngat timer
	IT0 = 1; // Ngat theo suon am
	TR1= 1; //Bat timer 1
	EA = 1; // Bat ngat tong
	while(1)
	{
	OSC_Out(f);
	}
} // Main