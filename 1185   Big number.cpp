#include <stdio.h>
#include <math.h>

double factorial[10000001] = { 0, 1 };

int main() {	

	int i, n, num;

	for (i = 2; i < 10000001; i++) {

		factorial[i] = factorial[i - 1] + log10(i);
	}	

	scanf("%d", &n), getchar();

	for (i = 1; i <= n; i++) {

		scanf("%d", &num), getchar();
		printf("%d\n", (int)factorial[num]);
	}

	return 0;
}