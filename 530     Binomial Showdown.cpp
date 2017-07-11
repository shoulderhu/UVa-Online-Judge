#include <stdio.h>

int main() {

	int i, n, k;

	while (scanf("%d %d", &n, &k) != EOF && !(n == 0 && k == 0)) {
						
		long long int result = 1;

		if (n - k < k) { k = n - k; }
		
		for (i = 0; i < k; i++) { result = result*(n - i) / (i + 1); }

		printf("%lld\n", result);		
	}

	return 0;
}