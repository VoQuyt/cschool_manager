using namespace std;
#include <iostream>
#include "console.h"
#include <conio.h>

#define MAUNEN 15
#define MAUCHU 8
#define vitri 5
#define X 10
#define Y 3
#define stop 300
typedef char str[32];

//-----------------------------------------------------------------------------

struct phonghoc
{
	char MAPH[20]; // ma phong hoc
	int SNHTD;// so sinh vien toi da
	int TT;// trang thai (trong hoac co lop hoc) 
	int NGAY; //ngay hoc tai phong hoc 
	int THANG;
	int NAM;
};
struct DAT
{
	int NGAY;
	int THANG;
	int NAM;
};

struct tang
{
	int SOTANG;// TANG HOC 
	phonghoc PHG; // PHONG HOC 
};
struct khoahoc
{
	char MAKH[20]; // ma khoa hoc
	DAT NKG; // Ngay khai giang 
	char TPH[20]; //ten phong hoc 
	int CAHOC; //  sang, chieu ,toi 
	int BH1; // 2,3,4,5,6,7,8
	int BH2; // 2,3,4,5,6,7,8
	//phonghoc PH; // PH LA phong hoc : 
};
struct node //nut tang hoc
{
	tang info;
	node *next;
};

struct Node //nut khoa hoc
{
	khoahoc Info;//nut khoa hoc
	Node *Next; //net khoa hoc
};

struct list1 //list tang hoc
{
	node *head;
	node *tail;
};

struct list2 //list khoa hoc
{
	Node *head;
	Node *tail;
};
int sosanhchuoi(char*chuoi1, char*chuoi2)
{
	char *tmp;
	if (tmp = strstr(chuoi1, chuoi2))
		return(tmp - chuoi1);
	else
		return -1;
}
tang NHAPTTTANG() // nhap thong tin tang hoc
{
	int dem = 0;
	char str1[20] = "PHG";
	tang t;
	gotoXY(X + 30, 10);
		cout << "nhap tang hoc (1->5)";
	gotoXY(X + 14, 6);
	cin >> t.SOTANG;
	while (t.SOTANG > 5 || t.SOTANG < 0)
	{
		gotoXY(X + 30, 10);
		cout << "nhap lai tang (1->5)";
		gotoXY(X + 14, 6);
		cin >> t.SOTANG;
	}
//--------------------------------------------------------
	gotoXY(X + 30, 10);
		cout << "nhap ma phong (PHG+MAPHG)";
	gotoXY(X + 28, 6);
	rewind(stdin);
	gets_s(t.PHG.MAPH);
	while (sosanhchuoi(t.PHG.MAPH, str1) == -1)
	{
		gotoXY(X + 30, 10);
		cout << "nhap lai MA PHONG (PHG+MAPHG)";
		gotoXY(X + 28, 6);
		gets_s(t.PHG.MAPH);
		
	}
//----------------------------------------------------------

	gotoXY(X + 30, 10);
		cout << "nhap so luong hoc sinh toi da";
	gotoXY(X + 46, 6);
	cin >> t.PHG.SNHTD;
//----------------------------------------------------------
	
	gotoXY(X + 30, 10);
		cout << "nhap ngay,thang,nam hoc tai phong";
	gotoXY(X + 30, 11);
		cout << "(1907 < nam < 2018)";
	gotoXY(X + 30, 12);
		cout << "nhap nam";
	gotoXY(X + 61, 6);
	cout << "/";
	gotoXY(X + 62, 6);
	cin >> t.PHG.NAM;
	while (t.PHG.NAM < 1907 || t.PHG.NAM> 2017)
	{
		gotoXY(X + 30, 12);
		cout << "nhap sai data, moi ban nhap lai ";
		gotoXY(X + 62, 6);
		cin >> t.PHG.NAM;
	}
//----------------------------------------------------------
	
	gotoXY(X + 30, 12);
		cout << "nhap thang                      ";
	gotoXY(X + 58, 6);
	cout << "/";
	gotoXY(X +59, 6);
	cin >> t.PHG.THANG;
	while (t.PHG.THANG < 1 || t.PHG.THANG>12)
	{
		gotoXY(X + 30, 12);
		cout << "nhap sai data,moi ban nhap lai ";
		gotoXY(X + 59, 6);
		cin >> t.PHG.THANG;
	}
//------------------------------------------------------------
	
	gotoXY(X + 30, 12);
		cout << "nhap ngay                      ";
	gotoXY(X + 56, 6);
	cin >> t.PHG.NGAY;
	if (t.PHG.THANG == 1 || t.PHG.THANG == 3 || t.PHG.THANG == 5 || t.PHG.THANG == 7 || t.PHG.THANG == 8 || t.PHG.THANG == 10 || t.PHG.THANG == 12)
	{
		while (t.PHG.NGAY < 1 || t.PHG.NGAY >31)
		{
			gotoXY(X + 30, 12);
			cout << "nhap sai data, moi ban nhap lai";
			gotoXY(X + 56, 6);
			cin >> t.PHG.NGAY;
		}
	}
	else if (t.PHG.THANG == 4 || t.PHG.THANG == 6 || t.PHG.THANG == 9 || t.PHG.THANG == 11)
	{
		while (t.PHG.NGAY < 1 || t.PHG.NGAY >30)
		{
			gotoXY(X + 30, 12);
			cout << "nhap sai data, moi ban nhap lai";
			gotoXY(X + 56, 6);
			cin >> t.PHG.NGAY;
		}
	}
	else
		while (t.PHG.NGAY < 1 || t.PHG.NGAY >29)
		{
			gotoXY(X + 30, 12);
			cout << "nhap sai data, moi ban nhap lai";
			gotoXY(X + 56, 6);
			cin >> t.PHG.NGAY;
		}

//-----------------------------------------------------------
	
	gotoXY(X + 30, 10);
		cout << "nhap trang thai cua phong          " << endl;
	gotoXY(X + 30, 11);
		cout << "nhap : 0  trong      " << endl;
	gotoXY(X + 30, 12);
		cout << "nhap : 1  co lop hoc " << endl;
	gotoXY(X + 74, 6);
	cin >> t.PHG.TT;

	while (t.PHG.TT < 0 || t.PHG.TT > 1)
	{
		gotoXY(X + 30, 10);
		cout << "ban nhap sai moi ban nhap lai      ";
		gotoXY(X + 74, 6);
		cin >> t.PHG.TT;
	}
	return t;
} 

