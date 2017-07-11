#include <stdio.h>

int main() {

	char num1[1000001], num2[1000001];
	int i, j, N, M, sum[1000001];

	scanf("%d", &N);
	getchar();

	for (i = 1; i <= N; i++) {

		scanf("%d", &M);
		getchar();

		for (j = M; j >= 1; j--) {

			scanf("%c %c", &num1[j], &num2[j]);
			getchar();
		}

		int carry = 0;

		for (j = 1; j <= M; j++) {

			sum[j] = (num1[j] - '0') + (num2[j] - '0') + carry;

			carry = 0;

			if (sum[j] >= 10) {

				sum[j] -= 10;
				carry = 1;
			}
		}

		if (carry == 1) { printf("1"); }		

		for (j = M; j >= 1; j--) { printf("%d", sum[j]); }
		printf("\n");

		if (N != i) { printf("\n"); }
	}

	return 0;
}