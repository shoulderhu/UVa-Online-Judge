#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	
	int i, j, T, salary[3];

	scanf("%d", &T), getchar();

	for (i = 1; i <= T; i++) {

		for (j = 0; j < 3; j++) { scanf("%d", &salary[j]); }
		getchar();

		sort(salary, salary + 3);

		printf("Case %d: %d\n", i, salary[1]);
	}

	return 0;
}