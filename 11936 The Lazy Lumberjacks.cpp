#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {

	int N, side[3];
	
	scanf("%d", &N), getchar();

	for (int i = 1; i <= N; i++) {

		scanf("%d %d %d", &side[0], &side[1], &side[2]), getchar();

		sort(side, side + 3);

		if (side[0] + side[1] > side[2]) { printf("OK\n"); }
		else { printf("Wrong!!\n"); }
	}
	
	return 0;
}
