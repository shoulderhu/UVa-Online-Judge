#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int C, S, Q, c1, c2, d, Case = 0;
	int edge[101][101];

	while (cin >> C >> S >> Q && !(C == 0 && S == 0 && Q == 0)) {

		if (Case > 0) { cout << endl; }

		for (int i = 1; i <= C; ++i) {

			edge[i][i] = 0;

			for (int j = i + 1; j <= C; ++j) {

				edge[i][j] = 1000000000;
				edge[j][i] = 1000000000;
			}
		}

		for (int i = 0; i < S; ++i) {

			cin >> c1 >> c2 >> d;
			edge[c1][c2] = d;
			edge[c2][c1] = d;			
		}

		for (int i = 1; i <= C; ++i) {

			for (int j = 1; j <= C; ++j) {

				for (int k = 1; k <= C; ++k) {

					if (edge[j][i] != 1000000000 && edge[i][k] != 1000000000) {

						edge[j][k] = min(edge[j][k], max(edge[j][i], edge[i][k]));
					}					 
				}
			}
		}

		cout << "Case #" << ++Case << '\n';

		for (int i = 0; i < Q; ++i) {

			cin >> c1 >> c2;

			if (edge[c1][c2] == 1000000000) {

				cout << "no path\n";
			}
			else { cout << edge[c1][c2] << '\n'; }			
		}
	}

	return 0;
}