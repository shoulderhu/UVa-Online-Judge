#include <stdio.h>

int main() {

	int i, j, row, column, enterColumn;
	char grid[10][10];
	int count[10][10];

	while (scanf("%d %d %d", &row, &column, &enterColumn) != EOF) {

		getchar();

		if (row == 0 && column == 0 && enterColumn == 0) { break; }

		for (i = 0; i < 10; i++) {

			for (j = 0; j < 10; j++) {

				count[i][j] = 0;
			}
		}

		for (i = 0; i < row; i++) {

			for (j = 0; j < column; j++) {

				scanf("%c", &grid[i][j]);
			}

			getchar();
		}

		int step = 0, loop = 0, enterRow = 0;
		enterColumn--;

		while (enterColumn<column && enterColumn>-1 && enterRow<row && enterRow>-1) {
			
			if(count[enterRow][enterColumn]==0){ count[enterRow][enterColumn] = ++step; }
			else {
								
				loop = step - count[enterRow][enterColumn] + 1;
				step = count[enterRow][enterColumn] - 1;
				break;
			}

			switch (grid[enterRow][enterColumn]) {

			case 'N': enterRow--; break;
			case 'S': enterRow++; break;
			case 'E': enterColumn++; break;
			case 'W': enterColumn--; break;
			}
		}
		
		if (loop == 0) { printf("%d step(s) to exit\n", step); }
		else { printf("%d step(s) before a loop of %d step(s)\n", step, loop); }
	}

	return 0;
}