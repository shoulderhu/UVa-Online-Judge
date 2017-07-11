#include <stdio.h>
#include <stdlib.h>
#include <set>

int main() {

	int i, n, x, y;
	
	while (scanf("%d", &n) != EOF) {

		getchar();

		std::set<int> N;

		scanf("%d", &x);
		getchar();

		for (i = 1; i < n; i++) { 
			
			scanf("%d", &y); 
		    getchar();

			int xy = abs(x - y);
			if (1 <= xy && xy < n) { N.insert(xy); }

			x = y;
		}

		printf(N.size() == n - 1 ? "Jolly\n" : "Not jolly\n");
	}

	return 0;
}

