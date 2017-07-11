#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

bool mySort(int a, int b) { return a > b; }

int main() {

	int N, length;
	vector<int> beard;

	scanf("%d", &N), getchar();

	printf("Lumberjacks:\n");

	for (int i = 1; i <= N; i++) {

		beard.clear();

		for (int j = 1; j <= 10; j++) {

			scanf("%d", &length), getchar();
			beard.push_back(length);
		}
				
		if (is_sorted(beard.begin(), beard.end()) == true) { printf("Ordered\n"); }
		else if (is_sorted(beard.begin(), beard.end(), mySort) == true) { printf("Ordered\n"); }
		else { printf("Unordered\n"); }
	}

	return 0;
}