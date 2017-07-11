#include <iostream>

using namespace std;

char board[9][9];
bool isVisit[9][9];

void DFS(int j, int k, int& t, int &b, int &w) {

	if (j < 0 || k < 0 || j >= 9 || k >= 9 || isVisit[j][k] == true) { return; }
	else if (board[j][k] == 'X') { ++b; return; }
	else if (board[j][k] == 'O') { ++w; return; }
	else {

		isVisit[j][k] = true;
		++t;
		DFS(j - 1, k, t, b, w);
		DFS(j, k + 1, t, b, w);
		DFS(j + 1, k, t, b, w);
		DFS(j, k - 1, t, b, w);
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int position;
	
	cin >> position;

	for (int i = 1; i <= position; ++i) {

		int black = 0, white = 0;

		for (int j = 0; j < 9; ++j) {

			for (int k = 0; k < 9; ++k) {

				cin >> board[j][k];
				isVisit[j][k] = false;
			}
		}

		for (int j = 0; j < 9; ++j) {

			for (int k = 0; k < 9; ++k) {

				if (board[j][k] == 'X') { ++black; }
				else if (board[j][k] == 'O') { ++white; }
				else if (isVisit[j][k] == false) {

					int territory = 0, b = 0, w = 0;
					DFS(j, k, territory, b, w);

					if ((b == 0) ^ (w == 0)) {

						w == 0 ? black += territory : white += territory;
					}
				}
			}
		}

		cout << "Black " << black << " White " << white << endl;
	}

	return 0;
}