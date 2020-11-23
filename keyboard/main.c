#include<regx51.h>
void delay(unsigned int t){
	unsigned int i;
	while(t--){
	for(i=0;i<80;i++){
	}
	}
	
}
	unsigned int count = 0;
void checkbt(){
	
	P1_0 = 1;
	P1_5 = 0;
	if(P1_0 ==0){
			delay(200);
			if(P1_0 ==0){
				count++;
				if(count == 4){
					count = 0;
				}
			}
		}
	
}
int main()
{
	

	while(1)
	{
		checkbt();
		if(count == 0){
			P2 = 0x00;
		}
		else if(count == 1){
			P2 = 0xFF;
		}
		else if(count == 2){
			P2 = 0xAA;
		}
		else if(count == 3){
			unsigned int j;
			for(j=0;j<8;j++){
				P2 = 0x01 << j;
				delay(200);
			}
			
			}		
	}
	return 0;
}