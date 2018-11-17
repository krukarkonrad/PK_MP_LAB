#ifndef L_FILES_H
#define L_FILES_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
WYPE�NIA TABLICE
@infile	 -plik z danymi WEJ�CIOWYMI
@lwz	 -lizczb w wczytywanym zestawie
@zestaw  -tablica tego zestawu
*/
void f_fillatab(std::ifstream &infile, int * lwz, int *zestaw);

/*
TWORZY TABLICE
@n -liczba elemntow ile ma mie� tablica

ZWRACA: Now� tablice
*/
int * f_newtab(int n);

int f_binarySearch(int* T, int l, int r, int x);

/*
LICZY POWT�RZONE ELEMENTY
@T		-tabliac w kt�rej liczmy
@index	-pozycja (pierwszej) liczonej liczby
@l		-liczb w zestawie

ZWRACA: Ile razy wyst�puje dana liczba
*/
int f_count(int* T, int index, int l);

/*
WYSZUKIWANIE INTERPOLACYJNE
@T	 - tabliac w kt�rej szukamy
@lwz - ilosc liczb w tablicy
@x   - szkana liczba

ZWRACA : indeks szukanej liczy w tablicy lub (gdy tej liczby nie ma) -1
*/
int f_interSearch(int *T, int lwz, int x);
#endif

