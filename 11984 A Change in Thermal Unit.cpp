#include <stdio.h>

int main() {

	int T, kace = 0;
	double C, d, newF, newC;

	scanf("%d", &T), getchar();

	for (int i = 1; i <= T; i++) {

		scanf("%lf %lf", &C, &d), getchar();

		newF = C * 9 / 5 + 32 + d;
		newC = (newF - 32) * 5 / 9;

		printf("Case %d: %.2lf\n", ++kace, newC);
	}

	return 0;
}