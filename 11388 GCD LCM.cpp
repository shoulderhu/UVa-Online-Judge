#include <stdio.h>

int main() {

	int T, G, L;

	scanf("%d", &T), getchar();

	for (int i = 1; i <= T; i++) {

		scanf("%d %d", &G, &L), getchar();

		if (L%G == 0) { printf("%d %d\n", G, L); }
		else { printf("-1\n"); }		
	}

	return 0;
}