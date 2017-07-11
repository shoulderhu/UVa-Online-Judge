#include <iostream>
#include <vector>

using namespace std;

int main() {

	int i, n, h, set = 0;
	vector<int> wall;
	vector<int>::iterator loop;

	while (scanf("%d", &n) != EOF && n != 0) {

		int brick = 0;

		wall.clear();

		for (i = 1; i <= n; i++) {

			scanf("%d", &h);
			wall.push_back(h);
			brick += h;
		}

		int averageBrick = brick / n, move = 0;

		for (loop = wall.begin(); loop != wall.end(); loop++) {

			if (*loop < averageBrick) { move += averageBrick - *loop; }
		}

		printf("Set #%d\n", ++set);
		printf("The minimum number of moves is %d.\n\n", move);
	}
	
	return 0;
}