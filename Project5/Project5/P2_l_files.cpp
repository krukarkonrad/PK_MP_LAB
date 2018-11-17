#include"P2_l_files.h"


int * f_newtab(int n) {
	int ** T = nullptr;
	try {

		T = new int *[n];
	}
	catch (bad_alloc) {
		cout << "!!!";
		exit(0);
	}
}

int nwd(int b, int a) {
	do
	{
		if (a>b) a = a - b;
		else b = b - a;
	} while (a != b);
	return a;
}

int dzielnik(int liczba, int dzielnik) {

	if (liczba % dzielnik != 0)
		return 0;
	else
		return 1;

}

int czy_pierwsza(int n)
{
	if (n<2)
		return 0; //gdy liczba jest mniejsza ni¿ 2 to nie jest pierwsz¹

	for (int i = 2;i*i <= n;i++)
		if (n%i == 0)
			return 0; //gdy znajdziemy dzielnik, to dana liczba nie jest pierwsza
	return 1;
}

void warunekI(int *warunki, vector <int>& liczby) {
	int a, b;
	for (int i = 0; i < liczby.size();i++) {
		a = liczby[i];
		b = a - 1;
		//cout << liczby[i] << " ";
		if (dzielnik(b, 4) == 0) {
			//cout << "Nie dzielnik 4" << endl;
		}
		else {
			//cout << "Dzielnik 4 " << endl;
			warunki[i]++;
		}
	}
}

void warunekII(int m, int *warunki, vector <int>& liczby) {
	int x, b;
	int iloscPierwszych = 0;
	int iloscWielokrotnosciPierwszych = 0;

	for (int i = 0; i < liczby.size(); i++) {
		b = liczby[i] - 1;
		for (int j = 1; j < liczby[i]; j++) {
			x = (dzielnik(m, j));
			if (x != 1) {
				x = czy_pierwsza(j);
				if (x == 1) {
					iloscPierwszych++;
					x = dzielnik(b, j);
					if (x != 1) {
						iloscWielokrotnosciPierwszych++;
					}
				}
			}
		}

		if ((iloscWielokrotnosciPierwszych == iloscPierwszych) and (iloscPierwszych > 0)) {
			warunki[i]++;
		}

		iloscPierwszych = 0;
		iloscWielokrotnosciPierwszych = 0;
	}
}

int podajC(int m) {
	int x, c;
	cout << "Podaj liczbe 'c', wzglednie pierwsza do m = " << m << endl;
	cin >> c;
	x = nwd(c, m);

	while (x != 1) {
		cout << "Blad, jeszcze raz" << endl;
		cout << "Podaj liczbe 'c', wzglednie pierwsza do m = " << m << endl;
		cin >> c;
		x = nwd(c, m);
	}

	return c;
}

int wyborLiczbyA(int *warunki, vector <int>& liczby) {

	int a = 0;
	int liczWarunki = 0;

	for (int i = 0;i < liczby.size();i++) {
		if (warunki[i] == 2) {
			if (liczby[i] > a) a = liczby[i];
			liczWarunki++;
		}
		if (liczWarunki == 0) {
			if (liczby[i] > a) a = liczby[i];
		}
	}

	return a;
}

void poczatkoweWyliczenia(int m, vector <int>& dane) {
	int w = 0, a = 2, l = 2;
	unsigned long int ap, r, p;
	a = pow(a, l);
	a = a % m;
	w = 1;
	ap = 2;
	r = 0;
	while (w != 0) {

		while (r != 1) {
			a = ap;
			l++;
			p = pow(a, l);
			r = p % m;
			if (l == m - 1) r = 1;
		}

		dane.push_back(ap);
		dane.push_back(l);

		ap++;
		l = 2;
		r = 0;
		if (ap == m) w = 0;

	}
}

void wyborNajwiekszejLambdy(vector <int>& dane, vector <int>& liczby) {
	int maks = 0;
	for (int i = 0; i < dane.size(); i = i + 2) {
		if (dane[i + 1] > maks)	maks = dane[i + 1];
	}

	for (int i = 0; i < dane.size(); i = i + 2) {
		if (dane[i + 1] == maks)	liczby.push_back(dane[i]);
	}
}

int podajSeed() {
	int m = 1;

	cout << "Podaj SEED do generotra" << endl;
	cin >> m;

	while (m == 0) {
		cout << "Podaj inny np. >0" << endl;
		cin >> m;
	}

	return m;
}

int podajM() {
	int m = 1;

	cout << "Podaj M do generotra" << endl;
	cin >> m;

	while (m == 0) {
		cout << "Podaj inny np. >0" << endl;
		cin >> m;
	}

	return m;
}

void generowanieLiczb(int a, int seed, int c, int m) {
	int w, ileLiczb;
	cout << "Ile liczb wygenerowac?" << endl;
	cin >> ileLiczb;
	for (int i = 0; i < ileLiczb; i++) {
		w = (a*seed + c) % m;
		seed = w;
		cout << w << " ";
	}
}
