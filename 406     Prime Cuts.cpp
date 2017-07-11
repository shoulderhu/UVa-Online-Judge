#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

int N;

bool isMatch(int i) { return i <= N; }

int main() {

	int i, j, C, prime[170] = { 0, 1, 2 }, n = 2;

	for (i = 3; i < 1000; i += 2) {

		bool isPrime = true;

		for (j = 2; j <= sqrt(i); j++) {

			if (i%j == 0) {

				isPrime = false;
				break;
			}
		}

		if (isPrime == true) { prime[++n] = i; }
	}

	while (scanf("%d %d", &N, &C) != EOF) {
		
		int K = count_if(prime + 1, prime + 170, isMatch);

		printf("%d %d:", N, C);

		if (K % 2 != 0) {
		    
			if (K >= 2 * C + 1) {

				for (i = (K + 1) / 2 - C + 1; i <= (K + 1) / 2 + C - 1; i++) {

					printf(" %d", prime[i]);
				}
			}
			else { for (i = 1; i <= K; i++) { printf(" %d", prime[i]); } }
		}
		else{
		    
			if (K >= 2 * C) {

				for (i = K / 2 - C + 1; i <= K / 2 + C; i++) {

					printf(" %d", prime[i]);
				}
			}
			else { for (i = 1; i <= K; i++) { printf(" %d", prime[i]); } }			
		}
				
		printf("\n\n");
	}

	return 0;
}