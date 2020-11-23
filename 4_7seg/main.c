#include "regx51.h"
#include "..\Lib\Delay.h"
sbit LED1 = P2^0;
sbit LED2 = P2^1;
sbit LED3 = P2^2;
sbit LED4 = P2^3;
unsigned char LED7SEG[10] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
void Delay (unsigned int Time)
{
while(Time--);
}
void main (void)
{
unsigned int i;
unsigned int j;
LED1 = 0;
LED2 = 0;
LED3 = 0;
LED4 = 0;
while(1)
{
for(i = 0; i < 10000; i++)
{
for (j = 0; j < 10; j++)
{
P0 = LED7SEG[i/1000];
LED1 = 0;
delay1(10);
LED1 = 1;
 
P0 = LED7SEG[(i%1000)/100];
LED2 = 0;
delay1(10);
LED2 = 1;
 
P0 = LED7SEG[(i%100)/10];
LED3 = 0;
delay1(10);
LED3 = 1;
 
P0 = LED7SEG[i%10];
LED4 = 0;
delay1(10);
LED4 = 1;
}
}
}
}