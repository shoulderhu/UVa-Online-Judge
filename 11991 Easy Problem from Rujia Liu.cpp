#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;

int main() {

	int i, j, m, n, N, k, v;
	
	map<int, int> table;
	map<int, map<int, int>> array;

	while (scanf("%d %d", &n, &m) != EOF) {

		array.clear(), table.clear();

		for (i = 1; i <= n; i++) {

			scanf("%d", &N);
			table[N]++;
			array[table[N]][N] = i;
		}

		for (i = 1; i <= m; i++) {

			scanf("%d %d", &k, &v), getchar();

			printf("%d\n", array[k][v]);
		}
	}

	return 0;
}