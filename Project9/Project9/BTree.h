#ifndef BTREE_H_INCLUDED
#define BTREE_H_INCLUDED
#include <string>
#include <iostream>
using namespace std;

class BTree {
	private:

		struct BTNode {
			BTNode *rightBTNode;
			BTNode *leftBTNode;
			char letter;
			int value;
			string HoffmanCode = "";
		};

	public:

		BTNode *root;
		BTree *NewTree;

		BTree();
		BTree(BTree *rightBT, BTree *leftBT);
		void addBTNode(int NextValue, char NextLetter);
		void TreeCheck(BTNode *TempNode, ofstream &outfile);
};
#endif