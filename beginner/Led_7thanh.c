#include <REGX51.H>
void Delay(unsigned int t)
{
	unsigned int i;
	while(t--)
	{
		for(i = 0;i < 83;i++)
		{
			
		}
	}
	
}

void main()
{
int array[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80,0x90};
unsigned char i = 0;
while(1)
{
P2 = array[i];
Delay(200);
i++;
if(i==10)
{
i = 0;
}
}
}
