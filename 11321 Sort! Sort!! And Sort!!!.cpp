#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int N, M;

bool rule(int x, int y) {

	int xMod = x%M, yMod = y%M, xMod2 = abs(x % 2), yMod2 = abs(y % 2);

	if (xMod != yMod) { return xMod < yMod; }
	else {

		if (xMod2 != yMod2) { return xMod2 > yMod2; }
		else if (xMod2 != 0 && yMod2 != 0) { return x > y; }
		else if (xMod2 == 0 && yMod2 == 0) { return x < y; }
	}
}

int main() {

	int n[10000];

	while (scanf("%d %d", &N, &M) != EOF && !(N == 0 && M == 0)) {

		printf("%d %d\n", N, M);
		
		for (int i = 0; i < N; i++) { scanf("%d", &n[i]), getchar(); }

		sort(n, n + N, rule);

		for (int i = 0; i < N; i++) { printf("%d\n", n[i]); }
	}

	printf("0 0\n");

	return 0;
}