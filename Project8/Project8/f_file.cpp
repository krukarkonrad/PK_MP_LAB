#include"f_file.h"
#include"struct.h"

void f_wczytanie(int &ilosc, int &poj_plecaka, przedmiot* &przedmioty, plecak &plecak) {
	ifstream infile;
	infile.open("dane.txt");

	if (infile.good() == true) {
		plecak.masa_aktualna = 0;
		plecak.wartosc_aktualna = 0;
		infile >> plecak.masa_max;
		infile >> ilosc;

		przedmioty = new przedmiot[ilosc];
		for (int i = 0; i < ilosc; i++){
			infile >> przedmioty[i].cena;
			infile >> przedmioty[i].waga;
			infile >> przedmioty[i].cenwag;
		}
	}
	infile.close();
}

void f_pakowaniePlecaka(przedmiot* przedmioty, int n, int i, plecak plecakTemp, plecak &plecakNajlepszy) {

	if (i > 0) {
		cout << "Przedmiot= " << i << endl;
	}

	if (plecakTemp.masa_max >= plecakTemp.masa_aktualna
		&& plecakTemp.wartosc_aktualna > plecakNajlepszy.wartosc_aktualna) {
		plecakNajlepszy = plecakTemp;
		cout << "Masa plecaka = " << plecakTemp.masa_aktualna << endl;
	}

	if (n == i) {
		return;
	}

	if (plecakTemp.masa_max < plecakTemp.masa_aktualna) {
		cout << "Przekroczono W, masa = " << plecakTemp.masa_aktualna << " Wartosc = " << plecakTemp.wartosc_aktualna << endl;
	}
	cout << przedmioty[i].cenwag;

	int bound;
	bound = plecakTemp.wartosc_aktualna + (plecakTemp.masa_max - plecakTemp.masa_aktualna)*przedmioty[i].cenwag;

	if (bound <= plecakNajlepszy.wartosc_aktualna) {
		cout << "Za maly bound " << endl;
		cout << "masa = " << plecakTemp.masa_aktualna
			<< ", wartosc = " << plecakTemp.wartosc_aktualna
			<< ", bound = " << bound << endl;
		return;
	}

	plecak nowyPlecak;
	nowyPlecak.masa_max = plecakTemp.masa_max;
	nowyPlecak.masa_aktualna = plecakTemp.masa_aktualna + przedmioty[i].waga;
	nowyPlecak.wartosc_aktualna = plecakTemp.wartosc_aktualna + przedmioty[i].cena;

	f_pakowaniePlecaka(przedmioty, n, i + 1, nowyPlecak, plecakNajlepszy);
	f_pakowaniePlecaka(przedmioty, n, i + 1, plecakTemp, plecakNajlepszy);
}