#include <iostream>

using namespace std;

int m, n;
char grid[101][101];
bool isVisit[101][101];

void DFS(int i, int j) {

	if (i < 0 || j < 0 || i >= m || j >= n || 
		isVisit[i][j] || grid[i][j] == '*') { return; }
	else {

		isVisit[i][j] = true;
		DFS(i - 1, j - 1);
		DFS(i - 1, j);
		DFS(i - 1, j + 1);
		DFS(i, j - 1);
		DFS(i, j + 1);
		DFS(i + 1, j - 1);
		DFS(i + 1, j);
		DFS(i + 1, j + 1);
	}
}

int main() {

	ios::sync_with_stdio(false);

	while (cin >> m >> n && m != 0) {
		
		for (int i = 0; i < m; ++i) {

			for (int j = 0; j < n; ++j) {

				cin >> grid[i][j];
				isVisit[i][j] = false;
			}			
		}

		int deposit = 0;

		for (int i = 0; i < m; ++i) {

			for (int j = 0; j < n; ++j) {

				if (isVisit[i][j] == false && grid[i][j] == '@') {

					++deposit, DFS(i, j);
				}
			}
		}

		cout << deposit << endl;	
	}

	return 0;
}
