#include <iostream>
#include <fstream>
#include"f_file.h"
#include"struct.h"

int main() {

	int Wplecaka, n, sumowanie, k, t;
	int p = 0, w = 0, mp = 0;
	przedmiot *przedmioty;
	plecak plecakStart;
	plecak plecakNajlepszy;

	f_wczytanie(n, Wplecaka, przedmioty, plecakStart);
	plecakNajlepszy = plecakStart;
	f_pakowaniePlecaka(przedmioty, n, 0, plecakStart, plecakNajlepszy);
	cout << "Najlepsze pakowanie\nmasa= " << plecakNajlepszy.masa_aktualna << " \nwartosc" << plecakNajlepszy.wartosc_aktualna;

	getchar();
	getchar();
}
