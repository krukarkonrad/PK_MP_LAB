#include <iostream>
using namespace std;
#include <fstream>
#include "generatorClass.h"
#include "cTablicaClass.h"
#include "CSortTablicyClass.h"
#include "Menu.h"


int main()
{
	menu();

	getchar();
	getchar();
    return 0;





	//MENU

	//CSortTablicy *test = new CSortTablicy;

	//test->f_fillatab();
	//test->GenerateXelements();



	// TODO :
	/*
	->klasa cSortTablicy
	|jest|->dodanie 2 sortowan do klasy cTablica
	|jest|->ilustracja dzialan roznych metod sortowania - wg przykladu
	-> stworzenie funkcji ktora 10 % elementow przestawia w tablicy
	-> wypisanie do pliku wyniku i wnioski
	-> jakies proste wyjatki, zeby chociaz 1 byl XD

	losuj liczby funkcja generateRandomNumbersIntoTable, ogolnie nie musisz zagladac do pliku z generatorem,
	mozesz tam dodac funkcje przestawiajaca 10 % elementow

	*/

	// 10
	//int tab[10] = {5,1,4,2,8,0,2,7,3,6} ;
	/*
	CTablica *sortTab = new CTablica(tab, 10) ;

	cout << "coctail" << endl ;
	sortTab->coctailSortInitialTable() ;
	cout << sortTab->nrOfComparitions << endl << sortTab->nrOfSubstitutions << endl ;
	sortTab->clearResults() ;

	cout << "hoare" << endl ;
	sortTab->QuickSortHoare(sortTab->initialTable, 0, 9) ;
	cout << sortTab->nrOfComparitions << endl << sortTab->nrOfSubstitutions << endl ;
	sortTab->clearResults() ;

	cout << "heapSort:" << endl ;
	sortTab->heapSort() ;
	cout << sortTab->nrOfComparitions << endl << sortTab->nrOfSubstitutions << endl ;
	sortTab->clearResults() ;

	cout << "Lomuto:" << endl;
	sortTab->LomutoQuickSort(sortTab->initialTable, 0, 9);
	cout << sortTab->nrOfComparitions << endl << sortTab->nrOfSubstitutions << endl;
	sortTab->clearResults();

	// 500 el
	int tabSize = 1000000 ;
	int *newTab = new int[tabSize] ;
	newTab = generateRandomNumbersIntoTable(tabSize) ;

	sortTab->loadNewTable(newTab, tabSize) ;
	cout << " 100 000" << endl << endl ;
	*/
	// dla babelkowego juz przy 10 000 wywalilo mi: moze na lepszym procku by poszlo - celeron za 120 zl XD
	/*  cout << "coctail" << endl ;
	sortTab->coctailSortInitialTable() ;
	cout << sortTab->nrOfComparitions << endl << sortTab->nrOfSubstitutions << endl ;
	sortTab->clearResults() ;*/
	/*
	cout << "hoare" << endl ;
	sortTab->QuickSortHoare(sortTab->initialTable, 0, tabSize -1) ;
	cout << sortTab->nrOfComparitions << endl << sortTab->nrOfSubstitutions << endl ;
	sortTab->clearResults() ;

	cout << "heapSort:" << endl ;
	sortTab->heapSort() ;
	cout << sortTab->nrOfComparitions << endl << sortTab->nrOfSubstitutions << endl ;
	sortTab->clearResults() ;


	//cout << "heap sort" << endl  ;

	//sortTab->heapSort() ;
	*/


	/* LinearCongurentMethod *generator = new LinearCongurentMethod(12, 100) ;
	newTab = generator->generateSequenceToTable(100) ;
	cout << "generated table" << endl ;*/


	// losowanie danych do funkcji
	/*
	int tabSize = 1000000 ;
	int *newTab = new int[tabSize] ;
	newTab = generateRandomNumbersIntoTable(tabSize) ;
	//showTable(newTab, tabSize) ;
	*/

}
