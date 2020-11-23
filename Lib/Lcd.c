#include "Delay.h"
sbit LCD_RW = P2^1;
sbit LCD_RS = P2^0;
sbit LCD_EN = P2^2;
#define LCD_DATA P0


void Lcd_Cmd(unsigned char cmd) // Ham gui lenh ra LCD
{
	LCD_RW = 0; // Chon che do ghi
	LCD_RS = 0; // Chon che do ghi lenh
	LCD_DATA = cmd; // Noi dung gui
	LCD_EN = 0;
	LCD_EN = 1;
	if(cmd <= 0x02)
	{
		delay2(20);
	}
	else{
		delay2(20);
	}
	
}
void Lcd_Char_Cp(char c)//Hàm hiển thị 1 kí tự tại vị trí con trỏ
{
   LCD_RW =0;
   LCD_RS =1; //Chọn chế độ gửi dữ liệu
   LCD_DATA =c;	 //Kí tự cần gửi ra màn hình
   LCD_EN = 0;
   LCD_EN =1;
   delay2(1);

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
	Lcd_Cmd(cmd);
	Lcd_Out_Cp(str);

}


void Lcd_Init() //Hàm khởi tạo LCD
{
 Lcd_Cmd(0x30);
 delay2(5);
 Lcd_Cmd(0x30);
 delay2(1);
 Lcd_Cmd(0x30);
 Lcd_Cmd(0x38);	  // Số dòng hiển thị là 2, cỡ chữ 5x8
 Lcd_Cmd(0x01);	  // xóa màn hình
 Lcd_Cmd(0x0C);	  //Bật hiển thị và tắt con trỏ các bạn có thể dùng lệnh 0xE0 để bật hiển thị và bật con trỏ
}