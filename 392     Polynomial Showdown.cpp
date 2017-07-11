#include <stdio.h>
#include <stdlib.h>

int main() {

	int i, j, coefficients[9];
	
	while (scanf("%d", &coefficients[0]) != EOF) {

		bool isFirst = true, isPrint = false;

		for (i = 1; i < 9; i++) { scanf("%d", &coefficients[i]); }

		for (i = 0; i < 9; i++) {

			if (coefficients[i] != 0) {
				
			    if (isFirst == true) {

					if (abs(coefficients[i]) != 1) {
						
						printf("%d", coefficients[i]); 
					}
					else {

						if (i == 8) { printf("%d", coefficients[i]); }
						else if (coefficients[i] < 0) { printf("-"); }
					}					

					isFirst = false, isPrint = true;
				}
				else {

					printf(coefficients[i] > 0 ? " + " : " - ");

					if (abs(coefficients[i]) != 1) {
						
						printf("%d", abs(coefficients[i])); 
					}
					else if (i == 8) { printf("1"); }
				}

				if (i != 8) { printf("x"); }
				if (i != 7 && i != 8) { printf("^%d", 8 - i); }				
			}
		}

		if (isPrint == false) { printf("0"); }
		printf("\n");
	}

	return 0;
}