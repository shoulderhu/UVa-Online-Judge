#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

bool isPrime(int iCp) {
		
	if (iCp == 2) { return true; }

	for (int i = 2; i <= sqrt((double)iCp); i++) {
		
		if (iCp%i == 0) { return false; }
	}

	return true;
}

int main() {

	int i, n;
				
	while (scanf("%d", &n) != EOF && n != 0) {

		bool isPair = false;

		for (i = 2; i < 1000000; i>2 ? i += 2 : i++) {

			if (isPrime(i) == true && isPrime(n - i) == true) {

				printf("%d = %d + %d\n", n, i, n-i);
				isPair = true;
				break;
			}			
		}

		if (isPair == false) { printf("Goldbach's conjecture is wrong.\n"); }
	}

	return 0;
}
