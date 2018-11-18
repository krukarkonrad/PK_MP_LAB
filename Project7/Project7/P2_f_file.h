#pragma once
#ifndef L_FILES_H
#define L_FILES_H

#include"P2_rzecz.h"
using namespace std;

/*
Fukncja wczytuj¹ca z pliku
@poj_plecaka - pojemnosc plecaka
@fileName    - nazwa pliku wejesciowego
*/
void f_wczytanie(vector <rzecz> &vectorRzeczy, int &poj_plecaka, string fileName);

/*
Funkcja pakujaca
@poj_plecaka - pojemnosc plecaka
*/
void f_pakowanie(vector <rzecz> vectorRzeczy, int poj_plecaka);

#endif