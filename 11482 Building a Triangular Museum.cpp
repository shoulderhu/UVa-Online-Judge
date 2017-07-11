#include <stdio.h>
#include <math.h>

int main() {

	int i, j, k, M, N, x = 0;

	while (scanf("%d %d", &M, &N) != EOF && !(M == 0 && N == 0)) {

		printf("Triangular Museum %d\n", ++x);

		for (i = 1; i <= M*N; i++) {

			for (j = M*N - i; j >= 1; j--) { printf(" "); }

			for (j = 1; j <= ceil((double)i / M); j++) {

				printf("/");

				int iCp = i;
				while (iCp > M) { iCp -= M; }
				
				if (i % M != 0) { for (k = 1; k <= 2 * (iCp - 1); k++) { printf(" "); } }
				else { for (k = 1; k <= 2 * (M - 1); k++) { printf("_"); } }

				printf("\\");
				
				if (j != ceil((double)i / M)) { for (k = 1; k <= (2 * (M - 1)) - (2 * (iCp - 1)); k++) { printf(" "); } }
			}

			printf("\n");
		}

		printf("\n");
	}
		return 0;
}
