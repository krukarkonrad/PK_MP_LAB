#include <iostream>
#include <fstream>
#include <string>
#include "BTree.h"

	BTree::BTree() {
		
		this->root = nullptr;
		this->NewTree = nullptr;
	
	}

	BTree::BTree(BTree *rightBT, BTree *leftBT) {
		
		int val;
		val = rightBT->root->value + leftBT->root->value;
		
		this->root = new BTNode();
		this->root->value = val;
		this->root->rightBTNode = rightBT->root;
		this->root->leftBTNode = leftBT->root;
	
	}

	void BTree::addBTNode(int NextValue, char NextLetter) {
	
		if (this->root != nullptr) {
			BTNode *NewTree = new BTNode();
			NewTree->value = NextValue;
			NewTree->letter = NextLetter;
			NewTree->rightBTNode = nullptr;
			NewTree->leftBTNode = nullptr;

			BTNode *TempTree = new BTNode();
			TempTree = root;

			while (TempTree != nullptr){
				if (NewTree->value < TempTree->value) {

					if (TempTree->leftBTNode != nullptr) {
						TempTree = TempTree->leftBTNode;
					}
					else {
						TempTree->leftBTNode = NewTree;
						return;
					}

				}
				else {

					if (TempTree->rightBTNode != nullptr) {
						TempTree = TempTree->rightBTNode;
					}
					else {
						TempTree->rightBTNode = NewTree;
						return;
					}

				}
			}

		}
		else {
			root = new BTNode;
			this->root->value = NextValue;
			this->root->letter = NextLetter;
		}
	}

	void BTree::TreeCheck(BTNode *TempNode, ofstream &outfile) {

		if (this->root == nullptr) {
			string error = "blad, za malo wezlow";
			throw error;
		}


		if (TempNode->leftBTNode != nullptr) {
			TempNode->leftBTNode->HoffmanCode = TempNode->HoffmanCode + "0";
			TreeCheck(TempNode->leftBTNode, outfile);
		}

		if (TempNode->rightBTNode != nullptr) {
			TempNode->rightBTNode->HoffmanCode = TempNode->HoffmanCode + "1";
			TreeCheck(TempNode->rightBTNode, outfile);
		}

		if (TempNode->leftBTNode == nullptr && TempNode->rightBTNode == nullptr) {
			if (TempNode->HoffmanCode != "\n") {
				outfile << TempNode->letter << " - " << TempNode->HoffmanCode << endl;
			}
			else {
				cout << "Puste Drzewo" << endl;
			}
			
		}
	}
