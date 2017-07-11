#include <stdio.h>

int main() {

	int i, j, N, num[1000];

	while (scanf("%d", &N) != EOF) {

		getchar();

		for (i = 0; i < N; i++) { scanf("%d", &num[i]), getchar(); }

		int operations = 0;

		for (i = 0; i < N - 1; i++) {

			for (j = 0; j < N - 1 - i; j++) {

				if (num[j] > num[j + 1]) {

					int temp = num[j];
					num[j] = num[j + 1];
					num[j + 1] = temp;
					operations++;
				}
			}
		}

		printf("Minimum exchange operations : %d\n", operations);
	}

	return 0;
}