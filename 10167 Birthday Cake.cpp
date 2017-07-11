#include <stdio.h>
#include <vector>

using namespace std;

int main() {

	int N;
	struct cherry { int x, y; }Cherry;
	vector<struct cherry> Vector;
	vector<struct cherry>::iterator iter;

	while (scanf("%d", &N) != EOF && N != 0) {

		Vector.clear();
		
		for (int i = 1; i <= 2 * N; i++) {

			scanf("%d %d", &Cherry.x, &Cherry.y), getchar();
			Vector.push_back(Cherry);
		}

		bool isFound = false;

		for (int A = -500; A <= 500; A++) {

			for (int B = -500; B <= 500; B++) {

				int cDiff = 0;

				for (iter = Vector.begin(); iter != Vector.end(); iter++) {

					int temp = A*iter->x + B*iter->y;

					if (temp == 0) { cDiff = 1; break; }
					else { temp > 0 ? cDiff++ : cDiff--; }
				}

				if (cDiff == 0) {
					
					printf("%d %d\n", A, B);
					isFound = true;
					break;
				}
			}

			if (isFound == true) { break; }
		}
	}

	return 0;
}