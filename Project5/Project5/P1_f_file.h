#ifndef L_FILES_H
#define L_FILES_H
#include <fstream>
#include <string>
#include <iostream>

/*
"POCZATEK FUKNCJI"
@tab-tablica zestawu;
@lwz-liczb w zestawie;
*/
int f_mergeSort(int* tab, int lwz);

/*
REKURENCYJNE DZIEL I ZWY.
@tab		-tablica zestawu
@temp_tab	-tablica tymczasowa stworzona przez f_mergeSort;
@left		-indeks lewej strony tablicy;
@rigrt		-indeks prawej strony tablicy;
*/
int f_rmergeSort(int *tab, int *temp_tab, int left, int right);

/*
ZLICZ INWERSJE
@tab		-tablica zestawu
@temp_tab	-tablica tymczasowa stworzona przez f_mergeSort;
@left		-indeks lewej strony tablicy;
@mid		-indeks œrodkowy tablicy;
@rigrt		-indeks prawej strony tablicy;
*/
int f_merge(int* tab, int* temp_tab, int left, int mid, int right);

/*
TWORZY TABLICE
@n -liczba elemntow ile ma mieæ tablica
*/
int * f_newtab(int n);

/*
WYPE£NIA TABLICE
@infile	 -plik z danymi WEJŒCIOWYMI
@lwz	 -lizczb w wczytywanym zestawie
@zestaw  -tablica tego zestawu
*/
void f_fillatab(std::ifstream &infile, int * lwz, int *zestaw);

#endif
