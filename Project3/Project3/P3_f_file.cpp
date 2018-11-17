#include"P3_f_file.h"

void sets(std::ofstream &outfile, int n) {

	int *numbers = new int[n];
	int *anumbers = new int[n];
	int d = 0, sum, l;

	for (int i = 0; i < n; i++) {
		numbers[i] = -1;
		anumbers[i] = -1;
	}

	numbers[0] = n;
	anumbers[0] = 1;

	outfile << n << endl;


	while (numbers[0] > 1) {
		sum = 0;
		if (numbers[d] == 1) {
			sum = sum + anumbers[d];
			anumbers[d] = -1;
			numbers[d] = -1;
			d--;
		}

		sum = sum + numbers[d];
		anumbers[d] --;
		l = numbers[d] - 1;

		if (anumbers[d] > 0)
			d++;

		numbers[d] = l;
		anumbers[d] = sum / l;
		l = sum % l;

		if (l != 0) {
			d++;
			numbers[d] = l;
			anumbers[d] = 1;
		}

		for (int i = 0; i < n; i++) {
			if (anumbers[i] != -1) {
				for (int j = 0; j < anumbers[i]; j++) {
					outfile << numbers[i];
					if (j < anumbers[i] - 1)
						outfile << "+";
				}
				if (anumbers[i + 1] > 0)
					outfile << "+";
			}
		}
		outfile << endl;
	}
}