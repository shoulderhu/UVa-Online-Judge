#include <stdio.h>

int bigMod(int BCp, int PCp, int MCp) {

	if (PCp == 0) { return 1; }
	else {

		if (PCp % 2 == 0) {
			
			int temp = bigMod(BCp, PCp / 2, MCp);

			return (temp*temp) % MCp;
		}
		else { return (bigMod(BCp, PCp - 1, MCp)*(BCp % MCp)) % MCp; }
	}
}

int main() {

	int B, P, M;

	while (scanf("%d %d %d", &B, &P, &M) != EOF) {
						
		printf("%d\n", bigMod(B, P, M));
	}

	return 0;
}