#include <iostream>
#include <string>

using namespace std;

int r, c;
char sky[100][100];
bool isVisit[100][100];

void DFS(int i, int j, int& pixel) {

	if (i < 0 || j < 0 || i >= r || j >= c || isVisit[i][j] == true 
		                                   || sky[i][j] == '.') { return; }
	else {

		++pixel, isVisit[i][j] = true;
		DFS(i - 1, j - 1, pixel);
		DFS(i - 1, j, pixel);
		DFS(i - 1, j + 1, pixel);
		DFS(i, j - 1, pixel);
		DFS(i, j + 1, pixel);
		DFS(i + 1, j - 1, pixel);
		DFS(i + 1, j, pixel);
		DFS(i + 1, j + 1, pixel);
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
		
	int pixel;
	string line;

	while (cin >> r >> c && (r != 0 || c != 0)) {

		int star = 0;

		for (int i = 0; i < r; ++i) {

			cin >> line;

			for (int j = 0; j < c; ++j) {
				
				sky[i][j] = line[j];	
				isVisit[i][j] = false;
			}
		}

		for (int i = 0; i < r; ++i) {

			for (int j = 0; j < c; ++j) {

				if (sky[i][j] == '*' && isVisit[i][j] == false) {

					pixel = 0, DFS(i, j, pixel);
					if (pixel == 1) { ++star; }
				}
			}
		}

		cout << star << endl;
	}
	
	return 0;
}