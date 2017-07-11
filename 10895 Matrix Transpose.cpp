#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int matrix[10001][10001];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int m, n, r, e;
	struct element {

		int pos, value;
		element(int &p, int &v) { pos = p, value = v; }
	};

	while (cin >> m >> n) {

		int Max = max(m, n);

		for (int i = 1; i <= Max; ++i) {

			for (int j = 1; j <= Max; ++j) {

				matrix[i][j] = 0;
			}
		}

		for (int i = 1; i <= m; ++i) {

			cin >> r;

			vector<int> R(r);
			for (int j = 0; j < r; ++j) { cin >> R[j]; }

			for (int j = 0; j < R.size(); ++j) {

				cin >> e;
				matrix[i][R[j]] = e;
			}
		}
		
		cout << n << " " << m << endl;

		for (int i = 1; i <= n; ++i) {

			vector<struct element> R;

			for (int j = 1; j <= m; ++j) {

				if (matrix[j][i] != 0) { R.emplace_back(j, matrix[j][i]); }
			}

			cout << R.size();
			for (int j = 0; j < R.size(); ++j) { cout << " " << R[j].pos; }
			cout << endl;

			for (int j = 0; j < R.size(); ++j) {
				
				cout << R[j].value;
				if (j != R.size() - 1) { cout << " "; }
			}
			cout << endl;
		}
	}

	return 0;
}