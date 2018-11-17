#include"P1_f_file.h"

/*
TWORZY KOMBINACJE
@outfile - plik wyjœciowy
@n		 - ilosc liczb
@c		 - liczba do zamiany cyfry na litere

@T		 - aktualan tablica
*/

void sets(std::ofstream &outfile, int n)
{
	if (outfile.good() == true)
	{
		int p, j;
		int* T = new int[n];

		for (int i = 0; i < n; i++)
		{
			T[i] = 0;
		}

		int i = 0;
		do {
			for (int i = 0; i < n; i++) {
				outfile << T[i];
			}

			outfile << " {";
			for (int i = 0; i < n; i++) {
				int c = i + 97;
				if (T[i] == 1)
					outfile << ((char)c) << " ";

			}
			outfile << "}" << endl;

			i++;	p = 0;	j = i;

			while (j % 2 == 0) {
				j = j / 2;
				p++;
			}

			if (p <= n) {
				T[p] = 1 - T[p];
			}

		} while (p < n);
	}
}