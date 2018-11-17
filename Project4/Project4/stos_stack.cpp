#include"stos_stack.h"

void ProgramStack() {
	cout << endl << "STOS" << endl;
	int n;

	int ptr = 0;
	int newElement;
	stack <int> stos;

	ifstream infile;
	infile.open("example.txt");
	infile >> n;
	int l = n;

	for (int i = 0; i < n; i++) {
		infile >> newElement;
		stos.push(newElement);
		cout << newElement << " ";
	}
	cout << endl;

	int z;
	z = stos.size();
	cout << "Ile Elementow = " << z << endl;

	cout << "Zabrany element: " << stos.top() << endl;
	stos.pop();

	z = stos.size();
	cout << "Ile Elementow po zabraniu = " << z << endl;

	cout << "Czy pusta 1-Tak/0-Nie = ";
	if (stos.empty())
		cout << "1";
	else
		cout << "0";

	infile.close();
	cout << endl;
}
//STOS KONIEC