#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

int digitPrime[1000001];

int digitSum(int iCp) {

	int sum = 0;

	while (iCp > 0) {

		sum += iCp % 10;
		iCp /= 10;
	}

	return sum;
}

bool isPrime(int iCp) {

	for (int j = 2; j <= sqrt(iCp); j++) {

		if (iCp%j == 0) { return false; }
	}

	return true;
}

int main() {

	int N, t1, t2, p = 1;

	fill(digitPrime, digitPrime + 1000001, 0);
	digitPrime[2] = 1;

	for (int i = 3; i < 1000000; i += 2) {

		if (isPrime(i) == true && isPrime(digitSum(i)) == true) { digitPrime[i] = ++p; }
	}

	scanf("%d", &N), getchar();

	for (int i = 1; i <= N; i++) {

		scanf("%d %d", &t1, &t2), getchar();

		while (digitPrime[t1] == 0) { t1++; }
		while (digitPrime[t2] == 0) { t2--; }

		int sum = digitPrime[t2] - digitPrime[t1] + 1;

		printf("%d\n", sum);
	}

	return 0;
}