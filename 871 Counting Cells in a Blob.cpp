#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int row, column;
bool isVisit[25][25];
char grid[25][25];

void DFS(int j, int k, int& blob) {

	if (j < 0 || k < 0 || j > row || k >= column || isVisit[j][k] == true 
		                                         || grid[j][k] != '1') { return; }
	else {

		++blob,	isVisit[j][k] = true;
		DFS(j - 1, k - 1, blob);
		DFS(j - 1, k, blob);
		DFS(j - 1, k + 1, blob);
		DFS(j, k - 1, blob);
		DFS(j, k + 1, blob);
		DFS(j + 1, k - 1, blob);
		DFS(j + 1, k, blob);
		DFS(j + 1, k + 1, blob);
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int kace;
	string line;

	cin >> kace, cin.ignore(), cin.ignore();

	for (int i = 1; i <= kace; ++i) {

		if (i > 1) { cout << endl; }

		row = -1;

		while (getline(cin, line) && line != "") {

			++row, column = line.size();

			for (int j = 0; j < line.size(); ++j) { 
				
				grid[row][j] = line[j]; 
				isVisit[row][j] = false;
			}
		}	

		int maxBlob = 0, blob;		

		for (int j = 0; j <= row; ++j) {

			for (int k = 0; k < column; ++k) {

				if (grid[j][k] == '1' && isVisit[j][k] == false) {

					blob = 0, DFS(j, k, blob);
					maxBlob = max(maxBlob, blob);
				}
			}
		}

		cout << maxBlob << endl;
	}

	return 0;
}