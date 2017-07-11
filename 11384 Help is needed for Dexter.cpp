#include <stdio.h>
#include <math.h>

int main() {

	int i, n;
	
	while (scanf("%d", &n) != EOF) {

		getchar();

		double sum = 0;

		for (i = 0;; i++) {

			sum += pow(2, i);

			if (sum >= n) {

				printf("%d\n", i+1);
				break;
			}
		}
	}

	return 0;
}