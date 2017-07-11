#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, d, r, length;

	while (cin >> n >> d >> r && !(n == 0 && d == 0 && r == 0)) {

		int pay = 0;
		vector<int> morning(n), afternoon(n);

		for (int i = 0; i < n; ++i) { cin >> morning[i]; }
		for (int i = 0; i < n; ++i) { cin >> afternoon[i]; }

		sort(morning.begin(), morning.end());
		sort(afternoon.begin(), afternoon.end());

		for (int i = 0; i < n; ++i){
			
			int temp = morning[i] + afternoon[n - 1 - i] - d;
			if (temp > 0) { pay += temp*r; }
		}

		cout << pay << endl;
	}

	return 0;
}