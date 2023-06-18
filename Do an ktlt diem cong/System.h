#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<direct.h>
using namespace std;

typedef struct GV {
	char MS[50];
	char HoTen[100];
	char Tuoi[4];
	char Gioitinh[50];
	char Nganh[50];
	char Monday[50];
};
typedef struct Nam {
	char STT[3];
	char Tennam[50];
	char ngayBD[4];
	char thangBD[4];
	char namBD[7];
	char ngayKT[4];
	char thangKT[4];
	char namKT[7];
};
typedef struct Lop {
	char STT[3];
	char TenLop[20];
};
typedef struct DSSV {
	char MKSV[20];
	char STT[3];
	char MSSV[15];
	char Ten[20];
	char Ho[50];
	char Gioitinh[5];
	char Ngaysinh[20];
	char idXH[20];
	char totalDiem[3];
	char finalDiem[3];
	char midDiem[3];
	char otherDiem[3];
};

typedef struct HK {
	char HKthu[3];
	char Nam[20];
	char ngayBD[4];
	char thangBD[4];
	char namBD[7];
	char ngayKT[4];
	char thangKT[4];
	char namKT[7];
};

typedef struct KhoaHoc {
	char id[10];
	char TenKH[100];
	char TenLop[30];
	char TenGV[50];
	char STC[5];
	char MaxSV[4];
	char Thu[4];
	char ses[3];
};

void Sinhvien(fstream& f, char MSSV[], char Ten[], int STT, int soSV);
void Giangvien(fstream& f, char TK[], char MK[], int STT, int soGV);
int Dangnhap();
void nhapTK();
void demDong(fstream& f, int& dem);
void ThongtinGiangvien(fstream& f, char TK[], int STT);
void doiMK(fstream& f, char TK[], int STT, int soGV);
void taoNam(fstream& f, char TK[]);
void tao1nam(fstream& f);
void themLop(fstream& f);
void them1SV(fstream& f);
void them1DS(fstream& f);
void xemDanhsachLop(fstream& f);
void xemHKvsKH(fstream& f);
void taoHK(fstream& f);
void addKH(char HK[]);
void listKH(char HK[]);
void updateKH(char HK[]);
void add1SV(char HK[]);
void delete1SV(char HK[]);
void delete1Course(char HK[]);
void quanliDiem(fstream& f);
void nhapDiem(fstream& f);
void themDiem(fstream& f);
void xemDiem1KH(fstream& f);
void capnhatDiem(fstream& f);
void ThongtinSinhvien(fstream& f, char MSSV[], int STT);
void doiMKSV(fstream& f, char MSSV[], int STT, int soSV);
void xemTKB(fstream& f, char MSSV[]);
void setupThoigian(int& d, int& m);
void xemDiem(fstream& f, char MSSV[]);