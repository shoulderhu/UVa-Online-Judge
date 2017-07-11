#include <stdio.h>

int main() {

	int i, j, k, N, L, carriages[50];

	scanf("%d", &N);
	getchar();

	for (i = 1; i <= N; i++) {

		scanf("%d", &L);
		getchar();

		for (j = 0; j < L; j++) { scanf("%d", &carriages[j]); }
		
		getchar();
		
		int S = 0;

		for (j = 0; j < L-1; j++) {

			for (k = 0; k < L - 1 - j; k++) {

				if (carriages[k] > carriages[k + 1]) {

					int temp = carriages[k];
					carriages[k] = carriages[k + 1];
					carriages[k + 1] = temp;
					S++;
				}
			}
		}

		printf("Optimal train swapping takes %d swaps.\n", S);
	}

	return 0;
}