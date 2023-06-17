#include"System.h"

void tao1nam(fstream& f) {// TAO MOT NAM HOC
	Nam nam, nam1;
	fstream f1;
	cout << "Nhap vao nien khoa (xx-xx) : ";
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
	while (!f.eof()) {// TIM THU TU HOC KI MOI TAO TRONG FILE HOC KI
		char a[100];
		f.getline(a, 100);
		k++;
	}
	f.close();
	f.open("Namhoc.csv", ios::app);// THEM VAO CUOI FILE HOC KI VUA DUOC TAO
	f << k << "," << nam.Tennam << "," << nam.ngayBD << "," << nam.thangBD << "," << nam.namBD << "," << nam.ngayKT << "," << nam.thangKT << "," << nam.namKT << endl;
	f.close();
	char temp1[50];
	_mkdir(nam.Tennam);
	strcpy_s(temp1, nam.Tennam);
	strcat_s(temp1, "\\");
	strcat_s(temp1, nam.Tennam);
	strcat_s(temp1, "_HK");
	_mkdir(temp1);
	strcat_s(temp1, "\\");
	strcat_s(temp1, nam.Tennam);
	strcat_s(temp1, "_HK");
	strcat_s(temp1, ".csv");// TAO FILE CHUA CAC HOC KI TRONG NAM HOC
	f.open(temp1, ios::out);
	f.close();
	strcpy_s(temp1, nam.Tennam);
	strcat_s(temp1, "\\");
	strcat_s(temp1, nam.Tennam);
	_mkdir(temp1);
	strcat_s(temp1, "\\");
	strcat_s(temp1, nam.Tennam);
	strcat_s(temp1, ".csv");// TAO FILE CHUA DANH SACH CAC LOP TRONG NAM
	f.open(temp1, ios::out);
	f.close();
	cout << "Hoc ky da duoc tao" << endl;
	cout << "An Enter de quay lai" << endl;
	system("pause");
}
void themLop(fstream& f) {
	char newclass[50];
	cin.ignore();
	cout << "Nhap lop can them vao : ";
	cin.getline(newclass, 50);
	int dem = 0;
	f.open("Namhoc.csv", ios::in);
	demDong(f, dem);
	f.close();
	Nam* nam = new Nam[dem];
	f.open("Namhoc.csv", ios::in);
	for (int i = 0; i < dem; i++) {// IN RA NAM HOC DE NGUOI DUNG LUA CHON
		f.getline(nam[i].STT, 3, ',');
		f.getline(nam[i].Tennam, 6, ',');
		char a[100];
		f.getline(a, 100, '\n');
		cout << nam[i].STT << ". " << nam[i].Tennam << endl;
	}
	f.close();
	int temp, k;
	cout << "Chon nam de them lop : ";
	cin >> temp;
	int dem1 = 0;
	char temp1[50];
	for (int i = 0; i < dem; i++) {// THEM LOP HOC VAO
		k = stoi(nam[i].STT);
		if (temp == k) {
			strcpy_s(temp1, strlen(nam[i].Tennam) + 1, nam[i].Tennam);
			strcat_s(temp1, "\\");
			strcat_s(temp1, nam[i].Tennam);
			strcat_s(temp1, "\\");
			strcat_s(temp1, newclass);
			strcat_s(temp1, ".csv");
			f.open(temp1, ios::out);
			f.close();
			strcpy_s(temp1, strlen(nam[i].Tennam) + 1, nam[i].Tennam);
			strcat_s(temp1, "\\");
			strcat_s(temp1, nam[i].Tennam);
			strcat_s(temp1, "\\");
			strcat_s(temp1, nam[i].Tennam);
			strcat_s(temp1, ".csv");
			f.open(temp1, ios::in);
			demDong(f, dem1);
			f.close();
			f.open(temp1, ios::app);
			break;
		}
	}
	f << dem1 + 1 << "," << newclass << endl;
	f.close();
	system("pause");
}
void them1SV(fstream& f) {// THEM SINH VIEN VAO LOP HOC CO TRUOC DO
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
	demDong(f, dem);
	f.close();
	Nam* nam = new Nam[dem];
	f.open("Namhoc.csv", ios::in);// CHON NAM HOC DE THEM VAO
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
	char temp1[50];
	for (int i = 0; i < dem; i++) {
		if (stoi(nam[i].STT) == Chon) {
			strcpy_s(temp1, strlen(nam[i].Tennam) + 1, nam[i].Tennam);
			strcat_s(temp1, "\\");
			strcat_s(temp1, nam[i].Tennam);
			strcat_s(temp1, "\\");
			strcat_s(temp1, nam[i].Tennam);
			strcat_s(temp1, ".csv");
			f.open(temp1, ios::in);
			dem = 0;
			demDong(f, dem);
			f.close();
			f.open(temp1, ios::in);
			Lop* lop = new Lop[dem];
			for (int j = 0; j < dem; j++) {// CHON LOP HOC TRONG NAM HOC DA CHON TRUOC DO DE THEM VAO
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
					strcpy_s(temp1, strlen(nam[i].Tennam) + 1, nam[i].Tennam);
					strcat_s(temp1, "\\");
					strcat_s(temp1, nam[i].Tennam);
					strcat_s(temp1, "\\");
					strcat_s(temp1, lop[j].TenLop);
					strcat_s(temp1, ".csv");
					f.open(temp1, ios::in);
					dem = 0;
					demDong(f, dem);
					f.close();
					DSSV* sv = new DSSV[dem];
					f.open(temp1, ios::in);
					int k = 0;
					for (; k < dem; k++) {
						f.getline(sv[k].STT, 3, ',');
						f.getline(sv[k].MSSV, 15, ',');
						f.getline(sv[k].Ten, 20, ',');
						f.getline(sv[k].Ho, 20, ',');
						f.getline(sv[k].Gioitinh, 5, ',');
						f.getline(sv[k].Ngaysinh, 20, ',');
						f.getline(sv[k].idXH, 20, '\n');
					}
					f.close();
					f.open(temp1, ios::out);
					k = 0;
					for (; k < dem; k++) {
						f << sv[k].STT << "," << sv[k].MSSV << "," << sv[k].Ten << "," << sv[k].Ho << "," << sv[k].Gioitinh << "," << sv[k].Ngaysinh << "," << sv[k].idXH << endl;
					}
					f << dem + 1 << "," << sv1.MSSV << "," << sv1.Ten << "," << sv1.Ho << "," << sv1.Gioitinh << "," << sv1.Ngaysinh << "," << sv1.idXH << endl;
					f.close();
					break;
				}
			}
			break;
		}
	}
}
void them1DS(fstream& f) {
	system("cls");
	int dem = 0, dem1 = 0;
	char temp2[300];
	cout << "Nhap dia chi file danh sach can them vao ";
	cin.ignore();
	cin.getline(temp2, 300);
	f.open(temp2, ios::in);
	demDong(f, dem1);
	f.close();
	f.open(temp2, ios::in);
	int i = 0;
	DSSV* sv1 = new DSSV[dem1];
	for (; i < dem1; i++) {
		f.getline(sv1[i].STT, 3, ',');
		f.getline(sv1[i].MSSV, 15, ',');
		f.getline(sv1[i].Ten, 20, ',');
		f.getline(sv1[i].Ho, 20, ',');
		f.getline(sv1[i].Gioitinh, 5, ',');
		f.getline(sv1[i].Ngaysinh, 20, ',');
		f.getline(sv1[i].idXH, 20, '\n');
	}
	f.close();
	f.open("Namhoc.csv", ios::in);
	dem = 0;
	demDong(f, dem);
	f.close();
	Nam* nam = new Nam[dem];
	f.open("Namhoc.csv", ios::in);// CHON NAM HOC DE THEM VAO
	for (i = 0; i < dem; i++) {
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
	char temp1[50];
	for (int i = 0; i < dem; i++) {
		if (stoi(nam[i].STT) == Chon) {
			strcpy_s(temp1, strlen(nam[i].Tennam) + 1, nam[i].Tennam);
			strcat_s(temp1, "\\");
			strcat_s(temp1, nam[i].Tennam);
			strcat_s(temp1, "\\");
			strcat_s(temp1, nam[i].Tennam);
			strcat_s(temp1, ".csv");
			f.open(temp1, ios::in);
			dem = 0;
			demDong(f, dem);
			f.close();
			f.open(temp1, ios::in);
			Lop* lop = new Lop[dem];
			for (int j = 0; j < dem; j++) {// CHON LOP HOC TRONG NAM HOC DA CHON TRUOC DO DE THEM VAO
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
					strcpy_s(temp1, strlen(nam[i].Tennam) + 1, nam[i].Tennam);
					strcat_s(temp1, "\\");
					strcat_s(temp1, nam[i].Tennam);
					strcat_s(temp1, "\\");
					strcat_s(temp1, lop[j].TenLop);
					strcat_s(temp1, ".csv");
					f.open(temp1, ios::in);
					dem = 0;
					demDong(f, dem);
					f.close();
					DSSV* sv = new DSSV[dem];
					f.open(temp1, ios::in);
					int k = 0;
					for (; k < dem; k++) {
						f.getline(sv[k].STT, 3, ',');
						f.getline(sv[k].MSSV, 15, ',');
						f.getline(sv[k].Ten, 20, ',');
						f.getline(sv[k].Ho, 20, ',');
						f.getline(sv[k].Gioitinh, 5, ',');
						f.getline(sv[k].Ngaysinh, 20, ',');
						f.getline(sv[k].idXH, 20, '\n');
					}
					f.close();
					f.open(temp1, ios::out);
					k = 0;
					for (; k < dem; k++) {
						f << sv[k].STT << "," << sv[k].MSSV << "," << sv[k].Ten << "," << sv[k].Ho << "," << sv[k].Gioitinh << "," << sv[k].Ngaysinh << "," << sv[k].idXH << endl;
					}
					k = 0;
					for (; k < dem1; k++) {
						f << sv1[k].STT << "," << sv1[k].MSSV << "," << sv1[k].Ten << "," << sv1[k].Ho << "," << sv1[k].Gioitinh << "," << sv1[k].Ngaysinh << "," << sv1[k].idXH << endl;
					}
					f.close();
					break;
				}
			}
			break;
		}
	}
}