khoahoc NHAPTTKHOAHOC()
{
	char str1[20] = "KH";// NHAP KH DE NHAP DUOC KHOA HOC 

	khoahoc k;
	gotoXY(X + 30, 10);
	cout << "nhap ma khoa hoc (KH + MAKH)";
	gotoXY(X + 10, 6);
	rewind(stdin);
	gets_s(k.MAKH);

	while (sosanhchuoi(k.MAKH, str1) == -1)
	{
		gotoXY(X + 30, 10);
		cout << "nhap lai MA KHOA HOC(KH + MAKH)";
		gotoXY(X + 10, 6);
		gets_s(k.MAKH);

	}

	gotoXY(X + 30, 10);
	cout << "nhap ten phong hoc                  ";
	gotoXY(X + 27, 6);
	rewind(stdin);
	gets_s(k.TPH);


	gotoXY(X + 30, 10);
	cout << "nhap thoi gian khai giang";
	gotoXY(X + 30, 11);
	cout << "(1907 < nam < 2018)      ";
	gotoXY(X + 30, 12);
	cout << "nhap nam                 ";
	gotoXY(X + 48, 6);
	cout << "/";
	gotoXY(X + 49, 6);
	cin >> k.NKG.NAM;
	while (k.NKG.NAM < 1907 || k.NKG.NAM> 2017)
	{
		gotoXY(X + 30, 12);
		cout << "nhap sai data, moi ban nhap lai ";
		gotoXY(X + 49, 6);
		cin >> k.NKG.NAM;
	}

	gotoXY(X + 30, 12);
	cout << "nhap thang                          ";
	gotoXY(X + 45, 6);
	cout << "/";
	gotoXY(X + 46, 6);
	cin >> k.NKG.THANG;
	while (k.NKG.THANG < 1 || k.NKG.THANG >12)
	{
		gotoXY(X + 30, 12);
		cout << "nhap sai data, moi ban nhap lai";
		gotoXY(X + 46, 6);
		cin >> k.NKG.THANG;
	}

	gotoXY(X + 30, 12);
	cout << "nhap ngay                           ";
	gotoXY(X + 43, 6);
	cin >> k.NKG.NGAY;
	if (k.NKG.THANG == 1 || k.NKG.THANG == 3 || k.NKG.THANG == 5 || k.NKG.THANG == 7 || k.NKG.THANG == 8 || k.NKG.THANG == 10 || k.NKG.THANG == 12)
	{
		while (k.NKG.NGAY < 1 || k.NKG.NGAY >31)
		{
			gotoXY(X + 30, 12);
			cout << "nhap sai data, moi ban nhap lai";
			gotoXY(X + 43, 6);
			cin >> k.NKG.NGAY;
		}
	}
	else if (k.NKG.THANG == 4 || k.NKG.THANG == 6 || k.NKG.THANG == 9 || k.NKG.THANG == 11)
	{
		while (k.NKG.NGAY < 1 || k.NKG.NGAY >30)
		{
			gotoXY(X + 30, 12);
			cout << "nhap sai data, moi ban nhap lai";
			gotoXY(X + 43, 6);
			cin >> k.NKG.NGAY;
		}
	}
	else
		while (k.NKG.NGAY < 1 || k.NKG.NGAY >29)
		{
			gotoXY(X + 30, 12);
			cout << "nhap sai data, moi ban nhap lai";
			gotoXY(X + 43, 6);
			cin >> k.NKG.NGAY;
		}

	gotoXY(X + 30, 10);
	cout << "chon ca hoc                            ";
	gotoXY(X + 30, 11);
	cout << "nhap 1: Ca Sang: 9h-11h                ";
	gotoXY(X + 30, 12);
	cout << "nhap 2: Ca Chieu: 15h - 17h            ";
	gotoXY(X + 30, 13);
	cout << "nhap 3: Ca Toi: 15h - 17h              ";
	gotoXY(X + 60, 6);
	cin >> k.CAHOC;
	while (k.CAHOC < 1 || k.CAHOC>3)
	{
		gotoXY(X + 30, 10);
		cout << "nhap sai data, moi ban chon lai ";
		gotoXY(X + 60, 6);
		cin >> k.CAHOC;
	}

	gotoXY(X + 30, 10); 
	cout << "nhap buoi hoc(thu 2 -> 8)               ";
	gotoXY(X + 30, 11);
	cout << "nhap buoi thu 1                         ";
	gotoXY(X + 30, 12);
	cout << "                                        ";
	gotoXY(X + 30, 13);
	cout << "                                        ";
	gotoXY(X + 74, 6);
	cin >> k.BH1;
	while (k.BH1 < 2 || k.BH1>8)
	{
		gotoXY(X + 30, 11);
		cout << "nhap sai data, moi ban nhap lai";
		gotoXY(X + 74, 6);
		cin >> k.BH1;
	}

	gotoXY(X + 30, 11);
	cout << "nhap buoi thu 2                    ";
	gotoXY(X + 85, 6);
	cin >> k.BH2;
	while (k.BH2 < 2 || k.BH2 > 8)
	{
		gotoXY(X + 30, 11);
		cout << "nhap sai data, moi ban nhap lai                                  ";
		gotoXY(X + 85, 6);
		cin >> k.BH2;
	}
	while (k.BH1 == k.BH2)
	{
		gotoXY(X + 30, 11);
		cout << "buoi so 2 bi trung voi buoi so 1, moi ban nhap lai buoi so 2";
		gotoXY(X + 85, 6);
		cin >> k.BH2;
	}
	return k;
}

