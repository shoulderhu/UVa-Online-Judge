#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);

	int N, R, C1, C2, P, map[101][101], S, D, T, scenario = 0;

	while (cin >> N >> R && !(N == 0 && R == 0)) {

		for (int i = 1; i <= N; ++i) {

			map[i][i] = 0;

			for (int j = i + 1; j <= N; ++j) {

				map[i][j] = -1, map[j][i] = -1;
			}
		}

		for (int i = 0; i < R; ++i) {

			cin >> C1 >> C2 >> P;
			map[C1][C2] = P, map[C2][C1] = P;
		}

		cin >> S >> D >> T;

		for (int i = 1; i <= N; ++i) {

			for (int j = 1; j <= N; ++j) {

				for (int z = 1; z <= N; ++z) {

					if (j != z && map[j][i] != -1 && map[i][z] != -1) {

						map[j][z] = max(map[j][z], min(map[j][i], map[i][z]));
					}
				}
			}
		}

		cout << "Scenario #" << ++scenario << endl
			 << "Minimum Number of Trips = "
			 << ceil(T / (map[S][D] - 1.0)) << endl << endl;
	}

	return 0;
}
