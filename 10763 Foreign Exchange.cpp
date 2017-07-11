#include <stdio.h>
#include <algorithm>

using namespace std;

int A[500000], B[500000];

int main() {
    
	int i, n;

	while (scanf("%d", &n) != EOF && n!=0) {

		getchar();

		for (i = 0; i < n; i++) { scanf("%d %d", &A[i], &B[i]); }

		sort(A, A + n), sort(B, B + n);

		bool isIdentity = true;

		for (i = 0; i < n; i++){
			
			if (A[i] != B[i]) { 
				
				isIdentity = false; 
				break;
			}
		}

		printf(isIdentity == true ? "YES\n" : "NO\n");		
	}

	return 0;
}