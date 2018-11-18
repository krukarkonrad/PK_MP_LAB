#include "P3_rzecz.h"


//KONSTRUKTORY
rzecz::rzecz() {
	nazwa = "brak";
	waga = 0;
	wartosc = 0;
}

rzecz::rzecz(string nazwa, int waga, int wartosc) {
	this->nazwa= nazwa;
	this->waga = waga;
	this->wartosc = wartosc;
}

//GETTERy
int rzecz::get_waga() {
	return waga;
}
int rzecz::get_wartosc() {
	return wartosc;
}
string rzecz::get_nazwa() {
	return nazwa;
}