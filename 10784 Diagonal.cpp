#include <stdio.h>
#include <math.h>

int main() {

	int kace = 0;
	double N;
			
	while (scanf("%lf", &N) != EOF && N != 0) {

		printf("Case %d: %.lf\n", ++kace, ceil((3 + sqrt(9 + 8 * N)) / 2));
	}

	return 0;
}