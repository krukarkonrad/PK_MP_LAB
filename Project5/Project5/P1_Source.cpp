#include"P1_f_file.h"
using namespace std;

int main(){

	int lz, lwz;
	int *zestaw=nullptr;
	string filename;
	ofstream outfile;
	ifstream infile;
	infile.open("example.txt");

	cout << "Nazwa pliku OUT= ";
	cin >> filename;

	filename += ".txt";
	outfile.open(filename, ofstream::out);

	infile >> lz;
	
	for (int i = 0;i < lz;i++){
		infile >> lwz;
		zestaw = f_newtab(lwz);
		f_fillatab(infile, &lwz, zestaw);
		outfile<< f_mergeSort(zestaw, lwz) << endl;
	}
	
	outfile.close();
	infile.close();
	getchar();
	getchar();
	return 0;

}