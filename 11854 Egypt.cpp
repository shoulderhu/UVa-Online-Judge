#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {

	int side[3];

	while (scanf("%d %d %d", &side[0], &side[1], &side[2]) != EOF && !(side[0] == 0 && side[1] == 0 && side[2] == 0)) {

		sort(side, side + 3);

		if (side[0] * side[0] + side[1] * side[1] == side[2] * side[2]) { printf("right\n"); }
		else { printf("wrong\n"); }
	}

	return 0;
}