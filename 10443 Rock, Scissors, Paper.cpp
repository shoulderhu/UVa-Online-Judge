#include <iostream>
#include <algorithm>

using namespace std;

int t, r, c, n;
char grid[100][100], territory[100][100];

bool isDefeat(char &t, char &g) {

	switch (t) {

	case 'S': return g == 'R'; break;
	case 'P': return g == 'S'; break;
	case 'R': return g == 'P'; break;
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> t;

	for (int i = 0; i < t; ++i) {

		if (i > 0) { cout << endl; }

		cin >> r >> c >> n;

		for (int j = 0; j < r; ++j) {

			for (int k = 0; k < c; ++k) {

				cin >> grid[j][k];
			}
		}
						
		for (int j = 0; j < n; ++j) {

			for (int k = 0; k < r; ++k) {

				for (int l = 0; l < c; ++l) {

					if (l - 1 >= 0 && isDefeat(grid[k][l], grid[k][l - 1])) {

						territory[k][l] = grid[k][l - 1];
					}
					else if (k - 1 >= 0 && isDefeat(grid[k][l], grid[k - 1][l])) {

						territory[k][l] = grid[k - 1][l];
					}
					else if (l + 1 < c && isDefeat(grid[k][l], grid[k][l + 1])) {

						territory[k][l] = grid[k][l + 1];
					}
					else if (k + 1 < r && isDefeat(grid[k][l], grid[k + 1][l])) {

						territory[k][l] = grid[k + 1][l];
					}
					else { territory[k][l] = grid[k][l]; }
				}
			}

			swap(grid, territory);
		}

		for (int j = 0; j < r; ++j, cout << endl) {

			for (int k = 0; k < c; ++k) {

				cout << grid[j][k];
			}
		}
	}

	return 0;
}