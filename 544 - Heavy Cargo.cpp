#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int n, r, weight[200][200], limit, x = 0;
string city1, city2;
unordered_map<string, int> Map;

int main() {

	ios::sync_with_stdio(false);

	while (cin >> n >> r && !(n == 0 && r == 0)) {

		int m = -1;
		Map.clear();

		for (int i = 0; i < n; ++i) {

			weight[i][i] = 0;

			for (int j = i + 1; j < n; ++j) {

				weight[i][j] = -1, weight[j][i] = -1;
			}
		}

		for (int i = 0; i < r; ++i) {

			cin >> city1 >> city2 >> limit;
			if (Map.find(city1) == Map.end()) { Map[city1] = ++m; }
			if (Map.find(city2) == Map.end()) { Map[city2] = ++m; }
			weight[Map[city1]][Map[city2]] = limit;
			weight[Map[city2]][Map[city1]] = limit;
		}

		cin >> city1 >> city2;

		for (int i = 0; i < n; ++i) {

			for (int j = 0; j < n; ++j) {

				for (int k = 0; k < n; ++k) {

					if (j != k && weight[j][i] != -1 && weight[i][k] != -1) {

						weight[j][k] = max(weight[j][k],
							               min(weight[j][i], weight[i][k]));
					}
				}
			}
		}

		cout << "Scenario #" << ++x << endl 
			 << weight[Map[city1]][Map[city2]] << " tons" << endl << endl;
	}

	return 0;
}