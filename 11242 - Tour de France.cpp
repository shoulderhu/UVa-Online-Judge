#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int f, r, F[100], p;
	double d[10000], MAX, m;
	
	while (cin >> f && f != 0) {

		cin >> r;
		p = -1, MAX = 0;

		for (int i = 0; i < f; ++i) {

			cin >> F[i];
		}

		for (int j = 0; j < r; ++j) {

			cin >> m;

			for (int k = 0; k < f; ++k) {

				d[++p] = F[k] / m;
			}
		}

		sort(d, d + p + 1);
		
		for (int j = 1; j <= p; ++j) {

			MAX = max(MAX, d[j] / d[j - 1]);
		}

		cout << fixed << setprecision(2) << MAX << "\n";
	}
	
	return 0;
}