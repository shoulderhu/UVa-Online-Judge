#include <stdio.h>
#include <math.h>

int main() {

	int number, up, down;

	while (scanf("%d", &number) != EOF) {

		int numberCp = number;
		double temp = sqrt(1.0 + 8 * numberCp);

		while (temp != (int)temp) { temp = sqrt(1 + 8 * (--numberCp)); }

		int n = (1 + (int)temp) / 4;

		up = number - (2 * n*n - n);
		if (up == 0) { up = 1; }
		else if (up > 2 * n + 1) { up -= (up - (2 * n + 1)) * 2; }
		
		n = (-1 + (int)temp) / 4;
		
		down = number - (2 * n*n + n);
		if (down == 0) { down = 1; }
		else if (down > 2 * n + 2) { down -= (down - (2 * n + 2)) * 2; }

		printf("TERM %d IS %d/%d\n", number, up, down);
	}

	return 0;
}