#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);

	int n, l, sprinkler;
	double w, side, x, r;
	pair<double, double> p;	
	
	while (cin >> n >> l >> w) {

		w /= 2;
		vector<pair<double, double>> pos;

		for (int i = 0; i < n; ++i) {

			cin >> x >> r;		

			if (r > w) {

				side = sqrt(r * r - w * w);
				p.first = x - side, p.second = x + side;
				pos.push_back(p);
			}			
		}

		sort(pos.begin(), pos.end(), [](pair<double, double> &a, pair<double, double> &b) {
		
			return a.first < b.first;
		});

		side = 0, sprinkler = 0;		

		for (int i = 0; side < l; ) {

			double far = side;
			
			while (i < pos.size() && pos[i].first <= side) {

				far = max(far, pos[i].second), ++i;
			}

			if (far == side) { break; }
			else { side = far, ++sprinkler; }
		}
		
		if (side < l) { cout << -1 << endl; }
		else { cout << sprinkler << endl; }
	}
		
	return 0;
}