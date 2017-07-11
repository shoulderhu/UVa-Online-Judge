#include <stdio.h>
#include <math.h>

int digitSum(int jCp) {

	int sum = 0;

	while (jCp > 0) {

		sum += jCp % 10;
		jCp /= 10;
	}

	return sum;
}

int primeSum(int jCp) {

	int j = jCp, sum = 0;

	for (int i = 2; i <= sqrt((double)j); i++) {

		while (j%i == 0) {

			sum += digitSum(i);
			j /= i;
		}
	}

	if (j != jCp && j != 1) { sum += digitSum(j); }

	return sum;
}

int main() {

	int kace, n;

	scanf("%d", &kace), getchar();

	for (int i = 1; i <= kace; i++) {

		scanf("%d", &n), getchar();

		for (int j = n + 1; ; j++) {

			if (digitSum(j) == primeSum(j)) {

				printf("%d\n", j);
				break;
			}
		}
	}

	return 0;
}