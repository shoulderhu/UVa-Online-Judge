#include <stdio.h>

int main() {

	int n, x, y;

	scanf("%d", &n), getchar();

	for (int i = 1; i <= n; i++) {

		scanf("%d %d", &x, &y), getchar();

		int ladder = y - x;
		bool isFound = false;
		long long int sum = 0;

		if (ladder == 0) { printf("0\n"); }
		else {

			for (int i = 1; ; i++) {

				for (int j = 1; j <= 2; j++) {

					sum += i;
					if (sum >= ladder) { 
						
						printf("%d\n", (i - 1) * 2 + j);
						isFound = true;
						break;
					}
				}

				if (isFound == true) { break; }
			}
		}
	}

	return 0;
}