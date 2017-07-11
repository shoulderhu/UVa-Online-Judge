#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, N, R, u, v, s, d, HQ[100][100], kace = 0;

	cin >> T;

	for (int i = 1; i <= T; ++i) {

		cin >> N >> R;

		for (int j = 0; j < N; ++j) {

			for (int k = 0; k < N; ++k) { HQ[j][k] = 100; }
			HQ[j][j] = 0;
		}

		for (int j = 1; j <= R; ++j) {

			cin >> u >> v;
			HQ[u][v] = 1, HQ[v][u] = 1;
		}

		for (int j = 0; j < N; ++j) {

			for (int k = 0; k < N; ++k) {

				for (int l = 0; l < N; ++l) {

					HQ[k][l] = min(HQ[k][l], HQ[k][j] + HQ[j][l]);
				}
			}
		}

		int time = 0;

		cin >> s >> d;

		for (int j = 0; j < N; ++j) { time = max(time, HQ[s][j] + HQ[j][d]); }

		cout << "Case " << ++kace << ": " << time << endl;
	}

	return 0;
}