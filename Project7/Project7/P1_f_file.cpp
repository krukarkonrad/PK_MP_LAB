#include"P1_f_file.h"
#include"P1_struct.h"

void f_wczytanie(int &ilosc, int &poj_plecaka, przedmiot* &przedmioty) {
	ifstream infile;
	infile.open("dane.txt");

	if (infile.good() == true) {
		infile >> poj_plecaka;
		infile >> ilosc;

		przedmioty = new przedmiot[ilosc];
		for (int i = 0; i < ilosc; i++)
		{
			infile >> przedmioty[i].nazwa;
			infile >> przedmioty[i].cena;
			infile >> przedmioty[i].waga;
			//przedmioty[i].cenwag = (przedmioty[i].cena / przedmioty[i].waga);
		}
	}
	infile.close();
}

void f_pakowanie(int &ilosc, int &poj_plecaka, przedmiot* &przedmioty, std::ofstream &outfile) {
	int aktualna_waga = 0, suma = 0;
	for (int i = 0;i < ilosc;i++) {
		if (przedmioty[i].waga + aktualna_waga <= poj_plecaka) {
			outfile << przedmioty[i].nazwa << " " << przedmioty[i].cena << " " << przedmioty[i].waga << endl;
			suma += przedmioty[i].cena;
			aktualna_waga += przedmioty[i].waga;
		}
	}
}
