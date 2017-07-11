#include <stdio.h>

int main() {

	int H1, M1, H2, M2, sleep;

	while (scanf("%d %d %d %d", &H1, &M1, &H2, &M2) != EOF) {

		if (H1 == 0 && M1 == 0 && H2 == 0 && M2 == 0) { break; }
		
		sleep = (H2 - H1) * 60 + (M2 - M1);

		if (sleep < 0) { sleep += 60 * 24; }

		printf("%d\n", sleep);
	}

	return 0;
}