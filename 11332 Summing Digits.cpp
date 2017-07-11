#include <stdio.h>

int main() {

	long long int n;
	
	while (scanf("%lld", &n) != EOF) {
		
		getchar();

		if (n == 0) { break; }
				
		long long int N = 0;

		while (n > 0) {

			N += n % 10;
			n /= 10;

			if (n == 0) {

				n = N;
				if (N < 10) { break; }
				N = 0;
			}
		}

		printf("%lld\n", n);
	}

	return 0;
}