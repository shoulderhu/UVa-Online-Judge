#include <stdio.h>
#include <math.h>

int main() {
	
	int g;

	while (scanf("%d", &g) != EOF && g != 0) {

		bool isPositive = true;

		printf("%d =", g);

		if (g < 0) { 
			
			printf(" -1");
			isPositive = false;
			g *= -1;
		}

		for (int i = 2; i <= sqrt(g); i++) {

			while (g%i == 0) {

				if(isPositive==true){
					
					printf(" %d", i);
					isPositive = false;
				}
				else{ printf(" x %d", i); }
				
				g /= i;
			}
		}
		
		if (g != 1) {

			if (isPositive == true) { printf(" %d", g); }
			else { printf(" x %d", g); }
		}
		
		printf("\n");
	}

	return 0;
}