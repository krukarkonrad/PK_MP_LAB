#include <iostream>
#include "P2_rzecz.h"
#include "P2_f_file.h"

int main() {

	vector <rzecz> plecak;
	int poj_okecaka;

	f_wczytanie(plecak, poj_okecaka, "dane.txt");
	f_pakowanie(plecak, poj_okecaka);

	getchar();
	getchar();
}