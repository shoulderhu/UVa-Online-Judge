#include <stdio.h>
#include <algorithm> 

int main() {

	int i, j, n;
	short int age[2000000];
	
	while (scanf("%d", &n) != EOF) {

		if (n == 0) { break; }

		for (i = 0; i < n; i++) { scanf("%hd", &age[i]); }
		
		std::sort(age, age + n);
	
		for (i = 0; i < n; i++) { 
					
			printf("%hd", age[i]); 
			if (i != n - 1) { printf(" "); }
		}

		printf("\n");
	}

	return 0;
}