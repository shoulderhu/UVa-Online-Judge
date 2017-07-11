#include <stdio.h>

int main() {

	int i, j, N, B[1000], J[1000], X=0;

	while (scanf("%d", &N) != EOF) {

		getchar();

		if (N == 0) { break; }

		for (i = 0; i < N; i++) {

			scanf("%d %d", &B[i], &J[i]);
			getchar();
		}

		for (i = 0; i < N - 1; i++) {

			for (j = 0; j < N - 1 - i; j++) {

				if (J[j] < J[j + 1]) {

					int tempj = J[j];
					J[j] = J[j + 1];
					J[j + 1] = tempj;

					int tempb = B[j];
					B[j] = B[j + 1];
					B[j + 1] = tempb;
				}
			}
		}

		int Y = 0, Ycopy, exceed = J[N - 1];

		for (i = 0; i < N; i++) {Y += B[i];}

		Ycopy = Y - B[0];
		
		for (i = 0; i <= N-2; i++) {

			if (J[i] > Ycopy) {

				if (J[i] - Ycopy > exceed) { exceed = J[i] - Ycopy; }
			}

			Ycopy -= B[i + 1];
		}

		printf("Case %d: %d\n", ++X, Y+exceed);
	}

	return 0;
}