#include <stdio.h>
#include <algorithm>

int main() {

	int i, T, side[3];

	scanf("%d", &T), getchar();

	for (i = 1; i <= T; i++) {

		scanf("%d %d %d", &side[0], &side[1], &side[2]), getchar();
		
		std::sort(side, side + 3);

		printf("Case %d: ", i);
		
		if (side[0] > 0 && side[1] > 0 && side[2] > 0 && (long long)side[0] + side[1] > side[2]) {

			if (side[0] == side[1] && side[1] == side[2]) { printf("Equilateral\n"); }
			else if (side[0] == side[1] || side[1] == side[2]) { printf("Isosceles\n"); }
			else { printf("Scalene\n"); }
		}
		else { printf("Invalid\n"); }		
	}
	
	return 0;
}