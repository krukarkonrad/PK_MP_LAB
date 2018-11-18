#include <iostream>
#include <fstream>
#include <string>
#include "BTree.h"
#include "f_file.h"
#include "PQueue.h"

using namespace std;

int openFile(ofstream &file, string name) {

	file.open(name);

	if (file.good() == true)
	{
		cout << "open" << endl;
		return 1;
	}
	else {
		cout << "not open" << endl;
		return 0;
	}
}

void generateHuffmanCode(int tSize, float *tabValues, char *tabLetters, ofstream &outputFile) {
	PQueue *kolejka = new PQueue();

	for (int i = 0; i<tSize; i++) {
		BTree *actTree = new BTree();
		try {
			actTree->addBTNode(tabValues[i], tabLetters[i]);
			kolejka->addTree(actTree);
		}
		catch (string w) {
			cout << "Wyjatek: " << w;
		}
	}
	try {
		kolejka->CreateHuffmanAlgoritm();
		kolejka->head->TreeCheck(kolejka->head->root, outputFile);
	}
	catch (string w) {
		cout << "Wyjatek: " << w;
	}

}
