#ifndef P2_P_FILES_H
#define P2_P_FILES_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
/*
NOWA TABLICA
@n - ilosc wierszy
@m - ilosc kolumn
*/
int ** f_newtab(int n, int m);

/*
WYPELNIA TABLICE
@infile - plik wjesciowy
@A		- tablica na ktorej dzialamy
@n		- ilosc wierszy
@m		- ilosc kolumn
@nos	- liczba wierzochlkow
*/
void f_filltab(std::ifstream &infile, int **A, int n, int m, int *nos);

/*
WYPISUJE MACIERZ INCYDENCJI DO PLIKU
@outfile - plik wyjsciowy
@A		 - tablica grafu
@n		 - liczba wierszy
@nos	 - liczba wierzochlkow
*/
void f_showmacierz(std::ofstream &outfile, int **A, int n, int nos);

/*
WYPISUJE SASIADOW
@outfile - plik wyjsciowy
@A		 - tablica grafu
@n		 - liczba wierszy
@nos	 - liczba wierzochlkow
*/
void f_showneigh(std::ofstream &outfile, int **A, int n, int nos);

#endif