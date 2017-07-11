#include <stdio.h>

int main() {

	int num1, num2;

	while (scanf("%d %d", &num1, &num2) != EOF) {

		getchar();

		if (num1 == 0 && num2 == 0) { break; }

		int carry = 0, sum = 0;

		while (num1>=num2? num1>0:num2>0) {

			if (num1 % 10 + num2 % 10 + carry > 9) { carry = 1, sum++; }
			else { carry = 0; }

			num1 /= 10, num2 /= 10;
		}

		if (sum == 0) { printf("No carry operation.\n"); }
		else if(sum == 1){ printf("1 carry operation.\n"); }
		else{ printf("%d carry operations.\n", sum); }		
	}

	return 0;
}