#include"System.h"
void Sinhvien(fstream& f, char MSSV[], char Ten[], int STT, int soSV) {
	int d = 0, m = 0, y = 0;
	while (1) {
		system("cls");// MENU CHINH
		cout << "1. Thong tin ca nhan" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "2. Doi mat khau" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "3. Xem thoi khoa bieu" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "4. Xem diem" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "5. Dang xuat" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		int Chon;
		cout << "Nhap : "; cin >> Chon;
		while (Chon != 1 && Chon != 2 && Chon != 3 && Chon != 4 && Chon != 5) {
			cout << "Nhap lai : "; cin >> Chon;
		}
		switch (Chon) {
		case 1:ThongtinSinhvien(f, MSSV, STT); break;
		case 2:doiMKSV(f, MSSV, STT, soSV); break;
		case 3: {
			xemTKB(f, MSSV);
			break;
		}
		case 4: xemDiem(f, MSSV); break;
		default: return;
		}
	}
}

void Giangvien(fstream& f, char TK[], char MK[], int STT, int soGV) {
	int d = 0, m = 0, y = 0;
	char temp[100];
	while (1) {
		system("cls");// MENU CHINH
		cout << "1. Thong tin ca nhan" << endl;
		cout << "----------------------------------------------" << endl;
		cout << "2. Doi mat khau" << endl;
		cout << "----------------------------------------------" << endl;
		cout << "3. Nam hoc" << endl;
		cout << "----------------------------------------------" << endl;
		cout << "4. Hoc ki" << endl;
		cout << "----------------------------------------------" << endl;
		cout << "5. Xem danh sach sinh vien trong mot lop" << endl;
		cout << "----------------------------------------------" << endl;
		cout << "6. Xem danh sach khoa hoc" << endl;
		cout << "----------------------------------------------" << endl;
		cout << "7. Quan li diem" << endl;
		cout << "----------------------------------------------" << endl;
		cout << "8. Set up thoi gian" << endl;
		cout << "----------------------------------------------" << endl;
		cout << "9. Dang xuat" << endl;
		cout << "----------------------------------------------" << endl;
		int Chon;
		cout << "Nhap : "; cin >> Chon;
		while (Chon != 1 && Chon != 2 && Chon != 3 && Chon != 4 && Chon != 5 && Chon != 6 && Chon != 7 && Chon != 8 && Chon != 9) {
			cout << "Nhap lai : "; cin >> Chon;
		}
		switch (Chon) {
		case 1:ThongtinGiangvien(f, TK, STT); break;
		case 2:doiMK(f, TK, STT, soGV); break;
		case 3: {
			if (d != 1 && m != 9) {
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "Chi co the tao hoc ky vao dau nam (ngay 1 thang 9)" << endl;
				system("pause");
				continue;
			}
			taoNam(f, TK);
			break;
		}
		case 4: {
			if (m != 9 && m != 2 && m != 6) {
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "Chi co the tao hoc ky vao dau hoc ki (thang 9, thang 1, thang 6)" << endl;
				system("pause");
				continue;
			}
			taoHK(f,temp); break;
		}
		case 5: {
			xemDanhsachLop(f); break;
		}
		case 6:xemHKvsKH(f); break;
		case 7: quanliDiem(f); break;
		case 8:setupThoigian(d, m); break;
		default: return;
		}
	}
}