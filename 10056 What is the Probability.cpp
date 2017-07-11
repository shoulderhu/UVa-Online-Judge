#include <stdio.h>
#include <math.h>

int main() {

	int S, N, I;
	double p;

	scanf("%d", &S), getchar();

	for (int i = 1; i <= S; i++) {

		scanf("%d %lf %d", &N, &p, &I), getchar();
			    
		if (p == 0) { printf("0.0000\n"); }
		else{ 

			double probability = pow(1 - p, I - 1)*p*(1 / (1 - pow(1 - p, N)));

			printf("%.4lf\n", probability); 
		}		
	}

	return 0;
}