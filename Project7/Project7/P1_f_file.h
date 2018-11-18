#pragma once
#ifndef L_FILES_H
#define L_FILES_H
#include <iostream>
#include <fstream>
#include <string>
#include"P1_struct.h"
using namespace std;

/*
Fukncja wczytuj¹ca z pliku
@ilosc - ilosc rzeczy
@poj_plecaka - pojemnosc plecaka
@przedmioty - struktura do przechowywania informacji o przedmiotach
*/
void f_wczytanie(int &ilosc, int &poj_plecaka, przedmiot* &przedmioty);

/*
Fukncja wczytuj¹ca z pliku
@ilosc - ilosc rzeczy
@poj_plecaka - pojemnosc plecaka
@przedmioty - struktura do przechowywania informacji o przedmiotach
@outfile - plik wyjsciowy
*/
void f_pakowanie(int &ilosc, int &poj_plecaka, przedmiot* &przedmioty, std::ofstream &outfile);

#endif