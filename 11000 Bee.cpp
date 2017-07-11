#include <stdio.h>

int main() {
	
	int N;

	while (scanf("%d", &N) != EOF && N != -1) {

		unsigned int maleBee = 0, femaleBee = 1;

		for (int i = 1; i <= N; i++) {

			unsigned int maleTmp = maleBee, femaleTmp = femaleBee;

			maleBee = maleTmp + femaleTmp;
			femaleBee = 1 + maleTmp;
		}

		printf("%u %u\n", maleBee, maleBee + femaleBee);
	}

	return 0;
}