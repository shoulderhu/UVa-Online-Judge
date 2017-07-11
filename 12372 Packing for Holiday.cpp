#include <stdio.h>

int main() {

	int T, L, H, W, kace = 0;

	scanf("%d", &T), getchar();

	for (int i = 1; i <= T; i++) {

		scanf("%d %d %d", &L, &W, &H), getchar();

		printf("Case %d: ", ++kace);

		if (L > 20 || W > 20 || H > 20) { printf("bad\n"); }
		else { printf("good\n"); }
	}

	return 0;
}