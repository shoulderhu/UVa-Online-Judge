#include <stdio.h>

int main() {

	int i, j, C, N, n[1000];

	scanf("%d", &C);
	getchar();

	for (i = 1; i <= C; i++) {

		int sum = 0, above = 0;
		double average, percentage;

		scanf("%d", &N);

		for (j = 0; j < N; j++) { 
			
			scanf("%d", &n[j]); 
			sum += n[j];
		}
		getchar();

		average = (double)sum / N;

		for (j = 0; j < N; j++) { if (average < n[j]) { above++; } }
		
		percentage = (double)above / N;
		printf("%.3lf%%\n", percentage*100);
	}

	return 0;
}