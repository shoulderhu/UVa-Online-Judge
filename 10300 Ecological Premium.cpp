#include <stdio.h>

int main() {

	int i, j, n, f, size, animals, environmentFriendliness;

	scanf("%d", &n);
	getchar();

	for (i = 1; i <= n; i++) {

		scanf("%d", &f);
		getchar();

		long long int burden = 0;

		for (j = 0; j < f; j++) {

			scanf("%d %d %d", &size, &animals, &environmentFriendliness);
			getchar();

			burden += (long long int)size*environmentFriendliness;
		}

		printf("%lld\n", burden);
	}

	return 0;
}