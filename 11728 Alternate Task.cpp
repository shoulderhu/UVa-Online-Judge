#include <stdio.h>
#include <string.h>

int main() {

	int S, kace = 0, Sum[1001];

	memset(Sum, 0, sizeof(Sum));

	while (scanf("%d", &S) != EOF && S != 0) {

		bool isFound = false;

		printf("Case %d: ", ++kace);

		for (int i = 1000; i >= 1; i--) {
			
			if (Sum[i] == 0) {

				int sum = 1;
				for (int j = 2; j <= i; j++) { if (i%j == 0) { sum += j; } }

				Sum[i] = sum;
			}
			
			if (Sum[i] == S) {

				printf("%d\n", i);
				isFound = true;
				break;
			}
		}

		if (isFound == false) { printf("-1\n"); }
	}

	return 0;
}
