#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);

	int T, n, t, N[50], K[10000], KK[10000];
		
	cin >> T;

	for (int i = 1; i <= T; ++i) {

		cin >> n >> t;
		--t;

		for (int j = 0; j < n; ++j) {

			cin >> N[j];
		}

		memset(K, 0, sizeof(K));
		memset(KK, 0, sizeof(KK));

		for (int j = 0; j < n; ++j) {

			for (int k = t; k >= N[j]; --k) {

				if (K[k] < K[k - N[j]] + 1) {

					K[k] = K[k - N[j]] + 1;
					KK[k] = KK[k - N[j]] + N[j];
				}
				else if (K[k] == K[k - N[j]] + 1) {

					KK[k] = max(KK[k], KK[k - N[j]] + N[j]);
				}										
			}
		}

		cout << "Case " << i << ": " << K[t] + 1 << " " << KK[t] + 678 << endl;
	}

	return 0;
}