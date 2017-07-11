#include <stdio.h>

int main() {

	int i, N;

	printf("PERFECTION OUTPUT\n");

	while (scanf("%d", &N) && N != 0) {
		
		int sum = 0;

		for (i = 1; i < N; i++) { if (N%i == 0) { sum += i; } }

		printf("%5d  ", N);

		if (sum == N) { printf("PERFECT\n"); }
		else if (sum < N) { printf("DEFICIENT\n"); }
		else if (sum > N) { printf("ABUNDANT\n"); }
	}

	printf("END OF OUTPUT\n");

	return 0;
}
