#ifndef STOS_TABLICA_H
#define STOS_TABLICA_H
#include <fstream>
#include <stack>
#include <iostream>

using namespace std;
/*
DODAJE ELEMENT DO STOSU
*/
void T_addElement(int *tab, int newElement, int ptr, int aon);
/*
USUWA ELEMENT SOTOSU
*/
int T_takeElement(int *tab, int &ptr);
/*
POKAZUJE LISTE
*/
void T_viewList(int *tab, int ptr);
/*
POKAZUJE WILE W LIŒCIE
*/
int T_howManyElements(int ptr);
/*
CZY PUSTY
*/
int T_isEmpty(int ptr);
/*
WYKONUJE POKAZANIE DZIA£AANIA
*/
void ProgramTablica();

#endif
