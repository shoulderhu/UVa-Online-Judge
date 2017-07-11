#include <stdio.h>
#include <stdlib.h>

int main() {

	int a, b;

	while (scanf("%d %d", &a, &b) != EOF && !(a == -1 && b == -1)) {

		int press = abs(a - b);

		if (press > 50) { press = 100 - press; }

		printf("%d\n", press);
	}

	return 0;
}
