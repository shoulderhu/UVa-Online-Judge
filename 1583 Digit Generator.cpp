#include <stdio.h>
#include <map>

using namespace std;

int main() {

	int T, N;
	map<int, int> generator;

	for (int i = 1; i < 100000; i++) {

		int n = i, m = i;

		while (m > 0) { n += m % 10, m /= 10; }

		if (generator[n] == 0 || generator[n] > i) { generator[n] = i; }
	}

	scanf("%d", &T), getchar();

	for (int i = 1; i <= T; i++) {

		scanf("%d", &N), getchar();

		printf("%d\n", generator[N]);
	}

	return 0;
}