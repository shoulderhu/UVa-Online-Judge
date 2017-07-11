#include <stdio.h>

int fib[4787][1000];

int main() {

	int input;
	fib[1][999] = 1, fib[2][999] = 1;

	for (int i = 3; i < 4787; i++) {

		for (int j = 999; j >= 0; j--) {

			fib[i][j] += fib[i - 1][j] + fib[i - 2][j];

			if (fib[i][j]>9) {

				fib[i][j - 1] += 1;
				fib[i][j] -= 10;
			}
		}
	}

	while (scanf("%d", &input) != EOF) {

		int pos = 0;

		while (fib[input][pos] == 0) { pos++; }

		for (int i = pos; i < 1000; i++) { printf("%d", fib[input][i]); }
		printf("\n");
	}

	return 0;
}