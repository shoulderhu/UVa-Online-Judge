#include <stdio.h>

int main() {

	int i, j, k, l, kace, n;
	char grid[10][11];

	scanf("%d", &kace);
	getchar();

	for (i = 1; i <= kace; i++) {

		scanf("%d", &n);
		getchar();

		for (j = 0; j < n; j++) {	
			
				scanf("%s", &grid[j]);
				getchar();		
		}

		for (j = 0; j < n; j++) {

			for (k = 0; k < n; k++) {

				if (grid[j][k] == '.') {

					for (l = 'A'; l <= 'Z'; l++) {

						bool flag = true;

						if (0 < j && grid[j - 1][k] == l)     { flag = false; }
						if (0 < k && grid[j][k - 1] == l)     { flag = false; }
						if (j < n - 1 && grid[j + 1][k] == l) { flag = false; }
						if (k < n - 1 && grid[j][k + 1] == l) { flag = false; }
						if (flag==true) { 
							
							grid[j][k] = l;
							break;
						}
					}
				}
			}
		}

		printf("Case %d:\n", i);

		for (j = 0; j < n; j++) { printf("%s\n", grid[j]); }
	}

	return 0;
}