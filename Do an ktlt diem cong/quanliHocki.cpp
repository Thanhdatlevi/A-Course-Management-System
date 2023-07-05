#include"System.h"

void addKH(char HK[]) {// THEM KHOA HOC VAO HOC KI
	system("cls");
	fstream f;
	char temp1[100];
	strcpy_s(temp1, strlen(HK) + 1, HK);
	strcat_s(temp1, "\\");
	strcat_s(temp1, "DSKH.csv");
	f.open(temp1, ios::out);
	KhoaHoc KHoc;
	while (1) {
		cin.ignore();
		cout << "ID Khoa Hoc : ";
		cin.getline(KHoc.id, 10);
		cout << "Ten Khoa Hoc : ";
		cin.getline(KHoc.TenKH, 30);
		cout << "Ten Lop : ";
		cin.getline(KHoc.TenLop, 30);
		cout << "Ten Giao Vien : ";
		cin.getline(KHoc.TenGV, 50);
		cout << "So Tin Chi : ";
		cin.getline(KHoc.STC, 5);
		cout << "So luong sinh vien : ";
		cin.getline(KHoc.MaxSV, 4);
		cout << "Thu : ";
		cin.getline(KHoc.Thu, 4);
		cout << "Tiet : ";
		cin.getline(KHoc.ses, 3);
		f << KHoc.id << "," << KHoc.TenKH << "," << KHoc.TenLop << "," << KHoc.TenGV << "," << KHoc.STC << "," << KHoc.MaxSV << "," << KHoc.Thu << "," << KHoc.ses << endl;// Lay 
		fstream f1;
		cout << "----------------------------------------------" << endl;
		cout << "Nhap dia chi file DS Sinh Vien : ";// THEM FILE DS SINH VIEN CO SAN VAO TRONG KHOA HOC 
		char temp[100];
		cin.getline(temp, 100);
		int dem = 0;
		f1.open(temp, ios::in);
		while (f1.is_open() == 0) {
			cout << "Ten file khong ton tai, vui long nhap lai. " << endl;
			cout << "----------------------------------------------" << endl;
			cout << "Nhap ten file DS Sinh Vien : ";
			cin.getline(temp, 100);
			f1.open(temp, ios::in);
		}
		demDong(f1, dem);
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
		strcpy_s(temp1, strlen(HK) + 1, HK);
		strcat_s(temp1, "\\");
		strcat_s(temp1, KHoc.TenKH);
		strcat_s(temp1, "-");
		strcat_s(temp1, KHoc.id);
		strcat_s(temp1, ".csv");
		f1.open(temp1, ios::out);
		for (int i = 0; i < dem; i++) {
			f1 << sv[i].STT << "," << sv[i].MSSV << "," << sv[i].Ten << "," << sv[i].Ho << "," << sv[i].Gioitinh << "," << sv[i].Ngaysinh << "," << sv[i].idXH << endl;
		}
		f1.close();
		delete[]sv;
		cout << "----------------------------------------------" << endl;
		cout << "1. Them khoa hoc             2.Thoat" << endl;// THEM NHIEU KHOA HOC VAO HOC KI
		cout << "----------------------------------------------" << endl;
		int Chon;
		cout << "Nhap : "; cin >> Chon;
		if (Chon == 2) {
			f.close();
			return;
		}
	}
	f.close();
}

