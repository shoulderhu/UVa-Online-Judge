#include <stdio.h>
#include <string.h>

int main() {

	int i, j, n;
	short int matrix[99][99], rowSum[99], columnSum[99];
		    
	while (scanf("%d", &n) != EOF && n != 0) {

		getchar();

		memset(rowSum, 0, sizeof(rowSum)), memset(columnSum, 0, sizeof(columnSum));

		for (i = 0; i < n; i++) {
			
			for (j = 0; j < n; j++) {

				scanf("%hd", &matrix[i][j]);

				rowSum[i] += matrix[i][j];
				columnSum[j] += matrix[i][j];
			}

			getchar();
		}

		int columnOdd = 0, rowOdd = 0, x, y;

		for (i = 0; i < n; i++){
		
			if (rowSum[i] % 2 != 0) { rowOdd++, x = i; }
			if (columnSum[i] % 2 != 0) { columnOdd++, y = i; }
		}
		
		if(rowOdd==0 && columnOdd==0){ printf("OK\n"); }
		else if (rowOdd == 1 && columnOdd == 1) { 
			
			printf("Change bit (%d,%d)\n", x + 1, y + 1);
		}
		else {printf("Corrupt\n");}
	}

	return 0;
}