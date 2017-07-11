#include <stdio.h>
#include <vector>

using namespace std;

long long int fermatTest(long long int iCp, long long int nCp, long long int nCpy) {

	if (nCp == 0) { return 1; }
	else {

		if (nCp % 2 == 0) {

			long long int temp = fermatTest(iCp, nCp / 2, nCpy);

			return temp * temp % nCpy;
		}
		else { return fermatTest(iCp, nCp - 1, nCpy) * (iCp%nCpy) % nCpy; }
	}
}

bool isPass(int nCp) {

	for (int i = 2; i < nCp; i++) {

		if (fermatTest(i, nCp, nCp) != i) { return false; }
	}

	return true;
}

int main() {
	
	int n;
	vector<bool> prime(65000, true);
	prime[0] = false, prime[1] = false;

	for (int i = 2; i < 32500; i++) {

		if (prime[i] == true) {

			for (int j = 2 * i; j < 65000; j += i) { prime[j] = false; }
		}
	}

	while (scanf("%d", &n) != EOF && n != 0) {
		
		if (prime[n] == false && isPass(n) == true) {

			printf("The number %d is a Carmichael number.\n", n);
		}
		else { printf("%d is normal.\n", n); }
	}
	
	return 0;
}