#include <stdio.h>

int main() {

	long long int N;

	while (scanf("%lld", &N) != EOF && N > 0) {

		if (N != 1) { printf("%lld%%\n", 25 * N); }
		else { printf("0%%\n"); }
	}

	return 0;
}
