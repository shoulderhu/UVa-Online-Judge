#include <iostream>
#include <set>
#include <map>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int m, n, i, j;
	map<int, set<int>> task;

	while (cin >> n >> m && !(n == 0 && m == 0)) {

		for (int k = 1; k <= n; k++) { task[k].clear(); }

		for (int k = 1; k <= m; k++) {

			cin >> i >> j;
			task[j].insert(i);
		}

		while (task.empty() == false) {

			int erase;

			for (auto iter = task.begin(); iter != task.end(); ++iter) {

				if (iter->second.size() == 0) { 
										
					cout << iter->first;
					if (task.size() != 1) { cout << " "; }
					erase = iter->first, task.erase(iter->first);
					break; 
				}
			}

			for (auto iter = task.begin(); iter != task.end(); ++iter) {

				auto jter = iter->second.find(erase);

				if (jter != iter->second.end()) { iter->second.erase(jter); }
			}
		}

		cout << endl;
	}

	return 0;
}
