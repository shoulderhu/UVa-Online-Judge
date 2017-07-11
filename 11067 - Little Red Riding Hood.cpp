#include <iostream>
#include <cstring>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int w, h, n, x, y;
	bool isWolf[101][101];
	long long int grid[101][101];

	while (cin >> w >> h && !(w == 0 && h == 0)) {

		cin >> n;
		memset(grid, 0, sizeof(grid));
		memset(isWolf, false, sizeof(isWolf));

		for (int i = 0; i < n; ++i) {

			cin >> x >> y;
			isWolf[x][y] = true;
		}

		for (int i = 0; i <= w; ++i) {

			if (!isWolf[i][0]) {

				grid[i][0] = 1;
			}
			else { break; }
		}

		for (int i = 0; i <= h; ++i) {

			if (!isWolf[0][i]) {

				grid[0][i] = 1;
			}
			else { break; }			
		}

		for (int i = 1; i <= w; ++i) {

			for (int j = 1; j <= h; ++j) {

				if (!isWolf[i][j]) {

					if (!isWolf[i - 1][j]) {

						grid[i][j] += grid[i - 1][j];
					}
					if (!isWolf[i][j - 1]) {

						grid[i][j] += grid[i][j - 1];
					}
				}
			}
		}

		switch (grid[w][h]) {

		case 0: cout << "There is no path.\n"; break;
		case 1: cout << "There is one path from Little Red Riding Hood's house to her grandmother's house.\n"; break;
		default: cout << "There are " << grid[w][h] 
			          << " paths from Little Red Riding Hood's house to her grandmother's house.\n"; break;			
		}
	}

	return 0;
}