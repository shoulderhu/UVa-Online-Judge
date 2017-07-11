#include <iostream>
#include <cmath>

using namespace std;

int main() {

	ios::sync_with_stdio(false);

	long long int N, n, row;

	while (cin >> N && N != 0) {

		n = floor((-2.0 + sqrt(4.0 - 4.0 * (1.0 - 4.0 * N))) / 2.0);
		if (n % 2 == 0) { --n; }
		
		N -= (n + 1) * (n + 1) / 4;
		row = (n + 1) / 2;

		if (N == 0) {

			if (row % 2 == 0) {

				cout << row << " " << 1 << endl;
			}
			else { cout << 1 << " " << row << endl; }
		}
		else {

			++row;

			if (row % 2 != 0) {

				if (N > row) {

					cout << row - (N - row) << " " << row << endl;
				}
				else { cout << row << " " << N << endl; }
			}
			else {

				if (N > row) {

					cout << row << " " << row  - (N - row) << endl;
				}
				else { cout << N << " " << row << endl; }
			}
		}		
	}

	return 0;
}
