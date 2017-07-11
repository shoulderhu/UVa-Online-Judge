#include <stdio.h>
#include <math.h>
#define PI acos(-1.0)

int main() {

	double r, n;

	while (scanf("%lf %lf", &r, &n) != EOF) { 
		
		printf("%.3lf\n", r*r*sin((360.0 / n)*PI / 180) / 2 * n); 
	}

	return 0;
}