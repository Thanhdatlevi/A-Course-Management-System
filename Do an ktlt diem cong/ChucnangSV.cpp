#include"System.h"

void ThongtinSinhvien(fstream& f, char MSSV[], int STT) {// IN RA THONG TIN KHI CHON XEM THONG TIN
	DSSV* sv = new DSSV[STT + 1];
	cout << left << setw(8) << "STT" << left << setw(13) << "MSSV" << left << setw(10) << "Ho" << left << setw(20) << "Ten" << left << setw(15) << "Gioi tinh" << left << setw(20) << "Ngay sinh" << "ID Xa hoi" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------" << endl;
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
	}cout << left << setw(8) << sv[STT].STT << left << setw(13) << sv[STT].MSSV << left << setw(10) << sv[STT].Ten << left << setw(20) << sv[STT].Ho << left << setw(15) << sv[STT].Gioitinh << left << setw(20) << sv[STT].Ngaysinh << sv[STT].idXH << endl;
	f.close();
	delete[]sv;
	cout << "------------------------------------" << endl;
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
	cout << "------------------------------------" << endl;
	cout << "Da thay doi mat khau thanh cong" << endl;
	f.close();
	delete[]sv;
	cout << "------------------------------------" << endl;
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
		cout << left << setw(8) << "STT" << "Nam" << endl;
		cout << "----------------------------------------------" << endl;
		f.open("Namhoc.csv", ios::in);
		char temp[100];
		for (int i = 0; i < dem; i++) {// DANH SACH NAM HOC
			f.getline(nam[i].STT, 3, ',');
			f.getline(nam[i].Tennam, 15, ',');
			char a[100];
			f.getline(a, 100, '\n');
			cout << left << setw(8) << nam[i].STT << nam[i].Tennam << endl;
			cout << "----------------------------------------------" << endl;
		}
		f.close();
		cout << "----------------------------------------------" << endl;// CHON NAM HOC
		cout << "Chon nien khoa de xem thoi khoa bieu : " << endl;
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
				cout << left << setw(8) << "STT" << left << setw(8) << "Hoc ki" << endl;
				cout << "----------------------------------------------" << endl;
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
				cout << "----------------------------------------------" << endl;// NHAP HOC KI CAN XEM TKB
				cout << "Hoc ki : " << endl;
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
						cout << left << setw(15) << "ID mon hoc" << left << setw(30) << "Khoa hoc" << left << setw(10) << "Lop" << left << setw(30) << "Giao vien" << left << setw(10) << "So TC" << left << setw(8) << "So SV" << left << setw(8) << "Thu" << left << setw(7) << "Tiet" << endl;
						cout << "----------------------------------------------------------------------------------------------------------------" << endl;
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
									cout << left << setw(15) << KHoc[k].id << left << setw(30) << KHoc[k].TenKH << left << setw(10) << KHoc[k].TenLop << left << setw(30) << KHoc[k].TenGV << left << setw(10) << KHoc[k].STC << left << setw(8) << KHoc[k].MaxSV << left << setw(8) << KHoc[k].Thu << left << setw(7) << KHoc[k].ses << endl;
									cout << "----------------------------------------------------------------------------------------------------------------" << endl;
									break;
								}
							}
							f1.close();
							delete[]sv;
						}
						f.close();
						delete[]KHoc;
						break;
					}
				}
				delete[]hk1;
				break;
			}
		}
		delete[]nam;
		cout << "----------------------------------------------" << endl;
		cout << "1. Xem thoi khoa bieu khac     2. Quay lai" << endl;
		cout << "----------------------------------------------" << endl;
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
		cout << left << setw(8) << "STT" << "Nam" << endl;
		cout << "----------------------------------------------" << endl;
		f.open("Namhoc.csv", ios::in);
		char temp[100];
		for (int i = 0; i < dem; i++) {// DANH SACH CAC NAM
			f.getline(nam[i].STT, 3, ',');
			f.getline(nam[i].Tennam, 15, ',');
			char a[100];
			f.getline(a, 100, '\n');
			cout << left << setw(8) << nam[i].STT << nam[i].Tennam << endl;
			cout << "----------------------------------------------" << endl;
		}
		f.close();
		cout << "----------------------------------------------" << endl;// CHON NAM XEM DIEM
		cout << "Chon nien khoa de xem diem : " << endl;
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
				cout << left << setw(8) << "STT" << left << setw(8) << "Hoc ki" << endl;
				cout << "----------------------------------------------" << endl;
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
				cout << "----------------------------------------------" << endl;// CHON HOC KI XEM DIEM
				cout << "Hoc ki : " << endl;
				cin >> Chon;
				cout << left << setw(30) << "Khoa hoc" << "Diem" << endl;
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
									cout << left << setw(30) << KHoc[k].TenKH << sv[l].totalDiem<<endl;
									cout << "----------------------------------------------" << endl;
								break;
								}
							}
							f1.close();
							delete[]sv;
						}
						f.close();
						delete[]KHoc;
						break;
					}
				}
				delete[]hk1;
				break;
			}
		}
		delete[]nam;
		cout << "----------------------------------------------" << endl;
		cout << "1. Xem thoi khoa bieu khac     2. Quay lai" << endl;
		cout << "----------------------------------------------" << endl;
		cout << "Nhap : "; cin >> Chon;
		if (Chon == 2) return;
	}
}