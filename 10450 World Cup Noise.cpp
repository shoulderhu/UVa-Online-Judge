#include <stdio.h>

long long int C(int m, int k) {

	long long int result = 1;

	for (int i = 1; i <= k; i++, m--) { result = result * m / i; }

	return result;
}

int main() {

	int scenario, bit;

	scanf("%d", &scenario), getchar();

	for (int i = 1; i <= scenario; i++) {

		scanf("%d", &bit), getchar();

		long long int sum = bit == 1 ? 2 : 1;
		
		for (int j = bit - 1; j >= 1; j--) {

			if (j + 1 < bit - j) { break; }
			else { sum += C(j + 1, bit - j); }
		}

		printf("Scenario #%d:\n%lld\n\n", i, sum);			
	}

	return 0;
}