void tao1HK(fstream& f,char temp[]) {
Chonlai:
	system("cls");
	HK hk;
	char temp1[100];
	cin.ignore();//NHAP THONG TIN HOC KI
	cout << "Nhap thoi gian bat dau hoc ky" << endl;
	cout << "Ngay : " << endl;
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
	else if (stoi(hk.thangBD) == 1) strcpy_s(hk.HKthu, "2");
	else strcpy_s(hk.HKthu, "3");
	system("cls");
	int dem = 0;
	f.open("Namhoc.csv", ios::in);
	demDong(f, dem);
	f.close();
	Nam* nam = new Nam[dem];
	cout << left << setw(8) << "STT" << "Nam" << endl;
	cout << "----------------------------------------------" << endl;
	f.open("Namhoc.csv", ios::in);
	for (int i = 0; i < dem; i++) {
		f.getline(nam[i].STT, 3, ',');
		f.getline(nam[i].Tennam, 15, ',');
		char a[100];
		f.getline(a, 100, '\n');
		cout << left << setw(8) << nam[i].STT << nam[i].Tennam << endl;
		cout << "----------------------------------------------" << endl;
	}
	f.close();
	int Chon;
	cout << "----------------------------------------------" << endl;
	cout << "Chon nam hoc cua hoc ky : " << endl;// CHON NAM DE THEM HOC KI VAO
	cin >> Chon;
	for (int i = 0; i < dem; i++) {
		if (stoi(nam[i].STT) == Chon) {
			strcpy_s(temp1, strlen(nam[i].Tennam) + 1, nam[i].Tennam);
			strcat_s(temp1, "\\");
			strcat_s(temp1, nam[i].Tennam);
			strcat_s(temp1, "_HK");
			strcat_s(temp1, "\\");
			strcat_s(temp1, nam[i].Tennam);
			strcat_s(temp1, "_HK.csv");
			f.open(temp1, ios::in);
			dem = 0;
			demDong(f, dem);
			f.close();
			f.open(temp1, ios::in);
			HK* hk1 = new HK[dem];
			for (int j = 0; j < dem; j++) {// KIEM TRA XEM HOC KI DO DA CO TRONG NAM HOC CHUA
				f.getline(hk1[j].HKthu, 3, ',');
				f.getline(hk1[j].ngayBD, 4, ',');
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
			f.open(temp1, ios::out);
			for (int j = 0; j < dem; j++) {
				f << hk1[j].HKthu << "," << hk1[j].ngayBD << "," << hk1[j].thangBD << "," << hk1[j].namBD << "," << hk1[j].ngayKT << "," << hk1[j].thangKT << "," << hk1[j].namKT << endl;
			}
			f << hk.HKthu << "," << hk.ngayBD << "," << hk.thangBD << "," << hk.namBD << "," << hk.ngayKT << "," << hk.thangKT << "," << hk.namKT << endl;
			f.close();
			strcpy_s(temp1, strlen(nam[i].Tennam) + 1, nam[i].Tennam);
			strcat_s(temp1, "\\");
			strcat_s(temp1, nam[i].Tennam);
			strcat_s(temp1, "_HK");
			strcat_s(temp1, "\\");
			strcat_s(temp1, nam[i].Tennam);
			strcat_s(temp1, "_HK");
			strcat_s(temp1, hk.HKthu);
			_mkdir(temp1); // TAO THU MUC CHUA DANH SACH KHOA HOC
			strcpy_s(temp, strlen(temp1) + 1, temp1);
			break;
		}
	}
}

void listKH(char HK[]) {// XEM DANH SACH KHOA HOC TRONG HOC KI HIEN TAI
	system("cls");
	fstream f;
	char temp1[100];
	int dem;
	strcpy_s(temp1, strlen(HK) + 1, HK);
	strcat_s(temp1, "\\");
	strcat_s(temp1, "DSKH.csv");
	cout << left << setw(15) << "ID mon hoc" << left << setw(30) << "Khoa hoc" << left << setw(10) << "Lop" << left << setw(30) << "Giao vien" << left << setw(10) << "So TC" << left << setw(8) << "So SV" << left << setw(8) << "Thu" << left << setw(7) << "Tiet" << endl;
	cout << "----------------------------------------------" << endl;
	f.open(temp1, ios::in);
	dem = 0;
	demDong(f, dem);
	f.close();
	dem++;
	KhoaHoc* KHoc = new KhoaHoc[dem];
	f.open(temp1, ios::in);
	for (int k = 0; k < dem; k++) {
		f.getline(KHoc[k].id, 10, ',');
		f.getline(KHoc[k].TenKH, 30, ',');
		f.getline(KHoc[k].TenLop, 30, ',');
		f.getline(KHoc[k].TenGV, 50, ',');
		f.getline(KHoc[k].STC, 5, ',');
		f.getline(KHoc[k].MaxSV, 4, ',');
		f.getline(KHoc[k].Thu, 4, ',');
		f.getline(KHoc[k].ses, 3, '\n');
		cout << left << setw(15) << KHoc[k].id << left << setw(30) << KHoc[k].TenKH << left << setw(10) << KHoc[k].TenLop << left << setw(30) << KHoc[k].TenGV << left << setw(10) << KHoc[k].STC << left << setw(8) << KHoc[k].MaxSV << left << setw(8) << KHoc[k].Thu << left << setw(7) << KHoc[k].ses << endl;
		cout << "----------------------------------------------" << endl;
	}
	f.close();
	cout << "----------------------------------------------" << endl;
	cout << "Nhap ID khoa hoc can xem danh sach : ";
	cin.ignore();
	cin.getline(temp1, 100);
	cout << "----------------------------------------------" << endl;
	for (int k = 0; k < dem; k++) {
		if (strcmp(temp1, KHoc[k].id) == 0) {
			strcpy_s(temp1, strlen(HK) + 1, HK);
			strcat_s(temp1, "\\");
			strcat_s(temp1, KHoc[k].TenKH);
			strcat_s(temp1, "-");
			strcat_s(temp1, KHoc[k].id);
			strcat_s(temp1, ".csv");
			f.open(temp1, ios::in);
			dem = 0;
			demDong(f, dem);
			f.close();
			DSSV* sv = new DSSV[dem];
			cout << left << setw(8) << "STT" << left << setw(13) << "MSSV" << left << setw(10) << "Ho" << left << setw(20) << "Ten" << left << setw(15) << "Gioi tinh" << left << setw(20) << "Ngay sinh" << "ID Xa hoi" << endl;
			cout << "----------------------------------------------" << endl;
			f.open(temp1, ios::in);
			for (int k = 0; k < dem; k++) {
				f.getline(sv[k].STT, 3, ',');
				f.getline(sv[k].MSSV, 15, ',');
				f.getline(sv[k].Ten, 20, ',');
				f.getline(sv[k].Ho, 20, ',');
				f.getline(sv[k].Gioitinh, 5, ',');
				f.getline(sv[k].Ngaysinh, 20, ',');
				f.getline(sv[k].idXH, 20, '\n');
				cout << left << setw(8) << sv[k].STT << left << setw(13) << sv[k].MSSV << left << setw(10) << sv[k].Ten << left << setw(20) << sv[k].Ho << left << setw(15) << sv[k].Gioitinh << left << setw(20) << sv[k].Ngaysinh << sv[k].idXH << endl;
				cout << "----------------------------------------------" << endl;
			}
			f.close();
			delete[]sv;
			break;
		}
	}
}

void updateKH(char HK[]) {
	fstream f;
	int dem = 0;
	char temp[100];
	strcpy_s(temp, strlen(HK) + 1, HK);
	strcat_s(temp, "\\");
	strcat_s(temp, "DSKH.csv");
	f.open(temp, ios::in);
	demDong(f, dem);
	f.close();
	dem++;
	KhoaHoc* KHoc = new KhoaHoc[dem];
	cout << left << setw(15) << "ID mon hoc" << left << setw(30) << "Khoa hoc" << left << setw(10) << "Lop" << left << setw(30) << "Giao vien" << left << setw(10) << "So TC" << left << setw(8) << "So SV" << left << setw(8) << "Thu" << left << setw(7) << "Tiet" << endl;
	cout << "----------------------------------------------" << endl;
	f.open(temp, ios::in);
	for (int i = 0; i < dem; i++) {
		f.getline(KHoc[i].id, 10, ',');
		f.getline(KHoc[i].TenKH, 30, ',');
		f.getline(KHoc[i].TenLop, 30, ',');
		f.getline(KHoc[i].TenGV, 50, ',');
		f.getline(KHoc[i].STC, 5, ',');
		f.getline(KHoc[i].MaxSV, 4, ',');
		f.getline(KHoc[i].Thu, 4, ',');
		f.getline(KHoc[i].ses, 3, '\n');
		cout << left << setw(15) << KHoc[i].id << left << setw(30) << KHoc[i].TenKH << left << setw(10) << KHoc[i].TenLop << left << setw(30) << KHoc[i].TenGV << left << setw(10) << KHoc[i].STC << left << setw(8) << KHoc[i].MaxSV << left << setw(8) << KHoc[i].Thu << left << setw(7) << KHoc[i].ses << endl;
		cout << "----------------------------------------------" << endl;
	}
	f.close();
	char temp1[100];
	cout << "----------------------------------------------" << endl;
	cout << "Nhap ID khoa hoc can cap nhat : ";// CAP NHAT KHOA HOC THEO ID
	cin.ignore();
	cin.getline(temp1, 100);
	cout << "----------------------------------------------" << endl;
	for (int i = 0; i < dem; i++) {
		if (strcmp(KHoc[i].id, temp1) == 0) {
			cout << "Cap nhat thong tin khoa hoc : " << endl;
			cout << "ID khoc hoc : " << KHoc[i].id << endl;
			cout << "Ten Khoa Hoc : " << KHoc[i].TenKH << endl;
			cout << "Ten Lop : ";
			cin.getline(KHoc[i].TenLop, 30);
			cout << "Ten Giao Vien : ";
			cin.getline(KHoc[i].TenGV, 50);
			cout << "So Tin Chi : ";
			cin.getline(KHoc[i].STC, 5);
			cout << "So luong sinh vien : ";
			cin.getline(KHoc[i].MaxSV, 4);
			cout << "Thu : ";
			cin.getline(KHoc[i].Thu, 4);
			cout << "Tiet : ";
			cin.getline(KHoc[i].ses, 3);
		}
	}
	f.open(temp, ios::out);
	for (int i = 0; i < dem; i++) {
		f << KHoc[i].id << "," << KHoc[i].TenKH << "," << KHoc[i].TenLop << "," << KHoc[i].TenGV << "," << KHoc[i].STC << "," << KHoc[i].MaxSV << "," << KHoc[i].Thu << "," << KHoc[i].ses << endl;
	}
	f.close();
	delete[]KHoc;
}

void add1SV(char HK[]) {
	system("cls");
	fstream f;
	char temp1[100];
	strcpy_s(temp1, strlen(HK) + 1, HK);
	strcat_s(temp1, "\\");
	strcat_s(temp1, "DSKH.csv");
	int dem = 0;
	f.open(temp1, ios::in);
	demDong(f, dem);
	dem++;
	f.close();
	KhoaHoc* KHoc = new KhoaHoc[dem];
	DSSV sv1;
	cin.ignore();
	cout << "Nhap thong tin sinh vien can them vao : " << endl;
	cout << "----------------------------------------------" << endl;
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
	cout << left << setw(15) << "ID mon hoc" << left << setw(30) << "Khoa hoc" << left << setw(10) << "Lop" << left << setw(30) << "Giao vien" << left << setw(10) << "So TC" << left << setw(8) << "So SV" << left << setw(8) << "Thu" << left << setw(7) << "Tiet" << endl;
	f.open(temp1, ios::in);
	for (int i = 0; i < dem; i++) {
		f.getline(KHoc[i].id, 10, ',');
		f.getline(KHoc[i].TenKH, 30, ',');
		f.getline(KHoc[i].TenLop, 30, ',');
		f.getline(KHoc[i].TenGV, 50, ',');
		f.getline(KHoc[i].STC, 5, ',');
		f.getline(KHoc[i].MaxSV, 4, ',');
		f.getline(KHoc[i].Thu, 4, ',');
		f.getline(KHoc[i].ses, 3, '\n');
		cout << left << setw(15) << KHoc[i].id << left << setw(30) << KHoc[i].TenKH << left << setw(10) << KHoc[i].TenLop << left << setw(30) << KHoc[i].TenGV << left << setw(10) << KHoc[i].STC << left << setw(8) << KHoc[i].MaxSV << left << setw(8) << KHoc[i].Thu << left << setw(7) << KHoc[i].ses << endl;
	}
	f.close();
	cout << "----------------------------------------------" << endl;
	cout << "Nhap id khoa hoc can them sinh vien : ";
	char temp[50];
	cin.getline(temp, 50);
	for (int i = 0; i < dem; i++) {
		if (strcmp(temp, KHoc[i].id) == 0) {
			strcpy_s(temp1, strlen(HK) + 1, HK);
			strcat_s(temp1, "\\");
			strcat_s(temp1, KHoc[i].TenKH);
			strcat_s(temp1, "-");
			strcat_s(temp1, KHoc[i].id);
			strcat_s(temp1, ".csv");
			f.open(temp1, ios::in);
			dem = 0;
			demDong(f, dem);
			f.close();
			DSSV* sv = new DSSV[dem];
			f.open(temp1, ios::in);
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
			f.open(temp1, ios::out);
			for (int i = 0; i < dem; i++) {
				f << sv[i].STT << "," << sv[i].MSSV << "," << sv[i].Ten << "," << sv[i].Ho << "," << sv[i].Gioitinh << "," << sv[i].Ngaysinh << "," << sv[i].idXH << endl;
			}
			f << dem + 1 << "," << sv1.MSSV << "," << sv1.Ten << "," << sv1.Ho << "," << sv1.Gioitinh << "," << sv1.Ngaysinh << "," << sv1.idXH << endl;
			f.close();
			delete[]sv;
			break;
		}
	}
	delete[]KHoc;
}

void delete1SV(char HK[]) {
	system("cls");
	fstream f;
	char temp1[100];
	strcpy_s(temp1, strlen(HK) + 1, HK);
	strcat_s(temp1, "\\");
	strcat_s(temp1, "DSKH.csv");
	int dem = 0;
	f.open(temp1, ios::in);
	demDong(f, dem);
	dem++;
	f.close();
	KhoaHoc* KHoc = new KhoaHoc[dem];
	cout << left << setw(15) << "ID mon hoc" << left << setw(30) << "Khoa hoc" << left << setw(10) << "Lop" << left << setw(30) << "Giao vien" << left << setw(10) << "So TC" << left << setw(8) << "So SV" << left << setw(8) << "Thu" << left << setw(7) << "Tiet" << endl;
	cout << "----------------------------------------------" << endl;
	f.open(temp1, ios::in);
	for (int i = 0; i < dem; i++) {
		f.getline(KHoc[i].id, 10, ',');
		f.getline(KHoc[i].TenKH, 30, ',');
		f.getline(KHoc[i].TenLop, 30, ',');
		f.getline(KHoc[i].TenGV, 50, ',');
		f.getline(KHoc[i].STC, 5, ',');
		f.getline(KHoc[i].MaxSV, 4, ',');
		f.getline(KHoc[i].Thu, 4, ',');
		f.getline(KHoc[i].ses, 3, '\n');
		cout << left << setw(15) << KHoc[i].id << left << setw(30) << KHoc[i].TenKH << left << setw(10) << KHoc[i].TenLop << left << setw(30) << KHoc[i].TenGV << left << setw(10) << KHoc[i].STC << left << setw(8) << KHoc[i].MaxSV << left << setw(8) << KHoc[i].Thu << left << setw(7) << KHoc[i].ses << endl;
		cout << "----------------------------------------------" << endl;
	}
	f.close();
	cout << "----------------------------------------------" << endl;
	cout << "Nhap id khoa hoc can xoa sinh vien : ";
	char temp[50];
	cin.ignore();
	cin.getline(temp, 50);
	for (int i = 0; i < dem; i++) {
		if (strcmp(temp, KHoc[i].id) == 0) {
			strcpy_s(temp1, strlen(HK) + 1, HK);
			strcat_s(temp1, "\\");
			strcat_s(temp1, KHoc[i].TenKH);
			strcat_s(temp1, "-");
			strcat_s(temp1, KHoc[i].id);
			strcat_s(temp1, ".csv");
			f.open(temp1, ios::in);
			dem = 0;
			demDong(f, dem);
			f.close();
			DSSV* sv = new DSSV[dem];
			cout << left << setw(8) << "STT" << left << setw(13) << "MSSV" << left << setw(10) << "Ho" << left << setw(20) << "Ten" << left << setw(15) << "Gioi tinh" << left << setw(20) << "Ngay sinh" << "ID Xa hoi" << endl;
			cout << "----------------------------------------------" << endl;
			f.open(temp1, ios::in);
			for (int j = 0; j < dem; j++) {
				f.getline(sv[j].STT, 3, ',');
				f.getline(sv[j].MSSV, 15, ',');
				f.getline(sv[j].Ten, 20, ',');
				f.getline(sv[j].Ho, 20, ',');
				f.getline(sv[j].Gioitinh, 5, ',');
				f.getline(sv[j].Ngaysinh, 20, ',');
				f.getline(sv[j].idXH, 20, '\n');
				cout << left << setw(8) << sv[j].STT << left << setw(13) << sv[j].MSSV << left << setw(10) << sv[j].Ten << left << setw(20) << sv[j].Ho << left << setw(15) << sv[j].Gioitinh << left << setw(20) << sv[j].Ngaysinh << sv[j].idXH << endl;
				cout << "----------------------------------------------" << endl;
			}
			f.close();
			cout << "----------------------------------------------" << endl;
			cout << "Nhap ma so sinh vien can xoa : ";
			char temp2[50];
			cin.getline(temp2, 50);
			f.open(temp1, ios::out);
			for (int j = 0; j < dem; j++) {
				if (strcmp(temp2, sv[j].MSSV) == 0) {
					j++;
					for (; j < dem; j++) {
						f << j << "," << sv[j].MSSV << "," << sv[j].Ten << "," << sv[j].Ho << "," << sv[j].Gioitinh << "," << sv[j].Ngaysinh << "," << sv[j].idXH << endl;
					}
					return;
				}
				f << sv[j].STT << "," << sv[j].MSSV << "," << sv[j].Ten << "," << sv[j].Ho << "," << sv[j].Gioitinh << "," << sv[j].Ngaysinh << "," << sv[j].idXH << endl;
			}
			f.close();
			delete[]sv;
			break;
		}
	}
	delete[]KHoc;
}

void delete1Course(char HK[]) {
	system("cls");
	fstream f;
	char temp1[100];
	strcpy_s(temp1, strlen(HK) + 1, HK);
	strcat_s(temp1, "\\");
	strcat_s(temp1, "DSKH.csv");
	int dem = 0;
	f.open(temp1, ios::in);
	demDong(f, dem);
	f.close();
	KhoaHoc* KHoc = new KhoaHoc[dem];
	cout << left << setw(15) << "ID mon hoc" << left << setw(30) << "Khoa hoc" << left << setw(10) << "Lop" << left << setw(30) << "Giao vien" << left << setw(10) << "So TC" << left << setw(8) << "So SV" << left << setw(8) << "Thu" << left << setw(7) << "Tiet" << endl;
	cout << "----------------------------------------------" << endl;
	f.open(temp1, ios::in);
	for (int i = 0; i < dem; i++) {
		f.getline(KHoc[i].id, 10, ',');
		f.getline(KHoc[i].TenKH, 30, ',');
		f.getline(KHoc[i].TenLop, 30, ',');
		f.getline(KHoc[i].TenGV, 50, ',');
		f.getline(KHoc[i].STC, 5, ',');
		f.getline(KHoc[i].MaxSV, 4, ',');
		f.getline(KHoc[i].Thu, 4, ',');
		f.getline(KHoc[i].ses, 3, '\n');
		cout << left << setw(15) << KHoc[i].id << left << setw(30) << KHoc[i].TenKH << left << setw(10) << KHoc[i].TenLop << left << setw(30) << KHoc[i].TenGV << left << setw(10) << KHoc[i].STC << left << setw(8) << KHoc[i].MaxSV << left << setw(8) << KHoc[i].Thu << left << setw(7) << KHoc[i].ses << endl;
		cout << "----------------------------------------------" << endl;
	}
	f.close();
	cout << "----------------------------------------------" << endl;
	cout << "Nhap id khoa hoc can xoa : ";
	char temp[50];
	cin.ignore();
	cin.getline(temp, 50);
	f.open(temp1, ios::out);
	for (int i = 0; i < dem; i++) {
		if (strcmp(temp, KHoc[i].id) == 0) {
			strcpy_s(temp1, strlen(HK) + 1, HK);
			strcat_s(temp1, "\\");
			strcat_s(temp1, KHoc[i].TenKH);
			strcat_s(temp1, "-");
			strcat_s(temp1, KHoc[i].id);
			strcat_s(temp1, ".csv");
			remove(temp1);
			break;
		}
	}
	for (int i = 0; i < dem; i++) {
		if (strcmp(temp, KHoc[i].id) == 0) {
			i++;
			for (; i < dem; i++) {
				f << KHoc[i].id << "," << KHoc[i].TenKH << "," << KHoc[i].TenLop << "," << KHoc[i].TenGV << "," << KHoc[i].STC << "," << KHoc[i].MaxSV << "," << KHoc[i].Thu << "," << KHoc[i].ses << endl;
			}
			return;
		}
		f << KHoc[i].id << "," << KHoc[i].TenKH << "," << KHoc[i].TenLop << "," << KHoc[i].TenGV << "," << KHoc[i].STC << "," << KHoc[i].MaxSV << "," << KHoc[i].Thu << "," << KHoc[i].ses << endl;
	}
	f.close();
	delete[]KHoc;
}