#include <stdio.h>
#include <stdlib.h>

int main() {

	int i, t, n;

	scanf("%d", &t), getchar();

	for (i = 1; i <= t; i++) {

		scanf("%d", &n), getchar();

		int answer = (n * 567 / 9 + 7492) * 235 / 47 - 498;

		answer /= 10, answer %= 10;

		printf("%d\n", abs(answer));
	}

	return 0;
}