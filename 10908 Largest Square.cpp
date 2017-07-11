#include <iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, M, N, Q, r, c;
	char grid[100][100];

	cin >> T;

	for (int i = 0; i < T; ++i) {

		cin >> M >> N >> Q;
		cout << M << " " << N << " " << Q << endl;

		for (int j = 0; j < M; ++j) {

			for (int k = 0; k < N; ++k) {

				cin >> grid[j][k];
			}
		}

		for (int j = 0; j < Q; ++j) {

			cin >> r >> c;			

			int length = 1;
			char C = grid[r][c];
			bool isLarge = false;

			for (int k = 1; ;++k, length += 2) {

				for (int l = r - k; l <= r + k; ++l) {

					for (int m = c - k; m <= c + k; ++m) {

						if (l < 0 || l >= M || m < 0 || m >= N || C != grid[l][m]) {

							isLarge = true;
							break;
						}
					}

					if (isLarge) { break; }
				}

				if (isLarge) { break; }				
			}

			cout << length << endl;
		}
	}

	return 0;
}