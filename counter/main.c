#include<regx51.h>
#include"stdio.h"
#include"string.h"
#include "stdlib.h"
sbit LCD_RW = P1^5;
sbit LCD_RS = P1^4;
sbit LCD_EN = P1^6;
#define LCD_DATA P2
char counter[10];
int count, Low_Byte,High_Byte;
void delay(unsigned int t)
{
	unsigned int i;
	while(t--){
		for(i = 0;i < 80;i++)
		{
			
		}
		
	}
	
}
void Lcd_cmd(unsigned char cmd) // Ham gui lenh ra LCD
{
	LCD_RW = 0; // Chon che do ghi
	LCD_RS = 0; // Chon che do ghi lenh
	LCD_DATA = cmd; // Noi dung gui
	LCD_EN = 0;
	LCD_EN = 1;
	if(cmd <= 0x02)
	{
		delay(20);
	}
	else{
		delay(20);
	}
	
}
void Lcd_Char_Cp(char c)//Hàm hiển thị 1 kí tự tại vị trí con trỏ
{
   LCD_RW =0;
   LCD_RS =1; //Chọn chế độ gửi dữ liệu
   LCD_DATA =c;	 //Kí tự cần gửi ra màn hình
   LCD_EN = 0;
   LCD_EN =1;
   delay(1);

}
void Lcd_Out_Cp(char *str)// Hàm gửi chuỗi kí tự tại vị trí con trỏ
{

unsigned char i=0;
while(str[i]!=0)  //Gửi từng kí tự của chuỗi đến khi gặp kí tự null
{
	 Lcd_Char_Cp(str[i]);
	 i++;
}

}


void Lcd_Out(unsigned char row, unsigned char col, char *str)		//Hàm Di chuyển vị trí con trỏ đến vị trí bất kì và in chuỗi ra màn hình
{
 	unsigned char cmd;

	// Di chuyển con trỏ đến vị trí cần thiết
	cmd = (row==1?0x80:0xC0) + col - 1;
	Lcd_cmd(cmd);
	Lcd_Out_Cp(str);

}


void Lcd_Init() //Hàm khởi tạo LCD
{

 Lcd_cmd(0x30);
 delay(5);
 Lcd_cmd(0x30);
 delay(1);
 Lcd_cmd(0x30);
 Lcd_cmd(0x38);	  // Số dòng hiển thị là 2, cỡ chữ 5x8
 Lcd_cmd(0x01);	  // xóa màn hình
 Lcd_cmd(0x0C);	  //Bật hiển thị và tắt con trỏ các bạn có thể dùng lệnh 0xE0 để bật hiển thị và bật con trỏ
}


main()
{
	
	TMOD=0x60;  //0x60=0110 0000 : C/T=1, bộ đếm 1, chế độ 2 tự nạp
  TH1=0x00;   //xóa bộ đếm ban đầu
  P3_5=1;     //set chân vào cho bộ đếm
  TR1=1;      //khởi động bộ đếm 1
	Lcd_Init();
	Lcd_Out(1,1,"COUNTER IN 8051")	;   //In dòng "Dien Tu 3M" ra hàng 1 và cột 4 trên màn hình
	Lcd_Out(2,1,"Count=")	;  //In dòng "Chotroihn.vn" ra hàng 2 và cột 3 trên màn hình
	while(1)
	{
		Low_Byte = TL1;
		High_Byte = TH1;
		count = (High_Byte*256) + Low_Byte;
		sprintf(counter,"%d",count);
		Lcd_Out(2,8,counter);
	}
}
