#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int n, p, q, vertex;
bool isVisit[101];
vector<int> edge[101];

inline void DFS(int p) {
	
	for (int i = 0; i < edge[p].size(); ++i) {

		if (isVisit[edge[p][i]] == false) {

			--vertex;
			isVisit[edge[p][i]] = true;
			DFS(edge[p][i]);
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	
	while (cin >> n && n != 0) {

		for (int i = 1; i <= n; ++i) {

			edge[i].clear();
		}

		while (cin >> p && p != 0) {

			while (cin >> q && q != 0) {

				edge[p].push_back(q);
			}
		}

		cin >> q;

		for (int i = 0; i < q; ++i) {

			cin >> p;
			memset(isVisit, false, sizeof(bool) * (n + 1));
			vertex = n, DFS(p);
			cout << vertex;

			for (int j = 1; j <= n; ++j) {

				if (isVisit[j] == false) {

					cout << ' ' << j;
				}
			}

			cout << '\n';
		}
	}

	return 0;
}