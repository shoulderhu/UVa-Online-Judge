#include <stdio.h>
#include <math.h>

int main() {

	double n, p;

	while (scanf("%lf", &n) != EOF) {

		getchar();

		scanf("%lf", &p), getchar();

		printf("%.0lf\n", pow(p, 1 / n));
	}
	
	return 0;
}