#include <iostream>
#include <iomanip>
#include <cmath>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

int Case, n, N;
double length;
vector<int> Vec;

inline int getRoot(int &n) {

	if (Vec[n] == n) { return n; }
	else { return Vec[n] = getRoot(Vec[n]); }
}

int main() {

	ios::sync_with_stdio(false);

	cin >> Case;

	for (int i = 0; i < Case; ++i) {

		if (i > 0) { cout << endl; }

		cin >> n;

		Vec.clear();		
		vector<pair<double, double>> F(n);
		vector<tuple<int, int, double>> I(n*(n - 1) / 2);

		for (int j = 0; j < n; ++j) {

			cin >> F[j].first >> F[j].second;
			Vec.push_back(j);
		}

		for (int j = 0, l = 0; j < n; ++j) {

			for (int k = j + 1; k < n; ++k, ++l) {

				get<0>(I[l]) = j, get<1>(I[l]) = k;
				get<2>(I[l]) = sqrt(pow(F[j].first - F[k].first, 2) +
					                pow(F[j].second - F[k].second, 2));
			}
		}

		sort(I.begin(), I.end(),
			[](tuple<int, int, double> &a, tuple<int, int, double> &b) {

			return get<2>(a) < get<2>(b);
		});

		length = 0, N = 0;

		for (int j = 0; j < I.size() && N < n; ++j) {

			get<0>(I[j]) = getRoot(get<0>(I[j]));
			get<1>(I[j]) = getRoot(get<1>(I[j]));

			if (get<0>(I[j]) != get<1>(I[j])) {

				Vec[get<1>(I[j])] = get<0>(I[j]);
				length += get<2>(I[j]), ++N;
			}
		}

		cout << fixed << setprecision(2) << length << endl;
	}

	return 0;
}