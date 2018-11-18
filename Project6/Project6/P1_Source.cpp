#include"P1_f_file.h"

/*
@n			- liczba krawedzi
@nos		- liczba wierzcholkow
@filename	- nazwa pliku
@infile		- plik wejsciowy
@outfile	- plik wyjsciowy
*/

int main()
{
	int n; 
	int nos; 

	int **graf = nullptr;
	string filename;
	
	//cin >> filename;

	filename = "dane";
	filename += ".txt";
	ifstream infile;
	infile.open(filename);
	ofstream outfile;
	outfile.open("out.txt");

	infile >> n;
	graf = f_newtab(n, 2);
	f_filltab(infile, graf, n, 2, &nos);
	f_showmacierz(outfile, graf, n, nos);
	f_showneigh(outfile, graf, n, nos);

	outfile.close();
	infile.close();

	getchar();
	getchar();
}

