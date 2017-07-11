#include <iostream>
#include <vector>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int cases, costs[36], Dec, query;

	cin >> cases;

	for (int i = 0; i < cases; ++i) {

		if (i > 0) { cout << endl; }

		for (int j = 0; j < 36; ++j) { cin >> costs[j]; }
				
		cout << "Case " << i + 1 << ":" << endl;
		cin >> query;

		for (int j = 0; j < query; ++j) {

			cin >> Dec;

			int min = 2000000000;
			vector<int> Vec;

			for (int k = 2; k <= 36; ++k) {

				int dec = Dec, cost = 0;

				while (dec != 0) {

					cost += costs[dec%k];
					dec /= k;
				}

				if (cost < min) {

					min = cost;
					Vec.clear(), Vec.push_back(k);
				}
				else if (cost == min) { Vec.push_back(k); }
			}
						
			cout << "Cheapest base(s) for number " << Dec << ":";
			for (int k = 0; k < Vec.size(); ++k) { cout << " " << Vec[k]; }
			cout << endl;
		}
	}

	return 0;
}