#include <iostream>
#include <map>
#include <set>

using namespace std;

int total;
map<int, set<int>> Map;
map<int, bool> isVisit;

void DFS(int z) {

	if (isVisit[z] == true) { return; }
	else {

		++total, isVisit[z] = true;

		for (auto iter = Map[z].begin(); iter != Map[z].end(); ++iter) {

			DFS(*iter);
		}
	}	
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int kace, n, m, l, x, y, z;
	
	cin >> kace;

	for (int i = 1; i <= kace; ++i) {

		cin >> n >> m >> l;

		Map.clear(), isVisit.clear(), total = 0;

		for (int j = 1; j <= m; ++j) {

			cin >> x >> y;
			Map[x].insert(y);
		}

		for (int j = 1; j <= l; ++j) {

			cin >> z;
			DFS(z);			
		}

		cout << total << endl;
	}

	return 0;
}