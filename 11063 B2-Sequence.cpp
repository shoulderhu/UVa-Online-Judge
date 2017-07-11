#include <stdio.h>
#include <set>

using namespace std;

int main() {

	int N, n[100], kace = 0;
	set<int> Set;

	while (scanf("%d", &N) != EOF) {

		Set.clear();
		bool isB2 = true;

		for (int i = 0; i < N; i++) { 
			
			scanf("%d", &n[i]);
			if (n[i] <= 0) { isB2 = false; }
		}

		if (isB2 == true) {

			for (int i = 0; i < N - 1; i++) {

				if (n[i] >= n[i + 1]) {

					isB2 = false;
					break;
				}
			}
		}
		
		if (isB2 == true) {

			for (int i = 0; i < N; i++) {

				for (int j = i; j < N; j++) {

					if (Set.find(n[i] + n[j]) != Set.end()) {

						isB2 = false;
						break;
					}
					else { Set.insert(n[i] + n[j]); }
				}

				if (isB2 == false) { break; }
			}
		}
		
		printf("Case #%d: It is ", ++kace);
		printf(isB2 == true ? "a B2-Sequence.\n" : "not a B2-Sequence.\n");
		printf("\n");
	}

	return 0;
}