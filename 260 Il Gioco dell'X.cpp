#include <iostream>

using namespace std;

int N;
char board[200][200];
bool isVisit[200][200];

bool DFS(int i, int j) {

	if (i < 0 || j < 0 || i >= N || j >= N || isVisit[i][j] == true
	                                       || board[i][j] == 'b') { return false; }
	else if (j == N - 1) { return true; }
	else {

		isVisit[i][j] = true;
		return DFS(i - 1, j - 1) || DFS(i - 1, j) || DFS(i, j - 1) || 
			   DFS(i, j + 1) || DFS(i + 1, j) || DFS(i + 1, j + 1);
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int game = 0;
		
	while (cin >> N && N != 0) {

		bool isWin = false;

		for (int i = 0; i < N; ++i) {

			for (int j = 0; j < N; ++j) {

				cin >> board[i][j];
				isVisit[i][j] = false;
			}
		}

		for (int i = 0; i < N; ++i) {

			if (board[i][0] == 'w') {

				isWin = DFS(i, 0);
			}

			if (isWin == true) { break; }
		}

		cout << ++game << " ";
		isWin == true ? cout << 'W' << endl : cout << 'B' << endl;
	}

	return 0;
}