#include <stdio.h>

int main() {

	int i, t, m, n, area;

	scanf("%d", &t);
	getchar();

	for (i = 1; i <= t; i++) {

		scanf("%d %d", &m, &n);

		area = (m / 3) * (n / 3);

		printf("%d\n", area);
	}

	return 0;
}