#include"System.h"
int Dangnhap() {// CHON DANG NHAP VAO TAI KHOAN SINH VIEN HAY TAI KHOAN GIAO VIEN
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
void demDong(fstream& f, int& dem) {
	while (!f.eof()) {
		char temp[100];
		f.getline(temp, 100, '\n');
		dem++;
	}
	dem--;
}
void ThongtinGiangvien(fstream &f,char TK[],int STT ) {// IN RA THONG TIN KHI CHON XEM THONG TIN
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
	for (int i = 0; i < soGV; i++) {// LAY THONG TIN TAT CA GIAO VIEN
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
	for (int i = 0; i < soGV; i++) {// NHAP LAI TAT CA GIAO VIEN VAO FILE VA THAY DOI MAT KHAU GIAO VIEN O DONG ELSE
		if(i!=STT-1) f << Ten[i].MS << "," << Ten[i].HoTen << "," << Ten[i].Tuoi << "," << Ten[i].Gioitinh << "," << Ten[i].Nganh << "," << Ten[i].Monday << endl;
		else f << temp << "," << Ten[i].HoTen << "," << Ten[i].Tuoi << "," << Ten[i].Gioitinh << "," << Ten[i].Nganh << "," << Ten[i].Monday << endl;
	}
	cout << "Da thay doi mat khau thanh cong"<<endl;
	f.close();
	delete[]Ten;
	cout << "An Enter de quay lai" << endl;
	system("pause");
}
void tao1nam(fstream& f) {// TAO MOT NAM HOC
	Nam nam,nam1;
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
	f << k << "," << nam.Tennam<<"," << nam.ngayBD << "," << nam.thangBD << "," << nam.namBD << "," << nam.ngayKT << "," << nam.thangKT << "," << nam.namKT << endl;
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
	char newclass[10];
	cin.ignore();
	cout << "Nhap lop can them vao : ";
	cin.getline(newclass, 9);
	int dem = 0;
	f.open("Namhoc.csv", ios::in);
	demDong(f, dem);
	f.close();
	Nam* nam = new Nam[dem];
	f.open("Namhoc.csv", ios::in);
	for(int i=0;i<dem;i++){// IN RA NAM HOC DE NGUOI DUNG LUA CHON
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
			demDong(f, dem);
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
					int k=0;
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
	int dem = 0,dem1 = 0;
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
void taoNam(fstream& f, char TK[]) {// TAO NAM HOC DUNG DE TAO MOT NAM HOC MOI HOAC THEM MOT LOP VAO NAM HOC DA CO
	while (1) {
		system("cls");
		cout << "1. Tao 1 nam" << endl;
		cout << "2. Them lop vao 1 nam hoc" << endl;
		cout << "3. Them 1 hoc sinh vao lop" << endl;
		cout << "4. Them danh sach co san vao mot lop" << endl;
		cout << "5. Thoat" << endl;
		int Chon;
		cout << "Nhap : "; cin >> Chon;
		while (Chon <1||Chon>5) {
			cout << "Nhap lai : "; cin >> Chon;
		}
		if (Chon == 1) tao1nam(f);
		else if (Chon == 2) themLop(f);
		else if (Chon == 3) them1SV(f);
		else if (Chon == 4) them1DS(f);
		else return;
	}
}
void xemDanhsachLop(fstream& f) {
	while (1) {
		system("cls");
		fstream f1;
		int dem = 0;
		f.open("Namhoc.csv", ios::in);
		demDong(f, dem);
		Nam* nam = new Nam[dem];
		f.close();
		f.open("Namhoc.csv", ios::in);
		char temp[100];
		for (int i = 0; i < dem; i++) {// DANH SACH CAC NAM DE LUA CHON
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
				demDong(f, dem);
				f.close();
				f.open(nam[i].Tennam, ios::in);
				Lop* lop = new Lop[dem];
				for (int j = 0; j < dem; j++) {// DANH SACH CAC LOP  DE LUA CHON
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
						demDong(f, dem);
						f.close();
						f.open(lop[j].TenLop, ios::in);
						DSSV* sv = new DSSV[dem];
						for (int i = 0; i < dem; i++) {// IN THONG TIN CUA MOT LOP
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
void setupThoigian(int &d, int &m) {// CHI DAU NAM HOC MOI CO THE TAO NAM HOC
	cout << "Ngay :"; cin >> d;
	cout << "Ngay :"; cin >> m;
}
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
		cout << KHoc.id << "  " << KHoc.TenKH << "  " << KHoc.TenLop << "  " << KHoc.TenGV << "  " << KHoc.STC <<"  " << KHoc.MaxSV << "  " << KHoc.Thu << "  " << KHoc.ses ;
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
				cout << "ID khoc hoc : "<< KHoc[i].id<<endl;
				cout << "Ten Khoa Hoc : "<< KHoc[i].TenKH<<endl;
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
void taoHK(fstream& f) {// TAO HOC KI
	while (1) {
	Chonlai:
		system("cls");
		HK hk;
		char temp1[100];
		cin.ignore();//NHAP THONG TIN HOC KI
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
		system("cls");
		int dem = 0;
		f.open("Namhoc.csv", ios::in);
		demDong(f, dem);
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
		cout << "Chon nam hoc cua hoc ky : " << endl;// CHON NAM DE THEM HOC KI VAO
		cin >> Chon;
		for (int i = 0; i < dem; i++) {
			if (stoi(nam[i].STT) == Chon) {
				strcpy_s(temp1, strlen(nam[i].Tennam)+1, nam[i].Tennam);
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
				f.open(temp1, ios::out);
				for (int j = 0; j < dem; j++) {
					f << hk1[j].HKthu << "," << hk1[j].ngayBD << "," << hk1[j].thangBD << "," << hk1[j].namBD << "," << hk1[j].ngayKT << "," << hk1[j].thangKT << "," << hk1[j].namKT << endl;
				}
				f << hk.HKthu  << "," << hk.ngayBD << "," << hk.thangBD << "," << hk.namBD << "," << hk.ngayKT << "," << hk.thangKT << "," << hk.namKT << endl;
				f.close();
				strcpy_s(temp1, strlen(nam[i].Tennam) + 1, nam[i].Tennam);
				strcat_s(temp1, "\\");
				strcat_s(temp1, nam[i].Tennam);
				strcat_s(temp1, "_HK");
				strcat_s(temp1, "\\");
				strcat_s(temp1, nam[i].Tennam);
				strcat_s(temp1, "_HK");
				strcat_s(temp1, hk.HKthu);
				_mkdir(temp1);
				addKH(temp1);// THEM CAC KHÔA HOC VAO HOC KI
				while (1) {
					system("cls");
					cout << "1. Xem danh sach khoa hoc" << endl;
					cout << "2. Cap nhap danh sach" << endl;
					cout << "3. Them 1 sinh vien vao khoa hoc" << endl;
					cout << "4. Xoa 1 sinh vien khoi khoa hoc" << endl;
					cout << "5. Xoa 1 khoa hoc" << endl;
					int Chon;
					cout << "Nhap : "; cin >> Chon;
					switch (Chon) {
					case 1: {
						listKH(temp1);
						system("pause");
						break;
					}
					case 2: {
						updateKH(temp1);
						break;
					}
					case 3: {
						add1SV(temp1);
						break;
					}
					case 4: {
						delete1SV(temp1);
						break;
					}
					case 5: {
						delete1Course(temp1);
						break;
					}
					default: {
						return;
					}
					}
				}
			}
		}

		return;
	}
}
void Giangvien(fstream &f,char TK[],char MK[],int STT,int soGV) {
	int d = 0, m = 0,y=0;
	while (1) {
		system("cls");// MENU CHINH
		cout << "1. Thong tin ca nhan" << endl;
		cout << "2. Doi mat khau" << endl;
		cout << "3. Nam hoc" << endl;
		cout << "4. Tao hoc ki" << endl;
		cout << "5. Xem danh sach lop" << endl;
		cout << "6. Set up thoi gian" << endl;
		cout << "7. Dang xuat" << endl;
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
			if (m != 9 && m!=2 && m!=6 ) {
				cout << "Chi co the tao hoc ky vao dau hoc ki (thang 9, thang 3, thang 6)" << endl;
				system("pause");
				continue;
			}
			taoHK(f); break;
		}
		case 5: {
			xemDanhsachLop(f); break;
		}
		case 6:setupThoigian(d, m); break;
		default: return;
		}
	}
}
void nhapTK() {
	while(1){// NHAP TAI KHOA TRONG FILE ADMIN
	DN:
		int x = Dangnhap();
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