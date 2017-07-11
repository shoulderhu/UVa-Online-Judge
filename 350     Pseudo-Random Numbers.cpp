#include <stdio.h>
#include <map>

using namespace std;

int main() {

	int Z, I, M, L, kace = 0;
	map<int, int> occurace;

	while (scanf("%d %d %d %d", &Z, &I, &M, &L) != EOF) {

		if (Z == 0 && I == 0 && M == 0 && L == 0) { break; }

		int length = 0;

		occurace.clear();

		while (occurace[L] == 0) {

			length++;
			occurace[L] = length;
			L = (Z*L + I) % M;
		}
						
		printf("Case %d: %d\n", ++kace, length - occurace[L] + 1);
	}
	
	return 0;
}