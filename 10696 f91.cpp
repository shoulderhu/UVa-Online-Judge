#include <stdio.h>

int f91(int numCp) {
		
	return numCp <= 100 ? f91(f91(numCp + 11)) : numCp - 10;
}

int main() {

	int num;

	while (scanf("%d", &num) != EOF && num != 0) {

        getchar();
		 
		printf("f91(%d) = %d\n", num, f91(num));
	}

	return 0;
}
