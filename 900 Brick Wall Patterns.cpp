#include <stdio.h>

int main() {

	int length;
	long long fib[51] = { 0, 1, 2 };

	for (int i = 3; i < 51; i++) { fib[i] = fib[i - 1] + fib[i - 2]; }
	
	while (scanf("%d", &length) != EOF && length != 0) {

		printf("%lld\n", fib[length]);
	}

	return 0;
}