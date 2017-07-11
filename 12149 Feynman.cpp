#include <stdio.h>

int main() {

	int N; 
	
	while (scanf("%d", &N) != EOF && N != 0) {

		int square = 1;

		for (int i = 2; i <= N; i++) { square += i*i; }

		printf("%d\n", square);
	}

	return 0;
}