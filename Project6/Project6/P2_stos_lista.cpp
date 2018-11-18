#include"P2_stos_lista.h"
#include <iostream>
#include <fstream>
#include <stack>

struct s_list {
	int val;
	s_list *next;
};

s_list *head = nullptr;
s_list *new_e;

void addElement(int el) {
	s_list *newElement = new s_list;
	newElement->val = el;
	newElement->next = head;
	head = newElement;
}



int takeElement() {
	s_list *element = head;
	s_list *element_next = head->next;
	int elementR;
	while (element == nullptr) {
		return -1;
	}
	
	while (element_next->next != nullptr) {
		element = element_next;
		element_next = element_next->next;
	}

	elementR = element_next->val;
	element->next = nullptr;
	return elementR;
}

void viewList() {
	s_list *actEl = head;
	while (actEl != nullptr) {
		cout << actEl->val << " ";
		actEl = actEl->next;
	}
	cout << endl;
}

int howManyElements() {
	s_list *actEl = head;
	int elNrs = 0;
	while (actEl != nullptr) {
		elNrs++;
		actEl = actEl->next;
	}
	return elNrs;
}

int isEmpty() {
	s_list *actEl = head;
	if (head == nullptr)
		return 1;
	else
		return 0;
}
void ProgramListy() {
	cout << endl << "LISTA" << endl;

	int n;

	ifstream infile;
	infile.open("example.txt");
	infile >> n;
	int* tab = new int[n];

	for (int i = 0; i < n; i++) {
		infile >> tab[i];
		//cout << tab[i];
		addElement(tab[i]);
	} 
	viewList();

	int z = takeElement();
	cout << "Zabrany element = " << z << endl;

	cout << "Lista po zabraniu:" << endl;
	viewList();

	cout << "Ile Elementow =" << howManyElements() << endl;
	cout << "Czy pusta 1-Tak/0-Nie = " << isEmpty() << endl;

	infile.close();
	cout << endl;
}
