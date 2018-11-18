#include "Menu.h"

void testSorts(CTablica *sortTab, CSortTablicy * test, int type) {

	sortTab->savePreTableName(type);

	test->showCocktail(sortTab);
	test->showShaker(sortTab);
	test->showQSLomuto(sortTab);
	test->showQSHoare(sortTab);
	test->showHeapSort(sortTab);
}


void menu() {

		CSortTablicy * test = new CSortTablicy;
		int menu2 = 9;
		while (menu2 != 0) {
			cout << "Co chcesz zrobic" << endl;
			cout << "1. Wprowadzenie zadanej liczby elementow z klawiatury" << endl;
			cout << "2. Losowanie zadanej liczby elementow" << endl;
			cout << "Wybor: ";
			cin >> menu2;

			switch (menu2) {

			case 1:
				test->f_fillatab();
				menu2 = 0;
				break;

			case 2:
				test->GenerateXelements();
				menu2 = 0;
				break;

			default:
				cout << "Jeszcze raz!" << endl;
				menu2 = 9;
				break;
			}

		}

		CTablica *sortTab = new CTablica(test->tableElements, test->tableSize);
		//ZWYK£A
		testSorts(sortTab, test, 0);

		//POSORTOWANA
		test->LomutoQuickSort(test->tableElements, 0, test->tableSize - 1);
		CTablica *sortTab1 = new CTablica(test->tableElements, test->tableSize);
		testSorts(sortTab1, test, 1);

		//ODWROTIE
		test->RevLomutoQuickSort(test->tableElements, 0, test->tableSize);
		CTablica *sortTab2 = new CTablica(test->tableElements, test->tableSize);
		testSorts(sortTab2, test, 2);

		//10%
		test->LomutoQuickSort(test->tableElements, 0, test->tableSize - 1);
		test->tenPercetnWrong(test->tableElements, test->tableSize - 1);
		CTablica *sortTab3 = new CTablica(test->tableElements, test->tableSize);
		testSorts(sortTab3, test, 3);

		/*
		menu2 = 9;
		while (menu2 != 0) {
			cout << "Co chcesz zrobic z tablica przed sorotowaniem?" << endl;
			cout << "1. Zostawic" << endl;
			cout << "2. Posortowac" << endl;
			cout << "3. Posortowac i odwrococ" << endl;
			cout << "4. Sorotwanie z 10% nieuporzadkwanych" << endl;
			cout << "5. DALEJ" << endl;
			cout << "Wybor: ";
			cin >> menu2;

			switch (menu2) {

			case 1:
				cout << endl << "Nic" << endl;
				//menu2 = 0;
				break;
			case 2:
				cout << endl << "Sortowanie" << endl;
				test->LomutoQuickSort(test->tableElements, 0, test->tableSize - 1);
				test->viewTable();
				//menu2 = 0;
				break;
			case 3:
				cout << endl << "Odwrotne sortowanie" << endl;
				test->RevLomutoQuickSort(test->tableElements, 0, test->tableSize);
				test->viewTable();
				//menu2 = 0;
				break;
			case 4:
				cout << endl << "Sortowanie + 10% zle" << endl;
				test->LomutoQuickSort(test->tableElements, 0, test->tableSize - 1);
				test->tenPercetnWrong(test->tableElements, test->tableSize - 1);
				test->viewTable();
				//menu2 = 0;
				break;
			case 5:
				menu2 = 0;
				break;
			default:
				cout << "Jeszcze raz!" << endl;
				menu2 = 9;
				break;
			}

		}

		CTablica *sortTab = new CTablica(test->tableElements, test->tableSize);
		testSorts(sortTab, test);
		*/

	
}