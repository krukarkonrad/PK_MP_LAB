#include <iostream>
#include <fstream>
#include <string>
#include"P3_f_file.h"
/*
@n		  - liczba
@filename - nazwa pliku
@outfile  - zmienna pliku
*/
using namespace std;

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
}