#include"System.h"

void ThongtinGiangvien(fstream& f, char TK[], int STT) {// IN RA THONG TIN KHI CHON XEM THONG TIN
	GV* Ten = new GV[STT];
	f.open("admin.csv", ios::in);
	for (int i = 0; i < STT; i++) {
		f.getline(Ten[i].MS, 50, ',');
		f.getline(Ten[i].HoTen, 100, ',');
		f.getline(Ten[i].Tuoi, 4, ',');
		f.getline(Ten[i].Gioitinh, 50, ',');
		f.getline(Ten[i].Nganh, 50, ',');
		f.getline(Ten[i].Monday, 50, '\n');
	}
	cout << Ten[STT - 1].HoTen << "  " << Ten[STT - 1].Tuoi << "  " << Ten[STT - 1].Gioitinh << "  " << Ten[STT - 1].Nganh << "  " << Ten[STT - 1].Monday << endl;
	f.close();
	delete[]Ten;
	cout << "An Enter de quay lai" << endl;
	system("pause");
}

void doiMK(fstream& f, char TK[], int STT, int soGV) {
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
		if (i != STT - 1) f << Ten[i].MS << "," << Ten[i].HoTen << "," << Ten[i].Tuoi << "," << Ten[i].Gioitinh << "," << Ten[i].Nganh << "," << Ten[i].Monday << endl;
		else f << temp << "," << Ten[i].HoTen << "," << Ten[i].Tuoi << "," << Ten[i].Gioitinh << "," << Ten[i].Nganh << "," << Ten[i].Monday << endl;
	}
	cout << "Da thay doi mat khau thanh cong" << endl;
	f.close();
	delete[]Ten;
	cout << "An Enter de quay lai" << endl;
	system("pause");
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
		while (Chon < 1 || Chon>5) {
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
		cout << "Chon nien khoa de xem danh sach lop : " << endl;
		int Chon;
		cin >> Chon;
		char temp1[100];
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
						f.open(temp1, ios::in);
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
void xemHKvsKH(fstream& f) {
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
		cout << "Chon nien khoa de xem danh sach lop : " << endl;
		int Chon;
		cin >> Chon;
		char temp1[100];
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
					cout << hk1[j].HKthu << ". Hoc ki thu " << hk1[j].HKthu << endl;
				}
				f.close();
				cout << "Hoc ki de xem khoa hoc : " << endl;
				cin >> Chon;
				for (int j = 0; j < dem; j++) {
					if (stoi(hk1[j].HKthu) == Chon) {
						strcpy_s(temp1, strlen(nam[i].Tennam) + 1, nam[i].Tennam);
						strcat_s(temp1, "\\");
						strcat_s(temp1, nam[i].Tennam);
						strcat_s(temp1, "_HK");
						strcat_s(temp1, "\\");
						strcat_s(temp1, nam[i].Tennam);
						strcat_s(temp1, "_HK");
						strcat_s(temp1, hk1[j].HKthu);
						strcat_s(temp1, "\\");
						strcat_s(temp1, "DSKH.csv");
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
							cout << KHoc[k].id << "  " << KHoc[k].TenKH << "  " << KHoc[k].TenLop << "  " << KHoc[k].TenGV << "  " << KHoc[k].STC << "  " << KHoc[k].MaxSV << "  " << KHoc[k].Thu << "  " << KHoc[k].ses << endl;
						}
						f.close();
						cout << "Nhap ID khoa hoc can cap nhat : ";// CAP NHAT KHOA HOC THEO ID
						cin.ignore();
						cin.getline(temp, 100);
						for (int k = 0; k < dem; k++) {
							if (strcmp(temp, KHoc[k].id) == 0) {
								strcpy_s(temp1, strlen(nam[i].Tennam) + 1, nam[i].Tennam);
								strcat_s(temp1, "\\");
								strcat_s(temp1, nam[i].Tennam);
								strcat_s(temp1, "_HK");
								strcat_s(temp1, "\\");
								strcat_s(temp1, nam[i].Tennam);
								strcat_s(temp1, "_HK");
								strcat_s(temp1, hk1[j].HKthu);
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
								f.open(temp1, ios::in);
								for (int k = 0; k < dem; k++) {
									f.getline(sv[k].STT, 3, ',');
									f.getline(sv[k].MSSV, 15, ',');
									f.getline(sv[k].Ten, 20, ',');
									f.getline(sv[k].Ho, 20, ',');
									f.getline(sv[k].Gioitinh, 5, ',');
									f.getline(sv[k].Ngaysinh, 20, ',');
									f.getline(sv[k].idXH, 20, '\n');
									cout << sv[k].STT << "     " << sv[k].MSSV << "     " << sv[k].Ten << "     " << sv[k].Ho << "     " << sv[k].Gioitinh << "     " << sv[k].Ngaysinh << "     " << sv[k].idXH << "     " << endl;
								}
								f.close();
							}
						}
						break;
					}
				}
			}break;
		}
		cout << "1. Xem danh sach khoa hoc khac            2. Thoat" << endl;
		cout << "Nhap : ";
		cin >> Chon;
		if (Chon != 1 && Chon != 2) {
			cout << "Nhap lai : "; cin >> Chon;
		}
		if (Chon == 2) return;
	}
}

void taoHK(fstream& f) {// TAO HOC KI
	while (1) {
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
				_mkdir(temp1);
				addKH(temp1);// THEM CAC KHÔA HOC VAO HOC KI
				while (1) {
					system("cls");
					cout << "1. Xem danh sach khoa hoc" << endl;
					cout << "2. Cap nhap danh sach" << endl;
					cout << "3. Them 1 sinh vien vao khoa hoc" << endl;
					cout << "4. Xoa 1 sinh vien khoi khoa hoc" << endl;
					cout << "5. Xoa 1 khoa hoc" << endl;
					cout << "6. Quay lai" << endl;
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

void quanliDiem(fstream& f) {
	while (1) {
		system("cls");// MENU CHINH
		cout << "1. Lay File sinh vien" << endl;
		cout << "2. Them File diem" << endl;
		cout << "3. Xem diem 1 khoa hoc" << endl;
		cout << "4. Cap nhat diem" << endl;
		cout << "5. Xem diem theo lop" << endl;
		cout << "6. Dang xuat" << endl;
		int Chon;
		cout << "Nhap : "; cin >> Chon;
		while (Chon != 1 && Chon != 2 && Chon != 3 && Chon != 4 && Chon != 5 && Chon != 6) {
			cout << "Nhap lai : "; cin >> Chon;
		}
		switch (Chon) {
		case 1:nhapDiem(f); break;
		case 2:themDiem(f); break;
		case 3:xemDiem1KH(f); break;
		case 4:capnhatDiem(f); break;
		default: return;
		}
	}
}