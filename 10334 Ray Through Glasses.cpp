#include <stdio.h>

using namespace std;

int main() {

	short n, ray[1001][210];

	for (int i = 0; i < 1001; i++) {

		for (int j = 0; j < 210; j++) {

			ray[i][j] = 0;
		}
	}

	ray[0][209] = 1, ray[1][209] = 2;

	for (int i = 2; i <= 1000; i++) {

		for (int j = 209; j >= 0; j--) {

			ray[i][j] += ray[i - 1][j] + ray[i - 2][j];

			if (ray[i][j] > 9) {

				ray[i][j - 1] += ray[i][j] / 10;
				ray[i][j] %= 10;
			}
		}
	}

	while (scanf("%d", &n) != EOF) {

		int pos = 0;

		while (ray[n][pos] == 0) { pos++; }
		
		for (int i = pos; i < 210; i++) { printf("%hd", ray[n][i]); }
		printf("\n");
	}
	
	return 0;
}
