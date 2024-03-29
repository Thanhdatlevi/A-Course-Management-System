#include"System.h"

void nhapDiem(fstream& f) {// LAY DANH SACH SINH VIEN DE NHAP DIEM
	while (1) {
		system("cls");
		fstream f1;
		int dem = 0;
		char temp[100];
		cout << "Nhap dia chi cua file chua danh sach xuat ra : ";
		cin.ignore();
		cin.getline(temp, 100);
		f.open("Namhoc.csv", ios::in);
		demDong(f, dem);
		Nam* nam = new Nam[dem];
		f.close();
		cout << left << setw(8) << "STT" << "Nam" << endl;
		cout << "----------------------------------------------" << endl;
		f.open("Namhoc.csv", ios::in);
		for (int i = 0; i < dem; i++) {// DANH SACH CAC NAM
			f.getline(nam[i].STT, 3, ',');
			f.getline(nam[i].Tennam, 15, ',');
			char a[100];
			f.getline(a, 100, '\n');
			cout << left << setw(8) << nam[i].STT << nam[i].Tennam << endl;
			cout << "----------------------------------------------" << endl;
		}
		f.close();
		cout << "----------------------------------------------" << endl;// CHON NAM LAY DANH SACH
		cout << "Chon nien khoa lay danh sach khoa hoc : " << endl;
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
					cout << left << setw(8) << hk1[j].HKthu << "Hoc ki thu " << hk1[j].HKthu << endl;// dANH SACH HOC KI
					cout << "----------------------------------------------" << endl;
				}
				f.close();
				cout << "----------------------------------------------" << endl;// CHON HOC KI DE LAY DIEM
				cout << "Hoc ki de lay danh sach khoa hoc : " << endl;
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
						cout << left << setw(15) << "ID mon hoc" << left << setw(30) << "Khoa hoc" << left << setw(10) << "Lop" << left << setw(30) << "Giao vien" << left << setw(10) << "So TC" << left << setw(8) << "So SV" << left << setw(8) << "Thu" << left << setw(7) << "Tiet" << endl;
						cout << "----------------------------------------------------------------------------------------------------------------" << endl;
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
							cout << "----------------------------------------------------------------------------------------------------------------" << endl;
						}
						f.close();
						cout << "----------------------------------------------" << endl;// CHON ID KHOA HOC DE NHAP DIEM
						cout << "Nhap id khoa hoc can lay danh sach : ";
						cin.ignore();
						cin.getline(temp1, 50);
						for (int k = 0; k < dem; k++) {
							if (strcmp(temp1, KHoc[k].id) == 0) {
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
								f1.open(temp, ios::out);
								f.open(temp1, ios::in);
								for (int l = 0; l < dem; l++) {
									f.getline(sv[l].STT, 3, ',');
									f.getline(sv[l].MSSV, 15, ',');
									f.getline(sv[l].Ten, 20, ',');
									f.getline(sv[l].Ho, 20, ',');
									f.getline(sv[l].Gioitinh, 5, ',');
									f.getline(sv[l].Ngaysinh, 20, ',');
									f.getline(sv[l].idXH, 20, '\n');
									f1 << sv[l].STT << ',' << sv[l].MSSV << ',' << sv[l].Ho << ' ' << sv[l].Ten << endl;
								}
								f.close();
								f1.close();
								delete[]sv;
								break;
							}
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
		cout << "1. Lay danh sach khac     2. Quay lai" << endl;
		cout << "----------------------------------------------" << endl;
		cout << "Nhap : "; cin >> Chon;
		if (Chon == 2) return;
	}
}

