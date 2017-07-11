#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N, a = -1, l, r;
bool isPrime[1000000];
long long int aPrime[80072], k, low, high;

int binarySearch(int L, int R, bool flag) {

	int M;
	long long int num = (flag ? low : high);

	while (L < R) {

		M = (L + R) / 2;
				
		if (num >= aPrime[M]) { L = M; }
		else { R = M; }

		if (R - L == 1) { return flag ? L : R; }
	}
}

int main() {
	
	ios::sync_with_stdio(false);

	memset(isPrime, true, sizeof(isPrime));

	for (long long int i = 2; i < 1000000; ++i) {

		if (isPrime[i]) {

			for (int j = i + i; j < 1000000; j += i) {

				isPrime[j] = false;
			}

			k = i * i;

			while (0 < k && k < 1000000000000) {

				aPrime[++a] = k;
				k *= i;
			}			
		}
	}

	aPrime[80070] = 0, aPrime[80071] = 1000000000000;
	sort(aPrime, aPrime + 80072);
	
	cin >> N;

	for (int i = 0; i < N; ++i) {

		cin >> low >> high;				
		r = binarySearch(0, 80071, false);
		l = binarySearch(0, r, true);
		if (aPrime[l] < low || l == 0) { ++l; }
		if (aPrime[r] > high || r == 80071) { --r; }
		cout << r - l + 1 << endl;
	}
	
	return 0;
}