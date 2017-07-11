#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	int i, j, k, T, N, P, p[100];
	bool n[3651];

	scanf("%d", &T), getchar();

	for (i = 1; i <= T; i++) {

		scanf("%d", &N), getchar();
		scanf("%d", &P);

		fill(n, n + N + 1, true);
		
		for (j = 0; j < P; j++) { scanf("%d", &p[j]); }
		getchar();

		for (j = 0; j < P; j++) { for (k = p[j]; k <= N; k += p[j]) { n[k] = false; } }

		for (j = 6; j <= N; j += 7) { n[j] = true; }
		for (j = 7; j <= N; j += 7) { n[j] = true; }

		int sum = 0;

		for (j = 1; j <= N; j++) { if (n[j] == false) { sum++; } }

		printf("%d\n", sum);
	}

	return 0;
}
