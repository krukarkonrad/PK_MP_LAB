#include"P1_f_file.h"
/*
@n		  - ilosc liczb
@filename - nazwa pliku
@outfile  - zmienna pliku
*/

int main()
{
	int n;
	string filename;
	ofstream outfile;

	cout << "Nazwa pliku = ";
	cin >> filename;

	filename += ".txt";

	outfile.open(filename, ofstream::out);

	cin >> n;
	while (n <= 0) {
		cout << "!n>0! ";
		cin >> n;
	}

	sets(outfile, n);

	outfile.close();

	getchar();
	getchar();
	return 0;
}