#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int Case, N, grid[151][151], n, N2, MAX, jj, kk;

int main() {

	ios::sync_with_stdio(false);
		
	cin >> Case;
		
	for (int i = 0; i < Case; ++i) {

		cin >> N;
		N2 = N*2, MAX = INT_MIN;
		
		for (int j = 1; j <= N; ++j) {

			for (int k = 1; k <= N; ++k) {

				cin >> n;
				grid[j][k] = n;
				grid[j + N][k] = n;
				grid[j][k + N] = n;
				grid[j + N][k + N] = n;
			}
		}

		for (int j = 1; j <= N2; ++j) {

			for (int k = 1; k <= N2; ++k) {
								
				grid[j][k] += (grid[j - 1][k] + grid[j][k - 1] - grid[j - 1][k - 1]);				
			}
		}

		for (int j = 0; j < N; ++j) {

			for (int k = 0; k < N; ++k) {

				jj = j + N, kk = k + N;

				for (int l = j + 1; l <= jj; ++l) {
					
					for (int m = k + 1; m <= kk; ++m) {
						
						MAX = max(MAX, grid[l][m] - grid[l][k] - grid[j][m] + grid[j][k]);
					}
				}
			}
		}

		cout << MAX << endl;		
	}

	return 0;
}