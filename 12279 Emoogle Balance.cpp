#include <stdio.h>

int main() {

	int N, X = 0, reason;

	while (scanf("%d", &N) != EOF && N != 0) {

		int suppose = 0, actually = 0;

		for (int i = 1; i <= N; i++) {

			scanf("%d", &reason);
			reason != 0 ? suppose++ : actually++;
		}

		printf("Case %d: %d\n", ++X, (suppose - actually));
	}

	return 0;
}