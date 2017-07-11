#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {

	int kace, side[4];

	scanf("%d", &kace), getchar();

	for (int i = 1; i <= kace; i++) {

		scanf("%d %d %d %d", &side[0], &side[1], &side[2], &side[3]), getchar();
		
		sort(side, side + 4);

		if (side[0] == side[1] && side[1] == side[2] && side[2] == side[3]) { printf("square\n"); }
		else if (side[0] == side[1] && side[2] == side[3]) { printf("rectangle\n"); }
		else if (side[0] + side[1] + side[2] > side[3]) { printf("quadrangle\n"); }
		else { printf("banana\n"); }
	}

	return 0;
}