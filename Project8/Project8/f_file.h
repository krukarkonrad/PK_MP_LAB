#ifndef L_FILES_H
#define L_FILES_H
#include <iostream>
#include <fstream>
#include <string>
#include"struct.h"

/*
Fukncja wczytuj¹ca z pliku
@ilosc		 - ilosc rzeczy
@poj_plecaka - pojemnosc plecaka
@przedmioty  - struktura do przechowywania informacji o przedmiotach
*/
void f_wczytanie(int &ilosc, int &poj_plecaka, przedmiot* &przedmioty, plecak &plecak);


/*
Funkcja pakuj¹ca
@przedmioty		 - informacje o przedmiotach
@n				 - ilosc przedmiotow
@i				 - numer przedmiotu
@plecakTemp		 - tymczasowy plecak
@plecakNajlepszy - przechowywane najlepsze rozwiazanie
*/
void f_pakowaniePlecaka(przedmiot* przedmioty, int n, int i, plecak plecakTemp, plecak &plecakNajlepszy);


/*
Fukncja wczytuj¹ca z pliku
@ilosc		 - ilosc rzeczy
@poj_plecaka - pojemnosc plecaka
@przedmioty  - struktura do przechowywania informacji o przedmiotach
@outfile	 - plik wyjsciowy
*/
void f_pakowanie(int &ilosc, int &poj_plecaka, przedmiot* &przedmioty, std::ofstream &outfile);

#endif