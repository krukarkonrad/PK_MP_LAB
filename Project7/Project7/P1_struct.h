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
	string nazwa;
	int cena;
	int waga;
	double cenwag;
};
#endif