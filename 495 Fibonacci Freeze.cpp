#include <stdio.h>
#include <string>

int fib[5001][1045];

int main() {

	int num;
	fib[1][1044] = 1;

	for (int i = 2; i < 5001; i++) { 
		
		for (int j = 1044; j >= 0; j--) {

			fib[i][j] += fib[i - 1][j] + fib[i - 2][j];

			if (fib[i][j] > 9) {

				fib[i][j - 1] += 1;
				fib[i][j] -= 10;
			}
		}		
	}
	
	while (scanf("%d", &num) != EOF) {

		int p = 0;

		if (num == 0) { p = 1044; }
		else { while (fib[num][p] == 0) { p++; } }

		printf("The Fibonacci number for %d is ", num);		
		for (int i = p; i < 1045; i++) { printf("%d", fib[num][i]); }
		printf("\n");
	}
	
	return 0;
}