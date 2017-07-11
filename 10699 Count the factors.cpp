#include <stdio.h>
#include <math.h>

int main() {
		
	int i, j, integer, prime[78499] = { 0, 2 }, n = 1;

	for (i = 3; i < 1000000; i += 2) {

		bool isPrime = true;

		for (j = 2; j <= sqrt(i); j++) {

			if (i%j == 0) {

				isPrime = false;
				break;
			}
		}

		if (isPrime == true) { prime[++n] = i; }
	}

	while (scanf("%d", &integer) != EOF && integer != 0) {

		int integerCp = integer, factor = 0;

		for (int i = 1; i < 78499; i++) {

			if (prime[i] > integer) { break; }
			if (integer%prime[i] == 0) { factor++; }
		}
		
		printf("%d : %d\n", integer, factor);
	}

	return 0;
}