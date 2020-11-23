#include "Delay.h"

void Delay(unsigned int t)
{
	unsigned int i;
	while(t--)
	{
	TMOD = 0x01; // Timer0 che do 1
	TH0 = 0xFC;
	TL0 = 0x18;
	TR0 = 1; // Khoi dong timer
	while(!TF0); // Kiem tra co tran
	TF0 = 0;
	TR0 = 0; // Dung timer
	}
	
}