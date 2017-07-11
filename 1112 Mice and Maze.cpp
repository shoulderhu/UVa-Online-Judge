#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

int main() {

	ios::sync_with_stdio(false);

	int kace, M, E, T, N, a, cell;
	struct path { int b, time; }Path;
	
	cin >> kace;

	for (int i = 0; i < kace; ++i) {

		if (i > 0) { cout << endl; }

		cin >> N >> E >> T >> M;

		int mice = 0;		
		vector<int> dis(N + 1, 1000000000);		
		set<pair<int, int>> Set = { {0, E} };
		unordered_map<int, vector<struct path>> Edge;

		for (int j = 0; j < M; ++j) {

			cin >> Path.b >> a >> Path.time;
			Edge[a].push_back(Path);
		}

		dis[E] = 0;

		while (Set.empty() == false) {

			cell = Set.begin()->second, Set.erase(Set.begin());

			for (auto iter = Edge[cell].begin(); iter != Edge[cell].end(); ++iter) {

				if (dis[iter->b] > dis[cell] + iter->time) {

					Set.erase({ dis[iter->b], iter->b });
					dis[iter->b] = dis[cell] + iter->time;
					Set.insert({ dis[iter->b], iter->b });					
				}				
			}
		}

		for (int j = 1; j < dis.size(); ++j) {

			if (dis[j] <= T) { ++mice; }
		}

		cout << mice << endl;
	}
	
	return 0;
}
