#include <stdio.h>

int main() {

	int i, j, k, l, n, m, Field[101][101], x = 0;
	char field[101][101];
	bool isBlank = false;
	
	while (scanf("%d %d", &n, &m) != EOF && n != 0 && m != 0) {

		getchar();
		
		if(x>0){ printf("\n"); }

		for (i = 1; i <= n; i++) {

			for (j = 1; j <= m; j++) {

				scanf("%c", &field[i][j]);
				Field[i][j] = 0;
			}

			getchar();
		}

		for (i = 1; i <= n; i++) {

			for (j = 1; j <= m; j++) {

				if (field[i][j] == '*') {

					for (k = i - 1; k <=  i+ 1; k++) {

						for (l = j - 1; l <= j + 1; l++) {

							Field[k][l]++;
						}
					}
				}
			}
		}

		printf("Field #%d:\n", ++x);

		for (i = 1; i <= n; i++) {

			for (j = 1; j <= m; j++) {

				if (field[i][j] == '*') { printf("*"); }
				else { printf("%d", Field[i][j]); }
			}

			printf("\n");
		}			
	}

	return 0;
}