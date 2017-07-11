#include <stdio.h>
#include <stdlib.h>

int main() {

	int i, j, k, n, m, cases=0, N[1000], M[24];
	
	while (scanf("%d", &n) != EOF) {

		getchar();

		if (n == 0) { break; }

		for (i = 0; i < n; i++) {
			
			scanf("%d", &N[i]);
			getchar();
		}

		scanf("%d", &m);
		getchar();

		printf("Case %d:\n", ++cases);

		for (i = 0; i < m; i++) {

			scanf("%d", &M[i]);
			getchar();

			int closest = abs(N[0] + N[1] - M[i]), sum = N[0] + N[1];

			for (j = 0; j < n; j++) {

				for (k = 0; k < n; k++) {

					if (j != k && abs(N[j] + N[k] - M[i]) < closest) {

						closest = abs(N[j] + N[k] - M[i]);
						sum = N[j] + N[k];
					}
				}
			}

			printf("Closest sum to %d is %d.\n", M[i], sum);
		}
	}

	return 0;
}