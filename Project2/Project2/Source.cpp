#include "f_file.h"

/*
@lz		 -liczba zestawow
@lwz	 -liczb w zestawie
@lsz	 -liczb szukanych
@ilosc	 -liczy liczby takie same
@index	 -pozyja liczby w tabeli

@zestaw  -tablica z zestawem do przeszukania
@szukane -tablica z szuaknymi warotsciami

@infile	 -plik z danymi WEJŒCIOWYMI
@outfile -plik z danymi WYJŒCIOWYMI
*/

using namespace std;

int main() {

	int lz, lwz, lsz, index, ilosc;
	int *zestaw = nullptr;
	int *szukane = nullptr;


	ifstream infile;
	infile.open("example.txt");
	ofstream outfile;
	outfile.open("out.txt");
	infile >> lz;

	for (int j = 0; j < lz; j++) {

		infile >> lwz;
		zestaw = f_newtab(lwz);
		f_fillatab(infile, &lwz, zestaw);

		infile >> lsz;
		szukane = f_newtab(lsz);
		f_fillatab(infile, &lsz, szukane);

		for (int i = 0; i < lsz; i++) {
			index = f_interSearch(zestaw, (lwz - 1), szukane[i]);

			if (index != -1) ilosc = f_count(zestaw, index, lwz);
			else ilosc = 0;

			outfile << "(" << ilosc << " " << index << ")" << " ";
		}
		outfile << endl;

		int i = 0;
		do {
			outfile << zestaw[i] << " ";
			i = i + f_count(zestaw, i, lwz);
		} while (i<lwz);
		outfile << endl;

	}
	infile.close();
	outfile.close();

	getchar();
	getchar();
}