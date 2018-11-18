#include <iostream>
#include"P3_f_file.h"
#include"P3_rzecz.h"

void f_pakowanie(string f_name) {

	ifstream infile;

	int iloscZbiorow, poj_plecaka, poj_iloscowa, ilsocRzeczy, start = 0;
	infile.open(f_name.c_str());
	if (!infile.good())
		exit(0);
	infile >> iloscZbiorow;

	while (!infile.eof()) {
		infile >> poj_plecaka;
		infile >> poj_iloscowa;
		vector <int> rzeczy;
		for (int i = 0; i < poj_iloscowa; i++) {
			infile >> ilsocRzeczy;
			rzeczy.push_back(ilsocRzeczy);
		}
		vector <int> pakowanie;
		int a = f_pakowanieRekurencja(pakowanie, rzeczy, 0, poj_plecaka);

		if (a == 1) {
			cout << poj_plecaka << " = ";
			int size = pakowanie.size();
			for (int i = 0; i < size; i++) {
				cout << pakowanie[i] << " ";
			}
			cout << endl;
		}

		else
			cout << "BRAK" << endl;

		rzeczy.clear();
		pakowanie.clear();
	}
	infile.close();
}

bool f_pakowanieRekurencja(vector <int> &pakowanie, vector <int> &rzeczy, int start, int poj_plecaka) {

	if (poj_plecaka == 0) return true;

	else if (start + 1 > rzeczy.size() || poj_plecaka < 0) return false;

	pakowanie.push_back(rzeczy[start]);

	bool a = f_pakowanieRekurencja(pakowanie, rzeczy, start + 1, poj_plecaka - rzeczy[start]);

	if (a == 1) return 1;

	pakowanie.pop_back();

	a = f_pakowanieRekurencja(pakowanie, rzeczy, start + 1, poj_plecaka);

	return a;
}
