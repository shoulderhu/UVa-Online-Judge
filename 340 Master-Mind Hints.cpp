#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

int main() {

	int N, s, g, game = 0;
	vector<int> secretCode, remain;
	map<int, int> table;

	while (scanf("%d", &N) != EOF && N != 0) {

		secretCode.clear();

		for (int i = 1; i <= N; i++) {

			scanf("%d", &s);
			secretCode.push_back(s);
		}

		printf("Game %d:\n", ++game);

		while (true) {

			int p = 0, q = 0;
			remain.clear(), table.clear();

			for (int i = 0; i < N; i++) {

				scanf("%d", &g);

				if (g == secretCode[i]) { p++; }
				else if (g != 0) {

					table[secretCode[i]]++;
					remain.push_back(g);
				}
			}

			if (g == 0) { break; }

			for (int i = 0; i < remain.size(); i++) {

				if (table[remain[i]]>0) { q++, table[remain[i]]--; }
			}

			printf("    (%d,%d)\n", p, q);
		}	
	}

	return 0;
}