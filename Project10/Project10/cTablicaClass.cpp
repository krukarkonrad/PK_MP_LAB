#include "cTablicaClass.h"

	CTablica::CTablica(){}

    CTablica::CTablica(int *tab, int tSize) {
        this->initialTable = new int[tSize] ;
        this->tableSize = tSize;
        copyValuesFromTableToTable(tab, this->initialTable, tSize) ;

        this->actualTable = new int[tSize] ;
        copyValuesFromTableToTable(tab, this->actualTable, tSize) ;
		outfile.open("res.txt", ios_base::app);
        //showTable(this->initialTable, tSize) ;
    }

    void CTablica::loadNewTable(int *tab, int tSize) {
        this->initialTable = new int[tSize] ;
        this->actualTable = new int[tSize] ;
        this->tableSize = tSize;

        copyValuesFromTableToTable(tab, this->initialTable, tSize) ;
        copyValuesFromTableToTable(tab, this->actualTable, tSize) ;

        //showTable(this->initialTable, tSize) ;
    }


	void CTablica::saveResultsTofile(int no) {
		string type[5] = { "Cocktail-Sort", "Shaker Sort", "QS: Lomuto", "QS: Hoare'a", "Kopcowanie" };
		outfile << type[no] << ":" <<endl;
		outfile << "Liczba porownan :" << this->nrOfComparitions << endl;
		outfile << "Liczba zmian    :" <<this->nrOfSubstitutions << endl;
		outfile << endl;
	}

	void CTablica::savePreTableName(int no) {
		string type[4] = { "Bez zmian","Posrotowane","Odwrotne Posrotowane","Posrotowane z 10% bledu" };
		outfile << "##################" << endl;
		outfile << endl << type[no] << endl << endl;
	}

    void CTablica::clearResults() {
        this->nrOfComparitions = 0 ;
        this->nrOfSubstitutions = 0 ;

    }

    void CTablica::coctailSortInitialTable() {

        int *actTable = new int[this->tableSize] ;
        copyValuesFromTableToTable(this->initialTable, actTable, this->tableSize);

        int leftStart = 0  ;
        int rightEnd = this->tableSize -1 ;
        int wasSwapped= 1 ;

        while(wasSwapped == 1){
            wasSwapped = 0 ;
            for(int i = leftStart ; i<rightEnd ; i++){
                this->nrOfComparitions ++ ;
                if(actTable[i] > actTable[i+1]){
                    this->nrOfSubstitutions ++ ;
                    swapValuesInTable(&actTable[i], &actTable[i+1]) ;
                    wasSwapped = 1 ;
                }
            }
            this->nrOfComparitions ++ ;
            if(wasSwapped == 0)
                return ;
            wasSwapped = 0 ;
            --rightEnd ;
            for(int j = rightEnd -1; j>=leftStart; j--){
                this->nrOfComparitions ++ ;
                if(actTable[j] > actTable[j+1]){
                    this->nrOfSubstitutions ++ ;
                    swapValuesInTable(&actTable[j], &actTable[j+1]) ;
                    wasSwapped = 1;
                }
            }
            ++leftStart;
            this->nrOfComparitions ++ ;
        }

    }

	void CTablica::ShakerSort(int *A, int n) {
		int i = 0;
		while (i < n) {
			this->nrOfComparitions++;
			for (int j = i; j < n; j++) {
				if (A[j] > A[j + 1]) {
					this->nrOfComparitions++;
					this->nrOfSubstitutions++;
					swap(A[j], A[j + 1]);
				}

			}
			//Zmnieszenie indeksu najwiekszej liczby
			n--;

			for (int j = n; j > i; j--) {
				if (A[j] < A[j - 1]) {
					this->nrOfComparitions++;
					this->nrOfSubstitutions++;
					swap(A[j], A[j - 1]);
				}
			}
			//Zwiekszenie indeksu najmniejszej liczby
			i++;
		}
	}


    int CTablica::HoarePartition(int *actTab, int startPos, int endPos) {
        int pivot = actTab[startPos] ;
        int i = startPos - 1 ;
        int j = endPos + 1 ;
        this->nrOfComparitions ++ ;
        while(true){
            do{
                j = j-1 ;
                this->nrOfComparitions ++ ;
            }while(actTab[j] > pivot) ;
            do{
                i = i+1 ;
                this->nrOfComparitions ++  ;
            }while(actTab[i] < pivot) ;
            this->nrOfComparitions ++ ;
            if(i < j){
                this->nrOfSubstitutions ++ ;
                swapValuesInTable(&actTab[i], &actTab[j]) ;
            }
            else
                return j ;
        }
    }

    void CTablica::QuickSortHoare(int *actTab, int startPos, int endPos){
        int pivot ;
        this->nrOfComparitions ++ ;
        if(startPos < endPos){
            pivot = HoarePartition(actTab, startPos, endPos) ;
            QuickSortHoare(actTab, startPos, pivot) ;
            QuickSortHoare(actTab, pivot +1, endPos) ;
        }
    }

	int CTablica::LomutoPartition(int *A, int p, int q) {

		int x = A[q];
		int i = p - 1;

		for (int j = p; j <= q - 1;j++) {
			this->nrOfComparitions++;
			if (A[j] <= x) {
				this->nrOfComparitions++;
				i++;
				this->nrOfSubstitutions++;
				swap(A[j], A[i]);
			}
		}
		this->nrOfSubstitutions++;
		swap(A[i + 1], A[q]);
		return(i + 1);
	}


	void CTablica::LomutoQuickSort(int *A, int p, int q) {
		this->nrOfComparitions++;
		if (p < q) {
			int pivot = LomutoPartition(A, p, q);
			LomutoQuickSort(A, p, pivot - 1);
			LomutoQuickSort(A, pivot + 1, q);
		}
	}



    void CTablica::heapSort() {
        int *actTable = new int[this->tableSize + 1] ;
        copyValuesFromTableToTable(this->initialTable, &actTable[1], this->tableSize);
        int childElement, parentElement, pomX;

        // budowanie kopca

        for(int i=2; i<= tableSize; i++) {
            childElement = i ;
            parentElement = childElement / 2 ;
            pomX = actTable[i] ;
            this->nrOfComparitions ++ ;
            while((parentElement > 0) && (actTable[parentElement]) < pomX){
                this->nrOfComparitions += 2 ;
                actTable[childElement] = actTable[parentElement] ;
                childElement = parentElement ;
                parentElement = childElement / 2 ;
                this->nrOfSubstitutions ++ ;
            }
            actTable[childElement] = pomX;
        }

        // rozbieranie kopca

        for(int i= tableSize; i> 1; i--){
            swapValuesInTable(&actTable[1], &actTable[i]) ;
            childElement = 1 ;
            parentElement = 2;
            this->nrOfComparitions ++ ;
            while(parentElement < i) {
                this->nrOfComparitions += 2 ;
                if((parentElement + 1 < i) && (actTable[parentElement + 1] > actTable[parentElement])) {
                    pomX = parentElement + 1 ;
                }
                else
                    pomX = parentElement ;
                this->nrOfComparitions ++ ;
                if(actTable[pomX] <= actTable[childElement])
                    break ;
                this->nrOfSubstitutions ++ ;
                swapValuesInTable(&actTable[childElement], &actTable[pomX]) ;
                childElement = pomX ;
                parentElement = childElement + childElement ;
            }
        }
        //showTable(&actTable[1], 10) ;
    }