void themDiem(fstream& f) {// THEM FILE DIEM VAO HE THONG
	while (1) {
		system("cls");
		fstream f1;
		int dem = 0;
		char temp[100];
		cout << "Nhap dia chi cua file chua danh sach xuat ra : ";
		cin.ignore();
		cin.getline(temp, 100);
		f.open("Namhoc.csv", ios::in);
		demDong(f, dem);
		Nam* nam = new Nam[dem];
		f.close();
		f.open("Namhoc.csv", ios::in);
		for (int i = 0; i < dem; i++) {// DANH SACH CAC NAM
			f.getline(nam[i].STT, 3, ',');
			f.getline(nam[i].Tennam, 15, ',');
			char a[100];
			f.getline(a, 100, '\n');
			cout << nam[i].STT << ". " << nam[i].Tennam << endl;
		}
		f.close();
		cout << "----------------------------------------------" << endl;// CHON NAM
		cout << "Chon nien khoa de them file diem : " << endl;
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
					cout << left << setw(8) << hk1[j].HKthu << "Hoc ki thu " << hk1[j].HKthu << endl;
					cout << "----------------------------------------------" << endl;
				}
				f.close();
				cout << "----------------------------------------------" << endl;// CHON HOC KI DE THEM FILE DIEM
				cout << "Hoc ki chua khoa hoc : " << endl;
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
						cout << left << setw(15) << "ID mon hoc" << left << setw(30) << "Khoa hoc" << left << setw(10) << "Lop" << left << setw(30) << "Giao vien" << left << setw(10) << "So TC" << left << setw(8) << "So SV" << left << setw(8) << "Thu" << left << setw(7) << "Tiet" << endl;
						cout << "----------------------------------------------------------------------------------------------------------------" << endl;
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
							cout << "----------------------------------------------------------------------------------------------------------------" << endl;
						}
						f.close();
						cout << "----------------------------------------------" << endl;// CHON KHOA HOC THEM DIEM
						cout << "Nhap id khoa hoc can them diem : ";
						cin.ignore();
						cin.getline(temp1, 50);
						for (int k = 0; k < dem; k++) {
							if (strcmp(temp1, KHoc[k].id) == 0) {
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
								strcat_s(temp1, "-Diem.csv");
								f.open(temp, ios::in);
								dem = 0;
								demDong(f, dem);
								f.close();
								DSSV* sv = new DSSV[dem];
								f1.open(temp1, ios::out);
								f.open(temp, ios::in);
								for (int l = 0; l < dem; l++) {
									f.getline(sv[l].STT, 3, ',');
									f.getline(sv[l].MSSV, 15, ',');
									f.getline(sv[l].Ho, 50, ',');
									f.getline(sv[l].totalDiem, 3, ',');
									f.getline(sv[l].finalDiem, 3, ',');
									f.getline(sv[l].midDiem, 3, ',');
									f.getline(sv[l].otherDiem, 3, '\n');
									f1 << sv[l].STT << ',' << sv[l].MSSV << ',' << sv[l].Ho << ',' << sv[l].totalDiem << ',' << sv[l].finalDiem << ',' << sv[l].midDiem << ',' << sv[l].otherDiem << endl;
								}
								f.close();
								f1.close();
								delete[]sv;
								break;
							}
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
		cout << "-----------------------------------------------------" << endl;
		cout << "1. Them File diem vao khoa hoc khac     2. Quay lai" << endl;
		cout << "-----------------------------------------------------" << endl;
		cout << "Nhap : "; cin >> Chon;
		if (Chon == 2) return;
	}
}

