#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, L, D, U, V, C, map[101][101], Map = 0;

	cin >> T;

	for (int i = 1; i <= T; ++i) {

		cin >> L >> D;

		for (int j = 1; j <= L; ++j) {

			for (int k = 1; k <= L; ++k) { map[j][k] = 99001; }
			map[j][j] = 0;
		}

		for (int j = 1; j <= D; ++j) {

			cin >> U >> V >> C;
			if (C < map[U][V]) { map[U][V] = C, map[V][U] = C; }
		}

		for (int j = 1; j <= L; ++j) {

			for (int k = 1; k <= L; ++k) {

				for (int l = 1; l <= L; ++l) {

					map[k][l] = min(map[k][l], map[k][j] + map[j][l]);					
				}
			}
		}

		int cost = 99001;

		for (int j = 6; j <= L; ++j) {

			if (map[1][j] == map[2][j] && map[2][j] == map[3][j] &&
				map[3][j] == map[4][j] && map[4][j] == map[5][j]) {

				int temp = map[1][j];

				for (int k = 6; k <= L; ++k) { temp = max(temp, map[j][k]); }
				cost = min(cost, temp);												
			}
		}
		
		cout << "Map " << ++Map << ": ";
		cost == 99001 ? cout << "-1" << endl : cout << cost << endl;		
	}

	return 0;
}