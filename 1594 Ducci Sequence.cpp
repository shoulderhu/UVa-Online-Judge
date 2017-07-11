#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <set>

using namespace std;

int main() {

	int T, n, d;
	vector<int> Ducci;
	set<vector<int>> Set;
		 
	scanf("%d", &T), getchar();

	for (int i = 1; i <= T; i++) {

		bool isZero = false;
		Set.clear(), Ducci.clear();

		scanf("%d", &n), getchar();

		vector<int> temp(n, 0), zero(n, 0);
				
		for (int j = 0; j < n; j++) { 
			
			scanf("%d", &d);
			Ducci.push_back(d);
		}
				
		do {
			if (Ducci == zero) {

				isZero = true;
				printf("ZERO\n");
				break;
			}

			Set.insert(Ducci), temp.swap(Ducci);

			for (int j = 0; j < n; j++) {

				if (j != n - 1) { Ducci[j] = abs(temp[j] - temp[j + 1]); }
				else { Ducci[j] = abs(temp[j] - temp[0]); }
			}			

		} while (Set.find(Ducci) == Set.end());
		
		if (isZero == false) { printf("LOOP\n"); }
	}	

	return 0;
}