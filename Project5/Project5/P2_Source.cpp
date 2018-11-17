#include"P2_l_files.h"

int main()
{
	int a, w, c, m, seed;
	vector <int> dane;
	vector <int> liczby;
	

	m = podajM();
	poczatkoweWyliczenia(m, dane);
	wyborNajwiekszejLambdy(dane, liczby);
	
	
	int *warunki = nullptr;
	warunki = f_newtab(liczby.size());
	
	for (int i = 0; i < liczby.size(); i++) {
		warunki[i] = 0;
	}
	
	warunekI(warunki, liczby);
	warunekII(m, warunki, liczby);

	a = wyborLiczbyA(warunki, liczby);
	c = podajC(m);
	seed = podajSeed();

	generowanieLiczb(a, seed, c, m);
	
	getchar();
	getchar();
}