#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int N, p, M;
	struct set { int x, y; } Set;
	vector<int> price;
	vector<struct set> match;

	while (scanf("%d", &N) != EOF) {

		price.clear(), match.clear();

		for (int i = 1; i <= N; i++) {

			scanf("%d", &p);
			price.push_back(p);
		}

		scanf("%d", &M), getchar();

		sort(price.begin(), price.end());

		for (int i = 0; i < price.size(); i++) {
			
			int temp = M - price[i];
			
			if (find(price.begin(), price.end(), temp) != price.end()) {
				
				if (price[i] < temp || (price[i] == temp && count(price.begin(), price.end(), price[i]) >= 2)) { 
					
					Set.x = price[i];
					Set.y = M - price[i];
					match.push_back(Set);
				}
				else { break; }
			}
		}

		printf("Peter should buy books whose prices are %d and %d.\n", match[match.size() - 1].x, match[match.size() - 1].y);
		printf("\n");
	}

	return 0;
}