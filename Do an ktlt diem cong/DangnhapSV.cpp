#include"System.h"


int Dangnhap() {// CHON DANG NHAP VAO TAI KHOAN SINH VIEN HAY TAI KHOAN GIAO VIEN
	system("cls");
	int Chon;
	cout << "Dang nhap" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "1) Sinh vien" << endl;
	cout << "2) Giang vien" << endl;
	cout  << "3) Thoat" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Nhap : " ;
	cin >> Chon;
	while (Chon != 2 && Chon != 1 && Chon != 3) {
		cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "Nhap loi vui long nhap lai : ";
		cin >> Chon;
	}
	if (Chon == 1) return 1;
	if (Chon == 2) return 2;
	else return 3;
}

void nhapTK() {
	while (1) {// NHAP TAI KHOA TRONG FILE ADMIN
	DN:
		int x = Dangnhap();
		if (x == 1) {
			system("cls");
			fstream f;
			char MK[20];
			char TK[20];
			f.open("Student.csv", ios::in);
			int soHS = 0;
			while (!f.eof()) {
				char a[100];
				f.getline(a, 100, '\n');
				soHS++;
			}
			f.close();
			DSSV* SV = new DSSV[soHS];
			cout << "Tai khoan : ";
			cin.ignore();
			cin.getline(TK, 20);
			cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "Mat Khau : ";
			cin.getline(MK, 20);
			f.open("Student.csv", ios::in);
			int k = 0;
			char temp[100];
			for (k; k < soHS; k++) {
				char temp[50];
				f.getline(SV[k].STT, 3, ',');
				f.getline(SV[k].MSSV, 15, ',');
				f.getline(SV[k].Ten, 20, ',');
				f.getline(SV[k].Ho, 20, ',');
				f.getline(SV[k].Gioitinh, 5, ',');
				f.getline(SV[k].Ngaysinh, 20, ',');
				f.getline(SV[k].idXH, 20, ',');
				f.getline(SV[k].MKSV, 20, '\n');
				if (strcmp(TK, SV[k].MSSV) == 0) {
					while (strcmp(MK, SV[k].MKSV) != 0) {
						cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
						cout << "Sai mat khau vui long nhap lai mat khau : ";
						cin.getline(MK, 20);
					}
					f.close();
					int Chon;
					cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
					cout << "1. Dang nhap                2. Quay lai" << endl;
					cout << "Nhap : "; cin >> Chon;
					if (Chon != 1 && Chon != 2) {
						cout << "Nhap lai : "; cin >> Chon;
					}
					if (Chon == 2) goto DN;
					else Sinhvien(f, SV[k].MSSV, SV[k].Ten, k, soHS);
					delete[]SV;
					break;
				}
			}

		}
		if (x == 3) { return; }
		if (x == 2) {
			system("cls");
			fstream f;
			char MK[20];
			char TK[20];
			f.open("admin.csv", ios::in);
			int soGV = 0;
			while (!f.eof()) {
				char a[100];
				f.getline(a, 100, '\n');
				soGV++;
			}
			f.close();
			GV* admin = new GV[soGV];
			cout << "Tai khoan : ";
			cin.ignore();
			cin.getline(TK, 20);
			cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "Mat Khau : ";
			cin.getline(MK, 20);
			f.open("admin.csv", ios::in);
			int k = 0;
			for (k; k < soGV; k++) {
				char temp[50];
				f.getline(admin[k].MS, 50, ',');
				f.getline(admin[k].HoTen, 50, ',');

				f.getline(temp, 50);
				if (strcmp(TK, admin[k].HoTen) == 0) {
					while (strcmp(MK, admin[k].MS) != 0) {
						cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
						cout << "Sai mat khau vui long nhap lai mat khau : ";
						cin.getline(MK, 20);
					}
					break;
				}
			}
			delete[]admin;
			k++;
			f.close();
			int Chon;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "1. Dang nhap                2. Quay lai" << endl;
			cout << "Nhap : "; cin >> Chon;
			if (Chon != 1 && Chon != 2) {
				cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "Nhap lai : "; cin >> Chon;
			}
			if (Chon == 2) goto DN;
			else Giangvien(f, TK, MK, k, soGV);
		}
	}
}