#include"System.h"

void setupThoigian(int& d, int& m) {// CHI DAU NAM HOC MOI CO THE TAO NAM HOC
	cout << "Ngay :"; cin >> d;
	cout << "Ngay :"; cin >> m;
}
void demDong(fstream& f, int& dem) {
	while (!f.eof()) {
		char temp[100];
		f.getline(temp, 100, '\n');
		dem++;
	}
	dem--;
}