#include "regx51.h"
void delay(){
	TMOD = 0x02; // Timer0 che do 2
	TL0 = 0x38;
	TH0 = 0x38;
	TR0 = 1; // Khoi dong timer
	while(!TF0); // Kiem tra co tran
	TF0 = 0;
	TR0 = 0; // Dung timer
}
void main(){
	while(1)
	{
		P2_0 = !P2_0;
		delay();
	}
}
