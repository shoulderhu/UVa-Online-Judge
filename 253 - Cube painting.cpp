#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int rotation[3][6] = { { 2, 1, 5, 0, 4, 3 },
                       { 1, 5, 2, 3, 0, 4 },
                       { 0, 2, 4, 1, 3, 5 } };
bool match;
string cube, cube2, tmp;
unordered_map<string, bool> Map;

inline void DFS(string cube) {
	
	Map[cube] = true;

	if (cube == cube2) {

		match = true;
		return;
	}

	for (int i = 0; i < 3 && match == false; ++i) {

		tmp.clear();

		for (int j = 0; j < 6; ++j) {

			tmp += cube[rotation[i][j]];
		}
			
		if (Map[tmp] == false) {
						
			DFS(tmp);
		}
	}	
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
		
	while (cin >> cube) {

		match = false;		
		cube2 = cube.substr(6);
		cube.erase(6, 6);
		Map.clear();
		DFS(cube);
		cout << (match ? "TRUE\n" : "FALSE\n");		
	}

	return 0;
}