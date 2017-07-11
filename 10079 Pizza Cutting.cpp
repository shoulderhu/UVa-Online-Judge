#include <stdio.h>

int main() {

	long long int N;

	while (scanf("%lld", &N) != EOF && N >= 0) {

		printf("%lld\n", N*(N + 1) / 2 + 1);
	}

	return 0;
}