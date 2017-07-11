#include<iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int N, R, n, d = 0;
string name, A, B;
vector<string> camera;
unordered_map<string, int> dfn, low;
unordered_map<string, vector<string>> edge;

inline void DFS(string u, string v) {

	int child = 0;
	bool isAP = false;
	dfn[u] = ++n, low[u] = n;

	for (auto iter = edge[u].begin(); iter != edge[u].end(); ++iter) {

		if (dfn[*iter] == -1) {

			++child;
			DFS(*iter, u);
			low[u] = min(low[u], low[*iter]);
			if (low[*iter] >= dfn[u]) { isAP = true; }
		}
		else if (*iter != v) {

			low[u] = min(low[u], dfn[*iter]);
		}
	}

	if (u == name) {

		if (child > 1) { camera.push_back(u); }
	}
	else if (isAP) { camera.push_back(u); }
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	
	while (cin >> N && N != 0) {

		if (d > 0) { cout << '\n'; }

		n = 0;
		dfn.clear(), low.clear();
		edge.clear(), camera.clear();

		for (int i = 0; i < N; ++i) {

			cin >> name;	
			dfn[name] = -1;
		}

		cin >> R;

		for (int i = 0; i < R; ++i) {

			cin >> A >> B;
			edge[A].push_back(B);
			edge[B].push_back(A);
		}

		for (auto iter = dfn.begin(); iter != dfn.end(); ++iter) {

			if (iter->second == -1) {

				name = iter->first;
				DFS(name, "");
			}
		}
				
		sort(camera.begin(), camera.end());

		cout << "City map #" << ++d << ": " << camera.size() << " camera(s) found\n";

		for (int i = 0; i < camera.size(); ++i) {

			cout << camera[i] << '\n';
		}
	}

	return 0;
}