node* GetNode(tang t)
{
	node *p;
	p = new node;
	if (p == NULL)
	{
		cout << "Khong du bo nho";
		exit(1);
	}
	p->info = t;
	p->next = NULL;
	return p;
}

Node* GetNode(khoahoc k)
{
	Node *q;
	q = new Node;
	if (q == NULL)
	{
		cout << "Khong du bo nho";
		exit(1);
	}
	q->Info = k;
	q->Next = NULL;
	return q;
}

void InsertHead(list1 &l1, tang t)
{
	node *p;
	p = GetNode(t);
	if (p == NULL)
	{
		cout << "Khong them duoc nut";
		exit(1);
	}
	if (l1.head == NULL)
		l1.head = l1.tail = p;
	else
	{
		p->next = l1.head;
		l1.head = p;
	}
}

void InsertHead(list2 &l2, khoahoc k)
{
	Node *q;
	q = GetNode(k);
	if (q == NULL)
	{
		cout << "Khong them duoc nut";
		exit(1);
	}
	if (l2.head == NULL)
		l2.head = l2.tail = q;
	else
	{
		q->Next = l2.head;
		l2.head = q;
	}
}
// chuc năng số 2 cập nhật thông tin của 1 phòng học tại một thời điểm bất kỳ
void update(list1 &l1)
{
	int ngay, thang, nam;
	int flag = 0;
	cout << "\n \t nhap ngay thang nam de cap nhap thong tin cua phong hoc ";
	cout << "\n\t nhap ngay ";
	cin >> ngay;
	cout << " \n \t nhap thang ";
	cin >> thang;
	cout << "\n\t nhap nam ";
	cin >> nam;
	for (node*p = l1.head; p != NULL; p = p->next)
	{
		if (p->info.PHG.NGAY == ngay && p->info.PHG.THANG == thang && p->info.PHG.NAM == nam)
		{
			flag = 1;
			cout << " \t phong hoc thuoc tang: " << p->info.SOTANG << endl;
			cout << " \t ma phong: " << p->info.PHG.MAPH << endl;
			cout << " \t so nguoi hoc toi da la: " << p->info.PHG.SNHTD << endl;
			if (p->info.PHG.TT == 0)
				cout << "\t phong trong " << endl;
			else cout << "\t co lop hoc" << endl;
		}
	}
	if (flag == 0)
		cout << "\n khong co phong hoc nao tai thoi diem nay ";
}
// chuc nang so 3: . Xuất ra danh sách phòng học đang trống tại hiện tại. (dưới dạng bảng liệt kê)
void xuatdsphongtrong(list1 &l1)
{
	int flag = 0;
	int i = 1;
	for (node*p = l1.head; p != NULL; p = p->next)
	{
		if (p->info.PHG.TT == 0)
		{
			flag = 1;
			gotoXY(X + 2, Y + i + 2);
			cout << i;
			gotoXY(X + 13, Y + i + 2);
			cout << p->info.SOTANG;//phong thuoc tang nao
			gotoXY(X + 28, Y + i + 2);
			cout << p->info.PHG.MAPH;
			i++;
		}
	}
	if (flag == 0)
	{
		gotoXY(X + 28, Y + i + 2);
		cout << "khong co ";
		gotoXY(X + 24, Y + i + 4);
		cout << "phong phu hop";
	}
}
// chuc nang 4 :Tìm một phòng học bất kỳ tại 1 thời điểm k có thể chứa được x sinh viên để trao đổi đồ án môn học. (x nhập từ bàn phím). 
void timk(list1  &l1)
{
	int x, i=1, flag = 0;
	cout << "nhap so luong sinh vien can tim phong: ";
	cin >> x;
	for (node*p = l1.head; p != NULL; p = p->next)
	{
		if (x <= p->info.PHG.SNHTD)
		{
			flag = 1;
			gotoXY(X + 2, Y + i + 2);
			cout << i;
			gotoXY(X + 13, Y + i + 2);
			cout << p->info.SOTANG << endl;//phong thuoc tang nao
			gotoXY(X + 28, Y + i + 2);
			cout << p->info.PHG.MAPH << endl;
			i++;
		}
	}
	if (flag == 0)
	{
		gotoXY(X + 28, Y + i + 2);
		cout << "khong co ";
		gotoXY(X + 24, Y + i + 4);
		cout << "phong phu hop";
	}
}
//xuat danh sch phong hoc
void output(list1 &l1)
{
	int i = 1;
	node *p;
	p = l1.head;
	while (p != NULL)
	{
		gotoXY(X + 2, Y + i + 2);
		Sleep(stop);
			cout << i;
		gotoXY(X + 13, Y + i + 2);
		Sleep(stop);
			cout <<p->info.SOTANG << endl;//phong thuoc tang nao
		gotoXY(X + 28, Y + i + 2);
		Sleep(stop);
			cout << p->info.PHG.MAPH << endl;//ma phong
		gotoXY(X + 44, Y + i + 2);
		Sleep(stop);
			cout << p->info.PHG.SNHTD <<" HS ";//so hoc sinh toi da
		gotoXY(X + 57, Y + i + 2);
		Sleep(stop);
			cout << p->info.PHG.NGAY << "/" << p->info.PHG.THANG << "/" << p->info.PHG.NAM;//ngay thang nam
		Sleep(stop);
		if (p->info.PHG.TT == 0)
		{
			gotoXY(X + 72, Y + i + 2);
			cout << "trong "<< endl;//phong trong
		}
		else
		{
			gotoXY(X + 72, Y + i + 2);
			cout <<"co lop" << endl;//phong co lop
		}
		p = p->next;
		i++;
	}
}
//xuat danh sach khoa hoc
void Output(list2 &l2)
{
	int i = 1;
	Node *q;
	q = l2.head;
	while (q != NULL)
	{
		gotoXY(X+2,Y+2+i);
		Sleep(stop);
			cout << i;
		gotoXY(X+12, Y + 2 + i);
		Sleep(stop);
			cout <<q->Info.MAKH;//ma khoa hoc
		gotoXY(X+27, Y + 2 + i);
		Sleep(stop);
			cout << q->Info.TPH;//ten phong
		gotoXY(X + 43, Y + 2 + i);
		Sleep(stop);
			cout << q->Info.NKG.NGAY << "/" << q->Info.NKG.THANG << "/" << q->Info.NKG.NAM;//ngya khai giang
		Sleep(stop);
		if (q->Info.CAHOC == 1)
			{
				gotoXY(X+58, Y + 2 + i);
				cout << "9h-11h";//ca hoc
			}
		else if (q->Info.CAHOC == 2)
		{
			gotoXY(X+58, Y + 2 + i);
			cout << "15h-17h";//ca hoc
		}
		else if (q->Info.CAHOC == 3)
		{
			gotoXY(X+58, Y + 2 + i);
			cout << "19h-21h";//ca hoc
		}
		Sleep(stop);
		if (q->Info.BH1 == 8&& q->Info.BH2 != 8)//buoi hoc 1 = 8, buoi 2 != 8 
		{
			gotoXY(X+71, Y + 2 + i);
			cout << "Chu Nhat " << endl;
			gotoXY(X+83, Y + 2 + i);
			cout << "thu: " << q->Info.BH2;
		}
		else	if (q->Info.BH1 != 8 && q->Info.BH2 == 8)//buoi hoc 2 = 8, buoi 1 != 8
		{
			gotoXY(X+72, Y + 2 + i);
			cout << "thu: " << q->Info.BH1;
			gotoXY(X+83, Y + 2 + i);
			cout << "Chu Nhat" << endl;
		}
		else if (q->Info.BH1 != 8 && q->Info.BH2 != 8)// 2 buoi hoc != 8 
		{
			gotoXY(X+72, Y + 2 + i);
			cout << "thu: " << q->Info.BH1;
			gotoXY(X+83, Y + 2 + i);
			cout << "thu: " << q->Info.BH2;
		}
		i++;
		q = q->Next;
	}
	cout << "\n";
}

