#include"P2_f_file.h"

/*
TWORZY KOMBINACJE
@outfile - plik wyjściowy
@n		 - ilosc elementow zbioru
@k   	 - ilosc elementow w podzbiorze 
@numbers - aktualan tablica z cyframi
*/
void sets(std::ofstream &outfile, int k, int n)
{
	int* numbers = new int[k + 1];

	for (int i = 0; i < k + 1; i++) {
		numbers[i] = i;
	}
	int p = k;

	while (p >= 1) {

		for (int i = 1; i < k + 1; i++) {
			outfile << numbers[i];
		}
		outfile << endl;

		if (numbers[k] == n)
			p = p - 1;
		else
			p = k;


		if (p >= 1) {
			for (int i = k; i >= p; i--) {
				numbers[i] = numbers[p] + i - p + 1;
			}
		}
	}
}