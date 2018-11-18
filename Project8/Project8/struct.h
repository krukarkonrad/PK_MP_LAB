#ifndef S_FILES_H
#define S_FILES_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
Struktura przedmiotu
@cenawag - stosunek cena/waga
*/
struct przedmiot
{
	int cena;
	int waga;
	int cenwag;
};

/*
Struktura plecaka
*/
struct plecak
{
	int masa_max;
	int masa_aktualna;
	int wartosc_aktualna;
};

#endif