#include"System.h"

void addKH(char HK[]) {
	system("cls");
	fstream f;
	char temp1[100];
	strcpy_s(temp1, strlen(HK) + 1, HK);
	strcat_s(temp1, "\\");
	strcat_s(temp1, "DSKH.csv");
	f.open(temp1, ios::out);
	KhoaHoc KHoc;
	while (1) {// THEM KHOA HOC VAO HOC KI DANG TAO
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
		f << KHoc.id << "," << KHoc.TenKH << "," << KHoc.TenLop << "," << KHoc.TenGV << "," << KHoc.STC << "," << KHoc.MaxSV << "," << KHoc.Thu << "," << KHoc.ses << endl;
		fstream f1;
		cout << "Nhap dia chi file DS Sinh Vien : ";// THEM FILE DS SINH VIEN CO SAN VAO TRONG KHOA HOC 
		char temp[100];
		cin.getline(temp, 100);
		int dem = 0;
		f1.open(temp, ios::in);
		while (f1.is_open() == 0) {
			cout << "Ten file khong ton tai, vui long nhap lai. " << endl;
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
		cout << "1. Them khoa hoc             2.Thoat" << endl;// THEM NHIEU KHOA HOC VAO HOC KI
		int Chon;
		cout << "Nhap : "; cin >> Chon;
		if (Chon == 2) {
			f.close();
			return;
		}
	}
	f.close();
}
void listKH(char HK[]) {// XEM DANH SACH KHOA HOC TRONG HOC KI HIEN TAI
	system("cls");
	fstream f;
	char temp1[100];
	strcpy_s(temp1, strlen(HK) + 1, HK);
	strcat_s(temp1, "\\");
	strcat_s(temp1, "DSKH.csv");
	KhoaHoc KHoc;
	f.open(temp1, ios::in);
	while (!f.eof()) {
		f.getline(KHoc.id, 10, ',');
		f.getline(KHoc.TenKH, 30, ',');
		f.getline(KHoc.TenLop, 30, ',');
		f.getline(KHoc.TenGV, 50, ',');
		f.getline(KHoc.STC, 5, ',');
		f.getline(KHoc.MaxSV, 4, ',');
		f.getline(KHoc.Thu, 4, ',');
		f.getline(KHoc.ses, 3, '\n');
		cout << KHoc.id << "  " << KHoc.TenKH << "  " << KHoc.TenLop << "  " << KHoc.TenGV << "  " << KHoc.STC << "  " << KHoc.MaxSV << "  " << KHoc.Thu << "  " << KHoc.ses;
		cout << endl;
	}
	f.close();
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
		cout << KHoc[i].id << "  " << KHoc[i].TenKH << "  " << KHoc[i].TenLop << "  " << KHoc[i].TenGV << "  " << KHoc[i].STC << "  " << KHoc[i].MaxSV << "  " << KHoc[i].Thu << "  " << KHoc[i].ses << endl;
	}
	f.close();
	char temp1[100];
	cout << "Nhap ID khoa hoc can cap nhat : ";// CAP NHAT KHOA HOC THEO ID
	cin.ignore();
	cin.getline(temp1, 100);
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
	f.open(temp1, ios::in);
	for (int i = 0; i < dem; i++) {// XEM DANH SACH KHOA HOC TRONG HOC KI HIEN TAI
		f.getline(KHoc[i].id, 10, ',');
		f.getline(KHoc[i].TenKH, 30, ',');
		f.getline(KHoc[i].TenLop, 30, ',');
		f.getline(KHoc[i].TenGV, 50, ',');
		f.getline(KHoc[i].STC, 5, ',');
		f.getline(KHoc[i].MaxSV, 4, ',');
		f.getline(KHoc[i].Thu, 4, ',');
		f.getline(KHoc[i].ses, 3, '\n');
		cout << KHoc[i].id << "  " << KHoc[i].TenKH << "  " << KHoc[i].TenLop << "  " << KHoc[i].TenGV << "  " << KHoc[i].STC << "  " << KHoc[i].MaxSV << "  " << KHoc[i].Thu << "  " << KHoc[i].ses;
		cout << endl;
	}
	f.close();
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
		}
	}
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
	f.open(temp1, ios::in);
	for (int i = 0; i < dem; i++) {// XEM DANH SACH KHOA HOC TRONG HOC KI HIEN TAI
		f.getline(KHoc[i].id, 10, ',');
		f.getline(KHoc[i].TenKH, 30, ',');
		f.getline(KHoc[i].TenLop, 30, ',');
		f.getline(KHoc[i].TenGV, 50, ',');
		f.getline(KHoc[i].STC, 5, ',');
		f.getline(KHoc[i].MaxSV, 4, ',');
		f.getline(KHoc[i].Thu, 4, ',');
		f.getline(KHoc[i].ses, 3, '\n');
		cout << KHoc[i].id << "  " << KHoc[i].TenKH << "  " << KHoc[i].TenLop << "  " << KHoc[i].TenGV << "  " << KHoc[i].STC << "  " << KHoc[i].MaxSV << "  " << KHoc[i].Thu << "  " << KHoc[i].ses;
		cout << endl;
	}
	f.close();
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
			f.open(temp1, ios::in);
			for (int j = 0; j < dem; j++) {
				f.getline(sv[j].STT, 3, ',');
				f.getline(sv[j].MSSV, 15, ',');
				f.getline(sv[j].Ten, 20, ',');
				f.getline(sv[j].Ho, 20, ',');
				f.getline(sv[j].Gioitinh, 5, ',');
				f.getline(sv[j].Ngaysinh, 20, ',');
				f.getline(sv[j].idXH, 20, '\n');
				cout << sv[j].STT << "     " << sv[j].MSSV << "     " << sv[j].Ten << "     " << sv[j].Ho << "     " << sv[j].Gioitinh << "     " << sv[j].Ngaysinh << "     " << sv[j].idXH << "     " << endl;
			}
			f.close();
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
			break;
		}
	}
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
	f.open(temp1, ios::in);
	for (int i = 0; i < dem; i++) {// XEM DANH SACH KHOA HOC TRONG HOC KI HIEN TAI
		f.getline(KHoc[i].id, 10, ',');
		f.getline(KHoc[i].TenKH, 30, ',');
		f.getline(KHoc[i].TenLop, 30, ',');
		f.getline(KHoc[i].TenGV, 50, ',');
		f.getline(KHoc[i].STC, 5, ',');
		f.getline(KHoc[i].MaxSV, 4, ',');
		f.getline(KHoc[i].Thu, 4, ',');
		f.getline(KHoc[i].ses, 3, '\n');
		cout << KHoc[i].id << "  " << KHoc[i].TenKH << "  " << KHoc[i].TenLop << "  " << KHoc[i].TenGV << "  " << KHoc[i].STC << "  " << KHoc[i].MaxSV << "  " << KHoc[i].Thu << "  " << KHoc[i].ses;
		cout << endl;
	}
	f.close();
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
}