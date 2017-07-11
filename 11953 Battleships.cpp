#include <iostream>

using namespace std;

int N;
char grid[100][100];
bool isVisit[100][100];

void DFS(int j, int k) {

	if (j < 0 || k < 0 || j >= N || k >= N || isVisit[j][k] == true 
		                                   || grid[j][k] == '.') { return; }
	else {

		isVisit[j][k] = true;
		DFS(j - 1, k);
		DFS(j, k + 1);
		DFS(j + 1, k);
		DFS(j, k - 1);
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	
	cin >> T;

	for (int i = 1; i <= T; ++i) {

		cin >> N;

		for (int j = 0; j < N; ++j) {

			for (int k = 0; k < N; ++k) {

				cin >> grid[j][k];
				isVisit[j][k] = false;
			}
		}

		int alive = 0;

		for (int j = 0; j < N; ++j) {

			for (int k = 0; k < N; ++k) {

				if (grid[j][k] == 'x' && isVisit[j][k] == false) {

					++alive, DFS(j, k);
				}
			}
		}

		cout << "Case " << i << ": " << alive << endl;
	}

	return 0;
}