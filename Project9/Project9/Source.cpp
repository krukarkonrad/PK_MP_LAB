#include <iostream>
#include "BTree.h"
#include "PQueue.h"
#include "f_file.h"
#include <fstream>

int main()
{
	ofstream outputFile;
	openFile(outputFile, "output.txt");

	outputFile << "Przyklad a: " << endl;
	char tabLetters[7] = { 'A','B','I','M','S','X', 'Z' };
	float tabValues[7] = { 12, 7, 18, 10, 9, 5, 2 };
	generateHuffmanCode(7, tabValues, tabLetters, outputFile);

}
