#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N, R, C, area[100][100], length;
string name;

void DFS(int j, int k, int h, int l) {

	if (j < 0 || k < 0 || j >= R || k >= C || h <= area[j][k]) {
	
		length = max(length, l);
		return;
	}
	else {

		DFS(j - 1, k, area[j][k], l + 1);
		DFS(j + 1, k, area[j][k], l + 1);
		DFS(j, k - 1, area[j][k], l + 1);
		DFS(j, k + 1, area[j][k], l + 1);
	}
}

int main() {

	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; ++i) {

		cin >> name >> R >> C;

		for (int j = 0; j < R; ++j) {

			for (int k = 0; k < C; ++k) {

				cin >> area[j][k];
			}
		}

		length = 0;

		for (int j = 0; j < R; ++j) {

			for (int k = 0; k < C; ++k) {

				DFS(j, k, area[j][k] + 1, 0);
			}
		}

		cout << name << ": " << length << endl;
	}

	return 0;
}