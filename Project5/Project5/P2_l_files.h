#ifndef L_FILES_H
#define L_FILES_H
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;

/*
TWORZY TABLICE
@n -liczba elemntow ile ma mieæ tablica
*/
int * f_newtab(int n);

/*
NAJMNIEJSZY WSPOLN DZIELNIK
a - liczba1;
b - liczba2
*/
int nwd(int b, int a);

/*
SPRAWDZA CZY JEST RESZTA Z DZIELENIA
*/
int dzielnik(int liczba, int dzielnik);

/*
SPRAWDZA CZY LICZBA JEST PIERWSZA
*/
int czy_pierwsza(int n);

/*
SPRAWDZA:
"b jest wielokrotnoœci¹ 4, o ile m jest równie¿ wielokrotnoœci¹ 4 (jeœli 4/m, to 4/a-1)"
warunki - tablica do zlicania czy dana liczba spelania te warunki
liczby	- liczby ktore sa sprawdzane
*/
void warunekI(int *warunki, vector <int>& liczby);

/*
SPRAWDZA:
"b = a-1 jest wielokrotnoœci¹ ka¿dej liczby pierwszej p, która jest dzielnikiem m"
m		- liczba M generatora
warunki - tablica do zlicania czy dana liczba spelania te warunki
liczby	- liczby ktore sa sprawdzane
*/
void warunekII(int m, int *warunki, vector <int>& liczby);

/*
PODAJ C
m - c jest wzglêdnie pierwsze z m (c i m nie mog¹ mieæ wspólnych dzielników)
*/
int podajC(int m);

/*
WYIERA LICZBE A DO GENERATORA
warunki - tablica do sprawdzenia czy dana liczba spelania te warunki
liczby  - liczby ktore sa sprawdzane
*/
int wyborLiczbyA(int *warunki, vector <int>& liczby);

/*
POCZATKOWE WYZNACZANIE LAMBD
m		- liczba M generatora
dane	- otrzymane wyniki 
*/
void poczatkoweWyliczenia(int m, vector <int>& dane);

/*
WYZACZANIE NAJWIEKSZEYCH LAMBD
liczby - liczby ktore sa sprawdzane
dane   - do wliczen
*/
void wyborNajwiekszejLambdy(vector <int>& dane, vector <int>& liczby);

/*
PODAJ SEED
*/
int podajSeed();

/*
PODAJ M
*/
int podajM();

/*
GENEROWANIE LICZB NA PODSTAWIE WYLICZEN WYRZEJ 
ze wzoru:
x(n+1)=(a * x(n) + c) mod m
a - zmienna a generatora
c - zmienna c generatora
m - zmienna m generatora
seed - ziarno generatora
*/
void generowanieLiczb(int a, int seed, int c, int m);
#endif

