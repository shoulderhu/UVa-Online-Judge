#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int N, M, n, m;
	vector<int> height;
	vector<int>::iterator iter, myLowerBound, myUpperBound;

	scanf("%d", &N), getchar();

	for (int i = 1; i <= N; i++) {

		scanf("%d", &n);
		height.push_back(n);
	}

	scanf("%d", &M), getchar();

	for (int i = 1; i <= M; i++) {

		scanf("%d", &m);
		
		myLowerBound = lower_bound(height.begin(), height.end(), m);
		myUpperBound = upper_bound(height.begin(), height.end(), m);

		if (myLowerBound - height.begin() > 0) { printf("%d ", *(myLowerBound - 1)); }
		else { printf("X "); }

		if (myUpperBound != height.end()) { printf("%d\n", *myUpperBound); }
		else { printf("X\n"); }
	}

	return 0;
}