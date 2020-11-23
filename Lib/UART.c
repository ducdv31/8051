#include"string.h"

void Send(unsigned char a)         //Định nghĩa hàm gửi 1 ký tự
{
	SBUF = a;           //Ghi 1 byte dữ liệu vào thanh ghi SBUF
	while(TI==0){}    //vòng lặp để đợi cờ truyền TI lên 1
	TI=0;             //Xóa cờ truyền TI sau khi truyền xong
}
void SendData(char *a)     //Định nghĩa hàm gửi 1 chuỗi ký tự
{
	int i,n;                  //Khai báo biến cục bộ số nguyên: i,n
	n=strlen(a);              //Tính độ dài của chuỗi *a, lưu vào biến n
	for(i=0;i<n;i++)          //Vòng lặp để gửi lần lượt từng ký tự lên,
	{                         //cho đến khi hết chuỗi *a (ký tự thứ n-1).
		Send(a[i]);             //Gọi hàm gửi 1 ký tự.
	}         
}