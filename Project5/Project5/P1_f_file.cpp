#include"P1_f_file.h"

int f_mergeSort(int *tab, int lwz)
{
	int* temp_tab = new int[(sizeof(int)*lwz)];
	return f_rmergeSort(tab, temp_tab, 0, lwz - 1);
}

int f_rmergeSort(int* tab, int* temp_tab, int left, int right)
{
	int mid, count = 0;
	if (right > left)
	{
		mid = (right + left) / 2;

		count = f_rmergeSort(tab, temp_tab, left, mid);
		count += f_rmergeSort(tab, temp_tab, mid + 1, right);

		count += f_merge(tab, temp_tab, left, mid + 1, right);
	}
	return count;
}

int f_merge(int *tab, int *temp_tab, int left, int mid, int right)
{
	int i, j, k;
	int count = 0;

	i = left; 
	j = mid;  
	k = left; 
	while ((i <= mid - 1) && (j <= right)){
		if (tab[i] <= tab[j]){
			temp_tab[k++] = tab[i++];
		}
		else{
			temp_tab[k++] = tab[j++];
			count = count + (mid - i);
		}
	}

	while (i <= mid - 1)
		temp_tab[k++] = tab[i++];

	while (j <= right)
		temp_tab[k++] = tab[j++];

	for (i = left; i <= right; i++)
		tab[i] = temp_tab[i];

	return count;
}


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
	catch (std::bad_alloc) {
		std::cout << "!!!";
		exit(0);
	}
}