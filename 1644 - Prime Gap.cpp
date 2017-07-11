#include <iostream>
#include <cstring>

using namespace std;

int prime[100000], p = -1, integer, L, R, M;
bool isPrime[1299710];

int main() {
	
	ios::sync_with_stdio(false);
	
	memset(isPrime, 1, sizeof(isPrime));
	
	for (int i = 2; i < 1299710; ++i) {

		if (isPrime[i]) {

			prime[++p] = i;

			for (int j = i + i; j < 1299710; j += i) {

				isPrime[j] = false;
			}
		}
	}
	
	while (cin >> integer && integer != 0) {

		if (isPrime[integer]) { cout << 0 << endl; continue; }

		L = 0, R = 99999;

		while (L < R) {

			M = (L + R) / 2;
			integer > prime[M] ? L = M : R = M;
			if (R - L == 1) { break; }			
		}

		cout << prime[R] - prime[L] << endl;
	}
	
	return 0;
}