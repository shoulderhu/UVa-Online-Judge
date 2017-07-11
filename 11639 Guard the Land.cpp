#include <stdio.h>

int main() {

	int i, j, k, l,N, x1[2], x2[2], y1[2], y2[2];
	short land[101][101];

	scanf("%d", &N), getchar();

	for (i = 1; i <= N; i++) {

		for (j = 0; j < 2; j++) {

			scanf("%d %d %d %d", &x1[j], &y1[j], &x2[j], &y2[j]);
		}

		for (j = 0; j < 100; j++) {

			for (k = 0; k < 100; k++) {

				land[j][k] = 0;
			}
		}

		for (l = 0; l < 2; l++) {

			for (j = y1[l]; j < y2[l]; j++) {

				for (k = x1[l]; k < x2[l]; k++) {

					land[j][k]++;
				}
			}
		}
	    
		int strongly = 0, weakly = 0, unsecured;

		for (j = 0; j < 100; j++) {

			for (k = 0; k < 100; k++) {

				if (land[j][k] == 1) { weakly++; }
				else if (land[j][k] == 2) { strongly++; }
			}
		}		

		unsecured = 10000 - strongly - weakly;

		printf("Night %d: %d %d %d\n", i, strongly, weakly, unsecured);
	}

	return 0;
}