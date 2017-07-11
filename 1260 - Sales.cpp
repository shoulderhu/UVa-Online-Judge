#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, n, a[5001], sum;

	cin >> T;

	for (int i = 0; i < T; ++i) {

		cin >> n >> a[1];
		sum = 0;

		for (int j = 2; j <= n; ++j) {

			cin >> a[j];

			sum += count_if(a + 1, a + j, [&a, &j](int &aa) {
			
				return aa <= a[j];
			});			
		}

		cout << sum << "\n";
	}
	
	return 0;
}