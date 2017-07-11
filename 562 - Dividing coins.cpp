#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);

	int n, m, M[100], sum, half, K[50000];

	cin >> n;

	for (int i = 0; i < n; ++i) {

		cin >> m;
		sum = 0;

		for (int j = 0; j < m; ++j) {

			cin >> M[j];
			sum += M[j];
		}
		
		half = sum / 2;
		memset(K, 0, sizeof(K));

		for (int j = 0; j < m; ++j) {

			for (int k = half; k >= M[j]; --k) {

				K[k] = max(K[k], K[k - M[j]] + M[j]);
			}
		}

		cout << sum - K[half] - K[half] << endl;
	}

	return 0;
}