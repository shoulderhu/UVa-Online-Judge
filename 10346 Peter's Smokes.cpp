#include <stdio.h>

int main() {

	int n, k;

	while (scanf("%d %d", &n, &k) != EOF) {

		getchar();

		int sum = n;

		while (n>=k) {

			n -= k;
			n++;
			sum++;
		}

		printf("%d\n", sum);
	}

	return 0;
}