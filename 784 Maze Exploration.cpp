#include <iostream>
#include <string>

using namespace std;

int r, c[30];
char maze[30][80];
bool isVisit[30][80];

void DFS(int x, int y) {

	if (x < 0 || y < 0 || x >= r || y >= c[x] || isVisit[x][y] == true) { return; }
	else if (maze[x][y] == ' ' || maze[x][y] == '*') {
	
		maze[x][y] = '#';
		DFS(x - 1, y);
		DFS(x, y + 1);
		DFS(x + 1, y);
		DFS(x, y - 1);
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int kace;
	string line;

	cin >> kace, cin.ignore();
	
	for (int i = 1; i <= kace; ++i) {

		bool isPainted = false;
		r = 0, c[r] = 0;

		while (getline(cin, line)) {
			
			for (int j = 0; j < line.size(); ++j) { maze[r][j] = line[j]; }

			c[r] = line.size(), ++r;
			if (line[0] == '_') { break; }
		}

		for (int j = 0; j < r; ++j) {

			for (int k = 0; k < c[j]; ++k) {

				isVisit[j][k] = false;
			}
		}

		for (int j = 0; j < r; ++j) {

			for (int k = 0; k < c[j]; ++k) {

				if (maze[j][k] == '*') { DFS(j, k); isPainted = true; break; }
			}

			if (isPainted == true) { break; }
		}

		for (int j = 0; j < r; ++j) {

			for (int k = 0; k < c[j]; ++k) {

				cout << maze[j][k];
			}

			cout << endl;
		}
	}

	return 0;
}
