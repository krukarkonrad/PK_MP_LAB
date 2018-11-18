#pragma once
#ifndef L_FILES_H
#define L_FILES_H
#include"P3_rzecz.h"
using namespace std;
/*
Fukncja zaczynajaca pakowanie + wczytanie
@fileName    - nazwa pliku wejesciowego
*/
void f_pakowanie(string f_name);

/*
pakowanie rekursja
@poj_plecaka - pojemnosc plecaka
*/
bool f_pakowanieRekurencja(vector <int> &pakowanie, vector <int> &rzeczy, int start, int poj_plecaka);

#endif