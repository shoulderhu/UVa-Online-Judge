#include <stdio.h>

int main() {

	int i, T, N, K, P;

	scanf("%d", &T), getchar();

	for (i = 1; i <= T; i++) {

		scanf("%d %d %d", &N, &K, &P), getchar();

		int player = (K + P) % N;

		if (player == 0) { player = N; }

		printf("Case %d: %d\n", i, player);
	}

	return 0;
}