#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int W, H, N, X[2], Y[2];
	bool board[501][501];

	while (cin >> W >> H >> N && !(W == 0 && H == 0 && N == 0)) {

		for (int i = 1; i <= W; ++i) {

			for (int j = 1; j <= H; ++j) {

				board[i][j] = true;
			}
		}

		for (int i = 1; i <= N; ++i) {

			cin >> X[0] >> Y[0] >> X[1] >> Y[1];
			sort(X, X + 2), sort(Y, Y + 2);

			for (int j = X[0]; j <= X[1]; ++j) {

				for (int k = Y[0]; k <= Y[1]; ++k) {

					board[j][k] = false;
				}
			}
		}

		int spot = 0;

		for (int i = 1; i <= W; ++i) {

			for (int j = 1; j <= H; ++j) {

				if (board[i][j] == true) { ++spot; }				
			}
		}

		if (spot == 0) { cout << "There is no empty spots." << endl; }
		else if (spot == 1) { cout << "There is one empty spot." << endl; }
		else { cout << "There are " << spot << " empty spots." << endl; }
	}

	return 0;
}