void xemDiem1KH(fstream& f) {
	while (1) {
		system("cls");
		fstream f1;
		int dem = 0;
		f.open("Namhoc.csv", ios::in);
		demDong(f, dem);
		Nam* nam = new Nam[dem];
		f.close();
		cout << left << setw(8) << "STT" << "Nam" << endl;
		cout << "----------------------------------------------" << endl;
		f.open("Namhoc.csv", ios::in);
		for (int i = 0; i < dem; i++) {// DANH SACH CAC NAM
			f.getline(nam[i].STT, 3, ',');
			f.getline(nam[i].Tennam, 15, ',');
			char a[100];
			f.getline(a, 100, '\n');
			cout << left << setw(8) << nam[i].STT << nam[i].Tennam << endl;
			cout << "----------------------------------------------" << endl;
		}
		f.close();
		cout << "----------------------------------------------" << endl;// CHON NAM
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
				f.open(temp1, ios::in);
				HK* hk1 = new HK[dem];
				cout << left << setw(8) << "STT" << left << setw(8) << "Hoc ki" << endl;// DANH SACH HOC KI
				cout << "----------------------------------------------" << endl;
				for (int j = 0; j < dem; j++) {
					f.getline(hk1[j].HKthu, 3, ',');
					f.getline(hk1[j].ngayBD, 4, ',');
					f.getline(hk1[j].thangBD, 4, ',');
					f.getline(hk1[j].namBD, 7, ',');
					f.getline(hk1[j].ngayKT, 4, ',');
					f.getline(hk1[j].thangKT, 4, ',');
					f.getline(hk1[j].namKT, 7, '\n');
					cout << left << setw(8) << hk1[j].HKthu << "Hoc ki thu " << hk1[j].HKthu << endl;
					cout << "----------------------------------------------" << endl;
				}
				f.close();
				cout << "----------------------------------------------" << endl;// CHON HOC KI DE XEM DIEM
				cout << "Hoc ki de xem diem : " << endl;
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
						cout << left << setw(15) << "ID mon hoc" << left << setw(30) << "Khoa hoc" << left << setw(10) << "Lop" << left << setw(30) << "Giao vien" << left << setw(10) << "So TC" << left << setw(8) << "So SV" << left << setw(8) << "Thu" << left << setw(7) << "Tiet" << endl;
						cout << "----------------------------------------------------------------------------------------------------------------" << endl;
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
							cout << "----------------------------------------------------------------------------------------------------------------" << endl;
						}
						f.close();
						cout << "----------------------------------------------" << endl;// CHON KHOA HOC DE XEM DIEM
						cout << "Nhap id khoa hoc can xem diem : ";
						cin.ignore();
						cin.getline(temp1, 50);
						for (int k = 0; k < dem; k++) {
							if (strcmp(temp1, KHoc[k].id) == 0) {
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
								strcat_s(temp1, "-Diem.csv");
								f.open(temp1, ios::in);
								dem = 0;
								demDong(f, dem);
								f.close();
								DSSV* sv = new DSSV[dem];
								cout << left << setw(8) << "STT" << left << setw(13) << "MSSV" << left << setw(30) << "Ten" << left << setw(12) << "Diem tong" << left << setw(12) << "Diem CK" << left << setw(12) << "Diem GK" << "Diem Khac" << endl;
								cout << "----------------------------------------------------------------------------------------------------------------" << endl;
								f.open(temp1, ios::in);
								for (int l = 0; l < dem; l++) {
									f.getline(sv[l].STT, 3, ',');
									f.getline(sv[l].MSSV, 15, ',');
									f.getline(sv[l].Ho, 50, ',');
									f.getline(sv[l].totalDiem, 3, ',');
									f.getline(sv[l].finalDiem, 3, ',');
									f.getline(sv[l].midDiem, 3, ',');
									f.getline(sv[l].otherDiem, 3, '\n');
									cout << left << setw(8) << sv[l].STT << left << setw(13) << sv[l].MSSV << left << setw(30) << sv[l].Ho << left << setw(12) << sv[l].totalDiem << left << setw(12) << sv[l].finalDiem << left << setw(12) << sv[l].midDiem  << sv[l].otherDiem << endl;
									cout << "----------------------------------------------------------------------------------------------------------------" << endl;
								}
								f.close();
								delete[]sv;
								break;
							}
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
		cout << "1. Xem diem khac     2. Quay lai" << endl;
		cout << "----------------------------------------------" << endl;
		cout << "Nhap : "; cin >> Chon;
		if (Chon == 2) return;
	}
}

