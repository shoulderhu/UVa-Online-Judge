#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int i, j, N, Q, n, q, kace = 0;
	vector<int> marble;

	while (scanf("%d %d", &N, &Q) != EOF && !(N == 0 && Q == 0)) {

		marble.clear();

		for (i = 1; i <= N; i++) {

			scanf("%d", &n), getchar();
			marble.push_back(n);
		}

		sort(marble.begin(), marble.end());
				
		printf("CASE# %d:\n", ++kace);
		
		for (i = 1; i <= Q; i++) {

			scanf("%d", &q), getchar();

			bool isfound = false;

			for (j = 0; j < marble.size(); j++) {

				if (marble[j] == q) {

					printf("%d found at %d\n", q, j + 1);
					isfound = true;
					break;
				}
			}

			if (isfound == false) { printf("%d not found\n", q); }
		}
	}

	return 0;
}