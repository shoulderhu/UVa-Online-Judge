#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int i, j, T, N, n;
	vector<int> speed;

	scanf("%d", &T), getchar();

	for (i = 1; i <= T; i++) {

		scanf("%d", &N), getchar();
		speed.clear();

		for (j = 1; j <= N; j++) {

			scanf("%d", &n);
			speed.push_back(n);
		}
		getchar();

		sort(speed.begin(), speed.end());

		printf("Case %d: %d\n", i, speed[N - 1]);
	}

	return 0;
}