#include <stdio.h>

int main() {

	int N, M;

	while (scanf("%d %d", &N, &M) != EOF && !(N == 0 && M == 0)) {

		int NCp = N, MCp = (N - M) > M ? M : (N - M);
		long long int result = 1;

		for (int i = 1; i <= MCp; i++, NCp--) { result = result * NCp / i; }

		printf("%d things taken %d at a time is %d exactly.\n", N, M, result);
	}

	return 0;
}