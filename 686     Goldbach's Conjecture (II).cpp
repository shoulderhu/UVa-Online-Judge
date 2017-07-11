#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {

	int i, j, integer, prime[3513] = {0, 2}, n = 1;

	for (i = 3; i < 32768; i += 2) {

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

		int pair = 0;

		for (i = 1; i < 3513; i++) {

			if (prime[i] > integer / 2) { break; }
			else if(find(prime + 1, prime + 3513, (integer - prime[i])) != (prime + 3513)) { pair++; }
		}

		printf("%d\n", pair);
	}
	
	return 0;
}