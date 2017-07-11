#include <stdio.h>
#include <math.h>

int grid[11][11], i, j, k, n;
bool collected[11][11];

int sums(int y, int x) {

	int sum = 0;
	
	for (i = x; i <= n; i++) {

		if (collected[y][i] == false) {

			collected[y][i] = true;
			sum += grid[y][i];
			x = i;
		}
		else { break; }
	}	

	for (i = y+1; i <= n; i++) {

		if (collected[i][x] == false) {

			collected[i][x] = true;
			sum += grid[i][x];
			y = i;
		}
		else { break; }
	}
	
	for (i = x-1; i >= 1; i--) {

		if (collected[y][i] == false) {

			collected[y][i] = true;
			sum += grid[y][i];
			x = i;
		}
		else { break; }
	}	

	for (i = y-1; i >=1 ; i--) {

		if (collected[i][x] == false) {

			collected[i][x] = true;
			sum += grid[i][x];			
		}
		else { break; }
	}	

	return sum;
}

int main() {

	int cases = 0;

	while (scanf("%d", &n) != EOF) {

		if (n == 0) { break; }
        
		for (i = 1; i <= n; i++) {

			for (j = 1; j <= n; j++) {

				scanf("%d", &grid[i][j]);
				collected[i][j] = false;
			}

			getchar();
		}
			
		printf("Case %d:", ++cases);
		
		for (k = 1; k <= ceil((double)n / 2); k++) {
			
			printf(" %d", sums(k, k));
		}		

		printf("\n");				
	}

	return 0;
}