void xemDiem1Lop(fstream& f) {
	while (1) {
		system("cls");
		long long S1=0;
		fstream f1;
		int dem = 0;
		f.open("Namhoc.csv", ios::in);
		demDong(f, dem);
		Nam* nam = new Nam[dem];
		f.close();
		cout << left << setw(8) << "STT" << "Nam" << endl;
		cout << "----------------------------------------------" << endl;
		f.open("Namhoc.csv", ios::in);
		for (int i = 0; i < dem; i++) {// DANH SACH CAC NAM
			f.getline(nam[i].STT, 3, ',');
			f.getline(nam[i].Tennam, 15, ',');
			char a[100];
			f.getline(a, 100, '\n');
			cout << left << setw(8) << nam[i].STT << nam[i].Tennam << endl;
			cout << "----------------------------------------------" << endl;
		}
		f.close();
		cout << "----------------------------------------------" << endl;// CHON NAM
		cout << "Chon nien khoa de xem diem theo lop : " << endl;
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
				cout << left << setw(8) << "STT" << left << setw(8) << "Hoc ki" << endl;
				cout << "----------------------------------------------" << endl;
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
				cout << "Hoc ki de xem diem : " << endl;
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
						int dem1 = 0;
						f.open(temp1, ios::in);
						cout << "----------------------------------------------" << endl;// NHAP LOP DE XEM DIEM
						cout << "Nhap lop can xem diem : ";
						cin.ignore();
						cin.getline(temp1, 50);
						cout << "----------------------------------------------" << endl;
						cout << left << setw(15) << "ID mon hoc" << left << setw(30) << "Khoa hoc" << left << setw(10) << "Lop" << left << setw(30) << "Giao vien" << left << setw(10) << "So TC" << left << setw(8) << "So SV" << left << setw(8) << "Thu" << left << setw(7) << "Tiet" << endl;
						cout << "----------------------------------------------------------------------------------------------------------------" << endl;
						for (int k = 0; k < dem; k++) {
							f.getline(KHoc[k].id, 10, ',');
							f.getline(KHoc[k].TenKH, 30, ',');
							f.getline(KHoc[k].TenLop, 30, ',');
							f.getline(KHoc[k].TenGV, 50, ',');
							f.getline(KHoc[k].STC, 5, ',');
							f.getline(KHoc[k].MaxSV, 4, ',');
							f.getline(KHoc[k].Thu, 4, ',');
							f.getline(KHoc[k].ses, 3, '\n');
							if (strcmp(temp1, KHoc[k].TenLop) == 0) {
								dem1++;
								cout << left << setw(15) << KHoc[k].id << left << setw(30) << KHoc[k].TenKH << left << setw(10) << KHoc[k].TenLop << left << setw(30) << KHoc[k].TenGV << left << setw(10) << KHoc[k].STC << left << setw(8) << KHoc[k].MaxSV << left << setw(8) << KHoc[k].Thu << left << setw(7) << KHoc[k].ses << endl;
								cout << "----------------------------------------------------------------------------------------------------------------" << endl;
							}
						}
						KhoaHoc* KHoc1 = new KhoaHoc[dem1];
						dem1 = 0;
						for (int k = 0; k < dem; k++) {
							if (strcmp(temp1, KHoc[k].TenLop) == 0) {
								KHoc1[dem1] = KHoc[k];
								dem1++;
							}
						}
						f.close();
						cout << "----------------------------------------------" << endl;// CHON KHOA HOC CU THE DE XEM DIEM
						cout << "Nhap id can xem diem : ";
						cin.getline(temp1, 50);
						for (int k = 0; k < dem1; k++) {
							if (strcmp(temp1, KHoc1[k].id) == 0) {
								strcpy_s(temp1, strlen(nam[i].Tennam) + 1, nam[i].Tennam);
								strcat_s(temp1, "\\");
								strcat_s(temp1, nam[i].Tennam);
								strcat_s(temp1, "_HK");
								strcat_s(temp1, "\\");
								strcat_s(temp1, nam[i].Tennam);
								strcat_s(temp1, "_HK");
								strcat_s(temp1, hk1[j].HKthu);
								strcat_s(temp1, "\\");
								strcat_s(temp1, KHoc1[k].TenKH);
								strcat_s(temp1, "-");
								strcat_s(temp1, KHoc1[k].id);
								strcat_s(temp1, "-Diem.csv");
								f.open(temp1, ios::in);
								dem = 0;
								demDong(f, dem);
								f.close();
								DSSV* sv = new DSSV[dem];
								cout << left << setw(8) << "STT" << left << setw(13) << "MSSV" << left << setw(30) << "Ten" << left << setw(12) << "Diem tong" << left << setw(12) << "Diem GPA" << endl;
								cout << "----------------------------------------------------------------------------------------------------------------" << endl;
								f.open(temp1, ios::in);
								for (int l = 0; l < dem; l++) {
									f.getline(sv[l].STT, 3, ',');
									f.getline(sv[l].MSSV, 15, ',');
									f.getline(sv[l].Ho, 50, ',');
									f.getline(sv[l].totalDiem, 3, ',');
									f.getline(sv[l].finalDiem, 3, ',');
									f.getline(sv[l].midDiem, 3, ',');
									f.getline(sv[l].otherDiem, 3, '\n');
									cout << left << setw(8) << sv[l].STT << left << setw(13) << sv[l].MSSV << left << setw(30) << sv[l].Ho << left << setw(12) << sv[l].totalDiem << left << setw(12)<<fixed<<setprecision(2) << (float)(stoi(sv[l].totalDiem) * 4 / 10) << endl;
									cout << "----------------------------------------------------------------------------------------------------------------" << endl;
									S1+=(float)(stoi(sv[l].totalDiem) * 4 / 10);
								}
								f.close();
								cout << "GPA cua tong sinh vien : " <<fixed<<setprecision(2) << S1<<endl;
								delete[]sv;
								break;
							}
						}
						f.close();
						delete[]KHoc;
						break;
					}
				}delete[]hk1;
				break;
			}
		}
		delete[]nam;
		cout << "----------------------------------------------" << endl;
		cout << "1. Xem diem lop khac     2. Quay lai" << endl;
		cout << "----------------------------------------------" << endl;
		cout << "Nhap : "; cin >> Chon;
		if (Chon == 2) return;
	}
}

