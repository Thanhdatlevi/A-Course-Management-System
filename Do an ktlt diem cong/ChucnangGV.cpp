#include"System.h"

void ThongtinGiangvien(fstream& f, char TK[], int STT) {// IN RA THONG TIN KHI CHON XEM THONG TIN
	system("cls");
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
	cout << left << setw(20) << "Ho ten" << left << setw(10) << "Tuoi" << left << setw(15) << "Gioi tinh" << left << setw(20) << "Nganh" << left << setw(20) << "Mon hoc" << endl;
	cout << "----------------------------------------------------------------------------------" << endl;
	cout << left << setw(20) << Ten[STT - 1].HoTen << left << setw(10) << Ten[STT - 1].Tuoi << left << setw(15) << Ten[STT - 1].Gioitinh << left << setw(20)<< Ten[STT - 1].Nganh << left << setw(20) << Ten[STT - 1].Monday << endl;
	f.close();
	delete[]Ten;
	cout << endl;
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
	cout << endl;
	cout << "------------------------------------------" << endl;
	cout << "Da thay doi mat khau thanh cong" << endl;
	f.close();
	cout << "------------------------------------------" << endl;
	delete[]Ten;
	cout << "An Enter de quay lai" << endl;
	system("pause");
}

void taoNam(fstream& f, char TK[]) {// MENU LIEN QUAN DEN NAM HOC VA LOP TRONG NAM HOC
	while (1) {
		system("cls");
		cout << "1. Tao 1 nam" << endl;
		cout << "--------------------------------------" << endl;
		cout << "2. Them lop vao 1 nam hoc" << endl;
		cout << "--------------------------------------" << endl;
		cout << "3. Them 1 hoc sinh vao lop" << endl;
		cout << "--------------------------------------" << endl;
		cout << "4. Them danh sach co san vao mot lop" << endl;
		cout << "--------------------------------------" << endl;
		cout << "5. Thoat" << endl;
		cout << "--------------------------------------" << endl;
		cout << endl;
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
		cout<<left<<setw(8) << "STT" << "Nam"<<endl;
		cout << "----------------------------------------------" << endl;
		for (int i = 0; i < dem; i++) {// DANH SACH CAC NAM
			f.getline(nam[i].STT, 3, ',');
			f.getline(nam[i].Tennam, 15, ',');
			char a[100];
			f.getline(a, 100, '\n');
			cout << left << setw(8) << nam[i].STT << nam[i].Tennam << endl;
			cout << "----------------------------------------------" << endl;
		}
		f.close();
		cin.ignore();
		cout << "----------------------------------------------"<<endl;// CHON NAM HOC DE XEM DANH SACH LOP
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
				cout << left << setw(8) << "STT" << "Lop"<<endl;
				cout << "----------------------------------------------" << endl;
				for (int j = 0; j < dem; j++) {// DANH SACH CAC LOP
					f.getline(lop[j].STT, 3, ',');
					f.getline(lop[j].TenLop, 20, '\n');
					cout << left << setw(8) << lop[j].STT<< lop[j].TenLop << endl;
					cout << "----------------------------------------------" << endl;
				}
				f.close();
				cin.ignore();
				cout << "----------------------------------------------" << endl;// CHON LOP DE COI DANH SACH
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
						cout << left << setw(8) << "STT" << left << setw(13) << "MSSV" << left << setw(10) << "Ho" << left << setw(20) << "Ten" << left << setw(15) << "Gioi tinh" << left << setw(20) << "Ngay sinh"  << "ID Xa hoi" << endl;
						cout << "----------------------------------------------" << endl;
						for (int i = 0; i < dem; i++) { // IN THONG TIN CUA MOT LOP
							f.getline(sv[i].STT, 3, ',');
							f.getline(sv[i].MSSV, 15, ',');
							f.getline(sv[i].Ten, 20, ',');
							f.getline(sv[i].Ho, 20, ',');
							f.getline(sv[i].Gioitinh, 5, ',');
							f.getline(sv[i].Ngaysinh, 20, ',');
							f.getline(sv[i].idXH, 50, '\n');
							cout << left << setw(8) << sv[i].STT << left << setw(13) << sv[i].MSSV << left << setw(10) << sv[i].Ten << left << setw(20) << sv[i].Ho << left << setw(15) << sv[i].Gioitinh << left << setw(20) << sv[i].Ngaysinh << sv[i].idXH  << endl;
							cout << "----------------------------------------------" << endl;
						}
						f.close();
						delete[]sv;
						break;
					}
				}
				delete[]lop;
				break;
			}
		}
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		cout << "1. Xem danh sach lop khac            2. Thoat" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		cout << "Nhap : ";
		cin >> Chon;
		if (Chon != 1 && Chon != 2) {
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
			cout << "Nhap lai : "; cin >> Chon;
		}
		delete[]nam;
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
		cout << left << setw(8) << "STT" << "Nam" << endl;
		cout << "----------------------------------------------" << endl;
		for (int i = 0; i < dem; i++) {// DANH SACH CAC NAM DE LUA CHON
			f.getline(nam[i].STT, 3, ',');
			f.getline(nam[i].Tennam, 15, ',');
			char a[100];
			f.getline(a, 100, '\n');
			cout << left << setw(8) << nam[i].STT << nam[i].Tennam << endl;
			cout << "----------------------------------------------" << endl;
		}
		f.close();
		cout << "----------------------------------------------" << endl;// CHON NAM DE XEM
		cout << "Chon nien khoa de xem danh sach khoa hoc : " << endl;
		int Chon;
		cout << "----------------------------------------------" << endl;
		cin >> Chon;
		char temp1[100];
		cout << left << setw(8)<<"STT" << left << setw(8) << "Hoc ki"<<endl;
		cout << "----------------------------------------------" << endl;
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
				for (int j = 0; j < dem; j++) {
					f.getline(hk1[j].HKthu, 3, ',');
					f.getline(hk1[j].ngayBD, 4, ',');
					f.getline(hk1[j].thangBD, 4, ',');
					f.getline(hk1[j].namBD, 7, ',');
					f.getline(hk1[j].ngayKT, 4, ',');
					f.getline(hk1[j].thangKT, 4, ',');
					f.getline(hk1[j].namKT, 7, '\n');
					cout << left << setw(8) << hk1[j].HKthu << "Hoc ki thu " << hk1[j].HKthu << endl;// DANH SACH HOC KI
					cout << "----------------------------------------------" << endl;
				}
				f.close();
				cout << "----------------------------------------------" << endl;// CHON HOC KI
				cout << "Hoc ki de xem khoa hoc : " << endl;
				cin >> Chon;
				cout << "----------------------------------------------" << endl;
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
						cout << left << setw(15) << "ID mon hoc" << left << setw(30) << "Khoa hoc" << left << setw(10) << "Lop" << left << setw(30) << "Giao vien" << left << setw(10) << "So TC" << left << setw(8) << "So SV" << left << setw(8) << "Thu" << left << setw(7) << "Tiet" << endl;
						cout << "----------------------------------------------" << endl;
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
						cout << "Nhap ID khoa hoc can xem danh sach : ";// CHON NAM HOC CAN XEM DANH SACH
						cin.ignore();
						cin.getline(temp, 100);
						cout << "----------------------------------------------" << endl;
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
						delete[]KHoc;
						break;
					}
				}
				delete[]hk1;
				break;
			}
		}
		delete[]nam;
		cout << "---------------------------------------------------" << endl;
		cout << "1. Xem danh sach khoa hoc khac            2. Thoat" << endl;
		cout << "---------------------------------------------------" << endl;
		cout << "Nhap : ";
		cin >> Chon;
		if (Chon != 1 && Chon != 2) {
			cout << "Nhap lai : "; cin >> Chon;
		}
		if (Chon == 2) return;
	}
}

