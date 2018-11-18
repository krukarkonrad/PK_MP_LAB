#include "P1_f_file.h"
#include "P1_struct.h"

/*
@outfile - plik wyjsciowy
@ilosc - ilosc rzeczy
@poj_plecaka - pojemnosc plecaka
*/
int main (){

	int poj_plecaka, ilosc;
	przedmiot *przedmioty;
	
	ofstream outfile;
	outfile.open("wynik.txt", ofstream::out);

	f_wczytanie(ilosc, poj_plecaka, przedmioty);
	f_pakowanie(ilosc, poj_plecaka, przedmioty, outfile);

	outfile.close();
	getchar();
	getchar();
	return 0;
}