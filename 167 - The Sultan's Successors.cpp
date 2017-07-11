#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

int k, Row[8], All[92][8], Set[8][8], set = 0, score, Max;

void Queen(int step) {

	if (step < 8) {

		for (int i = 0; i < 8; ++i) {

			for (int j = 0; j < step; ++j) {

				if (Row[j] == i || Row[j] - i == step - j ||
					Row[j] - i == j - step) { break; }
				if (j == step - 1) {

					Row[step] = i;
					Queen(step + 1);
				}
			}
		}
	}
	else {

		for (int i = 0; i < 8; ++i) {

			All[set][i] = Row[i];
		}

		++set;
	}
}

int main() {

	ios::sync_with_stdio(false);

	for (int i = 0; i < 8; ++i) {

		Row[0] = i;
		Queen(1);
	}
	
	cin >> k;

	for (int i = 0; i < k; ++i) {

		for (int j = 0; j < 8; ++j) {

			for (int l = 0; l < 8; ++l) {

				cin >> Set[j][l];
			}
		}

		Max = 0;

		for (int j = 0; j < 92; ++j) {

			score = 0;

			for (int l = 0; l < 8; ++l) {

				score += Set[All[j][l]][l];
			}

			Max = max(Max, score);
		}

		cout << setw(5) << Max << endl;
	}

	return 0;
}