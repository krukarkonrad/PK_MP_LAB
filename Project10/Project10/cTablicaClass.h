#ifndef CTABLICACLASS_H_INCLUDED
#define CTABLICACLASS_H_INCLUDED

#include "generatorClass.h"
#include <iostream>
using namespace std ;
#include <fstream>
#include <string>

class CTablica {

public:

	CTablica();

	ofstream outfile;

    int tableSize ;
    // tablica w ktorej mamy poczatkowe dane - > kopiujemy je do aktualnej tablicy abysmy mogli przetestowac kilka metod
    int *initialTable ;
    // tablica do sortowania, pod koniec algorytmu mamy w niej dane posortowane
    int *actualTable ;
    // liczba porownan
    long long int nrOfComparitions = 0 ;
    // liczba zamian
    long long int nrOfSubstitutions = 0 ;

    CTablica(int *tab, int tSize) ;

    // funkcja ladujaca nowa tablice do obiektu
    void loadNewTable(int *tab, int tSize) ;
    // funcka resetujaca liczbe zamian i porownan
    void clearResults();

	void saveResultsTofile(int no);
	void savePreTableName(int no);

    void coctailSortInitialTable() ;

    int HoarePartition(int *actTab, int startPos, int endPos);
    void QuickSortHoare(int *actTab, int startPos, int endPos);

	int LomutoPartition(int *A, int p, int q);
	void LomutoQuickSort(int *A, int p, int q);

	void ShakerSort(int *A, int n);

    void heapSort();

};





#endif // CTABLICACLASS_H_INCLUDED
