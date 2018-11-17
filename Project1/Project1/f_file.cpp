#include"f_file.h"


/*
WYPE£NIENIE TABLICY
n - liczba wierszy
m - liczba kolumn 
*/
int ** f_newtab(int n, int m) {
	int ** T = nullptr;
	try {

		T = new int *[n];
	}
	catch (bad_alloc) {
		cout << "!!!";
		exit(0);
	}

	for (int i = 0; i < n; i++) {
		try {
			T[i] = new int[m];
		}
		catch (bad_alloc) {
			cout << "!!";
			exit(0);
		}

	}
	return T;
}

/*
WYPE£NIENIE TABLICY
A - tablica
n - liczba kolumn
m - liczba wierszy
*/
void f_filltab(int **A, int n, int m)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> A[i][j];
		}
	}
}

/*
ALGORYTM SUMUJACY
A - tablica
n - liczba kolumn
*/
int f_kadane(int* A, int n) {

	int max = 0, value = 0;

	for (int i = 0; i < n; ++i) {

		if (A[i]>(A[i] + value))
			value = A[i];
		else
			value = A[i] + value;

		if (value > max)
			max = value;
	}
	return max;
}

/*
MAXYMALNA SUMA
tab - tablica
n	- liczba kolumn
m	- liczba wierszy
*/
int f_maxsum(int** tab, int n, int m) {

	int max = 0, value;
	int *temp, i, j, k;

	temp = new int[n];

	for (i = 0; i < m; ++i) {

		for (j = 0; j < n; ++j)
			temp[j] = 0;

		for (j = i; j < m; ++j) {

			for (k = 0; k < n; ++k)
				temp[k] += tab[k][j];

			value = f_kadane(temp, n);

			if (value > max)
				max = value;
		}
	}
	delete[] temp;

	return max;
}