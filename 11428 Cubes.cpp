#include <stdio.h>
#include <math.h>

int main() {

	int i, j, N; 

	while (scanf("%d", &N) != EOF && N != 0) {
			
		bool isFound = false;

		for (i = 1; i <= 58; i++) {

			for (j = i+1; j <= 59; j++) {

				if ((j*j*j - i*i*i) == N) { 
					
					printf("%d %d\n", j, i);
					isFound = true;
					break;
				}
			}

			if (isFound == true) { break; }
		}		

		if (isFound == false) { printf("No solution\n"); }
	}

	return 0;
}
