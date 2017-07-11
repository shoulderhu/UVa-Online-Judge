#include <stdio.h>

int main() {

	int i, N, e, f, c;

	scanf("%d", &N);
	getchar();

	for (i = 1; i <= N; i++) {

		scanf("%d %d %d", &e, &f, &c);
		getchar();

		int sum = 0;
		e += f;

		while (e >= c) {

			e -= c;
			sum++;
			e++;
		}

		printf("%d\n", sum);
	}	

	return 0;
}