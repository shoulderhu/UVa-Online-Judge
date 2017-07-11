#include <iostream>
#include <cstring>

using namespace std;

int main() {

	ios::sync_with_stdio(false);

	int n, k, m;
	long long int bar[51][51];
	
	while (cin >> n >> k >> m) {

		memset(bar, 0, sizeof(bar));
		
		for (int i = 1; i <= m; ++i) {

			bar[1][i] = 1;
		}

		for (int i = 2; i <= k; ++i) {

			for (int j = 1; j <= n; ++j) {

				for (int l = 1; l <= m && j > l; ++l) {

					bar[i][j] += bar[i - 1][j - l];
				}
			}
		}

		cout << bar[k][n] << endl;
	}

	return 0;
}