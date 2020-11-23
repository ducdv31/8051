#include<regx52.h>
void delay(unsigned int t)
{
	unsigned int i;
	while(t--)
	{
		for(i=0;i<100;i++){
		}
	}
}
int main(){
	while(1){
		P2_0 = 1;
		delay(500);
		P2_0 = 0;
		delay(500);
	}
	return 0;
}