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
	char STT[3];
	char MSSV[15];
	char Ten[20];
	char Ho[20];
	char Gioitinh[5];
	char Ngaysinh[20];
	char idXH[20];
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