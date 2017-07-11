#include <iostream>
#include <string>

using namespace std;

int region = 0, M, N;
char map[20][20], land;
bool isVisit[20][20];

void DFS(int x, int y) {

	if (y == N) { y = 0; }
	else if (y == -1) { y = N - 1; }
	
	if (x < 0 || x >= M || isVisit[x][y] == true || map[x][y] != land) { return; }
	else {

		++region, isVisit[x][y] = true;
		DFS(x - 1, y);
		DFS(x, y + 1);
		DFS(x, y - 1);
		DFS(x + 1, y);
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int X, Y;
	string line;

	while (cin >> M >> N) {

		cin.ignore(1024, '\n');

		int biggest = 0;

		for (int i = 0; i < M; ++i) {

			getline(cin, line);

			for (int j = 0; j < N; ++j) {

				map[i][j] = line[j];
				isVisit[i][j] = false;
			}
		}

		cin >> X >> Y;
		land = map[X][Y], DFS(X, Y);

		for (int i = 0; i < M; ++i) {

			for (int j = 0; j < N; ++j) {

				if (map[i][j] == land && isVisit[i][j] == false) {

					region = 0, DFS(i, j);
					if (region > biggest) { biggest = region; }
				}
			}
		}

		cout << biggest << endl;		
	}

	return 0;
}