#include <stdio.h>
#include <string.h>

int main() {

	int i, j, n, factorial[2568];
    	
	while (scanf("%d", &n) != EOF) {

		memset(factorial, 0, sizeof(factorial)), factorial[2567] = 1;

		for (i = 2; i <= n; i++) {
			
			int carry = 0;

			for (j = 2567; j >= 0; j--) {

				factorial[j] = factorial[j] * i + carry;

				carry = 0;

				if (factorial[j] > 9) { 
					
					carry = factorial[j] / 10;
					factorial[j] %= 10;
				}
			}
		}

		int begin = -1;

		while (factorial[++begin] == 0) {}

		printf("%d!\n", n);
		for (i = begin; i < 2568; i++) { printf("%d", factorial[i]); }
		printf("\n");
	}	

	return 0;
}