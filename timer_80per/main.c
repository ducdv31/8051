#include "regx51.h"
void delayh(){
	TMOD = 0x01; // Timer0 che do 1
	TH0 = 0xFC;
	TL0 = 0xE0;
	TR0 = 1; // Khoi dong timer
	while(!TF0); // Kiem tra co tran
	TF0 = 0;
	TR0 = 0; // Dung timer
}
void delayl(){
	TMOD = 0x01; // Timer0 che do 1
	TH0 = 0xFF;
	TL0 = 0x38;
	TR0 = 1; // Khoi dong timer
	while(!TF0); // Kiem tra co tran
	TF0 = 0;
	TR0 = 0; // Dung timer
}
void main(){
	while(1)
	{
		P2_0 = 1;
		delayh();
		P2_0 = 0;
		delayl();
	}
}
