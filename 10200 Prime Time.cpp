#include <stdio.h>
#include <math.h>

bool isPrime(int formulaCp) {

	for (int i = 2; i <= sqrt(formulaCp); i++) {

		if (formulaCp%i == 0) { return false; }
	}

	return true;
}

int main() {

	int a, b, i, table[10000], formula;

	for (i = 0; i < 10000; i++) {

		i <= 39 ? table[i] = 1 : table[i] = 0;
	}

	while (scanf("%d %d", &a, &b) != EOF) {

		int primeNum = 0;

		for (i = a; i <= b; i++) {

			if (table[i] == 0) {

				formula = i*i + i + 41;

				isPrime(formula) ? table[i] = 1 : table[i] = 2;
			}

			if (table[i] == 1) { primeNum++; }
		}

		printf("%.2lf\n", ((double)primeNum / (b - a + 1) * 100) + 0.00001);
	}
	
	return 0;
}