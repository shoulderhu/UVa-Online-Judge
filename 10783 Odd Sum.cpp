#include <stdio.h>

int main() {

	int T, a, b;

	scanf("%d", &T), getchar();

	for (int i = 1; i <= T; i++) {

		scanf("%d", &a), getchar();
		scanf("%d", &b), getchar();

		if (a % 2 == 0) { a++; }
		if (b % 2 == 0) { b--; }

		int n = (b - a) / 2 + 1;

		printf("Case %d: %d\n", i, (a + b)*n / 2);
	}

	return 0;
}