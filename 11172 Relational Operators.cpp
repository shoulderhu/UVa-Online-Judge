#include <stdio.h>

int main() {

	int i, t, a, b;

	scanf("%d", &t), getchar();

	for (i = 1; i <= t; i++) {

		scanf("%d %d", &a, &b), getchar();

		if (a > b) { printf(">\n"); }
		else if (a < b) { printf("<\n"); }
		else if (a == b) { printf("=\n"); }
	}

	return 0;
}