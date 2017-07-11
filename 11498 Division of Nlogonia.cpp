#include <stdio.h>

int main() {

	int K, N, M, X, Y;

	while (scanf("%d", &K) != EOF && K != 0) {

		getchar();

		scanf("%d %d", &N, &M), getchar();

		for (int i = 1; i <= K; i++) {

			scanf("%d %d", &X, &Y), getchar();

			if (X == N && Y == M) { printf("divisa\n"); }
			else if (X != N && Y == M) { printf("divisa\n"); }
			else if (X == N && Y != M) { printf("divisa\n"); }
			else if (N > X && M < Y) { printf("NO\n"); }
			else if (N < X && M < Y) { printf("NE\n"); }
			else if (N < X && M > Y) { printf("SE\n"); }
			else if (N > X && M > Y) { printf("SO\n"); }
		}
	}

	return 0;
}