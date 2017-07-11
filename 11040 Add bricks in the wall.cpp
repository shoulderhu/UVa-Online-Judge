#include <iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, wall[10][10];

	cin >> N;

	for (int i = 1; i <= N; ++i) {

		for (int j = 1; j < 10; j += 2) {

			int size = (j + 1) / 2;

			for (int k = 1; k <= j; k += 2) {

				cin >> wall[j][k];
			}
		}

		for (int j = 9; j >= 3; j -= 2) {

			for (int k = 2; k < j; k += 2) {

				wall[j][k] = (wall[j - 2][k - 1] - wall[j][k + 1] - wall[j][k - 1]) / 2;
			}
		}

		for (int j = 2; j <= 8; j += 2) {

			for (int k = 1; k <= j; ++k) {

				wall[j][k] = wall[j + 1][k] + wall[j + 1][k + 1];
			}
		}

		for (int j = 1; j < 10; ++j) {

			for (int k = 1; k <= j; ++k) {

				cout << wall[j][k];
				if (k != j) { cout << " "; }
			}

			cout << endl;
		}
	}

	return 0;
}