//------------------------------------------------------------------------------
//				VE BANG 

//bang them thong tin phong hoc
void Vebangthph()//bang them phong hoc
{
	gotoXY(33, 1);
	{
		TextColor(12);
		cout << "DANG THEM THONG TIN CAC PHONG HOC";
	}

	TextColor(14);
	for (int i = 7; i < 80; i++)//rong tren
	{
		gotoXY(X + i, Y);
		putchar(196);
	}
	for (int i = 7; i < 80; i++)//rong duoi
	{
		gotoXY(X + i, Y + 5);
		putchar(196);
	}

	for (int i = 7; i < 80; i++)//rong giua
	{

		gotoXY(X + i, Y + 2);
		putchar(196);
	}

	for (int i = 1; i < 5; i++)//cao giua 2
	{
		gotoXY(X + 22, Y + i);
		putchar(179);
	}
	for (int i = 1; i < 5; i++)//cao giua 1
	{
		gotoXY(X + 6, Y + i);
		putchar(179);
	}
	for (int i = 1; i < 5; i++)//cao giua 3
	{
		gotoXY(X + 40, Y + i);
		putchar(179);
	}
	gotoXY(64, 3);
	putchar(191);
	gotoXY(64, 8);
	putchar(217);

	for (int i = 1; i < 5; i++)//cao giua 4
	{
		gotoXY(X + 54, Y + i);
		putchar(179);
	}
	gotoXY(77, 3);
	putchar(191);
	gotoXY(77, 8);
	putchar(217);

	for (int i = 1; i < 5; i++)//cao giua 5
	{
		gotoXY(X + 67, Y + i);
		putchar(179);
	}
	gotoXY(90, 3);
	putchar(191);
	gotoXY(90, 8);
	putchar(217);

	for (int i = 1; i < 5; i++)//cao phai
	{
		gotoXY(X + 80, Y + i);
		putchar(179);
	}

	gotoXY(16, 3);
	putchar(218);
	gotoXY(16, 8);
	putchar(192);

	gotoXY(32, 3);
	putchar(191);
	gotoXY(32, 8);
	putchar(217);

	gotoXY(50, 3);//goc tren phai
	putchar(191);
	gotoXY(50, 8);//goc duoi phai
	putchar(217);


	TextColor(10);
	gotoXY(X + 12, 4);
	cout << "TANG";
	gotoXY(X + 28, 4);
	cout << "MAPHG";
	gotoXY(X + 44, 4);
	cout << "MAXSLOT";
	gotoXY(X + 58, 4);
	cout << "TIME";
	gotoXY(X + 72, 4);
	cout << "TTPHG";
}

