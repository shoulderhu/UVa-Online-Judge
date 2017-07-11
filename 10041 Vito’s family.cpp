#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int i, j, kace, r, s;
	vector<int> street;

	scanf("%d", &kace), getchar();

	for (i = 1; i <= kace; i++) {

		scanf("%d", &r);

		street.clear();

		for (j = 1; j <= r; j++){
			
			scanf("%d", &s);
			street.push_back(s);
		}

		sort(street.begin(), street.end());

		int median = (r % 2 == 0 ? street[r / 2] : street[(r - 1) / 2]), sum = 0;
		
		for (j = 0; j < r; j++) { sum += abs(median - street[j]); }

		printf("%d\n", sum);
	}

	return 0;
}