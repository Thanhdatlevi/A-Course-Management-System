#include"System.h"
int Dangnhap() {
	system("cls");
	int Chon;
	cout << "Dang nhap" << endl;
	cout << "1) Sinh vien" << endl;
	cout << "2) Giang vien" << endl;
	cout << "3) Thoat" << endl;
	cout << "Nhap : " << endl;
	cin >> Chon;
	while (Chon != 2 && Chon != 1 && Chon!=3 ) {
		cout << "Nhap loi vui long nhap lai : ";
		cin >> Chon;
	}
	if (Chon == 1) return 1;
	if (Chon == 2) return 2;
	else return 3;
}
void ThongtinGiangvien(fstream &f,char TK[],int STT ) {
	GV *Ten = new GV[STT];
	f.open("admin.csv", ios::in);
	for (int i = 0; i < STT; i++) {
		f.getline(Ten[i].MS, 50, ',');
		f.getline(Ten[i].HoTen, 100, ',');
		f.getline(Ten[i].Tuoi, 4, ',');
		f.getline(Ten[i].Gioitinh, 50, ',');
		f.getline(Ten[i].Nganh, 50, ',');
		f.getline(Ten[i].Monday, 50, '\n');
	}
	cout << Ten[STT-1].HoTen << "  " << Ten[STT - 1].Tuoi << "  " << Ten[STT - 1].Gioitinh << "  " << Ten[STT - 1].Nganh << "  " << Ten[STT - 1].Monday << endl;
	f.close();
	delete[]Ten;
	cout << "An Enter de quay lai" << endl;
	system("pause");
}

