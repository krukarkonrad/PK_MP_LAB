#include"stos_tablica.h"


void T_addElement(int *tab, int newElement, int ptr, int n) {
	if (ptr < n) {
		tab[ptr] = newElement;
		ptr++;
	}
	else {
		cout << "STACK IS FULL";
		system("pause");
	}
}

int T_takeElement(int *tab, int &ptr) {
	ptr--;
	return tab[ptr];
}

int T_isEmpty(int ptr) {
	if (ptr > 0) return(0);
	else return(1);
}

int T_howManyElements(int ptr) {
	return ptr;
}

void T_viewList(int *tab, int ptr) {
	for (int i = 0; i < ptr; i++) {
		cout << tab[i] << " ";
	}
	cout << endl;
}

void ProgramTablica() {
	cout << endl << "TABLICA" << endl;

	int n;

	ifstream infile;
	infile.open("example.txt");
	infile >> n;
	int ptr = 0;
	int newElement;
	int* tab = new int[n];

	for (int i = 0; i < n; i++) {
		infile >> newElement;
		T_addElement(tab, newElement, ptr++, n);
	}

	T_viewList(tab, ptr);
	int z = T_takeElement(tab, ptr);
	cout << "Zabrany element: " << z << endl;

	cout << "Lista po zabraniu:" << endl;
	T_viewList(tab, ptr);
	z = T_howManyElements(ptr);
	cout << "Ile Elementow = " << z << endl;
	z = T_isEmpty(ptr);
	cout << "Czy pusta 1-Tak/0-Nie = " << z << endl;

	infile.close();
	cout << endl;
}