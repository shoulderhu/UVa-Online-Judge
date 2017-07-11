#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int E, N, n, T, e;
	map<int, set<int>> Map;

	cin >> E;

	for (int i = 0; i < E; ++i) {

		cin >> N;
		
		for (int j = 1; j <= N; ++j) {

			cin >> n;
			Map[i].insert(n);
		}		
	}

	cin >> T;
	
	for (int i = 1; i <= T; ++i) {

		cin >> e;

		if (Map[e].size() == 0) { cout << "0" << endl; continue; }
		else {

			int max = 0, day;
			queue<int> Queue;
			map<int, bool> isVisit;
			Queue.push(e), isVisit[e] = true;

			for (int j = 1; Queue.empty() == false; ++j) {

				int length = Queue.size(), told = 0;

				for (int k = 1; k <= length; ++k) {

					int t = Queue.front();
					Queue.pop();

					for (auto iter = Map[t].begin(); iter != Map[t].end(); ++iter) {

						if (isVisit.find(*iter) == isVisit.end()) {

							Queue.push(*iter), isVisit[*iter] = true, ++told;
						}
					}
				}

				if (told > max) { day = j, max = told; }
			}

			cout << max << " " << day << endl;
		}		
	}

	return 0;
}