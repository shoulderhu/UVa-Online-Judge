#include <stdio.h>

int main() {

	int i, n;

	while (scanf("%d", &n) != EOF) {

		long long factorial = 1;
		
		if (n >= 0) {
	        
			bool isPrint = false;

			for (i = n; i >= 2; i--) {

				factorial *= i;

				if (factorial > 6227020800) {

					printf("Overflow!\n");
					isPrint = true;
					break;
				}
			}

			if (isPrint == false) {

				if (factorial < 10000) { printf("Underflow!\n"); }
				else { printf("%lld\n", factorial); }
			}
		}
		else {

			if (n % 2 == 0) { printf("Underflow!\n"); }
			else { printf("Overflow!\n"); }
		}			
	}

	return 0;
}