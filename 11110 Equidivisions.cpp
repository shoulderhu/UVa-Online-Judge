#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int square[100][100], sum, n, num;
bool isVisit[100][100];

void DFS(int i, int j) {

	if (i < 0 || j < 0 || i > n || j > n) { return; }
	else if (isVisit[i][j] == true || square[i][j] != num) { return; }
	else {

		++sum, isVisit[i][j] = true;
		DFS(i - 1, j);
		DFS(i, j + 1);
		DFS(i + 1, j);
		DFS(i, j - 1);
	}
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int x, y;
	string line;

	while (cin >> n && n != 0) {

		cin.ignore();

		for (int i = 1; i <= n; ++i) {

			for (int j = 1; j <= n; ++j) {

				square[i][j] = n;
				isVisit[i][j] = false;
			}
		}

		for (int i = 1; i < n; ++i) {

			getline(cin, line);

			stringstream ss(line);			
			while (ss >> x >> y) { square[x][y] = i; }			
		}
		
		bool isGood = true;

		for (int i = 1; i <= n; ++i) {

			for (int j = 1; j <= n; ++j) {

				if (isVisit[i][j] == false) {

					num = square[i][j], sum = 0, DFS(i, j);
					if (sum != n) { isGood = false; break; }
				}
			}

			if (isGood == false) { break; }
		}

		isGood == true ? cout << "good\n" : cout << "wrong\n";
	}

	return 0;
}