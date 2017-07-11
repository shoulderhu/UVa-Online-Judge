#include <stdio.h>

using namespace std;

int main() {

	int N, n[10001] = { 1, 1, 2, 6, 24, 12 };
	
	for (int i = 6; i < 10001; i++) {

		n[i] = n[i - 1] * i;
		while (n[i] % 10 == 0) { n[i] /= 10; }
		n[i] %= 100000;
	}

	while (scanf("%d", &N) != EOF) {
	
		printf("%5d -> %d\n", N, n[N] % 10);
	}

	return 0;		
}