#include"P1_f_file.h"

void f_showneigh(std::ofstream &outfile, int **A, int n, int nos) {

	vector <int> somsiady;
	for (int i = 1; i <= nos; i++) {
		outfile << i << "->";
		for (int j = 0; j < n; j++) {

			if (A[j][0] == i) somsiady.push_back(A[j][1]);
			if (A[j][1] == i) somsiady.push_back(A[j][0]);
		}

		for (int i = 0; i < somsiady.size(); i++) {
			outfile << somsiady[i] << " ";
		}
		somsiady.clear();
		outfile << endl;
	}
}

void f_showmacierz(std::ofstream &outfile, int **A, int n, int nos) {
	outfile << " ";
	for (int i = 0; i < nos; i++) {
		outfile << i + 1 << "  ";
	}
	outfile << endl;

	for (int i = 0; i < nos; i++) {
		outfile << "--";
	}
	outfile << endl;

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < nos; j++) {

			if (A[i][0] == j + 1) outfile << "-1";
			if (A[i][1] == j + 1) outfile << " 1";
			if (A[i][0] != j + 1 && A[i][1] != j + 1) outfile << " 0";
			outfile << " ";
		}
		outfile << endl;
	}
	outfile << endl;
}

int ** f_newtab(int n, int m) {
	int ** T = nullptr;
	try {

		T = new int *[n];
	}
	catch (bad_alloc) {
		cout << "!!!";
		exit(0);
	}

	for (int i = 0; i < n; i++) {
		try {
			T[i] = new int[m];
		}
		catch (bad_alloc) {
			cout << "!!";
			exit(0);
		}

	}
	return T;
}

void f_filltab(std::ifstream &infile, int **A, int n, int m, int *nos)
{
	*nos = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			infile >> A[i][j];
			if (A[i][j] > *nos) *nos = A[i][j];
		}
	}
}
