#include"System.h"

void setupThoigian(int& d, int& m) {// Chinh thoi gian cua nam hoc
	cout << "Ngay :"; cin >> d;
	cout << "Ngay :"; cin >> m;
}
void demDong(fstream& f, int& dem) {// Dem so dong cua 1 File
	while (!f.eof()) {
		char temp[100];
		f.getline(temp, 100, '\n');
		dem++;
	}
	dem--;
}