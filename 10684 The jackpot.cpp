#include <iostream>
#include <vector>

using namespace std;

int main() {

	int i, N, bet;

	while (scanf("%d", &N) != EOF && N != 0) {

		int maxStreak = 0, earn = 0;

		for (i = 1; i <= N; i++) {

			scanf("%d", &bet);

			earn += bet;

			if (earn < 0) { earn = 0; }
			if (earn > maxStreak) { maxStreak = earn; }
		}
		
		if (maxStreak != 0) { printf("The maximum winning streak is %d.\n", maxStreak); }
		else { printf("Losing streak.\n"); }
	}

	return 0;
}