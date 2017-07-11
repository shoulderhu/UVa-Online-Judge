#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int X, N = 0 ,median;
	vector<int> integer;

	while (scanf("%d", &X) != EOF) {

		integer.push_back(X), N++;

		sort(integer.begin(), integer.end());
				
		if (N % 2 == 0) { median = (integer[N / 2] + integer[N / 2 - 1]) / 2; }
		else { median = integer[(N - 1) / 2]; }

		printf("%d\n", median);
	}

	return 0;
}