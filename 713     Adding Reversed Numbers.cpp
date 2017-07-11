#include <stdio.h>
#include <string.h>

using namespace std;

int main() {

	int i, j, N, sum[201];
	char num1[201], num2[201];
			
	scanf("%d", &N), getchar();

	for (i = 1; i <= N; i++) {

		memset(num1, '0', sizeof(num1)), memset(num2, '0', sizeof(num1));
		memset(sum, 0, sizeof(sum));

		scanf("%s %s", &num1, &num2), getchar();
		num1[strlen(num1)] = '0', num2[strlen(num2)] = '0';		

		for (j = 0; j < 201; j++) {

			sum[j] += (num1[j]-'0') + (num2[j]-'0');
			if (sum[j] >= 10) { sum[j] -= 10, sum[j + 1]++; }	
		}
		
		int begin = 0, end = 200;

		while (sum[begin] == 0) { begin++; }
		while (sum[end] == 0) { end--; }

		for (j = begin; j <= end; j++) { printf("%d", sum[j]); }
		printf("\n");
	}

	return 0;
}