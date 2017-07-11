#include <stdio.h>
#include <queue>

using namespace std;

bool isEnsure(int N, int i) {

	queue<int> region;

	for (int j = 1; j <= N; j++) { region.push(j); }

	while (region.size() != 1) {

		region.pop();

		for (int j = 1; j < i; j++) {

			region.push(region.front());
			region.pop();
		}
	}

	return region.front() == 13;
}

int main() {

	int N;

	while (scanf("%d", &N) != EOF && N != 0) {

		for (int i = 1; ;i++) {

			if (isEnsure(N, i) == true) {

				printf("%d\n", i);
				break;
			}
		}
	}

	return 0;

}