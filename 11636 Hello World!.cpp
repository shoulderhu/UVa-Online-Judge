#include <stdio.h>
#include <math.h>

int main() {

	int i, N, X=0;

	while (scanf("%d", &N) != EOF) {

		if (N < 0) { break; }
        
		int Y = ceil(log2(N));
					
		printf("Case %d: %d\n", ++X, Y);
	}

	return 0;
}