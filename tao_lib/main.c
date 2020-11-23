#include "regx51.h"
//#include "..\Lib\Delay.h"
#include "..\Lib\Lcd.h"

void main()
{
	Lcd_Init();
	Lcd_Out(1,2,"Hello");
	Lcd_Out(2,2,"Test ok");
	while(1)
	{
	}
	
}