//bang them thong tin khoa hoc
void Vebangthkh()//bang them khoa hoc
{
	gotoXY(35, 1);
	{
		TextColor(12);
		cout << "DANG NHAP THONG TIN KHOA HOC";
	}

	TextColor(14);
	for (int i = 6; i < 92; i++)//rong tren
	{
		gotoXY(X + i, Y);
		putchar(196);
	}
	for (int i = 7; i < 92; i++)//rong duoi
	{
		gotoXY(X + i, Y + 5);
		putchar(196);
	}

	for (int i = 1; i < 5; i++)//cao phai
	{
		gotoXY(X + 92, Y + i);
		putchar(179);
	}
	for (int i = 6; i < 92; i++)//rong giua
	{

		gotoXY(X + i, Y + 2);
		putchar(196);
	}

	for (int i = 1; i < 5; i++)//cao giua 2
	{
		gotoXY(X + 22, Y + i);
		putchar(179);
	}
	for (int i = 1; i < 5; i++)//cao giua 1
	{
		gotoXY(X + 6, Y + i);
		putchar(179);
	}
	for (int i = 1; i < 5; i++)//cao giua 3
	{
		gotoXY(X + 40, Y + i);
		putchar(179);
	}
	gotoXY(64, 3);
	putchar(191);
	gotoXY(64, 8);
	putchar(217);

	for (int i = 1; i < 5; i++)//cao giua 4
	{
		gotoXY(X + 54, Y + i);
		putchar(179);
	}
	gotoXY(77, 3);
	putchar(191);
	gotoXY(77, 8);
	putchar(217);

	for (int i = 1; i < 5; i++)//cao giua 5
	{
		gotoXY(X + 67, Y + i);
		putchar(179);
	}
	gotoXY(90, 3);
	putchar(191);
	gotoXY(90, 8);
	putchar(217);

	for (int i = 1; i < 5; i++)//cao giua 6
	{
		gotoXY(X + 80, Y + i);
		putchar(179);
	}

	gotoXY(16, 3);
	putchar(218);
	gotoXY(16, 8);
	putchar(192);

	gotoXY(32, 3);
	putchar(191);
	gotoXY(32, 8);
	putchar(217);

	gotoXY(50, Y);//goc tren phai
	putchar(218);
	gotoXY(50, 8);//goc duoi phai
	putchar(217);

	gotoXY(102, 3);//goc tren phai
	putchar(191);
	gotoXY(102, 8);//goc tren phai
	putchar(217);

	TextColor(10);
	gotoXY(X + 12, 4);
	cout << "MAKH";
	gotoXY(X + 28, 4);
	cout << "TENPHG";
	gotoXY(X + 46, 4);
	cout << "TIME";
	gotoXY(X + 58, 4);
	cout << "CA HOC";
	gotoXY(X + 72, 4);
	cout << "BUOI 1";
	gotoXY(X + 83, 4);
	cout << "BUOI 2";
}

//bang xuat thong tin khoa hoc
void Vebangkh()
{
	gotoXY(35, 1);
	{
		TextColor(12);
		cout << "DANH SACH THONG TIN CAC KHOA HOC";
	}

	TextColor(14);
	for (int i = 0; i < 92; i++)//rong tren
	{
		gotoXY(X + i, Y);
		putchar(196);
	}
	for (int i = 0; i < 92; i++)//rong duoi
	{
		gotoXY(X + i, Y + 20);
		putchar(196);
	}
	for (int i = 1; i < 20; i++)//cao trai
	{
		gotoXY(X - 1, Y + i);
		putchar(179);
	}
	for (int i = 1; i < 20; i++)//cao phai
	{
		gotoXY(X + 92, Y + i);
		putchar(179);
	}
	for (int i = 0; i < 92; i++)//rong giua
	{

		gotoXY(X + i, Y + 2);
		putchar(196);
	}

	for (int i = 1; i < 20; i++)//cao giua 2
	{
		gotoXY(X + 22, Y + i);
		putchar(179);
	}
	for (int i = 1; i < 20; i++)//cao giua 1
	{
		gotoXY(X + 6, Y + i);
		putchar(179);
	}
	for (int i = 1; i < 20; i++)//cao giua 3
	{
		gotoXY(X + 40, Y + i);
		putchar(179);
	}
	gotoXY(64, 3);
	putchar(191);
	gotoXY(64, 23);
	putchar(217);

	for (int i = 1; i < 20; i++)//cao giua 4
	{
		gotoXY(X + 54, Y + i);
		putchar(179);
	}
	gotoXY(77, 3);
	putchar(191);
	gotoXY(77, 23);
	putchar(217);

	for (int i = 1; i < 20; i++)//cao giua 5
	{
		gotoXY(X + 67, Y + i);
		putchar(179);
	}
	gotoXY(90, 3);
	putchar(191);
	gotoXY(90, 23);
	putchar(217);

	for (int i = 1; i < 20; i++)//cao giua 6
	{
		gotoXY(X + 80, Y + i);
		putchar(179);
	}

	gotoXY(16, 3);
	putchar(191);
	gotoXY(16, 23);
	putchar(217);

	gotoXY(32, 3);
	putchar(191);
	gotoXY(32, 23);
	putchar(217);

	gotoXY(9, 23);//goc tren phai
	putchar(192);
	gotoXY(9, 3);//goc tren trai
	putchar(218);
	gotoXY(50, 3);//goc duoi trai
	putchar(191);
	gotoXY(50, 23);//goc duoi phai
	putchar(217);

	gotoXY(102, 3);//goc tren phai
	putchar(191);
	gotoXY(102, 23);//goc tren phai
	putchar(217);

	TextColor(10);
	gotoXY(X + 1, 4);
	cout << "STT";
	gotoXY(X + 12, 4);
	cout << "MAKH";
	gotoXY(X + 28, 4);
	cout << "TENPHG";
	gotoXY(X + 46, 4);
	cout << "TIME";
	gotoXY(X + 58, 4);
	cout << "CA HOC";
	gotoXY(X + 72, 4);
	cout << "BUOI 1";
	gotoXY(X + 83, 4);
	cout << "BUOI 2";
}

