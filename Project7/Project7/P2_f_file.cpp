#include"P2_f_file.h"
#include"P2_rzecz.h"

void f_wczytanie(vector <rzecz> &vectorRzeczy, int &poj_plecaka, string fileName) {

	int ilosc;
	int waga, wartosc;
	string nazwa;

	ifstream infile;
	infile.open(fileName);

	if (infile.good() == true) {
		infile >> poj_plecaka;
		infile >> ilosc;

		for (int i = 0; i < ilosc; i++)
		{
			infile >> nazwa;
			infile >> wartosc;
			infile >> waga;

			rzecz toPush(nazwa, waga, wartosc);
			vectorRzeczy.push_back(toPush);
		}
	}
	infile.close();
}


void f_pakowanie(vector <rzecz> vectorRzeczy, int poj_plecaka) {

	int size = vectorRzeczy.size();
	vector <int> wartosc;
	vector <int> waga;
	vector <int> koszt;
	vector <int> najlepszy;

	for (int i = 0; i < size; i++) {
		//cout << vectorRzeczy[i].get_wartosc() << endl;
		wartosc.push_back(vectorRzeczy[i].get_wartosc());
		//cout << vectorRzeczy[i].get_waga()  << endl;
		waga.push_back(vectorRzeczy[i].get_waga());
	}
	for (int i = 0; i < poj_plecaka + 1; i++) {
		koszt.push_back(0);
		najlepszy.push_back(0);
	}

	for (int i = 1; i < size + 1; i++) {
		for (int j = 1; j < poj_plecaka + 1; j++) {
			if (j >= waga[i - 1]) {
				if (koszt[j] < koszt[j - waga[i - 1]] + wartosc[i - 1]) {
					koszt[j] = koszt[j - waga[i - 1]] + wartosc[i - 1];
					najlepszy[j] = i;
				}
			}
		}
	}
	for (int i = 0; i < poj_plecaka + 1; i++) {
		cout << koszt[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < poj_plecaka + 1; i++) {
		cout << najlepszy[i] << " ";
	}
}