void doiMK(fstream& f, char TK[], int STT,int soGV) {
	char temp[50];
	GV* Ten = new GV[soGV];
	cout << "Nhap mat khau muon thay doi : ";
	cin.ignore();
	cin.getline(temp, 50);
	f.open("admin.csv", ios::in);
	for (int i = 0; i < soGV; i++) {
		f.getline(Ten[i].MS, 50, ',');
		f.getline(Ten[i].HoTen, 100, ',');
		f.getline(Ten[i].Tuoi, 4, ',');
		f.getline(Ten[i].Gioitinh, 50, ',');
		f.getline(Ten[i].Nganh, 50, ',');
		f.getline(Ten[i].Monday, 50, '\n');
	}
	f.close();
	f.open("admin.csv", ios::out);
	while (!f.is_open()) {
		cout << "Error File Open" << endl;
		cout << "Nhap lai ten file : ";
		cin.getline(TK, 20);
		f.open(TK, ios::out);
	}
	for (int i = 0; i < soGV; i++) {
		if(i!=STT-1) f << Ten[i].MS << "," << Ten[i].HoTen << "," << Ten[i].Tuoi << "," << Ten[i].Gioitinh << "," << Ten[i].Nganh << "," << Ten[i].Monday << endl;
		else f << temp << "," << Ten[i].HoTen << "," << Ten[i].Tuoi << "," << Ten[i].Gioitinh << "," << Ten[i].Nganh << "," << Ten[i].Monday << endl;
	}
	cout << "Da thay doi mat khau thanh cong"<<endl;
	f.close();
	delete[]Ten;
	cout << "An Enter de quay lai" << endl;
	system("pause");
}
void tao1nam(fstream& f) {
	Nam nam,nam1;
	fstream f1;
	cout << "Nhap vao nieen khoa (xx-xx) : ";
	cin.ignore();
	cin.getline(nam.Tennam, 20);
	cout << "Nhap thoi gian bat dau : ";
	cout << "Ngay :";
	cin.getline(nam.ngayBD, 4); 
	cout << "Thang : ";
	cin.getline(nam.thangBD, 20);
	cout << "Nam : ";
	cin.getline(nam.namBD, 20);
	cout << "Nhap thoi gian ket thuc : ";
	cout << "Ngay :";
	cin.getline(nam.ngayKT, 4);
	cout << "Thang : ";
	cin.getline(nam.thangKT, 20);
	cout << "Nam : ";
	cin.getline(nam.namKT, 20);
	int k = 0;
	f.open("Namhoc.csv", ios::in);
	while (!f.eof()) {
		char a[100];
		f.getline(a, 100);
		k++;
	}
	f.close();
	f.open("Namhoc.csv", ios::app);
	f << k << "," << nam.Tennam<<"," << nam.ngayBD << "," << nam.thangBD << "," << nam.namBD << "," << nam.ngayKT << "," << nam.thangKT << "," << nam.namKT << endl;
	f.close();
	char temp1[20];
	strcpy_s(temp1, nam.Tennam);
	strcat_s(temp1, "_HK.csv");
	f.open(temp1, ios::out);
	f.close();
	strcat_s(nam.Tennam, ".csv");
	f.open(nam.Tennam, ios::out);
	f.close();
	cout << "Hoc ky da duoc tao" << endl;
	cout << "An Enter de quay lai" << endl;
	system("pause");
}
void themLop(fstream& f) {
	char newclass[10];
	cin.ignore();
	cout << "Nhap lop can them vao : ";
	cin.getline(newclass, 9);
	int dem = 0;
	f.open("Namhoc.csv", ios::in);
	while (!f.eof()) {
		char temp[100];
		f.getline(temp, 100, '\n');
		dem++;
	}
	dem--;
	f.close();
	Nam* nam = new Nam[dem];
	f.open("Namhoc.csv", ios::in);
	for(int i=0;i<dem;i++){
		f.getline(nam[i].STT, 3, ',');
		f.getline(nam[i].Tennam, 6, ',');
		char a[100];
		f.getline(a, 100, '\n');
		cout << nam[i].STT << ". " << nam[i].Tennam << endl;
	}
	f.close();
	int temp,k;
	cout << "Chon nam de them lop : ";
	cin >> temp;
	int dem1 = 0;
	for (int i = 0; i < dem; i++) {
		k = stoi(nam[i].STT);
		if (temp == k) {
			strcat_s(nam[i].Tennam, ".csv");
			f.open(nam[i].Tennam, ios::in);
			while (!f.eof()) {
				char temp1[50];
				f.getline(temp1, 50, '\n');
				dem1++;
			}
			dem1--;
			f.close();
			f.open(nam[i].Tennam, ios::app);
			break;
		}
	}
	f << dem1 + 1 << "," << newclass << endl;
	f.close();
	system("pause");
}
void taoNam(fstream& f, char TK[]) {
	while (1) {
		system("cls");
		cout << "1. Tao 1 nam" << endl;
		cout << "2. Them lop vao 1 nam hoc" << endl;
		cout << "3. Thoat" << endl;
		int Chon;
		cout << "Nhap : "; cin >> Chon;
		while (Chon != 1 && Chon != 2&&Chon!=3) {
			cout << "Nhap lai : "; cin >> Chon;
		}
		if (Chon == 1) tao1nam(f);
		else if (Chon == 2) themLop(f);
		else return;
	}
}
void xemDanhsachLop(fstream& f) {
	while (1) {
		system("cls");
		fstream f1;
		int dem = 0;
		f.open("Namhoc.csv", ios::in);
		while (!f.eof()) {
			char temp[100];
			f.getline(temp, 100, '\n');
			dem++;
		}
		dem--;
		Nam* nam = new Nam[dem];
		f.close();
		f.open("Namhoc.csv", ios::in);
		char temp[100];
		for (int i = 0; i < dem; i++) {
			f.getline(nam[i].STT, 3, ',');
			f.getline(nam[i].Tennam, 15, ',');
			char a[100];
			f.getline(a, 100, '\n');
			cout << nam[i].STT << ". " << nam[i].Tennam << endl;
		}
		f.close();
		cin.ignore();
		cout << "Chon nam hoc de xem danh sach lop : " << endl;
		int Chon;
		cin >> Chon;
		for (int i = 0; i < dem; i++) {
			if (stoi(nam[i].STT) == Chon) {
				strcat_s(nam[i].Tennam, ".csv");
				f.open(nam[i].Tennam, ios::in);
				dem = 0;
				while (!f.eof()) {
					char temp[50];
					f.getline(temp, 50, '\n');
					dem++;
				}
				dem--;
				f.close();
				f.open(nam[i].Tennam, ios::in);
				Lop* lop = new Lop[dem];
				for (int j = 0; j < dem; j++) {
					f.getline(lop[j].STT, 3, ',');
					f.getline(lop[j].TenLop, 20, '\n');
					cout << lop[j].STT << ". " << lop[j].TenLop << endl;
				}
				f.close();
				cin.ignore();
				cout << "Chon lop de coi danh sach : " << endl;
				cin >> Chon;
				for (int j = 0; j < dem; j++) {
					if (stoi(lop[j].STT) == Chon) {
						strcat_s(lop[j].TenLop, ".csv");
						f.open(lop[j].TenLop, ios::in);
						dem = 0;
						while (!f.eof()) {
							char temp[100];
							f.getline(temp, 100, '\n');
							dem++;
						}dem--;
						f.close();
						f.open(lop[j].TenLop, ios::in);
						DSSV* sv = new DSSV[dem];
						for (int i = 0; i < dem; i++) {
							f.getline(sv[i].STT, 3, ',');
							f.getline(sv[i].MSSV, 15, ',');
							f.getline(sv[i].Ten, 20, ',');
							f.getline(sv[i].Ho, 20, ',');
							f.getline(sv[i].Gioitinh, 5, ',');
							f.getline(sv[i].Ngaysinh, 20, ',');
							f.getline(sv[i].idXH, 50, '\n');
							cout << sv[i].STT << "     " << sv[i].MSSV << "     " << sv[i].Ten << "     " << sv[i].Ho << "     " << sv[i].Gioitinh << "     " << sv[i].Ngaysinh << "     " << sv[i].idXH << "     " << endl;
						}
						f.close();
						break;
					}
				}
				break;
			}
		}
		cout << "1. Xem danh sach lop khac            2. Thoat" << endl;
		cout << "Nhap : ";
		cin >> Chon;
		if (Chon != 1 && Chon != 2) {
			cout << "Nhap lai : "; cin >> Chon;
		}
		if (Chon == 2) return;
	}
}
void setupThoigian(int &d, int &m) {
	cout << "Ngay :"; cin >> d;
	cout << "Ngay :"; cin >> m;
}
void addKH(char HK[]) {
	system("cls");
	fstream f;
	f.open(HK, ios::out);
	KhoaHoc KHoc;
	while (1) {
		cin.ignore();
		cout << "ID Khoa Hoc ";
		cin.getline(KHoc.id, 10);
		cout << "Ten Khoa Hoc : ";
		cin.getline(KHoc.TenKH, 30);
		cout << "Ten Lop : ";
		cin.getline(KHoc.TenLop, 30);
		cout << "Ten Giao Vie : ";
		cin.getline(KHoc.TenGV, 50);
		cout << "So Tin Chi : ";
		cin.getline(KHoc.STC, 5);
		cout << "So luong sinh vien : ";
		cin.getline(KHoc.MaxSV, 4);
		cout << "Thu : ";
		cin.getline(KHoc.Thu, 4);
		cout << "Tiet : ";
		cin.getline(KHoc.ses, 3);
		f << KHoc.id << "," << KHoc.TenKH << "," << KHoc.TenLop << "," << KHoc.TenGV << "," << KHoc.STC << "," << KHoc.MaxSV << "," << KHoc.Thu << "," << KHoc.ses << endl;
		fstream f1;
		strcat_s(KHoc.TenKH, "-");
		strcat_s(KHoc.TenKH, KHoc.id);
		strcat_s(KHoc.TenKH, ".csv");
		f1.open(KHoc.TenKH, ios::out);
		f1.close();
		cout << "Nhap ten file DS Sinh Vien : ";
		char temp[20];
		cin.getline(temp, 20);
		strcat_s(temp, ".csv");
		int dem = 0;
		f1.open(temp, ios::in);
		while (!f1.eof()) {
			char temp1[100];
			f1.getline(temp1, 100, '\n');
			dem++;
		}dem--;
		f1.close();
		DSSV* sv = new DSSV[dem];
		f1.open(temp, ios::in);
		for (int i = 0; i < dem; i++) {
			f1.getline(sv[i].STT, 3, ',');
			f1.getline(sv[i].MSSV, 15, ',');
			f1.getline(sv[i].Ten, 20, ',');
			f1.getline(sv[i].Ho, 20, ',');
			f1.getline(sv[i].Gioitinh, 5, ',');
			f1.getline(sv[i].Ngaysinh, 20, ',');
			f1.getline(sv[i].idXH, 20, '\n');
		}
		f1.close();
		f1.open(KHoc.TenKH, ios::out);
		for (int i = 0; i < dem; i++) {
			f1 << sv[i].STT << "," << sv[i].MSSV << "," << sv[i].Ten << "," << sv[i].Ho << "," << sv[i].Gioitinh << "," << sv[i].Ngaysinh << "," << sv[i].idXH << endl;
		}
		f1.close();
		cout << "1. Them khoa hoc             2.Thoat" << endl;
		int Chon;
		cout << "Nhap : "; cin >> Chon;
		if (Chon == 2) {
			f.close();
			return;
		}
	}
	f.close();
}
void listKH(char HK[]) {
	system("cls");
	fstream f;
	int dem = 0;
	f.open(HK, ios::in);
	while (!f.eof()) {
		char temp[100];
		f.getline(temp, 100, '\n');
		dem++;
	}
	f.close();
	KhoaHoc KHoc;
	f.open(HK, ios::in);
	while (!f.eof()) {
		f.getline(KHoc.id, 10, ',');
		f.getline(KHoc.TenKH, 30, ',');
		f.getline(KHoc.TenLop, 30);
		f.getline(KHoc.TenGV, 50);
		f.getline(KHoc.STC, 5);
		f.getline(KHoc.MaxSV, 4);
		f.getline(KHoc.Thu, 4);
		f.getline(KHoc.ses, 3);
		cout << KHoc.id << "  " << KHoc.TenKH << "  " << KHoc.TenLop << "  " << KHoc.TenGV << "  " << KHoc.STC <<"  " << KHoc.MaxSV << "  " << KHoc.Thu << "  " << KHoc.ses ;
		cout << endl;
	}
	f.close();
}
void updateKH(char hkNam[]) {

}
void taoHK(fstream& f) {
	while (1) {
		system("cls");
		HK hk;
		cin.ignore();
		cout << "Nhap thoi gian bat dau hoc ky"<<endl;
		cout << "Ngay : "<<endl;
		cin.getline(hk.ngayBD, 4);
		cout << "Thang : " << endl;
		cin.getline(hk.thangBD, 4); 
		cout << "Nam : " << endl;
		cin.getline(hk.namBD, 7); 
		cout << "Nhap thoi gian ket thuc hoc ky" << endl;
		cout << "Ngay : " << endl;
		cin.getline(hk.ngayKT, 4); 
		cout << "Thang : " << endl;
		cin.getline(hk.thangKT, 4); 
		cout << "Nam : " << endl;
		cin.getline(hk.namKT, 7);
		if (stoi(hk.thangBD) == 9) strcpy_s(hk.HKthu, "1");
		else if (stoi(hk.thangBD) == 3) strcpy_s(hk.HKthu, "2");
		else strcpy_s(hk.HKthu, "3");
		cout << hk.HKthu<<endl;
	Chonlai:
		system("cls");
		int dem = 0;
		f.open("Namhoc.csv", ios::in);
		while (!f.eof()) {
			char temp[100];
			f.getline(temp, 100, '\n');
			dem++;
		}
		dem--;
		f.close();
		Nam* nam = new Nam[dem];
		f.open("Namhoc.csv", ios::in);
		for (int i = 0; i < dem; i++) {
			f.getline(nam[i].STT, 3, ',');
			f.getline(nam[i].Tennam, 15, ',');
			char a[100];
			f.getline(a, 100, '\n');
			cout << nam[i].STT << ". " << nam[i].Tennam << endl;
		}
		f.close();
		int Chon;
		cout << "Chon nam hoc cua hoc ky : " << endl;
		cin >> Chon;
		for (int i = 0; i < dem; i++) {
			if (stoi(nam[i].STT) == Chon) {
				strcpy_s(hk.Nam, nam[i].Tennam);
				strcat_s(nam[i].Tennam, "_HK.csv");
				f.open(nam[i].Tennam, ios::in);
				dem = 0;
				while (!f.eof()) {
					char temp1[100];
					f.getline(temp1, 100, '\n');
					dem++;
				}dem--;
				f.close();
				f.open(nam[i].Tennam, ios::in);
				HK* hk1 = new HK[dem];
				for (int j = 0; j < dem; j++) {
					f.getline(hk1[j].HKthu, 3, ',');
					cout << hk1[j].HKthu;
					f.getline(hk1[j].Nam, 7, ',');
					f.getline(hk1[j].ngayBD,4 , ',');
					f.getline(hk1[j].thangBD, 4, ',');
					f.getline(hk1[j].namBD, 7, ',');
					f.getline(hk1[j].ngayKT, 4, ',');
					f.getline(hk1[j].thangKT, 4, ',');
					f.getline(hk1[j].namKT, 7, '\n');
					if (stoi(hk1[j].HKthu) == stoi(hk.HKthu)) {
						cout << "Hoc ky " << hk.HKthu << " da ton tai trong nam hoc" << endl;
						f.close();
						system("pause");
						goto Chonlai;
					}
				}
				f.close();
				f.open(nam[i].Tennam, ios::trunc);
				f.close();
				f.open(nam[i].Tennam, ios::out);
				for (int j = 0; j < dem; j++) {
					f << hk1[j].HKthu << "," << hk1[j].Nam << "," << hk1[j].ngayBD << "," << hk1[j].thangBD << "," << hk1[j].namBD << "," << hk1[j].ngayKT << "," << hk1[j].thangKT << "," << hk1[j].namKT << endl;
				}
				f << hk.HKthu << "," << hk.Nam << "," << hk.ngayBD << "," << hk.thangBD << "," << hk.namBD << "," << hk.ngayKT << "," << hk.thangKT << "," << hk.namKT << endl;
				f.close();
				strcat_s(hk.Nam, "-");
				strcat_s(hk.Nam,hk.HKthu);
				strcat_s(hk.Nam, ".csv");
				addKH(hk.Nam);
				cout << "1. Xem danh sach khoa hoc";
				cout << "2. Cap nhap danh sach";
				listKH(hk.Nam);
				updateKH(hk.Nam);
				system("pause");
			}
		}

		return;
	}
}
void them1SV(fstream& f) {
	system("cls");
	int dem = 0;
	DSSV sv1;
	cin.ignore();
	cout << "Nhap thong tin sinh vien can them vao : " << endl;
	cout << "Nhap ma so sinh vien : ";
	cin.getline(sv1.MSSV, 15);
	cout << "Nhap ten sinh vien : ";
	cin.getline(sv1.Ten, 20);
	cout << "Nhap ho va ten dem sinh vien : ";
	cin.getline(sv1.Ho, 20);
	cout << "Nhap gioi tinh sinh vien : ";
	cin.getline(sv1.Gioitinh, 5);
	cout << "Nhap ngay sinh sinh vien : ";
	cin.getline(sv1.Ngaysinh, 20);
	cout << "Nhap id xa hoi sinh vien : ";
	cin.getline(sv1.idXH, 20);
	f.open("Namhoc.csv", ios::in);
	while (!f.eof()) {
		char temp[100];
		f.getline(temp, 100, '\n');
		dem++;
	}
	dem--;
	f.close();
	Nam* nam = new Nam[dem];
	f.open("Namhoc.csv", ios::in);
	for (int i = 0; i < dem; i++) {
		f.getline(nam[i].STT, 3, ',');
		f.getline(nam[i].Tennam, 15, ',');
		char a[100];
		f.getline(a, 100, '\n');
		cout << nam[i].STT << ". " << nam[i].Tennam << endl;
	}
	f.close();
	int Chon;
	cout << "Chon nam hoc : " << endl;
	cin >> Chon;
	for (int i = 0; i < dem; i++) {
		if (stoi(nam[i].STT) == Chon) {
			strcat_s(nam[i].Tennam, ".csv");
			f.open(nam[i].Tennam, ios::in);
			dem = 0;
			while (!f.eof()) {
				char temp[50];
				f.getline(temp, 50, '\n');
				dem++;
			}
			dem--;
			f.close();
			f.open(nam[i].Tennam, ios::in);
			Lop* lop = new Lop[dem];
			for (int j = 0; j < dem; j++) {
				f.getline(lop[j].STT, 3, ',');
				f.getline(lop[j].TenLop, 20, '\n');
				cout << lop[j].STT << ". " << lop[j].TenLop << endl;
			}
			f.close();
			cin.ignore();
			cout << "Chon lop de coi danh sach : " << endl;
			cin >> Chon;
			for (int j = 0; j < dem; j++) {
				if (stoi(lop[j].STT) == Chon) {
					strcat_s(lop[j].TenLop, ".csv");
					f.open(lop[j].TenLop, ios::in);
					dem = 0;
					while (!f.eof()) {
						char temp[100];
						f.getline(temp, 100, '\n');
						dem++;
					}dem--;
					f.close();
					DSSV* sv = new DSSV[dem];
					f.open(lop[j].TenLop, ios::in);
					for (int i = 0; i < dem; i++) {
						f.getline(sv[i].STT, 3, ',');
						f.getline(sv[i].MSSV, 15, ',');
						f.getline(sv[i].Ten, 20, ',');
						f.getline(sv[i].Ho, 20, ',');
						f.getline(sv[i].Gioitinh, 5, ',');
						f.getline(sv[i].Ngaysinh, 20, ',');
						f.getline(sv[i].idXH, 20, '\n');
					}
					f.close();
					f.open(lop[j].TenLop, ios::out);
					for (int i = 0; i < dem; i++) {
						f << sv[i].STT << "," << sv[i].MSSV << "," << sv[i].Ten << "," << sv[i].Ho << "," << sv[i].Gioitinh << "," << sv[i].Ngaysinh << "," << sv[i].idXH << endl;
					}
					f<<dem+1 << "," << sv1.MSSV << "," << sv1.Ten << "," << sv1.Ho << "," << sv1.Gioitinh << "," << sv1.Ngaysinh << "," << sv1.idXH << endl;
					f.close();
					break;
				}
			}
			break;
		}
	}
}
void Giangvien(fstream &f,char TK[],char MK[],int STT,int soGV) {
	int d = 0, m = 0;
	while (1) {
		system("cls");
		cout << "1. Thong tin ca nhan" << endl;
		cout << "2. Doi mat khau" << endl;
		cout << "3. Tao nam hoc" << endl;
		cout << "4. Them 1 sinh vien vao mot lop" << endl;
		cout << "5. Tao hoc ki" << endl;
		cout << "6. Xem danh sach lop" << endl;
		cout << "7. Set up thoi gian" << endl;
		cout << "8. Dang xuat" << endl;
		int Chon;
		cout << "Nhap : "; cin >> Chon;
		while (Chon != 1 && Chon != 2 && Chon != 3 && Chon != 4&&Chon!=5&& Chon != 6&&Chon != 7 && Chon != 8) {
			cout << "Nhap lai : "; cin >> Chon;
		}
		switch (Chon) {
		case 1:ThongtinGiangvien(f, TK, STT); break;
		case 2:doiMK(f, TK, STT, soGV); break;
		case 3: {
			if (d != 1 && m != 9) {
				cout << "Chi co the tao hoc ky vao dau nam (ngay 1 thang 9)" << endl;
				system("pause");
				continue;
			}
			taoNam(f, TK);
			break; 
		}
		case 4: {
			them1SV(f);
			break;
		}
		case 5: {
			if (d != 1 && m != 9) {
				cout << "Chi co the tao hoc ky vao dau nam (ngay 1 thang 9)" << endl;
				system("pause");
				continue;
			}
			taoHK(f); break; 
		}
		case 6:xemDanhsachLop(f); break;
		case 7 : setupThoigian(d, m); break;
		default: return;
		}
	}
}
void nhapTK() {
	while(1){
	DN:
		int x = Dangnhap();
		if (x == 3) { return; }
		if (x == 2) {
			cout << system("cls");
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
			cout << "1. Dang nhap                2. Quay lai"<<endl;
			cout << "Nhap : "; cin >> Chon;
			if (Chon != 1 && Chon != 2) {
				cout << "Nhap lai : "; cin >> Chon;
			}
			if (Chon == 2) goto DN;
			else Giangvien(f, TK, MK, k, soGV);
		}
	}
}
int main() {
	nhapTK();
}