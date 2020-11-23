#include<regx51.h>
void delay(unsigned int t){
	unsigned int i;
	while(t--){
		for (i=0;i<82;i++){
	}
	}
}
int main(){
	while(1){
		// 10101010 = AAH
		// 01010101 = 55H
		// 11110000 = F0H
	P2 = 0xAA;
	delay(500);
	P2 = !P2;
	delay(500);
	}
	return 0;
}
