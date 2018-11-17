#include"f_file.h"


void f_fillatab(std::ifstream &infile, int * lwz, int *zestaw) {
	for (int i = 0; i < *lwz; i++) {
		infile >> zestaw[i];
	}
}

int * f_newtab(int n) {
	int ** T = nullptr;
	try {

		T = new int *[n];
	}
	catch (bad_alloc) {
		cout << "!!!";
		exit(0);
	}
}

int f_binarySearch(int* T, int l, int r, int x)
{
	if (r >= l)
	{
		int m = l + (r - l) / 2;

		if (T[m] == x)
			return m;

		if (T[m] > x)
			return f_binarySearch(T, l, m - 1, x);

		return f_binarySearch(T, m + 1, r, x);
	}
	return -1;
}

int f_count(int* T, int index, int l) {
	int x = T[index];
	int i = index;
	int c = 0;

	do {
		if (T[i] == x) c++;
		i++;
	} while (T[i] == x && i <= l);

	i = index - 1;
	do {
		if (T[i] == x) c++;
		i--;
	} while (T[i] == x && i != 0);

	return(c);
}

int f_interSearch(int *T, int lwz, int x)
{
	int ip = 0, ik = lwz, isz;

	while (T[ip] <= x && x <= T[ik]) {
		isz = ip + (x - T[ip])*(ik - ip) / (T[ik] - T[ip]);
		if (T[isz] == x)
			return isz;
		else if (T[isz] < x)
			ip = isz + 1;
		else
			ik = isz - 1;
	}
	return -1;
}