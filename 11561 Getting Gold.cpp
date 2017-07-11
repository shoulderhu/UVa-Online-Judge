#include <iostream>
#include <string>

using namespace std;

int W, H;
char map[50][50];
bool isVisit[50][50];

void DFS(int x, int y, int& gold) {

	if (x < 0 || y < 0 || x >= H || y >= W || isVisit[x][y] == true
		                         || map[x][y] == '#' || map[x][y] == 'T') { return; }
	else {

		if (map[x][y] == 'G') { ++gold; }
		isVisit[x][y] = true;

		if (x - 1 >= 0 && map[x - 1][y] == 'T') { return; }
		if (x + 1 < H && map[x + 1][y] == 'T') { return; }
		if (y - 1 >= 0 && map[x][y - 1] == 'T') { return; }
		if (y + 1 < W && map[x][y + 1] == 'T') { return; }
				
		DFS(x - 1, y, gold);
		DFS(x, y - 1, gold);
		DFS(x + 1, y, gold);
		DFS(x, y + 1, gold);					
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int Px, Py;
	string line;

	while (cin >> W >> H) {

		int gold = 0;

		for (int i = 0; i < H; ++i) {
			
			cin >> line;

			for (int j = 0; j < W; ++j) {

				map[i][j] = line[j];
				isVisit[i][j] = false;
				if (line[j] == 'P') { Px = i, Py = j; }				
			}
		}
		
		DFS(Px, Py, gold);
		cout << gold << endl;
	}

	return 0;
}