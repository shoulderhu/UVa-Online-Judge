#include <iostream>
#include <queue>

using namespace std;

int cases, R, C, Time[1000][1000], t, Size;
char maze[1000][1000];
bool isVisit[1000][1000], isExit;
pair<int, int> jf;
queue<pair<int, int>> J, F;

int main() {
	
	cin >> cases;

	for (int i = 0; i < cases; ++i) {

		cin >> R >> C;
		
		while (!J.empty()) { J.pop(); }
		
		for (int j = 0; j < R; ++j) {

			for (int k = 0; k < C; ++k) {

				cin >> maze[j][k];
				Time[j][k] = 2000, isVisit[j][k] = false;

				if (maze[j][k] == 'J') { 
					
					J.push({ j, k }), isVisit[j][k] = true;
				}
				else if (maze[j][k] == 'F') { 
					
					F.push({ j, k }), Time[j][k] = 0;
				}				
			}
		}

		t = 0;

		while (!F.empty()) {

			Size = F.size(), ++t;

			for (int j = 0; j < Size; ++j) {

				jf = F.front(), F.pop();

				if (jf.first - 1 >= 0 &&
					maze[jf.first - 1][jf.second] != '#' &&
					Time[jf.first - 1][jf.second] == 2000) {

					F.push({ jf.first - 1, jf.second });
					Time[jf.first - 1][jf.second] = t;
				}

				if (jf.first + 1 < R &&
					maze[jf.first + 1][jf.second] != '#' &&
					Time[jf.first + 1][jf.second] == 2000) {

					F.push({ jf.first + 1, jf.second });
					Time[jf.first + 1][jf.second] = t;
				}

				if (jf.second - 1 >= 0 &&
					maze[jf.first][jf.second - 1] != '#' &&
					Time[jf.first][jf.second - 1] == 2000) {

					F.push({ jf.first, jf.second - 1 });
					Time[jf.first][jf.second - 1] = t;
				}

				if (jf.second + 1 < C &&
					maze[jf.first][jf.second + 1] != '#' &&
					Time[jf.first][jf.second + 1] == 2000) {

					F.push({ jf.first, jf.second + 1 });
					Time[jf.first][jf.second + 1] = t;
				}
			}
		}

		isExit = false, t = 0;

		while (!J.empty()) {

			Size = J.size(), ++t;

			for (int j = 0; j < Size; ++j) {

				jf = J.front(), J.pop();
				
				if (jf.first == 0 || jf.first == R - 1 ||
					jf.second == 0 || jf.second == C - 1) {

					isExit = true;
					break;
				}

				if (jf.first - 1 >= 0 &&
					maze[jf.first - 1][jf.second] == '.' &&
					Time[jf.first - 1][jf.second] > t && 
					!isVisit[jf.first - 1][jf.second]) {

					J.push({ jf.first - 1, jf.second });
					isVisit[jf.first - 1][jf.second] = true;
				}

				if (jf.first + 1 < R &&
					maze[jf.first + 1][jf.second] == '.' &&
					Time[jf.first + 1][jf.second] > t &&
					!isVisit[jf.first + 1][jf.second]) {

					J.push({ jf.first + 1, jf.second });
					isVisit[jf.first + 1][jf.second] = true;
				}

				if (jf.second - 1 >= 0 &&
					maze[jf.first][jf.second - 1] == '.' &&
					Time[jf.first][jf.second - 1] > t &&
					!isVisit[jf.first][jf.second - 1]) {

					J.push({ jf.first, jf.second - 1 });
					isVisit[jf.first][jf.second - 1] = true;
				}

				if (jf.second + 1 < C &&
					maze[jf.first][jf.second + 1] == '.' &&
					Time[jf.first][jf.second + 1] > t &&
					!isVisit[jf.first][jf.second + 1]) {

					J.push({ jf.first, jf.second + 1 });
					isVisit[jf.first][jf.second + 1] = true;
				}				
			}

			if (isExit) { break; }
		}

		if (isExit) { cout << t << endl; }
		else { cout << "IMPOSSIBLE" << endl; }
	}

	return 0;
}