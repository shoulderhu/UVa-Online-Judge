#include <iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M, x, y;
	char map[10][10], robot[10][10];
	bool isVisit[10][10];

	while (cin >> N >> M && (N != 0 || M != 0)) {

		cin >> x >> y;

		for (int i = 0; i < N; ++i) {

			for (int j = 0; j < M; ++j) {

				cin >> map[i][j];
				robot[i][j] = '?';
				isVisit[i][j] = false;
			}
		}
		
		int movement = 0;
		--x, --y;

		for (;;++movement) {

			bool isMove = false;
			robot[x][y] = map[x][y], isVisit[x][y] = true;

			if (x - 1 >= 0) { robot[x - 1][y] = map[x - 1][y]; }
			if (y + 1 < M) { robot[x][y + 1] = map[x][y + 1]; }
			if (x + 1 < N) { robot[x + 1][y] = map[x + 1][y]; }
			if (y - 1 >= 0) { robot[x][y - 1] = map[x][y - 1]; }

			if (x - 1 >= 0 && map[x - 1][y] == '0' && isVisit[x - 1][y] == false) {

				--x; continue;
			}
			else if (y + 1 < M && map[x][y + 1] == '0' && isVisit[x][y + 1] == false) {

				++y; continue;
			}
			else if (x + 1 < N && map[x + 1][y] == '0' && isVisit[x + 1][y] == false) {

				++x; continue;
			}			
			else if (y - 1 >= 0 && map[x][y - 1] == '0' && isVisit[x][y - 1] == false) {

				--y; continue;
			}
			else { break; }
		}

		cout << endl;

		for (int i = 0; i < N; ++i) {

			for (int j = 0; j < M; ++j) { cout << "|---"; }
			cout << "|" << endl;

			for (int j = 0; j < M; ++j) {

				cout << "| " << robot[i][j] << " ";
			}
			cout << "|" << endl;
		}

		for (int j = 0; j < M; ++j) { cout << "|---"; }
		cout << "|" << endl;

		cout << endl;
		cout << "NUMBER OF MOVEMENTS: " << movement << endl;
	}

	return 0;
}