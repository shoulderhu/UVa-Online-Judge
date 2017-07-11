#include <stdio.h>

int main() {

	int n;

	while (scanf("%d", &n) != EOF && n != 0) {

		int drink = 0;

		while (n >= 3) {

			int temp = n / 3;
			drink += temp;
			n %= 3;
			n += temp;
		}

		if (n == 2) { drink++; }

		printf("%d\n", drink);
	}

	return 0;
}