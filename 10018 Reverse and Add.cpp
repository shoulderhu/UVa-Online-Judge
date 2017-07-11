#include <stdio.h>

unsigned int reverse(unsigned int p) {

	unsigned int num = 0;

	while (p > 0) {

		num = num * 10 + p % 10;
		p /= 10;
	}

	return num;
}

int main() {

	int i, N;
	unsigned int P;

	scanf("%d", &N);
	getchar();

	for (i = 1; i <= N; i++) {

		scanf("%u", &P);
		getchar();

		int iterations = 0;
		unsigned int rev = reverse(P);

		for (;;) {
			
            if (rev == P) { break; }
			P += rev;
			iterations++;
			rev = reverse(P);			
		}

		printf("%d %u\n", iterations, rev);
	}

	return 0;
}
