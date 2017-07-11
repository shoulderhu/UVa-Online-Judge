#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N, x, y, AP, n;
int dfn[100], low[100];
string line;
stringstream ss;
vector<int> edge[100];

inline void DFS(int u, int v) {
		
	int child = 0;
	bool isAP = false;
	dfn[u] = ++n, low[u] = n;

	for (int i = 0; i < edge[u].size(); ++i) {

		int e = edge[u][i];

		if (dfn[e] < 0) {
			
			++child;
			DFS(e, u);
			low[u] = min(low[u], low[e]);
			if (low[e] >= dfn[u]) { isAP = true; }
		}
		else if (e != v) {

			low[u] = min(low[u], dfn[e]);
		}
	}

	if (u == 1) {

		if (child > 1) { ++AP; }
	}
	else if (isAP) { ++AP; }
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
		
	while (cin >> N && N != 0) {
		
		cin.ignore();
		for (int i = 1; i <= N; ++i) { edge[i].clear(); }
				
		while (getline(cin, line)) {

			ss.clear(), ss << line, ss >> x;
			if (x == 0) { break; }
			
			while (ss >> y) {

				edge[x].push_back(y);
				edge[y].push_back(x);
			}			
		}

		memset(dfn, -1, sizeof(int) * (N + 1));
		AP = 0, n = 0, DFS(1, 0);
		cout << AP << '\n';
	}

	return 0;
}