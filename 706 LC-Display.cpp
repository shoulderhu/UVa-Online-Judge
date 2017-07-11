#include <stdio.h>

int main() {

	int i, j, k, s, n;

	while (scanf("%d %d", &s, &n) != EOF) {

		if (s == 0 && n == 0) { break; }

		int n_copy = n, size = 0, num[9];

		if (n_copy == 0) { size++; }

		while (n_copy > 0) {

			size++;
			n_copy /= 10;
		}

		for (i = size; i >= 1; i--) {

			num[i] = n % 10;
			n /= 10;
		}

		for (i = 1; i <= size; i++) {

			printf(" ");
			for (j = 1; j <= s; j++) {

				if (num[i] == 1 || num[i] == 4) { printf(" "); }
				else { printf("-"); }
			}
			printf(" ");
			if (i != size) { printf(" "); }
		}

		printf("\n");

		for (i = 1; i <= s; i++) {

			for (j = 1; j <= size; j++) {

				if (num[j] == 1 || num[j] == 2 || num[j] == 3 || num[j] == 7) { printf(" "); }
				else { printf("|"); }
				for (k = 1; k <= s; k++) { printf(" "); }
				if (num[j] == 5 || num[j] == 6) { printf(" "); }
				else { printf("|"); }
				if (j != size) { printf(" "); }
			}

			printf("\n");
		}

		for (i = 1; i <= size; i++) {

			printf(" ");
			for (j = 1; j <= s; j++) {

				if (num[i] == 1 || num[i] == 7 || num[i] == 0) { printf(" "); }
				else { printf("-"); }
			}
			printf(" ");
			if (i != size) { printf(" "); }
		}

		printf("\n");

		for (i = 1; i <= s; i++) {

			for (j = 1; j <= size; j++) {

				if (num[j] == 1 || num[j] == 3 || num[j] == 4 || num[j] == 5 || num[j] == 7 || num[j] == 9) { printf(" "); }
				else { printf("|"); }
				for (k = 1; k <= s; k++) { printf(" "); }
				if (num[j] == 2) { printf(" "); }
				else { printf("|"); }
				if (j != size) { printf(" "); }
			}

			printf("\n");
		}

		for (i = 1; i <= size; i++) {

			printf(" ");
			for (j = 1; j <= s; j++) {

				if (num[i] == 1 || num[i] == 4 || num[i] == 7) { printf(" "); }
				else { printf("-"); }
			}
			printf(" ");
			if (i != size) { printf(" "); }
		}

		printf("\n");
		printf("\n");
	}

	return 0;
}