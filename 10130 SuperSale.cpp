#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int T, N, P, W, G, MW;
	vector<int> p, w;
	p.reserve(1000), w.reserve(1000);

	cin >> T;

	for (int i = 1; i <= T; ++i) {

		cin >> N;

		int good = 0;
		p.clear(), w.clear();

		for (int j = 1; j <= N; ++j) {

			cin >> P >> W;
			p.push_back(P), w.push_back(W);
		}

		cin >> G;

		for (int j = 1; j <= G; ++j) {

			cin >> MW;

			vector<int> knapsack(MW + 1, 0);

			for (int k = 0; k < N; ++k) {

				for (int l = MW; l >= w[k]; --l) {

					knapsack[l] = max(knapsack[l], knapsack[l - w[k]] + p[k]);
				}
			}

			good += knapsack[MW];
		}

		cout << good << endl;
	}

	return 0;
}
