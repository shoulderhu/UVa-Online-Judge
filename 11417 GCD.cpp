#include <stdio.h>

int GCD(int iCp, int jCp) {

	while (jCp > 0) {

		int temp = iCp%jCp;
		iCp = jCp;
		jCp = temp;
	}

	return iCp;
}

int main() {

	int i, j, N;

	while (scanf("%d", &N) != EOF && N != 0) {

		int G = 0;

		for (i = 1; i < N; i++) {

			for (j = i + 1; j <= N; j++) {

				G += GCD(i, j);
			}
		}

		printf("%d\n", G);
	}

	return 0;
}