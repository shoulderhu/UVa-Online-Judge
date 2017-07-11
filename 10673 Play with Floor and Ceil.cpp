#include <iostream>
#include <cmath>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	long long int x, k;

	cin >> T;

	for (int i = 1; i <= T; ++i) {

		cin >> x >> k;

		long long int Ceil = ceil((double)x / k), Floor = floor((double)x / k);

		for (int j = 0; Floor*j <= x; ++j) {
			
			if ((x - Floor*j) % Ceil == 0) {

				cout << j << " " << (x - Floor*j) / Ceil << endl;
				break;
			}
		}
	}

	return 0;
}