#include "PQueue.h"
#include <iostream>

PQueue::PQueue() {
	this->head = nullptr;
	this->tail = nullptr;
}
void PQueue::addTree(BTree *treeRoot) {    
	if (this->head == nullptr) {
		this->head = treeRoot;
		this->tail = treeRoot;
		return;
	}
	BTree *TempElement = new BTree;
	TempElement = head;
	if (treeRoot->root->value >= TempElement->root->letter) {
		treeRoot->NewTree = this->head;
		this->head = treeRoot;
		return;
	}
	else {
		while (TempElement->NewTree != nullptr) {
			if (treeRoot->root->value >= TempElement->NewTree->root->value) {
				treeRoot->NewTree = TempElement->NewTree;
				TempElement->NewTree = treeRoot;
				return;
			}
			else if (treeRoot->root->value < TempElement->NewTree->root->value) {
				TempElement = TempElement->NewTree;
			}
		}
	}
	TempElement->NewTree = treeRoot;
}
void PQueue::viewTreeList() {
	BTree *TempElement = new BTree;
	TempElement = head;
	while (TempElement != nullptr) {
		cout << TempElement->root->value << endl;
		TempElement = TempElement->NewTree;
	}

}
int PQueue::showHowManyTreesInQueue() {
	int nrOfTrees = 0;
	BTree *TempElement = new BTree;
	TempElement = head;
	while (TempElement != nullptr) {
		nrOfTrees++;
		TempElement = TempElement->NewTree;
	}
	return nrOfTrees;
}
void PQueue::CreateHuffmanAlgoritm() {
	BTree *last2TreesMerged;
	if (this->showHowManyTreesInQueue() <= 1) {
		string exc = "Za malo drzew aby utworzyc kod Huffmana !";
		throw exc;
	}
	while (this->showHowManyTreesInQueue() > 1) {
		last2TreesMerged = new BTree(this->returnLastTree(), this->returnPreLastTree());
		this->deleteLastTree();
		this->deleteLastTree();
		this->addTree(last2TreesMerged);
	}
}
BTree* PQueue::returnLastTree() {
	if (this->head == nullptr) {
		//return ;
		cout << "nie ma czego zwrocic";
	}
	BTree *TempElement = new BTree;
	TempElement = head;
	while (TempElement->NewTree != nullptr) {
		TempElement = TempElement->NewTree;
	}
	return TempElement;
}

BTree* PQueue::returnPreLastTree() {
	if (this->head == nullptr || this->head->NewTree == nullptr) {
		//return ;
		cout << " nie ma przedostatniego drzewa";
	}
	BTree *TempElement = new BTree;
	TempElement = head;
	while (TempElement->NewTree->NewTree != nullptr) {
		TempElement = TempElement->NewTree;
	}
	return TempElement;
}

void PQueue::deleteLastTree() {
	if (this->head == nullptr)
		return;
	BTree *TempElement = new BTree;
	TempElement = head;
	if (TempElement->NewTree == nullptr) {
		delete TempElement;
		this->head = nullptr;
		return;
	}
	while (TempElement->NewTree != nullptr) {
		if (TempElement->NewTree->NewTree != nullptr) {
			TempElement = TempElement->NewTree;
		}
		else {
			delete TempElement->NewTree;
			TempElement->NewTree = nullptr;
			return;
		}
	}
}