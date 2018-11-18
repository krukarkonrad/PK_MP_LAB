#ifndef Class_INCLUDED
#define Class_INCLUDED
#include"cTablicaClass.h"
#include"generatorClass.h"
#include <fstream>
#include <iostream>

class CSortTablicy{

public:
	int tableSize;

	int *tableElements;

	CSortTablicy();

	void fillTable(int tableSize, int tableElements);

	void generateNumbers(int tableSize);

	int * f_newtab(int n);

	void f_fillatab();

	void GenerateXelements();

	void showCocktail(CTablica * sortTab);
	void showShaker(CTablica * sortTab);
	void showQSLomuto(CTablica * sortTab);
	void showQSHoare(CTablica * sortTab);
	void showHeapSort(CTablica * sortTab);

	int RevLomutoPartition(int *A, int p, int q);
	void RevLomutoQuickSort(int *A, int p, int q);

	int LomutoPartition(int *A, int p, int q);
	void LomutoQuickSort(int *A, int p, int q);

	void tenPercetnWrong(int *A, int length);
	void viewTable();
};
#endif