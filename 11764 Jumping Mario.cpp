#include <stdio.h>

int main() {

	int i, j, T, N, walls[49];

	scanf("%d", &T), getchar();

	for (i = 1; i <= T; i++) {

		scanf("%d", &N), getchar();

		for (j = 0; j < N; j++) { scanf("%d", &walls[j]); }
		getchar();

		int highJumps = 0, lowJumps = 0;

		for (j = 0; j < N - 1; j++) {

			if (walls[j]<walls[j + 1]) { highJumps++; }
			else if (walls[j]>walls[j + 1]) { lowJumps++; }
		}

		printf("Case %d: %d %d\n", i, highJumps, lowJumps);
	}

	return 0;
}
