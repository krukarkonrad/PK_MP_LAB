#ifndef F_FILE
#define F_FILE
#include <string>
#include <iostream>
using namespace std;

int openFile(ofstream &file, string name);

void generateHuffmanCode(int tSize, float *tabValues, char *tabLetters, ofstream &outputFile);

#endif