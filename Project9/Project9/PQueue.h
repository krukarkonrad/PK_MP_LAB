#ifndef PQUEUE_H_INCLUDED
#define PQUEUE_H_INCLUDED
#include <iostream>
#include "BTree.h"
using namespace std;

class PQueue {

public:

	BTree * head;
	BTree * tail;
	PQueue();

	void addTree(BTree *TreeRoot);

	void viewTreeList();

	int showHowManyTreesInQueue();

	void CreateHuffmanAlgoritm();

	BTree * returnLastTree();

	BTree * returnPreLastTree();

	void deleteLastTree();

};
#endif