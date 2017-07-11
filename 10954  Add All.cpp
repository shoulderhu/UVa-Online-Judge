#include <iostream>
#include<list>

using namespace std;

int main() {

	int i, N, n;
	list<int> number;	

	while (scanf("%d", &N) != EOF && N != 0) {

		number.clear();

		for (i = 1; i <= N; i++) {

			scanf("%d", &n);
			number.push_back(n);
		}

		int total = 0;

		while (number.size() != 1) {

			number.sort();

			int cost = 0;

			for (i = 1; i <= 2; i++) {

				cost += number.front();
				number.pop_front();
			}

			total += cost;
			number.push_back(cost);
		}
		
		printf("%d\n", total);
	}

	return 0;
}