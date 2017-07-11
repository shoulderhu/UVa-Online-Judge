#include <iostream>

using namespace std;

int main() {

	int i, j, T, N, n[10], kace = 0;	

	scanf("%d", &T), getchar();

	for (i = 1; i <= T; i++) {

		scanf("%d", &N);
		
		for (j = 0; j < N; j++) { scanf("%d", &n[j]); }
		getchar();

		printf("Case %d: %d\n", ++kace, n[(N - 1) / 2]);
	}

	return 0;
}