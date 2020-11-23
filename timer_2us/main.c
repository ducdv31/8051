#include "regx51.h"
#include "..\..\Lib\Delay.h"

void main(){
	P2_0 = 0;
	while(1)
	{
		P2_0 = !P2_0;
		Delay(2);
	}
}