//bang xuat thong tin khoa hoc
void Vebangph()
{
	gotoXY(33, 1);
	{
		TextColor(12);
		cout << "DANH SACH THONG TIN CAC PHONG HOC";
	}

	TextColor(14);
	for (int i = 0; i < 80; i++)//rong tren
	{
		gotoXY(X + i, Y);
		putchar(196);
	}
	for (int i = 0; i < 80; i++)//rong duoi
	{
		gotoXY(X + i, Y + 20);
		putchar(196);
	}
	for (int i = 1; i < 20; i++)//cao trai
	{
		gotoXY(X - 1, Y + i);
		putchar(179);
	}

	for (int i = 0; i < 80; i++)//rong giua
	{

		gotoXY(X + i, Y + 2);
		putchar(196);
	}

	for (int i = 1; i < 20; i++)//cao giua 2
	{
		gotoXY(X + 22, Y + i);
		putchar(179);
	}
	for (int i = 1; i < 20; i++)//cao giua 1
	{
		gotoXY(X + 6, Y + i);
		putchar(179);
	}
	for (int i = 1; i < 20; i++)//cao giua 3
	{
		gotoXY(X + 40, Y + i);
		putchar(179);
	}
	gotoXY(64, 3);
	putchar(191);
	gotoXY(64, 23);
	putchar(217);

	for (int i = 1; i < 20; i++)//cao giua 4
	{
		gotoXY(X + 54, Y + i);
		putchar(179);
	}
	gotoXY(77, 3);
	putchar(191);
	gotoXY(77, 23);
	putchar(217);

	for (int i = 1; i < 20; i++)//cao giua 5
	{
		gotoXY(X + 67, Y + i);
		putchar(179);
	}
	gotoXY(90, 3);
	putchar(191);
	gotoXY(90, 23);
	putchar(217);

	for (int i = 1; i < 20; i++)//cao phai
	{
		gotoXY(X + 80, Y + i);
		putchar(179);
	}

	gotoXY(16, 3);
	putchar(191);
	gotoXY(16, 23);
	putchar(217);

	gotoXY(32, 3);
	putchar(191);
	gotoXY(32, 23);
	putchar(217);

	gotoXY(9, 23);//goc tren phai
	putchar(192);
	gotoXY(9, 3);//goc tren trai
	putchar(218);
	gotoXY(50, 3);//goc duoi trai
	putchar(191);
	gotoXY(50, 23);//goc duoi phai
	putchar(217);


	TextColor(10);
	gotoXY(X + 1, 4);
	cout << "STT";
	gotoXY(X + 12, 4);
	cout << "TANG";
	gotoXY(X + 28, 4);
	cout << "MAPHG";
	gotoXY(X + 44, 4);
	cout << "MAXSLOT";
	gotoXY(X + 58, 4);
	cout << "TIME";
	gotoXY(X + 72, 4);
	cout << "TTPHG";
}
//------------------------------------------------------------------------------


str CONGVIEC[3] = { "CHUONG TRINH", "THONG TIN CHUNG", "THOAT" };//chon cong viec o menu chinh
str program[3] = { "BAT DAU", "HUONG DAN","LUI" };//chon cong viec trong menu PROGRAM
str back[1] = { "BACK" };//lui 1 buoc
//str Continue[1] = { "CONTINUE" };
enum TRANGTHAI {UP, DOWN,LEFT, RIGHT, ENTER};

int MENU(str CONGVIEC[3], int n);
void NOIDUNG1(int);//list chon str CONGVIEC
void NOIDUNG2(int);//list chon str program
void NOIDUNG3(int);//list chon str CONGVIEC.PRODUCT MAKERS
void NOIDUNG4(int);//list chon str program.Input
void NOIDUNG5(int);//list chon str program.Output


TRANGTHAI key(int k)
{
	if (k == 224)
	{
		char c;
		c = _getch();
		if (c = 72)
			return UP;
		if (c == 80)
			return DOWN;
		if (c == 77)
			return RIGHT;
		if (c == 75)
			return LEFT;
	}
	else if (k == 13)
		return ENTER;

}


//THONG TIN NHOM
void thongtinmakers()
{
	TextColor(10);
	gotoXY(12, vitri-2);
	Sleep(stop);
	cout << "THONG TIN THANH VIEN";
	TextColor(14);
	gotoXY(14, vitri);
	Sleep(stop);
		cout << "VO ANH QUYET		(graphic developer)";
	gotoXY(14, vitri+1);
	Sleep(stop);
		cout << "NGUYEN VAN SANG		(operator)";
	gotoXY(14, vitri + 2);
	Sleep(stop);
		cout << "NGUYEN LAM SON		(correctionist)";
	gotoXY(14, vitri+3);
	Sleep(stop);
		cout << "NGUYEN XUAN THINH		(coder, worker)";
	gotoXY(14, vitri + 4);
	Sleep(stop);
		cout << "DOAN CHI TOAN		(coder)";
	TextColor(10);
	Sleep(stop);
	gotoXY(12, vitri +6);
	cout << "THONG TIN LINK THAM KHAO";
	TextColor(14);
	Sleep(stop);
	gotoXY(14, vitri +8);
	cout << "http://diendan.congdongcviet.com/threads/t45558::tim-chuoi-con-trong-chuoi-cha.cpp";
	Sleep(stop);
	gotoXY(14, vitri + 9);
	cout << "https://www.youtube.com/watch?v=LY3F4BXVgr4";
}

