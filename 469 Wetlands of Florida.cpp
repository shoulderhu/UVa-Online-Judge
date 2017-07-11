#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

int r, c, sum;
char grid[100][100];
bool isVisit[100][100];

void DFS(int x, int y) {

	if (x < 0 || y < 0 || x >= r || y >= c || isVisit[x][y] == true || grid[x][y] == 'L') { return; }
	else {

		isVisit[x][y] = true;
		++sum;

		DFS(x - 1, y - 1);
		DFS(x - 1, y);
		DFS(x - 1, y + 1);
		DFS(x, y - 1);
		DFS(x, y + 1);
		DFS(x + 1, y - 1);
		DFS(x + 1, y);
		DFS(x + 1, y + 1);
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int kace = 0, x, y;
	string line;

	cin >> kace, cin.ignore(), cin.ignore();

	for (int i = 1; i <= kace; ++i) {

		if (i > 1) { cout << endl; }
		
		r = 0;
		
		while (getline(cin, line) && isalpha(line[0]) != 0) {
			
			int length = line.size();

			for (int j = 0; j < length; ++j) { grid[r][j] = line[j]; }

			++r, c = length;
		}
				
		do {
			stringstream ss(line);
			ss >> x >> y, sum = 0;

			for (int j = 0; j < r; ++j) {

				for (int k = 0; k < c; ++k) {

					isVisit[j][k] = false;
				}
			}

			DFS(x - 1, y - 1);
			cout << sum << endl;

		} while (getline(cin, line) && line != "");
	}

	return 0;
}