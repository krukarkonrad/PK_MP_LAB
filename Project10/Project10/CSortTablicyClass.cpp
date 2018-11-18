#include"CSortTablicyClass.h"

	CSortTablicy::CSortTablicy() {
		this->tableSize = 0;
		while(this->tableSize == 0) {
			cout << "Podaj rozmiar tablicy ";
			cin >> this->tableSize;
		}
		this->tableElements = new int[this->tableSize];
	}

	int CSortTablicy::*f_newtab(int n) {
		int * T = nullptr;
		try {
			T = new int [n];
		}
		catch (bad_alloc) {
			cout << "!!!";
			exit(0);
		}
	}

	void CSortTablicy::f_fillatab(){
		for (int i = 0; i < this->tableSize; i++) {
			cout << "[Element: " << i + 1 << "/" << this->tableSize << "] ";
			cin >> this->tableElements[i];
		}
	}

	void CSortTablicy::GenerateXelements() {
		int *tempTable = generateRandomNumbersIntoTable(this->tableSize);

		for (int i = 0; i < this->tableSize; i++) {
			this->tableElements[i] = tempTable[i];
		}
		showTable(this->tableElements, this->tableSize);
	}

	void CSortTablicy::showCocktail(CTablica *sortTab) {
		cout << "coctail" << endl;
		sortTab->coctailSortInitialTable();
		cout << sortTab->nrOfComparitions << endl << sortTab->nrOfSubstitutions << endl;
		sortTab->saveResultsTofile(0);
		sortTab->clearResults();
	}

	void CSortTablicy::showShaker(CTablica *sortTab) {
		cout << "shaker:" << endl;
		sortTab->ShakerSort(sortTab->initialTable, sortTab->tableSize);
		cout << sortTab->nrOfComparitions << endl << sortTab->nrOfSubstitutions << endl;
		sortTab->saveResultsTofile(1);
		sortTab->clearResults();
	}

	void CSortTablicy::showQSLomuto(CTablica *sortTab) {
		cout << "Lomuto:" << endl;
		sortTab->LomutoQuickSort(sortTab->initialTable, 0, sortTab->tableSize);
		cout << sortTab->nrOfComparitions << endl << sortTab->nrOfSubstitutions << endl;
		sortTab->saveResultsTofile(2);
		sortTab->clearResults();
	}

	void CSortTablicy::showQSHoare(CTablica *sortTab) {
		cout << "hoare" << endl;
		sortTab->QuickSortHoare(sortTab->initialTable, 0, sortTab->tableSize);
		cout << sortTab->nrOfComparitions << endl << sortTab->nrOfSubstitutions << endl;
		sortTab->saveResultsTofile(3);
		sortTab->clearResults();
	}

	void CSortTablicy::showHeapSort(CTablica *sortTab) {
		cout << "heapSort:" << endl;
		sortTab->heapSort();
		cout << sortTab->nrOfComparitions << endl << sortTab->nrOfSubstitutions << endl;
		sortTab->saveResultsTofile(4);
		sortTab->clearResults();
	}

	int CSortTablicy::RevLomutoPartition(int *A, int p, int q) {

		int x = A[q];
		int i = p - 1;

		for (int j = p; j <= q - 1;j++) {
			if (A[j] >= x) {
				i++;
				swap(A[j], A[i]);
			}
		}
		swap(A[i + 1], A[q]);
		return(i + 1);
	}

	void CSortTablicy::RevLomutoQuickSort(int *A, int p, int q) {
		if (p < q) {
			int pivot = RevLomutoPartition(A, p, q);
			RevLomutoQuickSort(A, p, pivot - 1);
			RevLomutoQuickSort(A, pivot + 1, q);
		}
	}

	int CSortTablicy::LomutoPartition(int *A, int p, int q) {

		int x = A[q];
		int i = p - 1;

		for (int j = p; j <= q - 1;j++) {
			if (A[j] <= x) {
				i++;
				swap(A[j], A[i]);
			}
		}
		swap(A[i + 1], A[q]);
		return(i + 1);
	}


	void CSortTablicy::LomutoQuickSort(int *A, int p, int q) {
		if (p < q) {
			int pivot = LomutoPartition(A, p, q);
			LomutoQuickSort(A, p, pivot - 1);
			LomutoQuickSort(A, pivot + 1, q);
		}
	}

	void CSortTablicy::tenPercetnWrong(int *A, int length){
		float tempAmointOfNo = (length) * 0.10;
		int amointOfNo = round(tempAmointOfNo);
		if (amointOfNo == 0) {
			cout << "Za malo elementow" << endl;
		}
		else{
			int tempLength = length;
			for (int i = 0; i <= (length/2);) {
				swap(A[i], A[tempLength]);
				i += amointOfNo;
				tempLength -=amointOfNo;
			}
		}
	}

	void CSortTablicy::viewTable() {
		for (int i = 0;i < this->tableSize; i++) {
			cout << this->tableElements[i] << " ";
		}
		cout << endl;
	}


