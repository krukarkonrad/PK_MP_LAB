#include"P2_f_file.h"
#include"P2_stos_lista.h"

/*
@n			- liczba krawedzi
@nos		- liczba wierzcholkow
@filename	- nazwa pliku
@infile		- plik wejsciowy
@outfile	- plik wyjsciowy
@sw			- Stopieñ wierzcho³ka
k			- licznik do stopni
*/

int main(){
	int n, nos;
	int **graf = nullptr;
	string filename;

	filename = "dane";
	filename += ".txt";
	ifstream infile;
	infile.open(filename);
	ofstream outfile;
	outfile.open("out.txt");

	infile >> n;

	int * sw = new int[n];

	graf = f_newtab(n, 2);
	f_filltab(infile, graf, n, 2, &nos);

	int k=0;

	for (int i = 1; i <= nos; i++) {
		outfile << i << "->";
		for (int j = 0; j < n; j++) {

			if (graf[j][0] == i) addElement(graf[j][1]); //somsiady.push_back(graf[j][1]);
			if (graf[j][1] == i) addElement(graf[j][0]); //somsiady.push_back(graf[j][0]);
		}
		
		sw[k] = howManyElements();
		k++;
		
		while (isEmpty()!=1){
			int z = takeElement();
			outfile << z << " ";
		}		
		outfile << endl;
	}

	for (int i=0; i < k ;i++) {
		outfile << i+1 << " - " << sw[i] << endl;
	}

	outfile.close();
	infile.close();

	getchar();
	getchar();
}

