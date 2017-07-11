#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int r = 0, c[35];
char grid[35][81], mark;
bool isVisit[35][80];


void DFS(int x, int y, char& mark, char& Vec) {

	if (x < 0 || y < 0 || x >= r || y >= c[x] || isVisit[x][y] == true
	         	                              || grid[x][y] == Vec) { return; }
	else {

		grid[x][y] = mark;
		isVisit[x][y] = true;
		DFS(x - 1, y, mark, Vec);
		DFS(x, y + 1, mark, Vec);
		DFS(x + 1, y, mark, Vec);
		DFS(x, y - 1, mark, Vec);
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	string line;
	map<char, int> Map;

	while (getline(cin, line)) {
				
		if (line[0] == '_') {
			
			vector<pair<char, int>> Vec(Map.begin(), Map.end());

			sort(Vec.begin(), Vec.end(), [](pair<char, int>& a, pair<char, int>& b) {
			
				return a.second > b.second;
			});

			for (int i = 0; i < r; ++i) {

				for (int j = 0; j < c[i]; ++j) {

					if (grid[i][j] != ' ' && grid[i][j] != Vec[0].first && isVisit[i][j] == false) {

						mark = grid[i][j], DFS(i, j, mark, Vec[0].first);
					}
				}
			}

			for (int i = 0; i < r; ++i, cout << endl) {

				for (int j = 0; j < c[i]; ++j) {

					cout << grid[i][j];
				}				
			}
			
			cout << line << endl;
			r = 0, Map.clear();
		}
		else { 
			
			c[r] = line.size();

			for (int i = 0; i < c[r]; ++i) {

				grid[r][i] = line[i], isVisit[r][i] = false;
				if (line[i] != ' ' && line[i] != '_') { ++Map[line[i]]; }
			}

			++r; 
		}
	}

	return 0;
}