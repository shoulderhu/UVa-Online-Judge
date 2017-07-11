#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {

	long long int L, H, V;

	while (scanf("%lld %lld", &L, &H) != EOF && !(L == 0 && H == 0)) {

		int max = 0;

		if (L > H) { swap(L, H); }

		for (long long int i = L; i <= H; i++) {

			int S = 0;
			long long int iCp = i;

			do {

				if (iCp % 2 == 0) { iCp /= 2; }
				else { iCp = iCp * 3 + 1; }
				S++;
			} while (iCp != 1);

			if (S > max) { max = S, V = i; }		
		}
		
		printf("Between %lld and %lld, %lld generates the longest sequence of %d values.\n", L, H, V, max);
	}

	return 0;
}