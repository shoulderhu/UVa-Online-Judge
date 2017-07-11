#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int c, n, m, x, system;
	struct way { int y, t; }Way;
	deque<int> Queue;
	
	cin >> c;

	for (int i = 0; i < c; ++i) {

		cin >> n >> m;

		bool isPossible = false;		
		vector<int> dis(n, 999001);
		vector<bool> isVisit(n, false);
		vector<vector<struct way>> Edge(n);
		
		for (int j = 0; j < m; ++j) {

			cin >> x >> Way.y >> Way.t;
			Edge[x].push_back(Way);
		}

		dis[0] = 0, isVisit[0] = true, Queue.push_back(0);

		while (Queue.empty() == false) {

			system = Queue.front(), Queue.pop_front();

			for (auto iter = Edge[system].begin(); iter != Edge[system].end(); ++iter) {

				if (dis[iter->y] > dis[system] + iter->t) {

					dis[iter->y] = dis[system] + iter->t;

					if (isVisit[iter->y] == false) {

						isVisit[iter->y] = true;
						Queue.push_back(iter->y);
					}
				}
			}
		}
				
		for (int i = 0; i < n && isPossible == false; ++i) {

			for (auto iter = Edge[i].begin(); iter != Edge[i].end(); ++iter) {

				if (dis[iter->y] > dis[i] + iter->t) {

					isPossible = true;
					break;
				}
			}			
		}

		isPossible == true ? cout << "possible" << endl : cout << "not possible" << endl;
	}

	return 0;
}