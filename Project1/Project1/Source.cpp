#include"f_file.h"


/*
#ZMIENNE#
l- ilosc zadan
n, m - kolumny, wiersze
A - tablica
*/

int main() {

	int **A = nullptr;
	int n, m, l;
	cin >> l;

	for (int i = 0; i < l; i++) {

		cin >> n >> m;

		if (((n <= 0 || n > 100) || (m <= 0 || m > 100))) {
			do {
				cout << "!(0-100)" << endl;
				cin >> n >> m;
			} while (((n <= 0 || n > 100) || (m <= 0 || m > 100)));
		}

		A = f_newtab(n, m);
		f_filltab(A, n, m);

		cout << f_maxsum(A, n, m) << endl;
	}

	getchar();
	getchar();
	return 0;
}

