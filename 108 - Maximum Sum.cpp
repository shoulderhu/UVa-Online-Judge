#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);

	int N, n, sum[101][101], MAX;

	for (int i = 0; i <= 100; ++i) {

		sum[i][0] = 0, sum[0][i] = 0;
	}

	while (cin >> N) {

		MAX = -2000000000;
		
		for (int i = 1; i <= N; ++i) {
			
			for (int j = 1; j <= N; ++j) {
				
				cin >> n;
				sum[i][j] = sum[i - 1][j] + sum[i][j - 1] -
					        sum[i - 1][j - 1] + n;
			}
		}

		for (int i = 1; i <= N; ++i) {
			
			for (int j = 1; j <= N; ++j) {
								
				for (int k = i; k <= N; ++k) {

					for (int l = j; l <= N; ++l) {

						MAX = max(MAX, sum[k][l] - sum[k][j - 1] -
							           sum[i - 1][l] + sum[i - 1][j - 1]);
					}
				}
			}
		}

		cout << MAX << endl;
	}

	return 0;
}