//THONG TIN NHOM
int MAKERS(str back[1], int n)
{
	int TT = 0;
	int *mau = new int[n];
	for (int i = 0; i > n; i++)
		mau[i] = MAUCHU;
	mau[TT] = MAUNEN; //hien dang o thao tac thu nhat
	while (1)
	{
		clrscr();
		thongtinmakers();
		for (int i = 0; i < n; i++)
		{
			TextColor(mau[i]);
			gotoXY(12, vitri+12);
			cout << back[i] << endl;
		}
		int z = _getch();
		int TRANGTHAI = key(z);
		switch (TRANGTHAI)
		{
		case UP:
		{
			if (TT == n - 1)
				TT = 0;
			else
				TT++;
			break;
		}
		case DOWN:
		{
			if (TT == 0)
				TT = n - 1;
			else
				TT--;
			break;
		}
		case  ENTER:
			return TT;//thuc thi cong viec do khi nhan enter
		}
		//reset lai mau
		for (int i = 0; i < n; i++)
			mau[i] = MAUCHU;
		mau[TT] = MAUNEN;
		
	}
}


//CHUONG TRINH
int PROGRAM(str program[3], int n)
{
	int TT = 0;
	int *mau = new int[n];
	for (int i = 0; i > n; i++)
		mau[i] = MAUCHU;
	mau[TT] = MAUNEN; //hien dang o thao tac thu nhat
	while (1)
	{
		clrscr();
		gotoXY(45, 7);
		TextColor(12);
		cout << "PHAN MEM QUAN LY TRUONG HOC";
		for (int i = 0; i < n; i++)
		{
			TextColor(mau[i]);
			gotoXY(50, 9 + 2 * i);
			cout << program[i] << endl;
		}
		int z = _getch();
		int TRANGTHAI = key(z);
		switch (TRANGTHAI)
		{
		case UP:
		{
			if (TT == n - 1)
				TT = 0;
			else
				TT++;
			break;
		}
		case DOWN:
		{
			if (TT == 0)
				TT = n - 1;
			else
				TT--;
			break;
		}
		case  ENTER:
			return TT;//thuc thi cong viec do khi nhan enter
		}
		//reset lai mau
		for (int i = 0; i < n; i++)
			mau[i] = MAUCHU;
		mau[TT] = MAUNEN;
	}
}

//BAT DAU
void nhapxuat()
	{
		list1 l1;
		list2 l2;
		l1.head = l1.tail = NULL;
		l2.head = l2.tail = NULL;
		int k, c;
		do
		{
			clrscr();
			TextColor(10);
			gotoXY(X+10, Y+5);
			Sleep(stop);
			cout << "1 => NHAP THONG TIN";
			gotoXY(X+50, Y+5);
			Sleep(stop);
			cout << "2 => XUAT THONG TIN";
			gotoXY(X+10, Y+8);
			Sleep(stop);
			cout << "0 => LUI LAI";
			gotoXY(X+50, Y+8);
			Sleep(stop);
			cout << "CHON: ";
			gotoXY(X+56, Y+8);
			cin >> k;
			switch (k)
			{
			case 1:
			{
				do
				{
					//clrscr();
					gotoXY(X+10, Y + 18);
					Sleep(stop);
					cout << "1 => THEM THONG TIN PHONG HOC";
					gotoXY(X+50, Y + 18);
					Sleep(stop);
					cout << "2 => THEM THONG TIN KHOA HOC";
					gotoXY(X+10, Y + 21);
					Sleep(stop);
					cout << "0 => LUI LAI";
					gotoXY(X+50, Y + 21);
					Sleep(stop);
					cout << "CHON: ";
					gotoXY(X+56, Y + 21);
					cin >> c;
					switch (c)
					{
					case 1:
					{
						clrscr();
					//	cout << "dang them thong tin phong hoc";
						Vebangthph();
						tang t = NHAPTTTANG();
						InsertHead(l1, t);
						break;
						
					}
					case 2:
					{
						clrscr();
					//	cout << "dang them thong tin khoa hoc";
						Vebangthkh();
						khoahoc k = NHAPTTKHOAHOC();
						InsertHead(l2, k);
						break;
					}
					}
				} while (c != 0);
				break;
			}
			case 2:
			{
				do
				{
					//clrscr();
					gotoXY(X + 10, 25);
					Sleep(stop);
						cout << "1 => phong hoc ";
					gotoXY(X + 10, 26);
					Sleep(stop);
						cout << "2 => khoa hoc";
					gotoXY(X + 35, 25);
					Sleep(stop);
						cout << "3 => phong trong";
					gotoXY(X + 35, 26);
					Sleep(stop);
						cout << "4 => phong phu hop";
					gotoXY(X + 10, 27);
					Sleep(stop);
						cout << "0 => lui lai";
					gotoXY(X + 35, 27);
					Sleep(stop);
						cout << "chon: ";
					gotoXY(X + 43, 27);
						cin >> c;
					switch (c)
					{
					case 1:
					{
						clrscr();
						//cout << "\n CLASSROOM INFORMATION ";
						Vebangph();
						output(l1);
						break;
					}
					case 2:
					{
						clrscr();
						//cout << "\n SCIENCE INFORMATION ";
						Vebangkh();
						Output(l2);
						break;
					}
					case 3:
					{
						clrscr();
						xuatdsphongtrong(l1);
						Vebangph();
						break;
					}
					case 4:
					{
						clrscr();
						timk(l1);
						Vebangph();
						break;
					}
					}
				} while (c != 0);
				break;
			}
			}
		} while (k != 0);
		_getch();
	}

