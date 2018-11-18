#ifndef RZECZ_H
#define RZECZ_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

class rzecz {

		string nazwa;
		int waga;
		int wartosc;
	public:
		//KONSTRUKTORY
		rzecz();
		rzecz(string nazwa, int waga, int wartosc);

		//GETTERy
		int get_waga();
		int get_wartosc();
		string get_nazwa();

};

class packeditem {
	rzecz p;
	int k;
public:
	packeditem(rzecz _p, int _k) {
		p = _p;
		k = _k;
	}
	int get_k() {
		return k;
	}
	rzecz get_p(){
		return p;
	}
};

#endif