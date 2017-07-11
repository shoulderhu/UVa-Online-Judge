#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

int main() {

	int N, prime[78499] = {0, 2}, p = 1;

	for (int i = 3; i < 1000000; i += 2) {

		bool isPrime = true;

		for (int j = 2; j <= sqrt(i); j++) {

			if (i%j == 0) {

				isPrime = false;
				break;
			}
		}

		if (isPrime == true) { prime[++p] = i; }
	}
	
	while (scanf("%d", &N) != EOF) {

		int n = 0, NCp = N;

		if (find(prime + 1, prime + 78499, N) == prime + 78499) { 
			
			printf("%d is not prime.\n", N); 
		}
		else {

			while (NCp > 0) {

				n = n * 10 + NCp % 10;
				NCp /= 10;
			}

			if (n != N && find(prime + 1, prime + 78499, n) != prime + 78499) { 
				
				printf("%d is emirp.\n", N); 
			}
			else { printf("%d is prime.\n", N); }
		}
	}
	
	return 0;
}