void capnhatDiem(fstream& f) {
	while (1) {
		system("cls");
		fstream f1;
		int dem = 0;
		f.open("Namhoc.csv", ios::in);
		demDong(f, dem);
		Nam* nam = new Nam[dem];
		f.close();
		cout << left << setw(8) << "STT" << "Nam" << endl;
		cout << "----------------------------------------------" << endl;
		f.open("Namhoc.csv", ios::in);
		for (int i = 0; i < dem; i++) {// DANH SACH CAC NAM DE LUA CHON
			f.getline(nam[i].STT, 3, ',');
			f.getline(nam[i].Tennam, 15, ',');
			char a[100];
			f.getline(a, 100, '\n'); 
			cout << left << setw(8) << nam[i].STT << nam[i].Tennam << endl;// Danh sach Nam
			cout << "----------------------------------------------" << endl;
		}
		f.close();
		cout << "----------------------------------------------" << endl;// CHON NAM HOC
		cout << "Chon nien khoa de cap nhat : " << endl;
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
				for (int j = 0; j < dem; j++) {// KIEM TRA XEM HOC KI DO DA CO TRONG NAM HOC CHUA
					f.getline(hk1[j].HKthu, 3, ',');
					f.getline(hk1[j].ngayBD, 4, ',');
					f.getline(hk1[j].thangBD, 4, ',');
					f.getline(hk1[j].namBD, 7, ',');
					f.getline(hk1[j].ngayKT, 4, ',');
					f.getline(hk1[j].thangKT, 4, ',');
					f.getline(hk1[j].namKT, 7, '\n');
					cout << left << setw(8) << hk1[j].HKthu << "Hoc ki thu " << hk1[j].HKthu << endl;
					cout << "----------------------------------------------" << endl;
				}
				f.close();
				cout << "----------------------------------------------" << endl;// CHON HOC KI
				cout << "Chon hoc ki de cap nhat : " << endl;
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
						cout << left << setw(15) << "ID mon hoc" << left << setw(30) << "Khoa hoc" << left << setw(10) << "Lop" << left << setw(30) << "Giao vien" << left << setw(10) << "So TC" << left << setw(8) << "So SV" << left << setw(8) << "Thu" << left << setw(7) << "Tiet" << endl;
						cout << "----------------------------------------------------------------------------------------------------------------" << endl;
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
							cout << "----------------------------------------------------------------------------------------------------------------" << endl;
						}
						f.close();
						cout << "----------------------------------------------" << endl;// NHAP ID KHOA HOC DE CA NHAT
						cout << "Nhap id khoa hoc can cap nhat diem : ";
						cin.ignore();
						cin.getline(temp1, 50);
						for (int k = 0; k < dem; k++) {
							if (strcmp(temp1, KHoc[k].id) == 0) {
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
								strcat_s(temp1, "-Diem.csv");
								f.open(temp1, ios::in);
								dem = 0;
								demDong(f, dem);
								f.close();
								DSSV* sv = new DSSV[dem];
								cout << left << setw(8) << "STT" << left << setw(13) << "MSSV" << left << setw(30) << "Ten" << left << setw(12) << "Diem tong" << left << setw(12) << "Diem CK" << left << setw(12) << "Diem GK" << "Diem Khac" << endl;
								cout << "----------------------------------------------------------------------------------------------------------------" << endl;
								f.open(temp1, ios::in);
								for (int l = 0; l < dem; l++) {
									f.getline(sv[l].STT, 3, ',');
									f.getline(sv[l].MSSV, 15, ',');
									f.getline(sv[l].Ho, 50, ',');
									f.getline(sv[l].totalDiem, 3, ',');
									f.getline(sv[l].finalDiem, 3, ',');
									f.getline(sv[l].midDiem, 3, ',');
									f.getline(sv[l].otherDiem, 3, '\n');
									cout << left << setw(8) << sv[l].STT << left << setw(13) << sv[l].MSSV << left << setw(30) << sv[l].Ho << left << setw(12) << sv[l].totalDiem << left << setw(12) << sv[l].finalDiem << left << setw(12) << sv[l].midDiem << sv[l].otherDiem << endl;
									cout << "----------------------------------------------------------------------------------------------------------------" << endl;
								}
								f.close();
								cout << "----------------------------------------------" << endl;
								cout << "Nhap MSSV can cap nhat : ";
								char temp[15];
								cin.getline(temp, 15);
								DSSV sv1;
								cout << "Nhap diem tong ket : ";
								cin.getline(sv1.totalDiem, 3);
								cout << "Nhap diem cuoi ki : ";
								cin.getline(sv1.finalDiem, 3);
								cout << "Nhap diem giua ki : ";
								cin.getline(sv1.midDiem, 3);
								cout << "Nhap diem khac : ";
								cin.getline(sv1.otherDiem, 3);
								f.open(temp1, ios::out);
								for (int l = 0; l < dem; l++) {
									if (strcmp(temp, sv[l].MSSV) == 0) {
										f << sv[l].STT << ',' << sv[l].MSSV << ',' << sv[l].Ho << ',' << sv1.totalDiem << ',' << sv1.finalDiem << ',' << sv1.midDiem << ',' << sv1.otherDiem << endl;
									}
									f << sv[l].STT << ',' << sv[l].MSSV << ',' << sv[l].Ho << ',' << sv[l].totalDiem << ',' << sv[l].finalDiem << ',' << sv[l].midDiem << ',' << sv[l].otherDiem << endl;
								}
								f.close();
								delete[]sv;
								break;
							}
						}
						f.close();
						delete[]KHoc;
						break;
					}
				}delete[]hk1;
				break;
			}
		}
		delete[]nam;
		cout << "----------------------------------------------" << endl;
		cout << "1. Cap nhat diem sinh vien khac     2. Quay lai" << endl;
		cout << "----------------------------------------------" << endl;
		cout << "Nhap : "; cin >> Chon;
		if (Chon == 2) return;
	}
}