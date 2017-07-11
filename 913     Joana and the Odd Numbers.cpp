#include <stdio.h>

int main() {

    int N;
	
	while (scanf("%d", &N) != EOF) {
				
		long long int sum = 0, end = long long int(N)*((N + 1) / 2) + ((N + 1) / 2 - 1);

		for (int i = 1; i <= 3; i++, end -= 2) { sum += end; }
		
		printf("%lld\n", sum);
	}

	return 0;
}