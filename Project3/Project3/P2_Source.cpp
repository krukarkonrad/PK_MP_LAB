#include"P2_f_file.h"

/*
@n		  - ilosc elementow zbioru
@k   	  - ilosc elementow w podzbiorze
@filename - nazwa pliku
@outfile  - zmienna pliku
*/

int main()
{
	int n, k;

	string filename;
	ofstream outfile;

	cout << "Nazwa pliku = ";
	cin >> filename;

	filename += ".txt";

	outfile.open(filename, ofstream::out);

	cout << "k= ";
	cin >> k;
	while (k <= 0) {
		cout << "!k>0! ";
		cin >> k;
	}

	cout << "n= ";

	cin >> n;

	if (k <= n)
		sets(outfile, k, n);
	else
		cout << "! k < n !";

	outfile.close();

	getchar();
	getchar();
}
