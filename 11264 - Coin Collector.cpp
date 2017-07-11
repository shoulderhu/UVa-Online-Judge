#include <iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, n, coin, value;
	int C[1000];

	cin >> T;

	for (int i = 0; i < T; ++i) {

		cin >> n;

		for (int j = 0; j < n; ++j) {

			cin >> C[j];
		}

		value = C[0], coin = 1;

		for (int j = 1; j < n - 1; ++j) {

			if (value + C[j] < C[j + 1]) {

				value += C[j];
				++coin;
			}
		}

		cout << coin + 1 << '\n';
	}
	
	return 0;
}