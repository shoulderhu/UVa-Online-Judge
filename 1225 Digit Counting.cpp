#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

int main() {

	int set, N;
	map<int, int> appearance = { {0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}, {8, 0}, {9, 0} };
	vector<map<int, int>> sequence;
	appearance[1]++;

	for (int i = 2; i < 10000; i++) {

		int iCpy = i;

		while (iCpy > 0) { appearance[iCpy % 10]++, iCpy /= 10; }

		sequence.push_back(appearance);
	}
	
	scanf("%d", &set), getchar();

	for (int i = 1; i <= set; i++) {

		scanf("%d", &N), getchar();

		map<int, int>::iterator iter = sequence[N - 2].begin();

		printf("%d", iter->second);

		for (++iter; iter != sequence[N - 2].end(); ++iter) {

			printf(" %d", iter->second);
		}

		printf("\n");
	}

	return 0;
}