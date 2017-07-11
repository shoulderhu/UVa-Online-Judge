#include <stdio.h>

int main() {
	
	int kace = 0, L;
	long long int A;

	while (scanf("%lld %d", &A, &L) != EOF && A >= 0 && L >= 0) {

		int term = 0;
		long long int ACp = A;

		while (ACp != 1 && ACp <= L) {

			term++;
			if (ACp % 2 == 0) { ACp /= 2; }
			else { ACp = ACp * 3 + 1; }			
		}

		if (ACp == 1) { term++; }

		printf("Case %d: A = %lld, limit = %d, number of terms = %d\n", ++kace, A, L, term);
	}

	return 0;
}
