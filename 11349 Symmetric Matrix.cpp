#include <stdio.h>

int main() {

	int i, j, k, T, n;
	long long int matrix[100][100];

	scanf("%d", &T), getchar();

	for (i = 1; i <= T; i++) {

		scanf("N = %d", &n), getchar();

		for (j = 0; j < n; j++) {

			for (k = 0; k < n; k++) {

				scanf("%lld", &matrix[j][k]);
			}

			getchar();
		}

		printf("Test #%d: ", i);

		bool isSymmetric = true;

		for (j = 0; j < n; j++) {

			for (k = 0; k < n; k++) {

				if (matrix[j][k] < 0 || matrix[j][k] != matrix[n - 1 - j][n - 1 - k]) {
					
					isSymmetric = false; 
					break;
				}
				
				if (j == n - 1 - j && k == n - 1 - k) { break; }
			}

			if (isSymmetric == false) { 
				
				printf("Non-symmetric.\n");
				break; 
			}
		}

		if (isSymmetric == true) { printf("Symmetric.\n"); }
	}

	return 0;
}
