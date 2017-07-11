#include <stdio.h>
#include <algorithm>

using namespace std;

int dream[1000000];

int main() {

	int n;

	while (scanf("%d", &n) != EOF) {
		
		for (int i = 0; i < n; i++) { scanf("%d", &dream[i]); }

		sort(dream, dream + n);

		int A, satisfy = 0, possible;

		if (n % 2 == 0) { 
			
			A = dream[n / 2 - 1]; 
		    
			for (int i = 0; i < n; i++) {

				if (dream[i] == A || dream[i] == dream[n / 2]) { satisfy++; }
			}

			possible = dream[n / 2] - A + 1;
		}
		else { 
			
			A = dream[(n - 1) / 2], possible = 1; 
		
			for (int i = 0; i < n; i++) {

				if (dream[i] == A) { satisfy++; }
			}
		}	
		
		printf("%d %d %d\n", A, satisfy, possible);
	}

	return 0;
}