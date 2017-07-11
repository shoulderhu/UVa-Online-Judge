#include <stdio.h>

int main() {

	int kace, amplitude, frequency;

	scanf("%d", &kace), getchar();

	for (int i = 1; i <= kace; i++) {
		
		if (i > 1) { printf("\n"); }

		scanf("%d", &amplitude), getchar();
		scanf("%d", &frequency), getchar();

		for (int j = 1; j <= frequency; j++) {

			if (j > 1) { printf("\n"); }

			for (int k = 1; k < amplitude; k++) {

				for (int l = 1; l <= k; l++) { printf("%d", k); }
				printf("\n");
			}

			for (int k = amplitude; k >= 1; k--) {

				for (int l = 1; l <= k; l++) { printf("%d", k); }
				printf("\n");
			}
		}
	}

	return 0;
}