void taoHK(fstream& f, char temp[]) {// Thao tac lien quan den hoc ki
	while (1) {
		system("cls");
		cout << "1. Tao hoc ki" << endl;
		cout << "----------------------------------------------" << endl;
		cout << "2. Them khoa hoc vao hoc ki" << endl;
		cout << "----------------------------------------------" << endl;
		cout << "3. Xem danh sach khoa hoc" << endl;
		cout << "----------------------------------------------" << endl;
		cout << "4. Cap nhap danh sach" << endl;
		cout << "----------------------------------------------" << endl;
		cout << "5. Them 1 sinh vien vao khoa hoc" << endl;
		cout << "----------------------------------------------" << endl;
		cout << "6. Xoa 1 sinh vien khoi khoa hoc" << endl;
		cout << "----------------------------------------------" << endl;
		cout << "7. Xoa 1 khoa hoc" << endl;
		cout << "----------------------------------------------" << endl;
		cout << "8. Quay lai" << endl;
		cout << "----------------------------------------------" << endl;
		int Chon;
		cout << "Nhap : "; cin >> Chon;
		switch (Chon) {
		case 1: {
			tao1HK(f, temp);
			break;
		}
		case 2: {
			addKH(temp);
			break;
		}
		case 3: {
			listKH(temp);
			system("pause");
			break;
		}
		case 4: {
			updateKH(temp);
			break;
		}
		case 5: {
			add1SV(temp);
			break;
		}
		case 6: {
			delete1SV(temp);
			break;
		}case 7: {
			delete1Course(temp);
			break;
		}
		default: {
			return;
		}

		}
	}
}

void quanliDiem(fstream& f) {
	while (1) {
		system("cls");// THAO TAC LIEN QUAN DEN DIEM
		cout << "1. Lay File sinh vien" << endl;
		cout << "----------------------------------------------" << endl;
		cout << "2. Them File diem" << endl;
		cout << "----------------------------------------------" << endl;
		cout << "3. Xem diem 1 khoa hoc" << endl;
		cout << "----------------------------------------------" << endl;
		cout << "4. Cap nhat diem" << endl;
		cout << "----------------------------------------------" << endl;
		cout << "5. Xem diem theo lop" << endl;
		cout << "----------------------------------------------" << endl;
		cout << "6. Dang xuat" << endl;
		cout << "----------------------------------------------" << endl;
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
		case 5:xemDiem1Lop(f); break;
		default: return;
		}
	}
}