#include <stdio.h>

int main() {

	int n;

	while (scanf("%d", &n) != EOF) {

		getchar();

		int sum = 1, ones = 1;

		while (ones%n != 0) {

			ones = ((ones%n) * 10 + 1);
			sum++;
		}

		printf("%d\n", sum);
	}

	return 0;
}