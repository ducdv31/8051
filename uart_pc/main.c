#include<at89x51.h>           //Khai báo thư viện cho 89c51
#include "..\Lib\UART.h"      // Thu vien giaao tiep  UART
#include "..\Lib\Delay.h"     // Thu vien dely
main()                        //Chương trình chính
{
	TMOD=0x20;                  //Chọn Timer1, chế độ 2
	TH1=0xFD;                   //Cài đặt tốc độ 9600 baud
	SCON=0x50;                  //0101 0000: Chọn chế độ 1, Cho phép nhận
	TR1=1;                      //Khởi động Timer1

	while(1)                    //Vòng lặp vô hạn
	{
	SendData("Hello AE");  			//Gọi hàm gửi 1 chuỗi
	Send(10);  									//Gửi dấu xuống dòng
	delay2(1000);
	}
}