void huongdan()
{
	TextColor(15);
	gotoXY(40, 7);
	Sleep(stop);
	cout << "trong tung buoc nhap";
	gotoXY(40, 8);
	Sleep(stop);
	cout << "chung toi da co nhung cau lenh huong dan ban nhap rat cu the";
	Sleep(stop);
	gotoXY(40, 9);
	cout << "chuong trinh duoc vietsub rat de hieu nen chung toi khong huong dan gi them";
}

//HUONG DAN
int Output(str back[1], int n)
{
	list1 l1;
	list2 l2;
	l1.head = l1.tail = NULL;
	l2.head = l2.tail = NULL;
	int TT = 0;
	int *mau = new int[n];
	for (int i = 0; i > n; i++)
		mau[i] = MAUCHU;
	mau[TT] = MAUNEN; //hien dang o thao tac thu nhat
	while (1)
	{
		clrscr();
		TextColor(12);
		gotoXY(50, 4);
		cout << "HUONG DAN";
		huongdan();
		for (int i = 0; i < n; i++)
		{
			TextColor(mau[i]);
			gotoXY(40, 12 + 2 * i);
			cout << back[i] << endl;
		}
		int z = _getch();
		int TRANGTHAI = key(z);
		switch (TRANGTHAI)
		{
		case UP:
		{
			if (TT == n - 1)
				TT = 0;
			else
				TT++;
			break;
		}
		case DOWN:
		{
			if (TT == 0)
				TT = n - 1;
			else
				TT--;
			break;
		}
		case  ENTER:
			return TT;//thuc thi cong viec do khi nhan enter
		}
		//reset lai mau
		for (int i = 0; i < n; i++)
			mau[i] = MAUCHU;
		mau[TT] = MAUNEN;
	}
}

//BAT DAU
int Input(str back[1], int n)
{
	list1 l1;
	list2 l2;
	l1.head = l1.tail = NULL;
	l2.head = l2.tail = NULL;
	int TT = 0;
	int *mau = new int[n];
	for (int i = 0; i > n; i++)
		mau[i] = MAUCHU;
	mau[TT] = MAUNEN; //hien dang o thao tac thu nhat
	while (1)
	{
		clrscr();
		nhapxuat();
		output(l1);
		for (int i = 0; i < n; i++)
		{
			TextColor(mau[i]);
			gotoXY(45, 16 + 2 * i);
			cout << back[i] << endl;
		}
		int z = _getch();
		int TRANGTHAI = key(z);
		switch (TRANGTHAI)
		{
		case UP:
		{
			if (TT == n - 1)
				TT = 0;
			else
				TT++;
			break;
		}
		case DOWN:
		{
			if (TT == 0)
				TT = n - 1;
			else
				TT--;
			break;
		}
		case  ENTER:
			return TT;//thuc thi cong viec do khi nhan enter
		}
		//reset lai mau
		for (int i = 0; i < n; i++)
			mau[i] = MAUCHU;
		mau[TT] = MAUNEN;

	}
}

void NOIDUNG2(int tt)
{
		switch (tt)
		{
		case 0:
		{
			system("cls");
			NOIDUNG4(Input(back, 1));
			break;
		}
		case 1:
		{
			system("cls");
			NOIDUNG5(Output(back, 1));
			break;
		}
		case 2:
		{
			NOIDUNG1(MENU(CONGVIEC, 3));
		}
		}
}

void NOIDUNG4(int tt)
{
	NOIDUNG2(PROGRAM(program,3));
}

void NOIDUNG5(int tt)
{
	NOIDUNG2(PROGRAM(program, 3));
}

void NOIDUNG3(int tt)
{
	NOIDUNG1(MENU(CONGVIEC, 3));
}

//MENU GIAO DIEN 1 KHI BAT DAU CHAY CHUONG TRINH
void NOIDUNG1(int tt)
{
	switch (tt)
	{

		case 0:
		{
			system("cls");
			//MENU GIAO DIEN 2 KHI CHON LENH DAU TIEN
			NOIDUNG2(PROGRAM(program,3));
			break;
		}
		case 1:
		{
			system("cls");
			//thongtinmakers();
			NOIDUNG3(MAKERS(back,1));
			break;
		}
		case 2:
		{
			exit(1);
		}
	}
}

int MENU(str CONGVIEC[3], int n)
{
		int tt = 0; //bien chi ra dang o cong viec nao
		int *mau = new int[n];
		for (int i = 0; i > n; i++)
			mau[i] = MAUCHU;
		mau[tt] = MAUNEN; //hien dang o thao tac thu nhat
		while (1)
		{
			clrscr();
			gotoXY(45, 7);
				TextColor(12);
				cout << "PHAN MEM QUAN LY TRUONG HOC";
			for (int i = 0; i < n; i++)
			{
				TextColor(mau[i]);
				gotoXY(50,9+2*i);
				cout << CONGVIEC[i] << endl;
			}
			int z = _getch();
			int TRANGTHAI = key(z);
			switch (TRANGTHAI)
			{
			case UP:
			{
				if (tt == n - 1)
					tt = 0;
				else
					tt++;
				break;
			}
			case DOWN:
			{
				if (tt == 0)
					tt = n - 1;
				else
					tt--;
				break;
			}
			case  ENTER:
				return tt;//thuc la chon cong viec do khi nhan enter
			}
			//reset lai mau
			for (int i = 0; i < n; i++)
			mau[i] = MAUCHU;
		mau[tt] = MAUNEN;
		}
}

int main()
{
	list1 l1;
	list2 l2;
	l1.head = l1.tail = NULL;
	l2.head = l2.tail = NULL;
	while (1)
	{	
		system("cls");
		NOIDUNG1(MENU(CONGVIEC, 3));
		system("pause");
	}
	return 0;
}