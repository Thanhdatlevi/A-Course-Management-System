#include"System.h"

void ThongtinSinhvien(fstream& f, char MSSV[], int STT) {// IN RA THONG TIN KHI CHON XEM THONG TIN
	DSSV* sv = new DSSV[STT + 1];
	f.open("Student.csv", ios::in);
	for (int i = 0; i < STT + 1; i++) {
		f.getline(sv[i].STT, 3, ',');
		f.getline(sv[i].MSSV, 15, ',');
		f.getline(sv[i].Ten, 20, ',');
		f.getline(sv[i].Ho, 20, ',');
		f.getline(sv[i].Gioitinh, 5, ',');
		f.getline(sv[i].Ngaysinh, 20, ',');
		f.getline(sv[i].idXH, 20, ',');
		f.getline(sv[i].MKSV, 20, '\n');
	}cout << sv[STT].STT << "     " << sv[STT].MSSV << "     " << sv[STT].Ten << "     " << sv[STT].Ho << "     " << sv[STT].Gioitinh << "     " << sv[STT].Ngaysinh << "     " << sv[STT].idXH << "     " << endl;
	f.close();
	delete[]sv;
	cout << "An Enter de quay lai" << endl;
	system("pause");
}

void doiMKSV(fstream& f, char MSSV[], int STT, int soSV) {
	char temp[50];
	cout << "Nhap mat khau muon thay doi : ";
	cin.ignore();
	cin.getline(temp, 50);
	DSSV* sv = new DSSV[soSV];
	f.open("Student.csv", ios::in);
	for (int i = 0; i < soSV; i++) {
		f.getline(sv[i].STT, 3, ',');
		f.getline(sv[i].MSSV, 15, ',');
		f.getline(sv[i].Ten, 20, ',');
		f.getline(sv[i].Ho, 20, ',');
		f.getline(sv[i].Gioitinh, 5, ',');
		f.getline(sv[i].Ngaysinh, 20, ',');
		f.getline(sv[i].idXH, 20, ',');
		f.getline(sv[i].MKSV, 20, '\n');
	}
	f.close();
	f.open("Student.csv", ios::out);
	for (int j = 0; j < soSV; j++) {// NHAP LAI TAT CA GIAO VIEN VAO FILE VA THAY DOI MAT KHAU GIAO VIEN O DONG ELSE
		if (j != STT) f << sv[j].STT << "," << sv[j].MSSV << "," << sv[j].Ten << "," << sv[j].Ho << "," << sv[j].Gioitinh << "," << sv[j].Ngaysinh << "," << sv[j].idXH << "," << sv[j].MKSV << endl;
		else f << sv[j].STT << "," << sv[j].MSSV << "," << sv[j].Ten << "," << sv[j].Ho << "," << sv[j].Gioitinh << "," << sv[j].Ngaysinh << "," << sv[j].idXH << "," << temp << endl;
	}
	cout << "Da thay doi mat khau thanh cong" << endl;
	f.close();
	delete[]sv;
	cout << "An Enter de quay lai" << endl;
	system("pause");
}

void xemTKB(fstream& f, char MSSV[]) {
	while (1) {
		system("cls");
		fstream f1;
		int dem = 0;
		int dem1 = 0;
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
							strcpy_s(temp, strlen(nam[i].Tennam) + 1, nam[i].Tennam);
							strcat_s(temp, "\\");
							strcat_s(temp, nam[i].Tennam);
							strcat_s(temp, "_HK\\");
							strcat_s(temp, nam[i].Tennam);
							strcat_s(temp, "_HK");
							strcat_s(temp, hk1[j].HKthu);
							strcat_s(temp, "\\");
							strcat_s(temp, KHoc[k].TenKH);
							strcat_s(temp, "-");
							strcat_s(temp, KHoc[k].id);
							strcat_s(temp, ".csv");
							dem1 = 0;
							f1.open(temp, ios::in);
							if (f1.is_open() == 0) {
								break;
							}
							demDong(f1, dem1);
							f1.close();
							dem1++;
							DSSV* sv = new DSSV[dem1];
							f1.open(temp, ios::in);
							for (int l = 0; l < dem1; l++) {
								f1.getline(sv[l].STT, 3, ',');
								f1.getline(sv[l].MSSV, 15, ',');
								f1.getline(sv[l].Ten, 20, ',');
								f1.getline(sv[l].Ho, 20, ',');
								f1.getline(sv[l].Gioitinh, 5, ',');
								f1.getline(sv[l].Ngaysinh, 20, ',');
								f1.getline(sv[l].idXH, 20, '\n');
								if (strcmp(sv[l].MSSV, MSSV) == 0) {
									cout << KHoc[k].id << "  " << KHoc[k].TenKH << "  " << KHoc[k].TenLop << "  " << KHoc[k].TenGV << "  " << KHoc[k].STC << "  " << KHoc[k].MaxSV << "  " << KHoc[k].Thu << "  " << KHoc[k].ses << endl;
									break;
								}
							}
							f1.close();
						}
						f.close();
						break;
					}
				}break;
			}
		}
		cout << "1. Xem thoi khoa bieu khac     2. Quay lai" << endl;
		cout << "Nhap : "; cin >> Chon;
		if (Chon == 2) return;
	}
}

void xemDiem(fstream& f, char MSSV[]) {
	while (1) {
		system("cls");
		fstream f1;
		int dem = 0;
		int dem1 = 0;
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
							strcpy_s(temp, strlen(nam[i].Tennam) + 1, nam[i].Tennam);
							strcat_s(temp, "\\");
							strcat_s(temp, nam[i].Tennam);
							strcat_s(temp, "_HK\\");
							strcat_s(temp, nam[i].Tennam);
							strcat_s(temp, "_HK");
							strcat_s(temp, hk1[j].HKthu);
							strcat_s(temp, "\\");
							strcat_s(temp, KHoc[k].TenKH);
							strcat_s(temp, "-");
							strcat_s(temp, KHoc[k].id);
							strcat_s(temp, "-Diem.csv");
							f1.open(temp, ios::in);
							if (f1.is_open() == 0) {
								break;
							}
							demDong(f1, dem1);
							f1.close();
							dem1++;
							DSSV* sv = new DSSV[dem1];
							f1.open(temp, ios::in);
							for (int l = 0; l < dem1; l++) {
								f1.getline(sv[l].STT, 3, ',');
								f1.getline(sv[l].MSSV, 15, ',');
								f1.getline(sv[l].Ho, 50, ',');
								f1.getline(sv[l].totalDiem, 3, ',');
								f1.getline(sv[l].finalDiem, 3, ',');
								f1.getline(sv[l].midDiem, 3, ',');
								f1.getline(sv[l].otherDiem, 3, '\n');
								if (strcmp(sv[l].MSSV, MSSV) == 0) {
									cout << KHoc[k].TenKH << "         " << sv[l].totalDiem;
								break;
								}
							}
							f1.close();
						}
						f.close();
						break;
					}
				}break;
			}
		}
		cout << "1. Xem thoi khoa bieu khac     2. Quay lai" << endl;
		cout << "Nhap : "; cin >> Chon;
		if (Chon == 2) return;
	}
}